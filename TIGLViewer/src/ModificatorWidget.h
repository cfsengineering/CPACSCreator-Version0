//
// Created by makem on 30/05/18.
//

#ifndef TIGL_MODIFICATORWIDGET_H
#define TIGL_MODIFICATORWIDGET_H


#include <QWidget>



class ModificatorManager; // forward delcaration


class ModificatorWidget: public QWidget {

    Q_OBJECT

public:

    ModificatorWidget(QWidget * parent = 0);

    virtual void init(ModificatorManager * associate);

    virtual void apply();


protected:

    // return true if the abs(a-b) < precision
    double precision;
    bool isApprox(double a, double b);

    ModificatorManager * associateManager;
};


#endif //TIGL_MODIFICATORWIDGET_H
