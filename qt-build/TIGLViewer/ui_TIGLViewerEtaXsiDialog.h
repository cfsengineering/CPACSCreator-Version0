/********************************************************************************
** Form generated from reading UI file 'TIGLViewerEtaXsiDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERETAXSIDIALOG_H
#define UI_TIGLVIEWERETAXSIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EtaXsiDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *etaSpinBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *xsiSpinBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QPushButton *closeButton;

    void setupUi(QDialog *EtaXsiDialog)
    {
        if (EtaXsiDialog->objectName().isEmpty())
            EtaXsiDialog->setObjectName(QStringLiteral("EtaXsiDialog"));
        EtaXsiDialog->setWindowModality(Qt::ApplicationModal);
        EtaXsiDialog->resize(174, 96);
        EtaXsiDialog->setModal(false);
        verticalLayout = new QVBoxLayout(EtaXsiDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(EtaXsiDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        etaSpinBox = new QDoubleSpinBox(EtaXsiDialog);
        etaSpinBox->setObjectName(QStringLiteral("etaSpinBox"));
        etaSpinBox->setMinimumSize(QSize(70, 0));
        etaSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        etaSpinBox->setDecimals(6);
        etaSpinBox->setMaximum(1);
        etaSpinBox->setSingleStep(0.05);
        etaSpinBox->setValue(0.5);

        gridLayout->addWidget(etaSpinBox, 0, 2, 1, 1);

        label_2 = new QLabel(EtaXsiDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        xsiSpinBox = new QDoubleSpinBox(EtaXsiDialog);
        xsiSpinBox->setObjectName(QStringLiteral("xsiSpinBox"));
        xsiSpinBox->setMinimumSize(QSize(70, 0));
        xsiSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        xsiSpinBox->setDecimals(6);
        xsiSpinBox->setMaximum(1);
        xsiSpinBox->setSingleStep(0.01);
        xsiSpinBox->setValue(0.5);

        gridLayout->addWidget(xsiSpinBox, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        insertButton = new QPushButton(EtaXsiDialog);
        insertButton->setObjectName(QStringLiteral("insertButton"));

        horizontalLayout->addWidget(insertButton);

        closeButton = new QPushButton(EtaXsiDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EtaXsiDialog);
        QObject::connect(closeButton, SIGNAL(pressed()), EtaXsiDialog, SLOT(reject()));
        QObject::connect(insertButton, SIGNAL(pressed()), EtaXsiDialog, SLOT(accept()));

        insertButton->setDefault(true);


        QMetaObject::connectSlotsByName(EtaXsiDialog);
    } // setupUi

    void retranslateUi(QDialog *EtaXsiDialog)
    {
        EtaXsiDialog->setWindowTitle(QApplication::translate("EtaXsiDialog", "Enter Coordinates", Q_NULLPTR));
        label->setText(QApplication::translate("EtaXsiDialog", "Eta", Q_NULLPTR));
        label_2->setText(QApplication::translate("EtaXsiDialog", "Xsi", Q_NULLPTR));
        insertButton->setText(QApplication::translate("EtaXsiDialog", "Insert", Q_NULLPTR));
        closeButton->setText(QApplication::translate("EtaXsiDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EtaXsiDialog: public Ui_EtaXsiDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERETAXSIDIALOG_H
