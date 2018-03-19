//
// Created by cfse on 3/13/18.
//

#include "CPACSAbstractModel.h"
#include "CCPACSWingSection.h"
#include "CCPACSWings.h"
#include "CCPACSWingSectionElement.h"
#include "CCPACSWing.h"

#include "MyCPACSReader.h"


CPACSAbstractModel::CPACSAbstractModel(const TIGLViewerDocument& doc, QObject* parent)
        : QAbstractItemModel(parent)
{
    MyCPACSReader reader = MyCPACSReader();

    root = reader.createRoot(doc.getLoadedDocumentFileName());

    //initTree(doc);

}



CPACSAbstractModel::~CPACSAbstractModel()
{
    root.reset();
}

void CPACSAbstractModel::initWingPart( tigl::CCPACSConfiguration& config ){


    QString tempUid;
    QString tempType;

    tigl::CCPACSWings& wings = config.GetWings();
    tempUid = QString("" ) ; // no UID  for wings by definition of the cpacs
    tempType = QString("wings");
    CPACSOverTreeItem* newWings = root->addChild(1, tempUid, tempType);


    for( int i = 1; i <= config.GetWingCount(); i++){  // cpacs index start at 1
        tigl::CCPACSWing& wing = config.GetWing(i);
        tempUid = QString(wing.GetUID().c_str() ) ;
        tempType = QString("wing");
        CPACSOverTreeItem* newWing = newWings->addChild(i, tempUid, tempType);

        tigl::CCPACSWingSections& sections = wing.GetSections();
        tempUid = QString("" ) ;
        tempType = QString("sections");
        CPACSOverTreeItem* newSections = newWing->addChild(i, tempUid, tempType);


        for(int j = 1; j <= wing.GetSectionCount(); j++){
            tigl::CCPACSWingSection& section = wing.GetSection(j);
            tempUid = QString(section.GetUID().c_str() ) ;
            tempType = QString("section");
            CPACSOverTreeItem* newSection = newSections->addChild(j,tempUid, tempType);

            tigl::CCPACSWingSectionElements& elements = section.GetElements();
            tempUid = QString("" ) ;
            tempType = QString("elements");
            CPACSOverTreeItem* newElements = newSection->addChild(i, tempUid, tempType);


            for(int k = 1; k <= section.GetSectionElementCount(); k++ ){
                tigl::CCPACSWingSectionElement& element = section.GetSectionElement(k);
                tempUid = QString(element.GetUID().c_str());
                tempType = QString("element");
                CPACSOverTreeItem * newElement = newElements->addChild(k, tempUid, tempType);
            }
        }
    }
}


void CPACSAbstractModel::initTree(const TIGLViewerDocument &doc)
{
/*
    QString tempUid;
    QString tempType;

    tigl::CCPACSConfiguration& config = doc.GetConfiguration();

    // init root
    tempUid = QString(config.GetUID().c_str() ) ;
    tempType = QString("root");
    root = new CPACSOverTreeItem(1, tempUid, tempType) ;

    initWingPart(config);
*/



}


QVariant CPACSAbstractModel::headerData(int section, Qt::Orientation orientation, int role) const {

    if (root != nullptr && orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return root->getDataName(section);
    }

    return QVariant();
}


QVariant CPACSAbstractModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    CPACSOverTreeItem *item = getItem(index);
    QVariant data ;
    if(index.column() == 0){
        data = item->getCpacsIndex();
    }else if(index.column() == 1){
        data = item->getCpacsType();
    }else if(index.column() == 2){
        data = item->getCpacsUid();
    }else{
        data = QVariant();
    }

    return data;
}


// return the index of the parent
QModelIndex CPACSAbstractModel::parent(const QModelIndex& index) const
{
    CPACSOverTreeItem * childItem = getItem(index);
    CPACSOverTreeItem* parentItem = childItem->getParent();

    return getIndex(parentItem, 0 );
}


// Count the number of children of this item
int CPACSAbstractModel::rowCount(const QModelIndex& idx) const
{
    CPACSOverTreeItem*  item = getItem(idx);
    return item->getChildren().count();

}

int CPACSAbstractModel::columnCount(const QModelIndex &idx ) const
{

    CPACSOverTreeItem*  item = getItem(idx);
    return item->getDataCount();
}




// return the QModelindex from a parent and row and column information
QModelIndex CPACSAbstractModel::index(int row, int column, const QModelIndex &parent) const
{
    CPACSOverTreeItem* parentItem = getItem(parent);    // return root if parent is empty or invalid
    CPACSOverTreeItem* childItem = parentItem->getChildren().at(row);

    if (childItem)  // case where the child is not a null pointer
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex CPACSAbstractModel::getIndex(CPACSOverTreeItem *item, int column) const
{
    if(item == root.get() || item == nullptr ){
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
    return root.get();    // empty index is the root
}