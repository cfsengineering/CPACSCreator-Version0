//
// Created by cfse on 9/26/18.
//

#include "TIGLIViewerFuselageWidget.h"

void TIGLViewerFuselageWidget::init(ModificatorManager * associate ) {
    ModificatorWidget::init(associate);

    // Retrieve component of the anchor interface
    spinBoxLength = this->findChild<QDoubleSpinBox*>("spinBoxLength");


}