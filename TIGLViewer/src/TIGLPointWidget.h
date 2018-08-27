/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
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
