/********************************************************************************
** Form generated from reading UI file 'TIGLViewerVTKExportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERVTKEXPORTDIALOG_H
#define UI_TIGLVIEWERVTKEXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TIGLViewerVTKExportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *cbWriteNormals;
    QLabel *label;
    QDoubleSpinBox *sbDeflection;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TIGLViewerVTKExportDialog)
    {
        if (TIGLViewerVTKExportDialog->objectName().isEmpty())
            TIGLViewerVTKExportDialog->setObjectName(QStringLiteral("TIGLViewerVTKExportDialog"));
        TIGLViewerVTKExportDialog->resize(216, 142);
        verticalLayout = new QVBoxLayout(TIGLViewerVTKExportDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(TIGLViewerVTKExportDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cbWriteNormals = new QCheckBox(groupBox);
        cbWriteNormals->setObjectName(QStringLiteral("cbWriteNormals"));

        gridLayout->addWidget(cbWriteNormals, 0, 0, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        sbDeflection = new QDoubleSpinBox(groupBox);
        sbDeflection->setObjectName(QStringLiteral("sbDeflection"));
        sbDeflection->setDecimals(4);
        sbDeflection->setMinimum(0.0001);
        sbDeflection->setMaximum(1);
        sbDeflection->setSingleStep(0.001);
        sbDeflection->setValue(0.001);

        gridLayout->addWidget(sbDeflection, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(TIGLViewerVTKExportDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TIGLViewerVTKExportDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TIGLViewerVTKExportDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TIGLViewerVTKExportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TIGLViewerVTKExportDialog);
    } // setupUi

    void retranslateUi(QDialog *TIGLViewerVTKExportDialog)
    {
        TIGLViewerVTKExportDialog->setWindowTitle(QApplication::translate("TIGLViewerVTKExportDialog", "Save VTK", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TIGLViewerVTKExportDialog", "Export options", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbWriteNormals->setToolTip(QApplication::translate("TIGLViewerVTKExportDialog", "Normals can lead to duplicate points, but improve visual quality.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbWriteNormals->setText(QApplication::translate("TIGLViewerVTKExportDialog", "Write normal vectors", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("TIGLViewerVTKExportDialog", "Maximum deviation of a triangle from the true geometry in meter.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("TIGLViewerVTKExportDialog", "Deflection", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TIGLViewerVTKExportDialog: public Ui_TIGLViewerVTKExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERVTKEXPORTDIALOG_H
