//
// Created by cfse on 11/5/18.
//

#include "CPACSTreeView.h"
#include "CPACSTreeItem.h"

CPACSTreeView::CPACSTreeView(QTreeView* view, CPACSCreatorAdapter* adapter) {

    treeView = view;
    model =  new CPACSAbstractModel(adapter);
    treeView->setModel(model);
    selectionModel = treeView->selectionModel();
    backupSelectedUID = "";

    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this,
                   SLOT(onSelectionChanged( const QItemSelection&, const QItemSelection&)));


}

void CPACSTreeView::onSelectionChanged(const QItemSelection & newSelection, const QItemSelection & oldSelection) {

    if (model->isValid() ){
        cpcr::CPACSTreeItem* newSelectedItem = model->getItemFromSelection(newSelection);
        emit newSelectedTreeItem(newSelectedItem);
    }else{
        LOG(WARNING) <<  "CPACSTreeView: onSelectionChanged called but no valid model is set" << std::endl;
    }
}

void CPACSTreeView::disconnectAdapter() {
    backupSelectedUID = model->getUidForIdx(selectionModel->currentIndex());
    model->disconnectAdapter();

}

void CPACSTreeView::connectAdapter(CPACSCreatorAdapter *adapter) {
    model->resetAdapter(adapter);
    treeView->hideColumn(3);
    QModelIndex idx = model->getIdxForUID(backupSelectedUID);
    selectionModel->setCurrentIndex(idx, QItemSelectionModel::Select); // can emit a onSelection changed
}
