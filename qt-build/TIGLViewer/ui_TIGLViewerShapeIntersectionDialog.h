/********************************************************************************
** Form generated from reading UI file 'TIGLViewerShapeIntersectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERSHAPEINTERSECTIONDIALOG_H
#define UI_TIGLVIEWERSHAPEINTERSECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TIGLViewerShapeIntersectionDialog
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *TabView;
    QWidget *tabSS;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QComboBox *shape1Combo;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QComboBox *shape2Combo;
    QSpacerItem *verticalSpacer;
    QWidget *tabSP;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *shapeCombo;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_4;
    QDoubleSpinBox *pxSB;
    QDoubleSpinBox *nxSB;
    QLabel *label_5;
    QDoubleSpinBox *pySB;
    QDoubleSpinBox *nySB;
    QLabel *label_6;
    QDoubleSpinBox *pzSB;
    QDoubleSpinBox *nzSB;
    QWidget *tabSPS;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_8;
    QComboBox *shapeComboS;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *p2xSB;
    QDoubleSpinBox *p1xSB;
    QDoubleSpinBox *wxSB;
    QDoubleSpinBox *p1ySB;
    QDoubleSpinBox *p2ySB;
    QLabel *label_10;
    QDoubleSpinBox *wySB;
    QLabel *label_9;
    QDoubleSpinBox *p1zSB;
    QDoubleSpinBox *p2zSB;
    QDoubleSpinBox *wzSB;
    QLabel *label_11;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TIGLViewerShapeIntersectionDialog)
    {
        if (TIGLViewerShapeIntersectionDialog->objectName().isEmpty())
            TIGLViewerShapeIntersectionDialog->setObjectName(QStringLiteral("TIGLViewerShapeIntersectionDialog"));
        TIGLViewerShapeIntersectionDialog->resize(380, 346);
        gridLayout_2 = new QGridLayout(TIGLViewerShapeIntersectionDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        TabView = new QTabWidget(TIGLViewerShapeIntersectionDialog);
        TabView->setObjectName(QStringLiteral("TabView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TabView->sizePolicy().hasHeightForWidth());
        TabView->setSizePolicy(sizePolicy);
        tabSS = new QWidget();
        tabSS->setObjectName(QStringLiteral("tabSS"));
        verticalLayout_4 = new QVBoxLayout(tabSS);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_3 = new QGroupBox(tabSS);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        shape1Combo = new QComboBox(groupBox_3);
        shape1Combo->setObjectName(QStringLiteral("shape1Combo"));

        verticalLayout_5->addWidget(shape1Combo);


        verticalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(tabSS);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        shape2Combo = new QComboBox(groupBox_4);
        shape2Combo->setObjectName(QStringLiteral("shape2Combo"));

        verticalLayout_6->addWidget(shape2Combo);


        verticalLayout_4->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        TabView->addTab(tabSS, QString());
        tabSP = new QWidget();
        tabSP->setObjectName(QStringLiteral("tabSP"));
        verticalLayout_3 = new QVBoxLayout(tabSP);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(tabSP);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        shapeCombo = new QComboBox(groupBox_2);
        shapeCombo->setObjectName(QStringLiteral("shapeCombo"));

        verticalLayout_2->addWidget(shapeCombo);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(tabSP);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        pxSB = new QDoubleSpinBox(groupBox);
        pxSB->setObjectName(QStringLiteral("pxSB"));
        pxSB->setMinimum(-99);

        gridLayout->addWidget(pxSB, 1, 1, 1, 1);

        nxSB = new QDoubleSpinBox(groupBox);
        nxSB->setObjectName(QStringLiteral("nxSB"));
        nxSB->setMinimum(-99);

        gridLayout->addWidget(nxSB, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        pySB = new QDoubleSpinBox(groupBox);
        pySB->setObjectName(QStringLiteral("pySB"));
        pySB->setMinimum(-99);

        gridLayout->addWidget(pySB, 2, 1, 1, 1);

        nySB = new QDoubleSpinBox(groupBox);
        nySB->setObjectName(QStringLiteral("nySB"));
        nySB->setMinimum(-99);

        gridLayout->addWidget(nySB, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        pzSB = new QDoubleSpinBox(groupBox);
        pzSB->setObjectName(QStringLiteral("pzSB"));
        pzSB->setMinimum(-99);

        gridLayout->addWidget(pzSB, 3, 1, 1, 1);

        nzSB = new QDoubleSpinBox(groupBox);
        nzSB->setObjectName(QStringLiteral("nzSB"));
        nzSB->setMinimum(-99);

        gridLayout->addWidget(nzSB, 3, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        TabView->addTab(tabSP, QString());
        tabSPS = new QWidget();
        tabSPS->setObjectName(QStringLiteral("tabSPS"));
        verticalLayout_7 = new QVBoxLayout(tabSPS);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_5 = new QGroupBox(tabSPS);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_8 = new QVBoxLayout(groupBox_5);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        shapeComboS = new QComboBox(groupBox_5);
        shapeComboS->setObjectName(QStringLiteral("shapeComboS"));

        verticalLayout_8->addWidget(shapeComboS);


        verticalLayout_7->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(tabSPS);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 4, 1, 1);

        label = new QLabel(groupBox_6);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        p2xSB = new QDoubleSpinBox(groupBox_6);
        p2xSB->setObjectName(QStringLiteral("p2xSB"));
        p2xSB->setMinimum(-99.99);

        gridLayout_3->addWidget(p2xSB, 1, 3, 1, 1);

        p1xSB = new QDoubleSpinBox(groupBox_6);
        p1xSB->setObjectName(QStringLiteral("p1xSB"));
        p1xSB->setMinimum(-99.99);

        gridLayout_3->addWidget(p1xSB, 1, 1, 1, 1);

        wxSB = new QDoubleSpinBox(groupBox_6);
        wxSB->setObjectName(QStringLiteral("wxSB"));
        wxSB->setMinimum(-99.99);

        gridLayout_3->addWidget(wxSB, 1, 4, 1, 1);

        p1ySB = new QDoubleSpinBox(groupBox_6);
        p1ySB->setObjectName(QStringLiteral("p1ySB"));
        p1ySB->setMinimum(-99.99);

        gridLayout_3->addWidget(p1ySB, 2, 1, 1, 1);

        p2ySB = new QDoubleSpinBox(groupBox_6);
        p2ySB->setObjectName(QStringLiteral("p2ySB"));
        p2ySB->setMinimum(-99.99);

        gridLayout_3->addWidget(p2ySB, 2, 3, 1, 1);

        label_10 = new QLabel(groupBox_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        wySB = new QDoubleSpinBox(groupBox_6);
        wySB->setObjectName(QStringLiteral("wySB"));
        wySB->setMinimum(-99.99);

        gridLayout_3->addWidget(wySB, 2, 4, 1, 1);

        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        p1zSB = new QDoubleSpinBox(groupBox_6);
        p1zSB->setObjectName(QStringLiteral("p1zSB"));
        p1zSB->setMinimum(-99.99);

        gridLayout_3->addWidget(p1zSB, 3, 1, 1, 1);

        p2zSB = new QDoubleSpinBox(groupBox_6);
        p2zSB->setObjectName(QStringLiteral("p2zSB"));
        p2zSB->setMinimum(-99.99);

        gridLayout_3->addWidget(p2zSB, 3, 3, 1, 1);

        wzSB = new QDoubleSpinBox(groupBox_6);
        wzSB->setObjectName(QStringLiteral("wzSB"));
        wzSB->setMinimum(-99.99);

        gridLayout_3->addWidget(wzSB, 3, 4, 1, 1);

        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_11, 3, 0, 1, 1);


        verticalLayout_7->addWidget(groupBox_6);

        TabView->addTab(tabSPS, QString());

        gridLayout_2->addWidget(TabView, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TIGLViewerShapeIntersectionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        QWidget::setTabOrder(TabView, shapeComboS);
        QWidget::setTabOrder(shapeComboS, p1xSB);
        QWidget::setTabOrder(p1xSB, p1ySB);
        QWidget::setTabOrder(p1ySB, p1zSB);
        QWidget::setTabOrder(p1zSB, p2xSB);
        QWidget::setTabOrder(p2xSB, p2ySB);
        QWidget::setTabOrder(p2ySB, p2zSB);
        QWidget::setTabOrder(p2zSB, wxSB);
        QWidget::setTabOrder(wxSB, wySB);
        QWidget::setTabOrder(wySB, wzSB);
        QWidget::setTabOrder(wzSB, nzSB);
        QWidget::setTabOrder(nzSB, shapeCombo);
        QWidget::setTabOrder(shapeCombo, shape2Combo);
        QWidget::setTabOrder(shape2Combo, shape1Combo);
        QWidget::setTabOrder(shape1Combo, pxSB);
        QWidget::setTabOrder(pxSB, pySB);
        QWidget::setTabOrder(pySB, pzSB);
        QWidget::setTabOrder(pzSB, nxSB);
        QWidget::setTabOrder(nxSB, nySB);

        retranslateUi(TIGLViewerShapeIntersectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TIGLViewerShapeIntersectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TIGLViewerShapeIntersectionDialog, SLOT(reject()));

        TabView->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TIGLViewerShapeIntersectionDialog);
    } // setupUi

    void retranslateUi(QDialog *TIGLViewerShapeIntersectionDialog)
    {
        TIGLViewerShapeIntersectionDialog->setWindowTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Define intersection", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape1", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape2", Q_NULLPTR));
        TabView->setTabText(TabView->indexOf(tabSS), QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape/Shape", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Plane", Q_NULLPTR));
        label_7->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Point", Q_NULLPTR));
        label_8->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Normal", Q_NULLPTR));
        label_4->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "X=", Q_NULLPTR));
        label_5->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Y=", Q_NULLPTR));
        label_6->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Z=", Q_NULLPTR));
        TabView->setTabText(TabView->indexOf(tabSP), QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape/Plane", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Two Points and Direction", Q_NULLPTR));
        label_3->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Direction", Q_NULLPTR));
        label->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Point 2", Q_NULLPTR));
        label_2->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Point 1", Q_NULLPTR));
        label_10->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Y =", Q_NULLPTR));
        label_9->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "X =", Q_NULLPTR));
        label_11->setText(QApplication::translate("TIGLViewerShapeIntersectionDialog", "Z = ", Q_NULLPTR));
        TabView->setTabText(TabView->indexOf(tabSPS), QApplication::translate("TIGLViewerShapeIntersectionDialog", "Shape/Plane segment", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TIGLViewerShapeIntersectionDialog: public Ui_TIGLViewerShapeIntersectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERSHAPEINTERSECTIONDIALOG_H
