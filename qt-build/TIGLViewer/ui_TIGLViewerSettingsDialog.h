/********************************************************************************
** Form generated from reading UI file 'TIGLViewerSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERSETTINGSDIALOG_H
#define UI_TIGLVIEWERSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TIGLViewerSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QStackedWidget *stackedWidget;
    QWidget *pageDisplaySettings;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QSlider *sliderTesselationAccuracy;
    QLabel *label_4;
    QLineEdit *tessAccuEdit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_6;
    QSlider *sliderTriangulationAccuracy;
    QLabel *label_7;
    QLineEdit *trianAccuEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QPushButton *buttonColorChoser;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *enumerateFaceCB;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_12;
    QCheckBox *debugBopCB;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_21;
    QLabel *label_12;
    QSpinBox *numUIsoLinesSB;
    QLabel *label_13;
    QSpinBox *numVIsoLinesSB;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_11;
    QPushButton *btnRestoreDefaults;
    QListWidget *settingsList;

    void setupUi(QDialog *TIGLViewerSettingsDialog)
    {
        if (TIGLViewerSettingsDialog->objectName().isEmpty())
            TIGLViewerSettingsDialog->setObjectName(QStringLiteral("TIGLViewerSettingsDialog"));
        TIGLViewerSettingsDialog->setWindowModality(Qt::ApplicationModal);
        TIGLViewerSettingsDialog->resize(465, 310);
        QIcon icon;
        icon.addFile(QStringLiteral(":/gfx/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        TIGLViewerSettingsDialog->setWindowIcon(icon);
        TIGLViewerSettingsDialog->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(TIGLViewerSettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        buttonBox = new QDialogButtonBox(TIGLViewerSettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 3);

        stackedWidget = new QStackedWidget(TIGLViewerSettingsDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageDisplaySettings = new QWidget();
        pageDisplaySettings->setObjectName(QStringLiteral("pageDisplaySettings"));
        verticalLayout = new QVBoxLayout(pageDisplaySettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(pageDisplaySettings);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_8 = new QLabel(pageDisplaySettings);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/gfx/settings-display.png")));

        horizontalLayout->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        label_2 = new QLabel(pageDisplaySettings);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_3 = new QLabel(pageDisplaySettings);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        sliderTesselationAccuracy = new QSlider(pageDisplaySettings);
        sliderTesselationAccuracy->setObjectName(QStringLiteral("sliderTesselationAccuracy"));
        sliderTesselationAccuracy->setMinimum(0);
        sliderTesselationAccuracy->setMaximum(10);
        sliderTesselationAccuracy->setValue(5);
        sliderTesselationAccuracy->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderTesselationAccuracy);

        label_4 = new QLabel(pageDisplaySettings);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        tessAccuEdit = new QLineEdit(pageDisplaySettings);
        tessAccuEdit->setObjectName(QStringLiteral("tessAccuEdit"));
        tessAccuEdit->setMinimumSize(QSize(20, 0));
        tessAccuEdit->setMaximumSize(QSize(28, 16777215));
        tessAccuEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(tessAccuEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        label_5 = new QLabel(pageDisplaySettings);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_6 = new QLabel(pageDisplaySettings);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        sliderTriangulationAccuracy = new QSlider(pageDisplaySettings);
        sliderTriangulationAccuracy->setObjectName(QStringLiteral("sliderTriangulationAccuracy"));
        sliderTriangulationAccuracy->setMinimum(0);
        sliderTriangulationAccuracy->setMaximum(10);
        sliderTriangulationAccuracy->setSingleStep(1);
        sliderTriangulationAccuracy->setValue(5);
        sliderTriangulationAccuracy->setSliderPosition(5);
        sliderTriangulationAccuracy->setOrientation(Qt::Horizontal);
        sliderTriangulationAccuracy->setInvertedAppearance(false);

        horizontalLayout_3->addWidget(sliderTriangulationAccuracy);

        label_7 = new QLabel(pageDisplaySettings);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        trianAccuEdit = new QLineEdit(pageDisplaySettings);
        trianAccuEdit->setObjectName(QStringLiteral("trianAccuEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(trianAccuEdit->sizePolicy().hasHeightForWidth());
        trianAccuEdit->setSizePolicy(sizePolicy1);
        trianAccuEdit->setMinimumSize(QSize(20, 0));
        trianAccuEdit->setMaximumSize(QSize(28, 16777215));
        trianAccuEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(trianAccuEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_9 = new QLabel(pageDisplaySettings);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        buttonColorChoser = new QPushButton(pageDisplaySettings);
        buttonColorChoser->setObjectName(QStringLiteral("buttonColorChoser"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(20);
        sizePolicy2.setHeightForWidth(buttonColorChoser->sizePolicy().hasHeightForWidth());
        buttonColorChoser->setSizePolicy(sizePolicy2);
        buttonColorChoser->setMinimumSize(QSize(0, 30));
        buttonColorChoser->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(buttonColorChoser);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(pageDisplaySettings);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_19 = new QLabel(page_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        horizontalLayout_9->addWidget(label_19);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        label_20 = new QLabel(page_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setPixmap(QPixmap(QString::fromUtf8(":/gfx/settings-display.png")));

        horizontalLayout_9->addWidget(label_20);


        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        enumerateFaceCB = new QCheckBox(page_2);
        enumerateFaceCB->setObjectName(QStringLiteral("enumerateFaceCB"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(enumerateFaceCB->sizePolicy().hasHeightForWidth());
        enumerateFaceCB->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(enumerateFaceCB);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setWordWrap(true);

        horizontalLayout_5->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_12 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_12);

        debugBopCB = new QCheckBox(page_2);
        debugBopCB->setObjectName(QStringLiteral("debugBopCB"));

        verticalLayout_2->addWidget(debugBopCB);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setWordWrap(true);

        horizontalLayout_6->addWidget(label_11);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_13 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_2->addItem(verticalSpacer_13);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_21 = new QLabel(page_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_7->addWidget(label_21);

        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_7->addWidget(label_12);

        numUIsoLinesSB = new QSpinBox(page_2);
        numUIsoLinesSB->setObjectName(QStringLiteral("numUIsoLinesSB"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(numUIsoLinesSB->sizePolicy().hasHeightForWidth());
        numUIsoLinesSB->setSizePolicy(sizePolicy4);
        numUIsoLinesSB->setMinimumSize(QSize(40, 0));
        numUIsoLinesSB->setMaximumSize(QSize(60, 16777215));
        numUIsoLinesSB->setMaximum(50);

        horizontalLayout_7->addWidget(numUIsoLinesSB);

        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_7->addWidget(label_13);

        numVIsoLinesSB = new QSpinBox(page_2);
        numVIsoLinesSB->setObjectName(QStringLiteral("numVIsoLinesSB"));
        numVIsoLinesSB->setMaximum(50);

        horizontalLayout_7->addWidget(numVIsoLinesSB);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalSpacer_11 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_11);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 2, 1, 1);

        btnRestoreDefaults = new QPushButton(TIGLViewerSettingsDialog);
        btnRestoreDefaults->setObjectName(QStringLiteral("btnRestoreDefaults"));

        gridLayout->addWidget(btnRestoreDefaults, 1, 0, 1, 1);

        settingsList = new QListWidget(TIGLViewerSettingsDialog);
        new QListWidgetItem(settingsList);
        new QListWidgetItem(settingsList);
        settingsList->setObjectName(QStringLiteral("settingsList"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(settingsList->sizePolicy().hasHeightForWidth());
        settingsList->setSizePolicy(sizePolicy5);
        settingsList->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(settingsList, 0, 0, 1, 1);


        retranslateUi(TIGLViewerSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TIGLViewerSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TIGLViewerSettingsDialog, SLOT(reject()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TIGLViewerSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *TIGLViewerSettingsDialog)
    {
        TIGLViewerSettingsDialog->setWindowTitle(QApplication::translate("TIGLViewerSettingsDialog", "Preferences", Q_NULLPTR));
        label->setText(QApplication::translate("TIGLViewerSettingsDialog", "<html><head/><body><p><span style=\" font-size:13pt;\">Display Settings</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QString());
        label_2->setText(QApplication::translate("TIGLViewerSettingsDialog", "Tesselation accuracy", Q_NULLPTR));
        label_3->setText(QApplication::translate("TIGLViewerSettingsDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">inaccurate<br/>fast</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("TIGLViewerSettingsDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">accurate<br/>slow</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("TIGLViewerSettingsDialog", "Triangulation accuracy", Q_NULLPTR));
        label_6->setText(QApplication::translate("TIGLViewerSettingsDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">inaccurate<br/>fast</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("TIGLViewerSettingsDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">accurate<br/>slow</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("TIGLViewerSettingsDialog", "Background Color", Q_NULLPTR));
        buttonColorChoser->setText(QApplication::translate("TIGLViewerSettingsDialog", "choose", Q_NULLPTR));
        label_19->setText(QApplication::translate("TIGLViewerSettingsDialog", "<html><head/><body><p><span style=\" font-size:13pt;\">Debugging</span></p></body></html>", Q_NULLPTR));
        label_20->setText(QString());
        enumerateFaceCB->setText(QApplication::translate("TIGLViewerSettingsDialog", "Enumerate faces", Q_NULLPTR));
        label_10->setText(QApplication::translate("TIGLViewerSettingsDialog", "<i>Enumerate faces displays a number on each face. This helps to understand the order of face creation of OpenCASCADE.</i>", Q_NULLPTR));
        debugBopCB->setText(QApplication::translate("TIGLViewerSettingsDialog", "Debug boolean operations", Q_NULLPTR));
        label_11->setText(QApplication::translate("TIGLViewerSettingsDialog", "<i>Writes BRep geometries before and after each trimming operation into files inside the working directory.</i>", Q_NULLPTR));
        label_21->setText(QApplication::translate("TIGLViewerSettingsDialog", "Number of iso lines per face  ", Q_NULLPTR));
        label_12->setText(QApplication::translate("TIGLViewerSettingsDialog", "U", Q_NULLPTR));
        label_13->setText(QApplication::translate("TIGLViewerSettingsDialog", "V", Q_NULLPTR));
        btnRestoreDefaults->setText(QApplication::translate("TIGLViewerSettingsDialog", "Restore Defaults", Q_NULLPTR));

        const bool __sortingEnabled = settingsList->isSortingEnabled();
        settingsList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = settingsList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("TIGLViewerSettingsDialog", "Display Settings", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = settingsList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("TIGLViewerSettingsDialog", "Debugging", Q_NULLPTR));
        settingsList->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class TIGLViewerSettingsDialog: public Ui_TIGLViewerSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERSETTINGSDIALOG_H
