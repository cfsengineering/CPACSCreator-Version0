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
// Created by cfse on 7/9/18.
//

#ifndef TIGL_TIGLVIEWERPOSITIONINGSWIDGET_H
#define TIGL_TIGLVIEWERPOSITIONINGSWIDGET_H

#include <CPACSCreatorLib/CPACSTreeItem.h>
#include "ModificatorWidget.h"
#include <CPACSCreatorLib/CPACSPositioning.h>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class TIGLViewerPositioningsWidget : public ModificatorWidget {

    Q_OBJECT


public:

    TIGLViewerPositioningsWidget(QWidget * parent = 0);

    void init(ModificatorManager * associate ) override ;
    void apply() override ;

    void setPositionings(cpcr::CPACSTreeItem* positionings);

protected:
    void setDisplay();
    void clean();


private:

    std::list<std::pair<cpcr::CPACSTreeItem*, cpcr::CPACSPositioning >> internals;
    std::vector<QDoubleSpinBox*> sweeps;
    std::vector<QDoubleSpinBox*> dihedrals;
    std::vector<QDoubleSpinBox*> lengths;
    std::vector<QLabel*> labels;

    std::vector<QLabel*> header;


    QHBoxLayout *globalLayout ;
    QVBoxLayout *sweepLayout ;
    QVBoxLayout *dihedralLayout ;
    QVBoxLayout *lengthLayout ;
    QVBoxLayout *labelLayout ;

    int precision; // set the precision of the qdoublespinbox and is use to detect false change


};


#endif //TIGL_TIGLVIEWERPOSITIONINGSWIDGET_H
