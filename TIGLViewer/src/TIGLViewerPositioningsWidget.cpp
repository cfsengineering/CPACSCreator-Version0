//
// Created by cfse on 7/9/18.
//

#include "TIGLViewerPositioningsWidget.h"
#include "ModificatorManager.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

TIGLViewerPositioningsWidget::TIGLViewerPositioningsWidget(QWidget *parent) : ModificatorWidget(parent) {

}

void TIGLViewerPositioningsWidget::init(ModificatorManager *associate) {
    ModificatorWidget::init(associate);

    precision = 4; // 4 decimal after the
    globalLayout = new QHBoxLayout;

    labelLayout = new QVBoxLayout;
    sweepLayout = new QVBoxLayout;
    dihedralLayout = new QVBoxLayout;
    lengthLayout = new QVBoxLayout;

    header.push_back(new QLabel("Tixi Index"));
    header.push_back(new QLabel("Sweep"));
    header.push_back(new QLabel("Dihedral"));
    header.push_back(new QLabel("Length"));

    labelLayout->addWidget(header[0]);
    sweepLayout->addWidget(header[1]);
    dihedralLayout->addWidget(header[2]);
    lengthLayout->addWidget(header[3]);

    globalLayout->addLayout(labelLayout);
    globalLayout->addLayout(sweepLayout);
    globalLayout->addLayout(dihedralLayout);
    globalLayout->addLayout(lengthLayout);

    this->setLayout(globalLayout);




}

void TIGLViewerPositioningsWidget::apply() {

    int numberOfChange = 0;
    int i = 0;
    bool hasChanged;
    for (std::pair<cpcr::CPACSTreeItem *, cpcr::CPACSPositioning> p: internals) {

        hasChanged = ( ! isApprox( p.second.getLength(), lengths[i]->value() ) )
                        || ( ! isApprox(p.second.getDihedralAngle(), dihedrals[i]->value() ))
                        || ( ! isApprox(p.second.getSweepAngle(), sweeps[i]->value() ));

        if(hasChanged){
            p.second.setDihedralAngle(dihedrals[i]->value() ); // set internals from boxes
            p.second.setSweepAngle(sweeps[i]->value() ); // set internals from boxes
            p.second.setLength(lengths[i]->value() ); // set internals from boxes
            associateManager->adapter->setPositioning(p.first, p.second ); // set in CPACS
            numberOfChange ++;
        }

        i++; // we parse in the same order than we have created
    }

    if(numberOfChange > 0){
        associateManager->adapter->writeToFile();
    }

}



void TIGLViewerPositioningsWidget::setPositionings(cpcr::CPACSTreeItem *item) {

    clean();

    this->internals = associateManager->adapter->getPositionings(item);

    int count = 1;
    for(std::pair<cpcr::CPACSTreeItem*,cpcr::CPACSPositioning> p: internals){

        QDoubleSpinBox *tempSweep = new QDoubleSpinBox;
        tempSweep->setRange(-360, 360);
        tempSweep->setDecimals(precision);
        tempSweep->setValue(p.second.getSweepAngle());
        sweeps.push_back(tempSweep);

        QDoubleSpinBox *tempDihedral = new QDoubleSpinBox;
        tempDihedral->setRange(-360, 360);
        tempSweep->setDecimals(precision);
        tempDihedral->setValue(p.second.getDihedralAngle());
        dihedrals.push_back(tempDihedral);

        QDoubleSpinBox *tempLength = new QDoubleSpinBox;
        tempLength->setRange(-1000, 1000);
        tempSweep->setDecimals(precision);
        tempLength->setValue(p.second.getLength());
        lengths.push_back(tempLength);

        QLabel *tempLabel = new QLabel;
        tempLabel->setText( std::to_string(p.first->getTixiIndex()).c_str()  );
        labels.push_back(tempLabel);
        count++;
    }



    setDisplay();
}


void TIGLViewerPositioningsWidget::clean() {

    for(int i = 0; i < sweeps.size(); i++){

        sweepLayout->removeWidget(sweeps[i]);
        delete sweeps[i];

        dihedralLayout->removeWidget(dihedrals[i]);
        delete  dihedrals[i];

        lengthLayout->removeWidget(lengths[i]);
        delete lengths[i];

        labelLayout->removeWidget(labels[i]);
        delete labels[i];
    }

    sweeps.clear();
    dihedrals.clear();
    lengths.clear();
    labels.clear();

    internals.clear();
}



void TIGLViewerPositioningsWidget::setDisplay() {


    for(int i = 0; i < sweeps.size(); i++){
        labelLayout->addWidget(labels[i]);
        sweepLayout->addWidget(sweeps[i]);
        dihedralLayout->addWidget(dihedrals[i]);
        lengthLayout->addWidget(lengths[i]);
    }

}
