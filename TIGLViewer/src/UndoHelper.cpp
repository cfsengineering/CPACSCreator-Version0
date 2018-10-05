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

    addCommit();
    QFile::copy(originFile.absoluteFilePath(), this->currentFile());


}

void UndoHelper::clean() {

    currentIdx = -1;
    files = QStringList();
    originFile = QFileInfo();
    generatorIdx = 0;

}

bool UndoHelper::undoIsAvailable() {
    return false;
}

QString UndoHelper::undo() {
    return QString();
}

bool UndoHelper::redoIsAvailable() {
    return false;
}

QString UndoHelper::redo() {
    return QString();
}

QString UndoHelper::addCommit() {
    // TODO case of idx not 0
    QString newFN = generateFileName();
    files.push_front(newFN);
    currentIdx = 0;
    return newFN;
}

QString UndoHelper::currentFile() {
    return files[currentIdx];
}

QString UndoHelper::generateFileName() {
    generatorIdx = generatorIdx + 1;
    // filename without suffix
    QString newFN = originFile.absoluteFilePath().remove(originFile.absoluteFilePath().size() - originFile.suffix().size()- 1, originFile.suffix().size() + 1);
    newFN = newFN + "-temp-" + std::to_string(generatorIdx).c_str() + "." + originFile.suffix();
    return newFN;
}

