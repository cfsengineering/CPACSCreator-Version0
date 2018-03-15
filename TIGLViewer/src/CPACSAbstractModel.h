//
// Created by cfse on 3/13/18.
//

#ifndef TIGL_CPACSABSTRACTMODEL_H
#define TIGL_CPACSABSTRACTMODEL_H

#include <QAbstractItemModel>

#include "CPACSOverTreeItem.h"
#include "TIGLViewerDocument.h"

class CPACSAbstractModel: public QAbstractItemModel {

Q_OBJECT

public:
    explicit CPACSAbstractModel( const TIGLViewerDocument& doc , QObject *parent = 0);
    ~CPACSAbstractModel();


    // get the data
    QVariant data(const QModelIndex& index, int role) const override;

    // Qt::ItemFlags flags(const QModelIndex &index) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &index) const override;
    // count the number of child of a index
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    // count the number of data a index hold
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

protected:

    // return the item for the given index
    // empty index is considered as the root index!
    CPACSOverTreeItem* getItem( QModelIndex index) const;

    // return a index for the item
    QModelIndex getIndex( CPACSOverTreeItem * item, int column ) const ;

private:

    void initTree( const TIGLViewerDocument& doc);
    void deleteTree();
    CPACSOverTreeItem * root;

};


#endif //TIGL_CPACSABSTRACTMODEL_H
