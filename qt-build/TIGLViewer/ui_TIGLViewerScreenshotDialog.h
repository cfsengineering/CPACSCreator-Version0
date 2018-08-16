/********************************************************************************
** Form generated from reading UI file 'TIGLViewerScreenshotDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERSCREENSHOTDIALOG_H
#define UI_TIGLVIEWERSCREENSHOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TiglViewerScreenshotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *unitsBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *heightBox;
    QSpinBox *widthBox;
    QSpacerItem *horizontalSpacer;
    QGroupBox *qualityBox;
    QHBoxLayout *horizontalLayout;
    QSlider *qualitySlider;
    QSpinBox *qualityBox_2;
    QCheckBox *whiteBGCheckbox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TiglViewerScreenshotDialog)
    {
        if (TiglViewerScreenshotDialog->objectName().isEmpty())
            TiglViewerScreenshotDialog->setObjectName(QStringLiteral("TiglViewerScreenshotDialog"));
        TiglViewerScreenshotDialog->resize(299, 208);
        verticalLayout = new QVBoxLayout(TiglViewerScreenshotDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(TiglViewerScreenshotDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        unitsBox = new QComboBox(groupBox);
        unitsBox->setObjectName(QStringLiteral("unitsBox"));

        gridLayout->addWidget(unitsBox, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        heightBox = new QSpinBox(groupBox);
        heightBox->setObjectName(QStringLiteral("heightBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(heightBox->sizePolicy().hasHeightForWidth());
        heightBox->setSizePolicy(sizePolicy);
        heightBox->setMinimumSize(QSize(80, 0));
        heightBox->setMinimum(1);
        heightBox->setMaximum(5000);

        gridLayout->addWidget(heightBox, 1, 1, 1, 1);

        widthBox = new QSpinBox(groupBox);
        widthBox->setObjectName(QStringLiteral("widthBox"));
        sizePolicy.setHeightForWidth(widthBox->sizePolicy().hasHeightForWidth());
        widthBox->setSizePolicy(sizePolicy);
        widthBox->setMinimumSize(QSize(80, 0));
        widthBox->setMinimum(1);
        widthBox->setMaximum(5000);

        gridLayout->addWidget(widthBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        qualityBox = new QGroupBox(TiglViewerScreenshotDialog);
        qualityBox->setObjectName(QStringLiteral("qualityBox"));
        qualityBox->setEnabled(true);
        horizontalLayout = new QHBoxLayout(qualityBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qualitySlider = new QSlider(qualityBox);
        qualitySlider->setObjectName(QStringLiteral("qualitySlider"));
        qualitySlider->setMaximum(100);
        qualitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(qualitySlider);

        qualityBox_2 = new QSpinBox(qualityBox);
        qualityBox_2->setObjectName(QStringLiteral("qualityBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qualityBox_2->sizePolicy().hasHeightForWidth());
        qualityBox_2->setSizePolicy(sizePolicy1);
        qualityBox_2->setMinimumSize(QSize(60, 0));
        qualityBox_2->setMaximum(100);

        horizontalLayout->addWidget(qualityBox_2);


        verticalLayout->addWidget(qualityBox);

        whiteBGCheckbox = new QCheckBox(TiglViewerScreenshotDialog);
        whiteBGCheckbox->setObjectName(QStringLiteral("whiteBGCheckbox"));
        whiteBGCheckbox->setChecked(true);

        verticalLayout->addWidget(whiteBGCheckbox);

        buttonBox = new QDialogButtonBox(TiglViewerScreenshotDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(widthBox, heightBox);
        QWidget::setTabOrder(heightBox, unitsBox);
        QWidget::setTabOrder(unitsBox, qualitySlider);
        QWidget::setTabOrder(qualitySlider, qualityBox_2);
        QWidget::setTabOrder(qualityBox_2, buttonBox);

        retranslateUi(TiglViewerScreenshotDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TiglViewerScreenshotDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TiglViewerScreenshotDialog, SLOT(reject()));
        QObject::connect(qualitySlider, SIGNAL(valueChanged(int)), qualityBox_2, SLOT(setValue(int)));
        QObject::connect(qualityBox_2, SIGNAL(valueChanged(int)), qualitySlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(TiglViewerScreenshotDialog);
    } // setupUi

    void retranslateUi(QDialog *TiglViewerScreenshotDialog)
    {
        TiglViewerScreenshotDialog->setWindowTitle(QApplication::translate("TiglViewerScreenshotDialog", "Screenshot Settings", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TiglViewerScreenshotDialog", "Image Size", Q_NULLPTR));
        unitsBox->clear();
        unitsBox->insertItems(0, QStringList()
         << QApplication::translate("TiglViewerScreenshotDialog", "px", Q_NULLPTR)
         << QApplication::translate("TiglViewerScreenshotDialog", "mm", Q_NULLPTR)
         << QApplication::translate("TiglViewerScreenshotDialog", "in", Q_NULLPTR)
        );
        label->setText(QApplication::translate("TiglViewerScreenshotDialog", "Width", Q_NULLPTR));
        label_2->setText(QApplication::translate("TiglViewerScreenshotDialog", "Height", Q_NULLPTR));
        qualityBox->setTitle(QApplication::translate("TiglViewerScreenshotDialog", "Quality", Q_NULLPTR));
        whiteBGCheckbox->setText(QApplication::translate("TiglViewerScreenshotDialog", "White Background", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TiglViewerScreenshotDialog: public Ui_TiglViewerScreenshotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERSCREENSHOTDIALOG_H
