//
// Created by cfse on 10/5/18.
//

#ifndef TIGL_UNDOHELPER_H
#define TIGL_UNDOHELPER_H

#include <QStringList>
#include <QFileInfo>

/***
 * Helper class to manage the undo and redo operations.
 * The undo operation is done by saving files
 *
 * Basically this class take care of repertoring the filenames to do the undo operations.
 */
class UndoHelper {


public:

    UndoHelper();

    /**
     * Initialize the undo helper
     *
     * @param fileName
     */
    void init(QString fileName);

    void set(QString fileName);

    /**
     * reset every thing to null
     */
    void clean();

    /***
     * Return true if there is a filename available for a undo operation
     * @return
     */
    bool undoIsAvailable();

    /**
    *  Return the filename that correspond to the file to restore to do the undo.
    *  The current index is updated to this file.
    *  If it is impossible to do a undo this function return a empty string.
    *  @remark No change will occurs in tiglViewer, only the name is returned
    * @return
    */
    QString undo();


    bool redoIsAvailable();

    QString redo();

    /***
     * Save the current index into the original file.
     * @return
     */
    void saveInOriginal();



    /***
     * Create a new fileName to use to store the commit.
     * If there is redo on the stack they will be earsed.
     *
     */
    QString addCommit();

    /**
     * Return the current file.
     * Should be the same as the file that is actually used by cpacscreator.
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

private:

    int currentIdx;
    QStringList files;
    QFileInfo originFile;
    int generatorIdx;


};


#endif //TIGL_UNDOHELPER_H
