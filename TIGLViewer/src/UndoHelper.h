//
// Created by cfse on 10/5/18.
//

#ifndef TIGL_UNDOHELPER_H
#define TIGL_UNDOHELPER_H

#include <QStringList>
#include <QFileInfo>

/***
 * Helper class to manage undo and redo operations.
 *
 * On "init" (or "set"), the helper will duplicate the given file. This copied file becomes the "currentFile".
 * Then the user should work with this "currentFile" (for example to open the CPACSConfiguration).
 * At some point, the user can add a check point calling the "addCheckPoint".
 * The "addCheckPoint" function will copy the file and register it, but the "currentFile" stay the same.
 * On calling "undo" the helper file return the last check point file and the current file will be updated. It'is up
 * to the user to reopen the returned file in its application (the filename is no more the same as before).
 * At the end (when the destructor or the clean function is call) every temp files (bakcup files) will be delete. This
 * include the current file.
 *
 *
 */
class UndoHelper {


public:

    /***
     * Initialize a empty UndoHelper
     */
    UndoHelper();

    /***
     * Destroy the UndoHelper
     * @remark All the backup files will be deleted! Make sure to save your result before.
     *
     */
    ~UndoHelper();

    /**
     * Initialize the undo helper with a particular file.
     * @param fileName
     */
    void init(QString fileName);


    /***
     * Check if the filename is already used by some check points.
     * If yes, this check point file will become the current file.
     * Otherwise the UndoHelper will be reinitialized with this new filename.
     *
     * @param fileName
     */
    void set(QString fileName);

    /**
     * Reset every variable and destroy backup files.
     */
    void clean();

    /***
     * Return true if there is a checkpoint available for a undo operation
     * @return
     */
    bool undoIsAvailable();

    /**
    *  Return the filename that correspond to the file to restore to do the undo.
    *  The currentFile is updated.
    *  If it is impossible to do a undo, this function return a empty string.
    *  @remark No change will occurs in tiglViewer, only the name is returned
    * @return
    */
    QString undo();


    /***
     * Return true if there is a checkpoint available for a redo operation
     * @return
     */
    bool redoIsAvailable();


    /**
    *  Return the filename that correspond to the file to restore to do the redo.
    *  The currentFile is updated.
    *  If it is impossible to do a redo, this function return a empty string.
    *  @remark No change will occurs in tiglViewer, only the name is returned
    * @return
    */
    QString redo();

    /***
     * Save the currentFile into the original file.
     * @return
     */
    void saveInOriginal();



    /***
     * Copy the currentFile in a new file and register this new file.
     * If the currentFile has some possible redo available, they will be destroyed.
     *
     */
    void addCheckPoint();

    /**
     * Return the current file.
     * @return
     */
    QString currentFile();


    bool isXmlFile();


protected:
    QString generateFileName();

    /***
     * Check if the UndoHelper is in a valid state.
     * This means that the original file is set and the current index reference a existing filename.
     * @return
     */
    bool isValid();

    void print();

private:

    int currentIdx;
    QStringList backupFiles;
    QFileInfo originFile;
    int generatorIdx;


};


#endif //TIGL_UNDOHELPER_H
