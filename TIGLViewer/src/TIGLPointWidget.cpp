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

