//
// Created by cfse on 3/13/18.
//

#include "CPACSOverTreeItem.h"
#include <iostream>
#include <QtGui>


CPACSOverTreeItem::CPACSOverTreeItem(int index, QString uid, QString cpacsType)
{
    this->cpacsIndex = index;
    this->cpacsUid = uid;
    this->cpacsType = cpacsType;
    this->parent = nullptr;
}

CPACSOverTreeItem::~CPACSOverTreeItem(){
    //std::cout << "destructor tree item called" << cpacsUid.toStdString() << std::endl;
    qDeleteAll(children);   //recursive call of destructor
}



CPACSOverTreeItem*  CPACSOverTreeItem::addChild(int index, QString uid, QString cpacsType) {

    CPACSOverTreeItem* newChild = new CPACSOverTreeItem(index, uid, cpacsType);
    newChild->parent = this;
    children.push_back(newChild);
    return newChild;
}

CPACSOverTreeItem* CPACSOverTreeItem::getParent() const{
    return parent;
};

QList<CPACSOverTreeItem*> CPACSOverTreeItem::getChildren() const{
    return children;
};


QString CPACSOverTreeItem::print() const {
    return QString("TreeItem: cpacsType: %1, uid: %2, index: %3").arg(cpacsType).arg(cpacsUid).arg(cpacsIndex) ;
}

int CPACSOverTreeItem::getCpacsIndex() const {
    return cpacsIndex;
}

QString CPACSOverTreeItem::getCpacsType() const {
    return cpacsType;
}

QString CPACSOverTreeItem::getCpacsUid() const {
    return cpacsUid;
}

int CPACSOverTreeItem::positionRelativelyToParent() const {

    int position = -1;
    CPACSOverTreeItem* parent = getParent();
    if (parent != nullptr){
        position = parent->children.indexOf(const_cast<CPACSOverTreeItem*> (this));
    }
    return position;
}

QString CPACSOverTreeItem::getDataName(int i) {
    if(i == 0){
        return "index";
    }else if (i==1){
        return "type";
    }else if (i==2){
        return "UID";
    }else{
        return "invalid";
    }
}
