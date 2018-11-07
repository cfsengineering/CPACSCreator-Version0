//
// Created by cfse on 10/5/18.
//

#include "UndoHelper.h"
#include <QFile>
#include "logging/CTiglLogging.h"

UndoHelper::UndoHelper() {
    this->clean();
}

void UndoHelper::set(QString fileName) {
    if(backupFiles.contains(fileName)){
        currentIdx = backupFiles.indexOf(fileName);
    }
    else{
        init(fileName);
    }
}

void UndoHelper::init(QString fileName) {
    clean();
    originFile = QFileInfo(fileName);
    if( ! (originFile.exists() && originFile.isFile() ) ){
        LOG(WARNING) << "UndoHelper::init::unable to find file:" << originFile.absoluteFilePath().toStdString() << std::endl;
        return;
    }
    QString newFN = generateFileName();
    backupFiles.push_front(newFN);
    currentIdx = 0;

    QFile::copy(originFile.absoluteFilePath(), this->currentFile());


}

void UndoHelper::clean() {
    // delete backup files
    for(int i = 0; i < backupFiles.size(); i++){
        bool removed = QFile::remove(backupFiles[i]) ;
        if( !removed){
            LOG(WARNING) << "UndoHelper::clean: the bakcup files was not removed correctly";
        }
    }
    currentIdx = -1;
    backupFiles = QStringList();
    originFile = QFileInfo();
    generatorIdx = 0;

}

bool UndoHelper::undoIsAvailable() {
    if( isValid()){
        return  ( (currentIdx + 1) >= 0  &&  ((currentIdx + 1) < backupFiles.size() ) ) ;
    }
    else {
        LOG(WARNING) << "UndoHelper: this undoHelper seems to be in an incorrect state, impossible to perform the undo " << std::endl;
        return false;
    }
}

QString UndoHelper::undo() {

    if( isValid()){
         if( undoIsAvailable() ){
             currentIdx = currentIdx + 1;
             return backupFiles.at(currentIdx);
         }else{
             // TODO throw ERROR
             return QString();
         }
    }
    else {
        // TODO throw ERROR
        return QString();
    }
}

bool UndoHelper::redoIsAvailable() {
    if( isValid()){
        return  ( (currentIdx - 1) >= 0  &&  ((currentIdx - 1) < backupFiles.size() ) ) ;
    }
    else {
        LOG(WARNING) << "UndoHelper: this undoHelper seems to be in an incorrect state, impossible to perform the redo " << std::endl;
        return false;
    }
}

QString UndoHelper::redo() {
    if( isValid()){
        if( redoIsAvailable() ){
            currentIdx = currentIdx - 1;
            return backupFiles.at(currentIdx);
        }else{
            // TODO throw ERROR
            return QString();
        }
    }
    else {
        // TODO throw ERROR
        return QString();
    }
}

void UndoHelper::addCheckPoint() {
    if ( ! isValid()){
        // TODO throw ERROR
    }
    QString currentF = this->currentFile();

    // redo and undo cases -> when we add a commit the previous commit will be the current commit and all
    if(currentIdx > 0) {
        for(int i = 0; i < currentIdx; i++){
            bool removed = QFile::remove(backupFiles[0]) ;
            if( !removed){
                LOG(WARNING) << "UndoHelper::clean: the bakcup files was not removed correctly";
            }
            backupFiles.pop_front();
        }
    }

    QString newBackup = generateFileName();
    QFile::copy(currentF, newBackup );
    currentIdx = 0;
    backupFiles.insert(1, newBackup);

}

QString UndoHelper::currentFile() {
    if(currentIdx < backupFiles.size() && currentIdx >= 0){
        return backupFiles.at(currentIdx);
    }else {
        LOG(WARNING) << " UndoHelper::currentFile but current file is not set right now!" << std::endl;
        return "";
    }

}

QString UndoHelper::generateFileName() {
    generatorIdx = generatorIdx + 1;
    // filename without suffix
    QString newFN = originFile.absoluteFilePath().remove(originFile.absoluteFilePath().size() - originFile.suffix().size()- 1, originFile.suffix().size() + 1);
    newFN = newFN + "-temp-" + std::to_string(generatorIdx).c_str() + "." + originFile.suffix();
    return newFN;
}

bool UndoHelper::isXmlFile() {

    return (originFile.suffix().toLower() == "xml");

}

void UndoHelper::saveInOriginal() {
    if( isValid()){
        // delete the old file
        QFile::remove(originalFile());
        // copy the temp file at the original place
        QFile::copy(backupFiles.at(currentIdx), originFile.absoluteFilePath());
    }
    else {
        LOG(WARNING) << "UndoHelper: this undo helper seems to be in an incorrect state, the saving is not performed " << std::endl;
    }
}



void UndoHelper::saveInFile(QString saveFilename) {
    if( isValid()){
        if(QFile::exists(saveFilename)){
            QFile::remove(saveFilename);
        }
        QFile::copy(backupFiles.at(currentIdx), saveFilename );
        originFile = QFileInfo(saveFilename);
        if( ! (originFile.exists() && originFile.isFile() ) ){
            LOG(WARNING) << "UndoHelper::saveInFile:: someting go wrong to save in file:" << saveFilename.toStdString() << std::endl;
            return;
        }
    }
    else {
        LOG(WARNING) << "UndoHelper: this undo helper seems to be in an incorrect state, the saving is not performed " << std::endl;
    }
}



bool UndoHelper::isValid() {
    bool fileExist = originFile.exists() && originFile.isFile();
    bool idxValid = (0 <= currentIdx) && (currentIdx < backupFiles.size() ) ;
    return fileExist && idxValid;
}

UndoHelper::~UndoHelper() {
    clean();
}

void UndoHelper::print() {
    LOG(WARNING) << "backup list" << std::endl;
    for(QString f: backupFiles){
        LOG(WARNING) << f.toStdString() << std::endl;
    }
    LOG(WARNING) << "currentIdx:" << std::to_string(currentIdx) << std::endl;
}

QString UndoHelper::originalFile() {
    return originFile.absoluteFilePath();
}

