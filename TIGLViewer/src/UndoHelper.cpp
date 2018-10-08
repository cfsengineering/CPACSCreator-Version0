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
    if(files.contains(fileName)){
        currentIdx = files.indexOf(fileName);
    }
    else{
        init(fileName);
    }
}

void UndoHelper::init(QString fileName) {
    originFile = QFileInfo(fileName);
    if( ! (originFile.exists() && originFile.isFile() ) ){
        LOG(WARNING) << "UndoHelper::init::unable to find file:" << originFile.absoluteFilePath().toStdString() << std::endl;
        clean();
        return;
    }

    QString newFN = generateFileName();
    files.push_front(newFN);
    currentIdx = 0;

    QFile::copy(originFile.absoluteFilePath(), this->currentFile());


}

void UndoHelper::clean() {

    currentIdx = -1;
    files = QStringList();
    originFile = QFileInfo();
    generatorIdx = 0;

}

bool UndoHelper::undoIsAvailable() {
    if( isValid()){
        return  ( (currentIdx + 1) >= 0  &&  ((currentIdx + 1) < files.size() ) ) ;
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
             return files.at(currentIdx);
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
        return  ( (currentIdx - 1) >= 0  &&  ((currentIdx - 1) < files.size() ) ) ;
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
            return files.at(currentIdx);
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

QString UndoHelper::addCommit() {
    if ( ! isValid()){
        // TODO throw ERROR
        return QString();
    }
    // redo and undo cases -> when we add a commit the previous commit will be the current commit and all
    if(currentIdx > 0) {
        for(int i = 0; i < currentIdx; i++){
            QFile::remove(files[0] ) ;
            files.pop_front();
        }
    }

    QString newFN = generateFileName();
    files.push_front(newFN);
    currentIdx = 0;
    return newFN;
}

QString UndoHelper::currentFile() {
    return files.at(currentIdx);
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
        QFile::copy(files.at(currentIdx), originFile.absoluteFilePath());
    }
    else {
        LOG(WARNING) << "UndoHelper: this undo helper seems to be in an incorrect state, the saving is not performed " << std::endl;
    }
}

bool UndoHelper::isValid() {
    bool fileExist = originFile.exists() && originFile.isFile();
    bool idxValid = (0 <= currentIdx) && (currentIdx < files.size() ) ;
    return fileExist && idxValid;
}

