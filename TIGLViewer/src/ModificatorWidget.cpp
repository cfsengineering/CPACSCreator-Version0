//
// Created by makem on 30/05/18.
//

#include "ModificatorWidget.h"
#include "CPACSCreatorLib/easylogging++.h"


ModificatorWidget::ModificatorWidget(QWidget *parent): QWidget(parent) {

}


void ModificatorWidget::init(ModificatorManager *associate) {
    this->associateManager = associate;
    precision = 4;
}

void ModificatorWidget::apply() {
  DLOG(WARNING) << "ModificatorWidget: apply function should be overwrite in children classes";
}


bool ModificatorWidget::isApprox(double a, double b) {
    // so if the spin box is set with precision "precision", only the real change are detected and not the rounding
    double delta = pow(10, -precision) / 2.0 ;
    return ( fabs( a - b ) <= delta );
}