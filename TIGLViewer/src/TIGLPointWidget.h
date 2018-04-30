//
// Created by cfse on 3/12/18.
//

#ifndef TIGL_TIGLPOINTWIDGET_H
#define TIGL_TIGLPOINTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QtGui>

#include "CTiglPoint.h"


class TIGLPointWidget: public QWidget
{
    Q_OBJECT


signals:
    void valueChanged(tigl::CTiglPoint tiglPoint);


public:
    TIGLPointWidget(QWidget * parent = 0);
    // Initialize the linked objects
    void init();
    void setSpinBoxesFromTiglePoint();
    void setTiglePointFromSpinBoxes();



protected:

    void keyPressEvent(QKeyEvent *event);




private:

    QDoubleSpinBox* boxX;
    QDoubleSpinBox* boxY;
    QDoubleSpinBox* boxZ;

    tigl::CTiglPoint tiglPoint;


};

#endif //TIGL_TIGLPOINTWIDGET_H
