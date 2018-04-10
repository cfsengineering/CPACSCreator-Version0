//
// Created by cfse on 3/13/18.
//

#include <QtCore/QItemSelection>
#include "CPACSAbstractModel.h"
#include "CCPACSWingSection.h"
#include "CCPACSWings.h"
#include "CCPACSWingSectionElement.h"
#include "CCPACSWing.h"
#include "TIGLViewerWindow.h"
#include "AircraftTree.h"
#include "CCPACSWingSegment.h"


CPACSAbstractModel::CPACSAbstractModel(CPACSCreatorAdapter* adapter, QObject* parent )
        : QAbstractItemModel(parent)
{
   creatorAdapter = adapter;
}



CPACSAbstractModel::~CPACSAbstractModel()
{
}


QVariant CPACSAbstractModel::headerData(int section, Qt::Orientation orientation, int role) const  {

    if (isValid() && orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return QString((creatorAdapter->getRoot()->getDataName(section)).c_str());
    }

    return QVariant();
}


QVariant CPACSAbstractModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    CPACSOverTreeItem *item = getItem(index);
    QVariant data ;
    if(index.column() == 0){
        data = item->getCpacsIndex();
    }else if(index.column() == 1){
        data = QString( item->getCpacsType().c_str() );
    }else if(index.column() == 2){
        data = QString(item->getCpacsUid().c_str());
    }else if(index.column() == 3){
        data = QString(item->getXPath().c_str());
    }else{
        data = QVariant();
    }

    return data;
}


// return the index of the parent
QModelIndex CPACSAbstractModel::parent(const QModelIndex& index) const
{
    if(!isValid())
        return QModelIndex();

    CPACSOverTreeItem * childItem = getItem(index);
    CPACSOverTreeItem* parentItem = childItem->getParent();

    return getIndex(parentItem, 0 );
}


// Count the number of children of this item
int CPACSAbstractModel::rowCount(const QModelIndex& idx) const
{
    if(!isValid())
        return 0;

    CPACSOverTreeItem*  item = getItem(idx);
    return item->getChildren().count();

}

int CPACSAbstractModel::columnCount(const QModelIndex &idx ) const
{

    if(!isValid())
        return 0;

    CPACSOverTreeItem*  item = getItem(idx);
    return item->getDataCount();
}


// return the QModelindex from a parent and row and column information
QModelIndex CPACSAbstractModel::index(int row, int column, const QModelIndex &parent) const
{
    if( !isValid())
        return QModelIndex();

    CPACSOverTreeItem* parentItem = getItem(parent);    // return root if parent is empty or invalid
    CPACSOverTreeItem* childItem = parentItem->getChildren().at(row);

    if (childItem)  // case where the child is not a null pointer
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex CPACSAbstractModel::getIndex(CPACSOverTreeItem *item, int column) const
{
    if( !isValid() || item == creatorAdapter->getRoot().get() || item == nullptr ){
        return QModelIndex();   // We use empty index for the root
    }

    int row = item->positionRelativelyToParent();
    return createIndex(row, column, item);
}

CPACSOverTreeItem* CPACSAbstractModel::getItem(QModelIndex index) const
{
    // Internal identifier is the item pointer
    if( index.isValid() ){
        CPACSOverTreeItem* item = static_cast<CPACSOverTreeItem*>(index.internalPointer());
        if(item) return item;
     }
    return creatorAdapter->getRoot().get();    // empty index is the root
}

void CPACSAbstractModel::onItemSelectionChanged(const QItemSelection & newSelection, const QItemSelection & oldSelection)
{
    CPACSOverTreeItem * item = getItem(newSelection.indexes().at(0));

    std::cout << "selection changed " << item->getCpacsUid() << std::endl;

    if(item->getCpacsType() == "transformation"){
        emit selectionIsATransformation(item);
    }

//    Quantity_Color color = Quantity_Color( 255/255.,192/255.,203/255.  , Quantity_TOC_RGB);
//
//    if(item->getCpacsType() == "wing"){
//
//        tigl::CCPACSWing& wing = m_doc.GetConfiguration().GetWing(item->getCpacsIndex());
//
//        for (int i = 1; i <= wing.GetSegmentCount(); i++) {
//            // Draw segment loft
//            app.getScene()->displayShape(wing.GetSegment(i).GetLoft(), true, color);
//        }
//    }
}

inline bool CPACSAbstractModel::isValid() const {
    return creatorAdapter->getRoot() != nullptr;
}