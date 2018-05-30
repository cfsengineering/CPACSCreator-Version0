//
// Created by makem on 30/05/18.
//

#include "ModificatorWidget.h"
#include "CPACSCreatorLib/easylogging++.h"


ModificatorWidget::ModificatorWidget(QWidget *parent): QWidget(parent) {

}


void ModificatorWidget::init(ModificatorManager *associate) {
    this->associateManager = associate;
}

void ModificatorWidget::apply() {
  DLOG(WARNING) << " FDSFSDAFAS";
}
