/********************************************************************************
** Form generated from reading UI file 'TIGLViewerFuseDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERFUSEDIALOG_H
#define UI_TIGLVIEWERFUSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FuseDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *mirrorCheckBox;
    QCheckBox *trimFFCheckBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FuseDialog)
    {
        if (FuseDialog->objectName().isEmpty())
            FuseDialog->setObjectName(QStringLiteral("FuseDialog"));
        FuseDialog->resize(370, 155);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FuseDialog->sizePolicy().hasHeightForWidth());
        FuseDialog->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(FuseDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(FuseDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        mirrorCheckBox = new QCheckBox(groupBox);
        mirrorCheckBox->setObjectName(QStringLiteral("mirrorCheckBox"));
        mirrorCheckBox->setChecked(true);
        mirrorCheckBox->setTristate(false);

        verticalLayout->addWidget(mirrorCheckBox);

        trimFFCheckBox = new QCheckBox(groupBox);
        trimFFCheckBox->setObjectName(QStringLiteral("trimFFCheckBox"));

        verticalLayout->addWidget(trimFFCheckBox);


        verticalLayout_2->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(FuseDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(FuseDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FuseDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FuseDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FuseDialog);
    } // setupUi

    void retranslateUi(QDialog *FuseDialog)
    {
        FuseDialog->setWindowTitle(QApplication::translate("FuseDialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FuseDialog", "Fusing and trimming options", Q_NULLPTR));
        label->setText(QApplication::translate("FuseDialog", "With these options, you can alter the resulting aircraft shape.", Q_NULLPTR));
        mirrorCheckBox->setText(QApplication::translate("FuseDialog", "Mirror components at their symmetry plane.", Q_NULLPTR));
        trimFFCheckBox->setText(QApplication::translate("FuseDialog", "Trim aircraft with far field (if available)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FuseDialog: public Ui_FuseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERFUSEDIALOG_H
