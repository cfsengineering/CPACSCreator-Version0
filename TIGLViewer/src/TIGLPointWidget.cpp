#include "TIGLPointWidget.h"
#include <iostream>


TIGLPointWidget::TIGLPointWidget(QWidget *parent)
    :QWidget(parent)
{
    tiglPoint = tigl::CTiglPoint(1,3.4,8);
}



void TIGLPointWidget::keyPressEvent(QKeyEvent *event)
{
    std::cout << "event->key(): " << event->key() << std::endl;
    setTiglePointFromSpinBoxes();
    emit valueChanged(tiglPoint);
}


void TIGLPointWidget::init()
{
    boxX = this->findChild<QDoubleSpinBox*>("doubleSpinBoxX");
    boxY = this->findChild<QDoubleSpinBox*>("doubleSpinBoxY");
    boxZ = this->findChild<QDoubleSpinBox*>("doubleSpinBoxZ");

    setSpinBoxesFromTiglePoint();
}

void TIGLPointWidget::setSpinBoxesFromTiglePoint()
{
    boxX->setValue(tiglPoint.x);
    boxY->setValue(tiglPoint.y);
    boxZ->setValue(tiglPoint.z);
}

void TIGLPointWidget::setTiglePointFromSpinBoxes()
{
    tiglPoint.x = boxX->value();
    tiglPoint.y = boxY->value();
    tiglPoint.z = boxZ->value();
}

