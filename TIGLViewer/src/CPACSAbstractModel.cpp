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
#include "MyCPACSReader.h"
#include "CCPACSWingSegment.h"


CPACSAbstractModel::CPACSAbstractModel(TIGLViewerWindow& main, QObject* parent)
        : QAbstractItemModel(parent), app(main)
{
    root = nullptr;
    currentFileName = QString();
    currentConfigUid = QString();
}



CPACSAbstractModel::~CPACSAbstractModel()
{
}
//
//void CPACSAbstractModel::initWingsFrom(tigl::CCPACSConfiguration &config){
//
//
//    QString tempUid;
//    QString tempType;
//
//    tigl::CCPACSWings& wings = config.GetWings();
//    tempUid = QString("" ) ; // no UID  for wings by definition of the cpacs
//    tempType = QString("wings");
//    CPACSOverTreeItem* newWings = root->addChild(1, tempUid, tempType);
//
//
//    for( int i = 1; i <= config.GetWingCount(); i++){  // cpacs index start at 1
//        tigl::CCPACSWing& wing = config.GetWing(i);
//        tempUid = QString(wing.GetUID().c_str() ) ;
//        tempType = QString("wing");
//        CPACSOverTreeItem* newWing = newWings->addChild(i, tempUid, tempType);
//
//        tigl::CCPACSWingSections& sections = wing.GetSections();
//        tempUid = QString("" ) ;
//        tempType = QString("sections");
//        CPACSOverTreeItem* newSections = newWing->addChild(i, tempUid, tempType);
//
//
//        for(int j = 1; j <= wing.GetSectionCount(); j++){
//            tigl::CCPACSWingSection& section = wing.GetSection(j);
//            tempUid = QString(section.GetUID().c_str() ) ;
//            tempType = QString("section");
//            CPACSOverTreeItem* newSection = newSections->addChild(j,tempUid, tempType);
//
//            tigl::CCPACSWingSectionElements& elements = section.GetElements();
//            tempUid = QString("" ) ;
//            tempType = QString("elements");
//            CPACSOverTreeItem* newElements = newSection->addChild(i, tempUid, tempType);
//
//
//            for(int k = 1; k <= section.GetSectionElementCount(); k++ ){
//                tigl::CCPACSWingSectionElement& element = section.GetSectionElement(k);
//                tempUid = QString(element.GetUID().c_str());
//                tempType = QString("element");
//                CPACSOverTreeItem * newElement = newElements->addChild(k, tempUid, tempType);
//            }
//        }
//    }
//}





void CPACSAbstractModel::initTree( TIGLViewerDocument &doc)
{
    // Destroy old tree if existe
    std::cout << "Destroy tree model: filename=" << currentFileName.toStdString() << " uid=" << currentConfigUid.toStdString() << std::endl;
    root = nullptr;
    currentFileName = QString();
    currentConfigUid = QString();

    // Check if the new document is valid
    if(!doc.isConfigurationValid()){
        return;
    }

    // check rotorcraft
    tigl::CCPACSConfiguration& config = doc.GetConfiguration();
    if( config.IsRotorcraft() ){
        std::cout << "Rotorcraft is not supported by the tree viewer" << std::endl;
        return;
    }

    // Create the tree
    MyCPACSReader reader = MyCPACSReader();
    currentFileName = doc.getLoadedDocumentFileName();
    currentConfigUid = QString(config.GetUID().c_str()) ;
    root = reader.createRoot(currentFileName, currentConfigUid );
    return;
}


QVariant CPACSAbstractModel::headerData(int section, Qt::Orientation orientation, int role) const {

    if (isValid() && orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return QString((root->getDataName(section)).c_str());
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
    if( !isValid() || item == root.get() || item == nullptr ){
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

void CPACSAbstractModel::onItemSelectionChanged(const QItemSelection & newSelection, const QItemSelection & oldSelection)
{
    CPACSOverTreeItem * item = getItem(newSelection.indexes().at(0));

    std::cout << "selection changed " << item->getCpacsUid() << std::endl;

    Quantity_Color color = Quantity_Color( 255/255.,192/255.,203/255.  , Quantity_TOC_RGB);
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
    return root != nullptr;
}