/********************************************************************************
** Form generated from reading UI file 'TIGLSliderDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLSLIDERDIALOG_H
#define UI_TIGLSLIDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_TIGLSliderDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QSlider *slider;

    void setupUi(QDialog *TIGLSliderDialog)
    {
        if (TIGLSliderDialog->objectName().isEmpty())
            TIGLSliderDialog->setObjectName(QStringLiteral("TIGLSliderDialog"));
        TIGLSliderDialog->setWindowModality(Qt::NonModal);
        TIGLSliderDialog->resize(19, 106);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TIGLSliderDialog->sizePolicy().hasHeightForWidth());
        TIGLSliderDialog->setSizePolicy(sizePolicy);
        TIGLSliderDialog->setFocusPolicy(Qt::NoFocus);
        horizontalLayout = new QHBoxLayout(TIGLSliderDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        slider = new QSlider(TIGLSliderDialog);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(slider);


        retranslateUi(TIGLSliderDialog);

        QMetaObject::connectSlotsByName(TIGLSliderDialog);
    } // setupUi

    void retranslateUi(QDialog *TIGLSliderDialog)
    {
        TIGLSliderDialog->setWindowTitle(QApplication::translate("TIGLSliderDialog", "\"\"", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TIGLSliderDialog: public Ui_TIGLSliderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLSLIDERDIALOG_H
