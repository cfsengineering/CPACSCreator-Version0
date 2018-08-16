/********************************************************************************
** Form generated from reading UI file 'TIGLViewerDrawVectorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERDRAWVECTORDIALOG_H
#define UI_TIGLVIEWERDRAWVECTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TIGLViewerDrawVectorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupPoint;
    QGridLayout *gridLayout;
    QDoubleSpinBox *pxSB;
    QLabel *label_5;
    QDoubleSpinBox *pySB;
    QLabel *label_4;
    QDoubleSpinBox *pzSB;
    QLabel *label_6;
    QGroupBox *groupDirection;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QDoubleSpinBox *nxSB;
    QLabel *label_13;
    QDoubleSpinBox *nySB;
    QLabel *label_12;
    QDoubleSpinBox *nzSB;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TIGLViewerDrawVectorDialog)
    {
        if (TIGLViewerDrawVectorDialog->objectName().isEmpty())
            TIGLViewerDrawVectorDialog->setObjectName(QStringLiteral("TIGLViewerDrawVectorDialog"));
        TIGLViewerDrawVectorDialog->resize(302, 174);
        verticalLayout = new QVBoxLayout(TIGLViewerDrawVectorDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupPoint = new QGroupBox(TIGLViewerDrawVectorDialog);
        groupPoint->setObjectName(QStringLiteral("groupPoint"));
        gridLayout = new QGridLayout(groupPoint);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pxSB = new QDoubleSpinBox(groupPoint);
        pxSB->setObjectName(QStringLiteral("pxSB"));
        pxSB->setDecimals(7);
        pxSB->setMinimum(-99);

        gridLayout->addWidget(pxSB, 0, 1, 1, 1);

        label_5 = new QLabel(groupPoint);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        pySB = new QDoubleSpinBox(groupPoint);
        pySB->setObjectName(QStringLiteral("pySB"));
        pySB->setDecimals(7);
        pySB->setMinimum(-99);

        gridLayout->addWidget(pySB, 1, 1, 1, 1);

        label_4 = new QLabel(groupPoint);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        pzSB = new QDoubleSpinBox(groupPoint);
        pzSB->setObjectName(QStringLiteral("pzSB"));
        pzSB->setDecimals(7);
        pzSB->setMinimum(-99);

        gridLayout->addWidget(pzSB, 2, 1, 1, 1);

        label_6 = new QLabel(groupPoint);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);


        horizontalLayout->addWidget(groupPoint);

        groupDirection = new QGroupBox(TIGLViewerDrawVectorDialog);
        groupDirection->setObjectName(QStringLiteral("groupDirection"));
        groupDirection->setEnabled(true);
        groupDirection->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupDirection);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_11 = new QLabel(groupDirection);
        label_11->setObjectName(QStringLiteral("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        nxSB = new QDoubleSpinBox(groupDirection);
        nxSB->setObjectName(QStringLiteral("nxSB"));
        nxSB->setDecimals(7);
        nxSB->setMinimum(-10);
        nxSB->setMaximum(10);
        nxSB->setSingleStep(0.05);

        gridLayout_2->addWidget(nxSB, 0, 1, 1, 1);

        label_13 = new QLabel(groupDirection);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        nySB = new QDoubleSpinBox(groupDirection);
        nySB->setObjectName(QStringLiteral("nySB"));
        nySB->setDecimals(7);
        nySB->setMinimum(-10);
        nySB->setMaximum(10);
        nySB->setSingleStep(0.05);

        gridLayout_2->addWidget(nySB, 1, 1, 1, 1);

        label_12 = new QLabel(groupDirection);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        nzSB = new QDoubleSpinBox(groupDirection);
        nzSB->setObjectName(QStringLiteral("nzSB"));
        nzSB->setDecimals(7);
        nzSB->setMinimum(-10);
        nzSB->setMaximum(10);
        nzSB->setSingleStep(0.05);
        nzSB->setValue(1);

        gridLayout_2->addWidget(nzSB, 2, 1, 1, 1);


        horizontalLayout->addWidget(groupDirection);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(TIGLViewerDrawVectorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TIGLViewerDrawVectorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TIGLViewerDrawVectorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TIGLViewerDrawVectorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TIGLViewerDrawVectorDialog);
    } // setupUi

    void retranslateUi(QDialog *TIGLViewerDrawVectorDialog)
    {
        TIGLViewerDrawVectorDialog->setWindowTitle(QApplication::translate("TIGLViewerDrawVectorDialog", "Dialog", Q_NULLPTR));
        groupPoint->setTitle(QApplication::translate("TIGLViewerDrawVectorDialog", "Point", Q_NULLPTR));
        label_5->setText(QApplication::translate("TIGLViewerDrawVectorDialog", "Y=", Q_NULLPTR));
        label_4->setText(QApplication::translate("TIGLViewerDrawVectorDialog", "X=", Q_NULLPTR));
        label_6->setText(QApplication::translate("TIGLViewerDrawVectorDialog", "Z=", Q_NULLPTR));
        groupDirection->setTitle(QApplication::translate("TIGLViewerDrawVectorDialog", "Direction", Q_NULLPTR));
        label_11->setText(QApplication::translate("TIGLViewerDrawVectorDialog", "X=", Q_NULLPTR));
        label_13->setText(QApplication::translate("TIGLViewerDrawVectorDialog", "Z=", Q_NULLPTR));
        label_12->setText(QApplication::translate("TIGLViewerDrawVectorDialog", "Y=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TIGLViewerDrawVectorDialog: public Ui_TIGLViewerDrawVectorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERDRAWVECTORDIALOG_H
