//
// Created by cfse on 3/13/18.
//

#ifndef TIGL_CPACSABSTRACTMODEL_H
#define TIGL_CPACSABSTRACTMODEL_H

#include <QAbstractItemModel>

#include <QtCore/QItemSelection>

#include "CPACSOverTreeItem.h"
#include "TIGLViewerDocument.h"

#include <Quantity_Color.hxx>


class CPACSAbstractModel: public QAbstractItemModel {

Q_OBJECT

public:
    explicit CPACSAbstractModel( TIGLViewerWindow& main, QObject *parent = 0);
    ~CPACSAbstractModel();

    void initTree( TIGLViewerDocument& doc);

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


    // Return true if there is a valid root
    inline bool isValid() const;



public slots:
    void onItemSelectionChanged(const QItemSelection &, const QItemSelection &);


protected:


    // return the item for the given index
    // empty index is considered as the root index!
    CPACSOverTreeItem* getItem( QModelIndex index) const;

    // return a index for the item
    QModelIndex getIndex( CPACSOverTreeItem * item, int column ) const ;

    QString stdStringToQString(std::string stdString);

private:

    // alternative to CPACS reader, take info form tigl instead from the xml directly
//    void initWingsFrom(tigl::CCPACSConfiguration &config);

    CSharedPtr<CPACSOverTreeItem>  root;
    TIGLViewerWindow& app;
    QString currentFileName;    // filename of the displayed tree
    QString currentConfigUid;   // Uid of the display tree model
};


#endif //TIGL_CPACSABSTRACTMODEL_H
