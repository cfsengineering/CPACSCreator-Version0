//
// Created by cfse on 3/21/18.
//

#ifndef TIGL_TIGLVIEWERTRANSFORMATIONWIDGET_H
#define TIGL_TIGLVIEWERTRANSFORMATIONWIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>

class TIGLViewerTransformationWidget : public QWidget
{
    Q_OBJECT

signals:
   void valuesChanged();

public slots:
    void setSpinBoxes(double sx, double sy, double  sz,
                    double rx, double ry, double  rz,
                    double tx, double ty, double  tz);


public:
    TIGLViewerTransformationWidget(QWidget * parent = 0);
    // Initialize the linked objects
    void init();
    void setSpinBoxesFromInternal();


private:

    QDoubleSpinBox* boxSX;
    QDoubleSpinBox* boxSY;
    QDoubleSpinBox* boxSZ;

    QDoubleSpinBox* boxRX;
    QDoubleSpinBox* boxRY;
    QDoubleSpinBox* boxRZ;

    QDoubleSpinBox* boxTX;
    QDoubleSpinBox* boxTY;
    QDoubleSpinBox* boxTZ;

    double sx, sy, sz, rx, ry, rz, tx, ty, tz;


};



#endif //TIGL_TIGLVIEWERTRANSFORMATIONWIDGET_H
