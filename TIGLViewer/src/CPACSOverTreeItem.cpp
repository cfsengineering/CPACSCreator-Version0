//
// Created by cfse on 3/13/18.
//

#include "CPACSOverTreeItem.h"
#include <iostream>
#include <QtGui>

/*
CPACSOverTreeItem::CPACSOverTreeItem(int index, std::string uid, std::string cpacsType, std::string xPath)
{
    this->cpacsIndex = index;
    this->cpacsUid = uid;
    this->cpacsType = cpacsType;
    this->parent = nullptr;
    this->xPath = xPath;
}

CPACSOverTreeItem::~CPACSOverTreeItem(){
    qDeleteAll(children);   //recursive call of destructor
}



CPACSOverTreeItem*  CPACSOverTreeItem::addChild(int index, std::string uid, std::string cpacsType, std::string xPath) {

    CPACSOverTreeItem* newChild = new CPACSOverTreeItem(index, uid, cpacsType, xPath);
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

int CPACSOverTreeItem::getCpacsIndex() const {
    return cpacsIndex;
}

std::string CPACSOverTreeItem::getCpacsType() const {
    return cpacsType;
}

std::string CPACSOverTreeItem::getCpacsUid() const {
    return cpacsUid;
}

std::string CPACSOverTreeItem::getXPath() const {
    return xPath;
}

int CPACSOverTreeItem::positionRelativelyToParent() const {

    int position = -1;
    CPACSOverTreeItem* parent = getParent();
    if (parent != nullptr){
        position = parent->children.indexOf(const_cast<CPACSOverTreeItem*> (this));
    }
    return position;
}

std::string CPACSOverTreeItem::getDataName(int i) {
    if(i == 0){
        return "index";
    }else if (i==1){
        return "type";
    }else if (i==2){
        return "UID";
    }else if (i=3){
        return "XPath";
    }else{
        return "invalid";
    }
}

*/

