//
// Created by cfse on 3/21/18.
//

#include "TIGLViewerTransformationWidget.h"
#include <iostream>

TIGLViewerTransformationWidget::TIGLViewerTransformationWidget(QWidget *parent):
    QWidget(parent)
{}


void TIGLViewerTransformationWidget::init()
{
    boxSX = this->findChild<QDoubleSpinBox*>("spinBoxSX");
    boxSY = this->findChild<QDoubleSpinBox*>("spinBoxSY");
    boxSZ = this->findChild<QDoubleSpinBox*>("spinBoxSZ");

    boxRX = this->findChild<QDoubleSpinBox*>("spinBoxRX");
    boxRY = this->findChild<QDoubleSpinBox*>("spinBoxRY");
    boxRZ = this->findChild<QDoubleSpinBox*>("spinBoxRZ");

    boxTX = this->findChild<QDoubleSpinBox*>("spinBoxTX");
    boxTY = this->findChild<QDoubleSpinBox*>("spinBoxTY");
    boxTZ = this->findChild<QDoubleSpinBox*>("spinBoxTZ");

    setSpinBoxesFromInternal();
    this->hide();
}

void TIGLViewerTransformationWidget::setSpinBoxesFromInternal()
{
    boxSX->setValue(sx);
    boxSY->setValue(sy);
    boxSZ->setValue(sz);

    boxRX->setValue(rx);
    boxRY->setValue(ry);
    boxRZ->setValue(rz);

    boxTX->setValue(tx);
    boxTY->setValue(ty);
    boxTZ->setValue(tz);

}


void TIGLViewerTransformationWidget::setInternalFromSpinBoxes()
{
    sx = boxSX->value();
    sy = boxSY->value();
    sz = boxSZ->value();

    rx = boxRX->value();
    ry = boxRY->value();
    rz = boxRZ->value();

    tx = boxTX->value();
    ty = boxTY->value();
    tz = boxTZ->value();

}


void TIGLViewerTransformationWidget::setValues(QString xpath,
                                               double sx, double sy, double sz,
                                               double rx, double ry, double rz,
                                               double tx, double ty, double tz)  {
    this->xpath = xpath;

    this->sx = sx;
    this->sy = sy;
    this->sz = sz;

    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    this->tx = tx;
    this->ty = ty;
    this->tz = tz;

    setSpinBoxesFromInternal();

    this->setVisible(true);
}




void TIGLViewerTransformationWidget::keyPressEvent(QKeyEvent *event)
{
    std::cout << "event->key(): "  << std::endl;


    setInternalFromSpinBoxes();

    emit valuesChanged(xpath, sx,sy,sz, rx,ry,rz, tx,ty,tz );
}