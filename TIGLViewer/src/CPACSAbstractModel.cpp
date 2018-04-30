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

        if(section == 0){
            return "index";
        }else if (section == 1){
            return "type";
        }else if (section == 2){
            return "UID";
        }else if (section == 3){
            return "XPath";
        }else{
            return "invalid";
        }

    }

    return QVariant();
}


QVariant CPACSAbstractModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    cpcr::CPACSTreeItem *item = getItem(index);
    QVariant data ;
    if(index.column() == 0){
        data = item->getTixiIndex();
    }else if(index.column() == 1){
        data = QString( item->getType().c_str() );
    }else if(index.column() == 2){
        data = QString(item->getUid().c_str());
    }else if(index.column() == 3){
        data = QString(item->getXPath().toString().c_str());
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

    cpcr::CPACSTreeItem * childItem = getItem(index);
    cpcr::CPACSTreeItem* parentItem = childItem->getParent();

    return getIndex(parentItem, 0 );
}


// Count the number of children of this item
int CPACSAbstractModel::rowCount(const QModelIndex& idx) const
{
    if(!isValid())
        return 0;

    cpcr::CPACSTreeItem*  item = getItem(idx);
    return item->getChildren().size();

}

int CPACSAbstractModel::columnCount(const QModelIndex &idx ) const
{

    if(!isValid())
        return 0;

    cpcr::CPACSTreeItem*  item = getItem(idx);
    return 4;   // we have for values in a tree item
}


// return the QModelindex from a parent and row and column information
QModelIndex CPACSAbstractModel::index(int row, int column, const QModelIndex &parent) const
{
    if( !isValid())
        return QModelIndex();

    cpcr::CPACSTreeItem* parentItem = getItem(parent);    // return root if parent is empty or invalid
    cpcr::CPACSTreeItem* childItem = parentItem->getChildren()[row];

    if (childItem)  // case where the child is not a null pointer
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex CPACSAbstractModel::getIndex(cpcr::CPACSTreeItem *item, int column) const
{
    if( !isValid() || item == creatorAdapter->getRoot() || item == nullptr ){
        return QModelIndex();   // We use empty index for the root
    }

    int row = item->positionRelativelyToParent();
    return createIndex(row, column, item);
}

cpcr::CPACSTreeItem* CPACSAbstractModel::getItem(QModelIndex index) const
{
    // Internal identifier is the item pointer
    if( index.isValid() ){
        cpcr::CPACSTreeItem* item = static_cast<cpcr::CPACSTreeItem*>(index.internalPointer());
        if(item) return item;
     }
    return creatorAdapter->getRoot();    // empty index is the root
}

void CPACSAbstractModel::onItemSelectionChanged(const QItemSelection & newSelection, const QItemSelection & oldSelection)
{
    cpcr::CPACSTreeItem * item = getItem(newSelection.indexes().at(0));

    std::cout << "selection changed " << item->getUid() << std::endl;

    if(item->getType() == "transformation"){
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
    return creatorAdapter->isValid();
}