//
// Created by cfse on 11/5/18.
//

#ifndef TIGL_CPACSTREEVIEW_H
#define TIGL_CPACSTREEVIEW_H


#include "CPACSAbstractModel.h"
#include <QTreeView>
#include "CPACSCreatorAdapter.h"
#include <QObject>


class CPACSTreeView: public QObject {

Q_OBJECT


signals:

    void newSelectedTreeItem(cpcr::CPACSTreeItem *);


private slots:

    void onSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);



public:

    CPACSTreeView(QTreeView* view,  CPACSCreatorAdapter* adapter);

    void disconnectAdapter();
    void connectAdapter(CPACSCreatorAdapter *adapter);

private:

    CPACSAbstractModel* model;
    QTreeView * treeView;
    QItemSelectionModel* selectionModel;

    std::string backupSelectedUID;



};


#endif //TIGL_CPACSTREEVIEW_H
