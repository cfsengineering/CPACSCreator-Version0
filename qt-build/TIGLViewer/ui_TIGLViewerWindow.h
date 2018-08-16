/********************************************************************************
** Form generated from reading UI file 'TIGLViewerWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERWINDOW_H
#define UI_TIGLVIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "TIGLViewerPositioningsWidget.h"
#include "TIGLViewerTransformationWidget.h"
#include "TIGLViewerWidget.h"
#include "TIGLViewerWingWidget.h"
#include "TiglViewerConsole.h"

QT_BEGIN_NAMESPACE

class Ui_TIGLViewerWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *openScriptAction;
    QAction *actionRecent_Files;
    QAction *actionBlubb;
    QAction *saveAction;
    QAction *printAction;
    QAction *setBackgroundAction;
    QAction *exitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *showAllWingsAndFuselagesAction;
    QAction *showAllWingsAndFuselagesSurfacePointsAction;
    QAction *drawFusedAircraftAction;
    QAction *drawWingsAction;
    QAction *drawWingProfilesAction;
    QAction *drawWingOverlayCPACSProfilePointsAction;
    QAction *drawWingTriangulationAction;
    QAction *drawWingSamplePointsAction;
    QAction *drawFusedWingAction;
    QAction *drawWingComponentSegmentAction;
    QAction *drawRotorBladesAction;
    QAction *drawRotorProfilesAction;
    QAction *drawRotorBladeOverlayCPACSProfilePointsAction;
    QAction *drawRotorBladeTriangulationAction;
    QAction *drawRotorBladeSamplePointsAction;
    QAction *drawFusedRotorBladeAction;
    QAction *drawRotorBladeComponentSegmentAction;
    QAction *drawRotorBladeCSPointAction;
    QAction *drawRotorBladeShellAction;
    QAction *drawAllRotorsWingsAndFuselagesAction;
    QAction *drawRotorsAction;
    QAction *drawRotorDisksAction;
    QAction *showRotorPropertiesAction;
    QAction *drawFuselageAction;
    QAction *drawFuselageProfilesAction;
    QAction *drawFuselageTriangulationAction;
    QAction *drawFuselageSamplePointsAction;
    QAction *drawFuselageSamplePointsAngleAction;
    QAction *drawFusedFuselageAction;
    QAction *tiglExportIgesAction;
    QAction *tiglExportFusedIgesAction;
    QAction *tiglExportStepAction;
    QAction *tiglExportStepWithMetaDataAction;
    QAction *tiglExportMeshedWingSTL;
    QAction *tiglExportMeshedWingVTK;
    QAction *tiglExportMeshedWingVTKsimple;
    QAction *tiglExportMeshedFuselageVTK;
    QAction *tiglExportMeshedFuselageVTKsimple;
    QAction *tiglExportMeshedFuselageSTL;
    QAction *viewFrontAction;
    QAction *viewBackAction;
    QAction *viewTopAction;
    QAction *viewBottomAction;
    QAction *viewLeftAction;
    QAction *viewRightAction;
    QAction *viewAxoAction;
    QAction *viewGridAction;
    QAction *viewResetAction;
    QAction *viewZoomInAction;
    QAction *viewZoomOutAction;
    QAction *backgroundAction;
    QAction *fitAction;
    QAction *fitAllAction;
    QAction *zoomAction;
    QAction *panAction;
    QAction *rotAction;
    QAction *gridOnAction;
    QAction *gridOffAction;
    QAction *gridXYAction;
    QAction *gridXZAction;
    QAction *gridYZAction;
    QAction *gridRectAction;
    QAction *gridCircAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *showConsoleAction;
    QAction *showScriptAction;
    QAction *showWireframeAction;
    QAction *drawIntersectionAction;
    QAction *showFusedAirplaneTriangulation;
    QAction *closeAction;
    QAction *selectAction;
    QAction *settingsAction;
    QAction *drawWingShellAction;
    QAction *tiglExportStructuredIgesAction;
    QAction *tiglExportWingColladaAction;
    QAction *tiglExportFuselageColladaAction;
    QAction *drawWingCSPointAction;
    QAction *tiglExportMeshedConfigVTK;
    QAction *tiglExportMeshedConfigVTKNoFuse;
    QAction *drawFarFieldAction;
    QAction *tiglExportFusedStepAction;
    QAction *tiglExportWingBRepAction;
    QAction *tiglExportFuselageBRepAction;
    QAction *tiglExportFusedConfigBRep;
    QAction *drawWingGuideCurvesAction;
    QAction *drawRotorBladeGuideCurvesAction;
    QAction *drawFuselageGuideCurvesAction;
    QAction *tiglExportWingCurvesBRepAction;
    QAction *tiglExportFuselageCurvesBRepAction;
    QAction *actionCreate_Screenshot;
    QAction *saveScreenshotAction;
    QAction *tiglExportConfigurationColladaAction;
    QAction *drawPointAction;
    QAction *drawVectorAction;
    QAction *drawSystemsAction;
    QAction *drawWingStructureAction;
    QAction *tiglExportMeshedConfigSTL;
    QAction *showReflectionLinesAction;
    QAction *drawComponentAction;
    QAction *selectAllAction;
    QAction *refreshAction;
    QAction *drawTEDAction;
    QAction *showCreatorAction;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    TIGLViewerWidget *myOCC;
    QMenuBar *menubar;
    QMenu *fileMenu;
    QMenu *recentFileMenu;
    QMenu *tiglMenu;
    QMenu *menuExport_to_IGES;
    QMenu *menuExport_to_STEP;
    QMenu *menuExport_to_VTK;
    QMenu *menuExport_to_STL;
    QMenu *menuExport_to_Collada;
    QMenu *menuExport_to_BRep;
    QMenu *cpacsMenu;
    QMenu *menuAircraft;
    QMenu *menuWings;
    QMenu *menuFuselages;
    QMenu *menuRotorcraft;
    QMenu *menuRotorBlades;
    QMenu *menuMisc_Geometry;
    QMenu *viewMenu;
    QMenu *viewDisplayMenu;
    QMenu *viewActionsMenu;
    QMenu *gridMenu;
    QMenu *helpMenu;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBarView;
    QDockWidget *consoleDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout2;
    Console *console;
    QDockWidget *creatorDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeView;
    TIGLViewerWingWidget *wingModificator;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *anchorLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelAnchor;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxAnchorX;
    QLabel *label_3;
    QDoubleSpinBox *spinBoxAnchorY;
    QLabel *label_8;
    QDoubleSpinBox *spinBoxAnchorZ;
    QHBoxLayout *orientationLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelOrientation;
    QComboBox *comboBoxWingOrientation;
    QLabel *labelSymmetry;
    QComboBox *comboBoxSymmetry;
    QHBoxLayout *sweepLayout;
    QPushButton *btnExpendSweepDetails;
    QLabel *labelSweep;
    QDoubleSpinBox *spinBoxSweep;
    QWidget *widgetSweepDetails;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelChord;
    QDoubleSpinBox *spinBoxSweepChord;
    QLabel *labelMethod;
    QComboBox *comboBoxSweepMethod;
    QHBoxLayout *dihedralLayout;
    QPushButton *btnExpendDihedralDetails;
    QLabel *labelDihedral;
    QDoubleSpinBox *spinBoxDihedral;
    QWidget *widgetDihedralDetails;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelDihedralChord;
    QDoubleSpinBox *spinBoxDihedralChord;
    QHBoxLayout *areaLayout;
    QPushButton *btnExpendAreaDetails;
    QLabel *labelArea;
    QCheckBox *checkBoxIsAreaConstant;
    QLabel *labelXY;
    QDoubleSpinBox *spinBoxAreaXY;
    QWidget *widgetAreaDetails;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelXZ;
    QDoubleSpinBox *spinBoxAreaXZ;
    QLabel *labelYZ;
    QDoubleSpinBox *spinBoxAreaYZ;
    QLabel *labelT;
    QDoubleSpinBox *spinBoxAreaT;
    QHBoxLayout *spanLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelSpan;
    QCheckBox *checkBoxIsSpanConstant;
    QDoubleSpinBox *spinBoxSpan;
    QHBoxLayout *aRLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelAR;
    QCheckBox *checkBoxIsARConstant;
    QDoubleSpinBox *spinBoxAR;
    QHBoxLayout *aifoilLayout;
    QPushButton *btnExpendAirfoilDetails;
    QLabel *labelAirfoil;
    QComboBox *comboBoxAirfoil;
    QWidget *widgetAirfoilDetails;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnAddAifoilToDB;
    QHBoxLayout *standardizationLayout;
    QPushButton *btnExpendStandardizationDetails;
    QLabel *labelStandardization;
    QComboBox *comboBoxStdGlobal;
    QWidget *widgetStandardizationDetails;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBoxStdAirfoils;
    QCheckBox *checkBoxStdSections;
    QCheckBox *checkBoxStdPositionings;
    QCheckBox *checkBoxStdAnchor;
    TIGLViewerTransformationWidget *transforamtionModificator;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *transformationLayout;
    QHBoxLayout *header;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_4;
    QHBoxLayout *scaling;
    QLabel *labelScaling;
    QDoubleSpinBox *spinBoxSX;
    QDoubleSpinBox *spinBoxSY;
    QDoubleSpinBox *spinBoxSZ;
    QHBoxLayout *rotation;
    QLabel *labelRotation;
    QDoubleSpinBox *spinBoxRX;
    QDoubleSpinBox *spinBoxRY;
    QDoubleSpinBox *spinBoxRZ;
    QHBoxLayout *translation;
    QLabel *labelTranslation;
    QDoubleSpinBox *spinBoxTX;
    QDoubleSpinBox *spinBoxTY;
    QDoubleSpinBox *spinBoxTZ;
    TIGLViewerPositioningsWidget *positioningsModificator;
    QWidget *widgetApply;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QPushButton *commitButton;

    void setupUi(QMainWindow *TIGLViewerWindow)
    {
        if (TIGLViewerWindow->objectName().isEmpty())
            TIGLViewerWindow->setObjectName(QStringLiteral("TIGLViewerWindow"));
        TIGLViewerWindow->resize(1141, 830);
        QIcon icon;
        icon.addFile(QStringLiteral(":/gfx/Icon_TIGL_128.png"), QSize(), QIcon::Normal, QIcon::Off);
        TIGLViewerWindow->setWindowIcon(icon);
        TIGLViewerWindow->setUnifiedTitleAndToolBarOnMac(true);
        newAction = new QAction(TIGLViewerWindow);
        newAction->setObjectName(QStringLiteral("newAction"));
        openAction = new QAction(TIGLViewerWindow);
        openAction->setObjectName(QStringLiteral("openAction"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/gfx/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon1);
        openScriptAction = new QAction(TIGLViewerWindow);
        openScriptAction->setObjectName(QStringLiteral("openScriptAction"));
        actionRecent_Files = new QAction(TIGLViewerWindow);
        actionRecent_Files->setObjectName(QStringLiteral("actionRecent_Files"));
        actionBlubb = new QAction(TIGLViewerWindow);
        actionBlubb->setObjectName(QStringLiteral("actionBlubb"));
        saveAction = new QAction(TIGLViewerWindow);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/gfx/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon2);
        printAction = new QAction(TIGLViewerWindow);
        printAction->setObjectName(QStringLiteral("printAction"));
        setBackgroundAction = new QAction(TIGLViewerWindow);
        setBackgroundAction->setObjectName(QStringLiteral("setBackgroundAction"));
        exitAction = new QAction(TIGLViewerWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        undoAction = new QAction(TIGLViewerWindow);
        undoAction->setObjectName(QStringLiteral("undoAction"));
        redoAction = new QAction(TIGLViewerWindow);
        redoAction->setObjectName(QStringLiteral("redoAction"));
        cutAction = new QAction(TIGLViewerWindow);
        cutAction->setObjectName(QStringLiteral("cutAction"));
        copyAction = new QAction(TIGLViewerWindow);
        copyAction->setObjectName(QStringLiteral("copyAction"));
        pasteAction = new QAction(TIGLViewerWindow);
        pasteAction->setObjectName(QStringLiteral("pasteAction"));
        showAllWingsAndFuselagesAction = new QAction(TIGLViewerWindow);
        showAllWingsAndFuselagesAction->setObjectName(QStringLiteral("showAllWingsAndFuselagesAction"));
        showAllWingsAndFuselagesSurfacePointsAction = new QAction(TIGLViewerWindow);
        showAllWingsAndFuselagesSurfacePointsAction->setObjectName(QStringLiteral("showAllWingsAndFuselagesSurfacePointsAction"));
        drawFusedAircraftAction = new QAction(TIGLViewerWindow);
        drawFusedAircraftAction->setObjectName(QStringLiteral("drawFusedAircraftAction"));
        drawWingsAction = new QAction(TIGLViewerWindow);
        drawWingsAction->setObjectName(QStringLiteral("drawWingsAction"));
        drawWingProfilesAction = new QAction(TIGLViewerWindow);
        drawWingProfilesAction->setObjectName(QStringLiteral("drawWingProfilesAction"));
        drawWingOverlayCPACSProfilePointsAction = new QAction(TIGLViewerWindow);
        drawWingOverlayCPACSProfilePointsAction->setObjectName(QStringLiteral("drawWingOverlayCPACSProfilePointsAction"));
        drawWingTriangulationAction = new QAction(TIGLViewerWindow);
        drawWingTriangulationAction->setObjectName(QStringLiteral("drawWingTriangulationAction"));
        drawWingSamplePointsAction = new QAction(TIGLViewerWindow);
        drawWingSamplePointsAction->setObjectName(QStringLiteral("drawWingSamplePointsAction"));
        drawFusedWingAction = new QAction(TIGLViewerWindow);
        drawFusedWingAction->setObjectName(QStringLiteral("drawFusedWingAction"));
        drawWingComponentSegmentAction = new QAction(TIGLViewerWindow);
        drawWingComponentSegmentAction->setObjectName(QStringLiteral("drawWingComponentSegmentAction"));
        drawRotorBladesAction = new QAction(TIGLViewerWindow);
        drawRotorBladesAction->setObjectName(QStringLiteral("drawRotorBladesAction"));
        drawRotorProfilesAction = new QAction(TIGLViewerWindow);
        drawRotorProfilesAction->setObjectName(QStringLiteral("drawRotorProfilesAction"));
        drawRotorBladeOverlayCPACSProfilePointsAction = new QAction(TIGLViewerWindow);
        drawRotorBladeOverlayCPACSProfilePointsAction->setObjectName(QStringLiteral("drawRotorBladeOverlayCPACSProfilePointsAction"));
        drawRotorBladeTriangulationAction = new QAction(TIGLViewerWindow);
        drawRotorBladeTriangulationAction->setObjectName(QStringLiteral("drawRotorBladeTriangulationAction"));
        drawRotorBladeSamplePointsAction = new QAction(TIGLViewerWindow);
        drawRotorBladeSamplePointsAction->setObjectName(QStringLiteral("drawRotorBladeSamplePointsAction"));
        drawFusedRotorBladeAction = new QAction(TIGLViewerWindow);
        drawFusedRotorBladeAction->setObjectName(QStringLiteral("drawFusedRotorBladeAction"));
        drawRotorBladeComponentSegmentAction = new QAction(TIGLViewerWindow);
        drawRotorBladeComponentSegmentAction->setObjectName(QStringLiteral("drawRotorBladeComponentSegmentAction"));
        drawRotorBladeCSPointAction = new QAction(TIGLViewerWindow);
        drawRotorBladeCSPointAction->setObjectName(QStringLiteral("drawRotorBladeCSPointAction"));
        drawRotorBladeShellAction = new QAction(TIGLViewerWindow);
        drawRotorBladeShellAction->setObjectName(QStringLiteral("drawRotorBladeShellAction"));
        drawAllRotorsWingsAndFuselagesAction = new QAction(TIGLViewerWindow);
        drawAllRotorsWingsAndFuselagesAction->setObjectName(QStringLiteral("drawAllRotorsWingsAndFuselagesAction"));
        drawRotorsAction = new QAction(TIGLViewerWindow);
        drawRotorsAction->setObjectName(QStringLiteral("drawRotorsAction"));
        drawRotorDisksAction = new QAction(TIGLViewerWindow);
        drawRotorDisksAction->setObjectName(QStringLiteral("drawRotorDisksAction"));
        showRotorPropertiesAction = new QAction(TIGLViewerWindow);
        showRotorPropertiesAction->setObjectName(QStringLiteral("showRotorPropertiesAction"));
        drawFuselageAction = new QAction(TIGLViewerWindow);
        drawFuselageAction->setObjectName(QStringLiteral("drawFuselageAction"));
        drawFuselageProfilesAction = new QAction(TIGLViewerWindow);
        drawFuselageProfilesAction->setObjectName(QStringLiteral("drawFuselageProfilesAction"));
        drawFuselageTriangulationAction = new QAction(TIGLViewerWindow);
        drawFuselageTriangulationAction->setObjectName(QStringLiteral("drawFuselageTriangulationAction"));
        drawFuselageSamplePointsAction = new QAction(TIGLViewerWindow);
        drawFuselageSamplePointsAction->setObjectName(QStringLiteral("drawFuselageSamplePointsAction"));
        drawFuselageSamplePointsAngleAction = new QAction(TIGLViewerWindow);
        drawFuselageSamplePointsAngleAction->setObjectName(QStringLiteral("drawFuselageSamplePointsAngleAction"));
        drawFusedFuselageAction = new QAction(TIGLViewerWindow);
        drawFusedFuselageAction->setObjectName(QStringLiteral("drawFusedFuselageAction"));
        tiglExportIgesAction = new QAction(TIGLViewerWindow);
        tiglExportIgesAction->setObjectName(QStringLiteral("tiglExportIgesAction"));
        tiglExportFusedIgesAction = new QAction(TIGLViewerWindow);
        tiglExportFusedIgesAction->setObjectName(QStringLiteral("tiglExportFusedIgesAction"));
        tiglExportStepAction = new QAction(TIGLViewerWindow);
        tiglExportStepAction->setObjectName(QStringLiteral("tiglExportStepAction"));
        tiglExportStepWithMetaDataAction = new QAction(TIGLViewerWindow);
        tiglExportStepWithMetaDataAction->setObjectName(QStringLiteral("tiglExportStepWithMetaDataAction"));
        tiglExportMeshedWingSTL = new QAction(TIGLViewerWindow);
        tiglExportMeshedWingSTL->setObjectName(QStringLiteral("tiglExportMeshedWingSTL"));
        tiglExportMeshedWingVTK = new QAction(TIGLViewerWindow);
        tiglExportMeshedWingVTK->setObjectName(QStringLiteral("tiglExportMeshedWingVTK"));
        tiglExportMeshedWingVTKsimple = new QAction(TIGLViewerWindow);
        tiglExportMeshedWingVTKsimple->setObjectName(QStringLiteral("tiglExportMeshedWingVTKsimple"));
        tiglExportMeshedFuselageVTK = new QAction(TIGLViewerWindow);
        tiglExportMeshedFuselageVTK->setObjectName(QStringLiteral("tiglExportMeshedFuselageVTK"));
        tiglExportMeshedFuselageVTKsimple = new QAction(TIGLViewerWindow);
        tiglExportMeshedFuselageVTKsimple->setObjectName(QStringLiteral("tiglExportMeshedFuselageVTKsimple"));
        tiglExportMeshedFuselageSTL = new QAction(TIGLViewerWindow);
        tiglExportMeshedFuselageSTL->setObjectName(QStringLiteral("tiglExportMeshedFuselageSTL"));
        viewFrontAction = new QAction(TIGLViewerWindow);
        viewFrontAction->setObjectName(QStringLiteral("viewFrontAction"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/gfx/view-front.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewFrontAction->setIcon(icon3);
        viewBackAction = new QAction(TIGLViewerWindow);
        viewBackAction->setObjectName(QStringLiteral("viewBackAction"));
        viewTopAction = new QAction(TIGLViewerWindow);
        viewTopAction->setObjectName(QStringLiteral("viewTopAction"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/gfx/view-top.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewTopAction->setIcon(icon4);
        viewBottomAction = new QAction(TIGLViewerWindow);
        viewBottomAction->setObjectName(QStringLiteral("viewBottomAction"));
        viewLeftAction = new QAction(TIGLViewerWindow);
        viewLeftAction->setObjectName(QStringLiteral("viewLeftAction"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/gfx/view-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewLeftAction->setIcon(icon5);
        viewRightAction = new QAction(TIGLViewerWindow);
        viewRightAction->setObjectName(QStringLiteral("viewRightAction"));
        viewAxoAction = new QAction(TIGLViewerWindow);
        viewAxoAction->setObjectName(QStringLiteral("viewAxoAction"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/gfx/view-axo.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewAxoAction->setIcon(icon6);
        viewGridAction = new QAction(TIGLViewerWindow);
        viewGridAction->setObjectName(QStringLiteral("viewGridAction"));
        viewResetAction = new QAction(TIGLViewerWindow);
        viewResetAction->setObjectName(QStringLiteral("viewResetAction"));
        viewZoomInAction = new QAction(TIGLViewerWindow);
        viewZoomInAction->setObjectName(QStringLiteral("viewZoomInAction"));
        viewZoomOutAction = new QAction(TIGLViewerWindow);
        viewZoomOutAction->setObjectName(QStringLiteral("viewZoomOutAction"));
        backgroundAction = new QAction(TIGLViewerWindow);
        backgroundAction->setObjectName(QStringLiteral("backgroundAction"));
        fitAction = new QAction(TIGLViewerWindow);
        fitAction->setObjectName(QStringLiteral("fitAction"));
        fitAllAction = new QAction(TIGLViewerWindow);
        fitAllAction->setObjectName(QStringLiteral("fitAllAction"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/gfx/view-fit.png"), QSize(), QIcon::Normal, QIcon::Off);
        fitAllAction->setIcon(icon7);
        zoomAction = new QAction(TIGLViewerWindow);
        zoomAction->setObjectName(QStringLiteral("zoomAction"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/gfx/zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomAction->setIcon(icon8);
        panAction = new QAction(TIGLViewerWindow);
        panAction->setObjectName(QStringLiteral("panAction"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/gfx/translate.png"), QSize(), QIcon::Normal, QIcon::Off);
        panAction->setIcon(icon9);
        rotAction = new QAction(TIGLViewerWindow);
        rotAction->setObjectName(QStringLiteral("rotAction"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/gfx/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotAction->setIcon(icon10);
        gridOnAction = new QAction(TIGLViewerWindow);
        gridOnAction->setObjectName(QStringLiteral("gridOnAction"));
        gridOnAction->setCheckable(true);
        gridOnAction->setChecked(true);
        gridOffAction = new QAction(TIGLViewerWindow);
        gridOffAction->setObjectName(QStringLiteral("gridOffAction"));
        gridXYAction = new QAction(TIGLViewerWindow);
        gridXYAction->setObjectName(QStringLiteral("gridXYAction"));
        gridXZAction = new QAction(TIGLViewerWindow);
        gridXZAction->setObjectName(QStringLiteral("gridXZAction"));
        gridYZAction = new QAction(TIGLViewerWindow);
        gridYZAction->setObjectName(QStringLiteral("gridYZAction"));
        gridRectAction = new QAction(TIGLViewerWindow);
        gridRectAction->setObjectName(QStringLiteral("gridRectAction"));
        gridCircAction = new QAction(TIGLViewerWindow);
        gridCircAction->setObjectName(QStringLiteral("gridCircAction"));
        aboutAction = new QAction(TIGLViewerWindow);
        aboutAction->setObjectName(QStringLiteral("aboutAction"));
        aboutQtAction = new QAction(TIGLViewerWindow);
        aboutQtAction->setObjectName(QStringLiteral("aboutQtAction"));
        showConsoleAction = new QAction(TIGLViewerWindow);
        showConsoleAction->setObjectName(QStringLiteral("showConsoleAction"));
        showConsoleAction->setCheckable(true);
        showConsoleAction->setChecked(true);
        showScriptAction = new QAction(TIGLViewerWindow);
        showScriptAction->setObjectName(QStringLiteral("showScriptAction"));
        showScriptAction->setCheckable(true);
        showScriptAction->setChecked(true);
        showWireframeAction = new QAction(TIGLViewerWindow);
        showWireframeAction->setObjectName(QStringLiteral("showWireframeAction"));
        showWireframeAction->setCheckable(true);
        drawIntersectionAction = new QAction(TIGLViewerWindow);
        drawIntersectionAction->setObjectName(QStringLiteral("drawIntersectionAction"));
        showFusedAirplaneTriangulation = new QAction(TIGLViewerWindow);
        showFusedAirplaneTriangulation->setObjectName(QStringLiteral("showFusedAirplaneTriangulation"));
        closeAction = new QAction(TIGLViewerWindow);
        closeAction->setObjectName(QStringLiteral("closeAction"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/gfx/document-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeAction->setIcon(icon11);
        selectAction = new QAction(TIGLViewerWindow);
        selectAction->setObjectName(QStringLiteral("selectAction"));
        selectAction->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/gfx/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectAction->setIcon(icon12);
        settingsAction = new QAction(TIGLViewerWindow);
        settingsAction->setObjectName(QStringLiteral("settingsAction"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/gfx/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsAction->setIcon(icon13);
        drawWingShellAction = new QAction(TIGLViewerWindow);
        drawWingShellAction->setObjectName(QStringLiteral("drawWingShellAction"));
        tiglExportStructuredIgesAction = new QAction(TIGLViewerWindow);
        tiglExportStructuredIgesAction->setObjectName(QStringLiteral("tiglExportStructuredIgesAction"));
        tiglExportWingColladaAction = new QAction(TIGLViewerWindow);
        tiglExportWingColladaAction->setObjectName(QStringLiteral("tiglExportWingColladaAction"));
        tiglExportFuselageColladaAction = new QAction(TIGLViewerWindow);
        tiglExportFuselageColladaAction->setObjectName(QStringLiteral("tiglExportFuselageColladaAction"));
        drawWingCSPointAction = new QAction(TIGLViewerWindow);
        drawWingCSPointAction->setObjectName(QStringLiteral("drawWingCSPointAction"));
        tiglExportMeshedConfigVTK = new QAction(TIGLViewerWindow);
        tiglExportMeshedConfigVTK->setObjectName(QStringLiteral("tiglExportMeshedConfigVTK"));
        tiglExportMeshedConfigVTKNoFuse = new QAction(TIGLViewerWindow);
        tiglExportMeshedConfigVTKNoFuse->setObjectName(QStringLiteral("tiglExportMeshedConfigVTKNoFuse"));
        drawFarFieldAction = new QAction(TIGLViewerWindow);
        drawFarFieldAction->setObjectName(QStringLiteral("drawFarFieldAction"));
        drawFarFieldAction->setEnabled(false);
        tiglExportFusedStepAction = new QAction(TIGLViewerWindow);
        tiglExportFusedStepAction->setObjectName(QStringLiteral("tiglExportFusedStepAction"));
        tiglExportWingBRepAction = new QAction(TIGLViewerWindow);
        tiglExportWingBRepAction->setObjectName(QStringLiteral("tiglExportWingBRepAction"));
        tiglExportFuselageBRepAction = new QAction(TIGLViewerWindow);
        tiglExportFuselageBRepAction->setObjectName(QStringLiteral("tiglExportFuselageBRepAction"));
        tiglExportFusedConfigBRep = new QAction(TIGLViewerWindow);
        tiglExportFusedConfigBRep->setObjectName(QStringLiteral("tiglExportFusedConfigBRep"));
        drawWingGuideCurvesAction = new QAction(TIGLViewerWindow);
        drawWingGuideCurvesAction->setObjectName(QStringLiteral("drawWingGuideCurvesAction"));
        drawRotorBladeGuideCurvesAction = new QAction(TIGLViewerWindow);
        drawRotorBladeGuideCurvesAction->setObjectName(QStringLiteral("drawRotorBladeGuideCurvesAction"));
        drawFuselageGuideCurvesAction = new QAction(TIGLViewerWindow);
        drawFuselageGuideCurvesAction->setObjectName(QStringLiteral("drawFuselageGuideCurvesAction"));
        tiglExportWingCurvesBRepAction = new QAction(TIGLViewerWindow);
        tiglExportWingCurvesBRepAction->setObjectName(QStringLiteral("tiglExportWingCurvesBRepAction"));
        tiglExportFuselageCurvesBRepAction = new QAction(TIGLViewerWindow);
        tiglExportFuselageCurvesBRepAction->setObjectName(QStringLiteral("tiglExportFuselageCurvesBRepAction"));
        actionCreate_Screenshot = new QAction(TIGLViewerWindow);
        actionCreate_Screenshot->setObjectName(QStringLiteral("actionCreate_Screenshot"));
        saveScreenshotAction = new QAction(TIGLViewerWindow);
        saveScreenshotAction->setObjectName(QStringLiteral("saveScreenshotAction"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/gfx/screenshot.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveScreenshotAction->setIcon(icon14);
        tiglExportConfigurationColladaAction = new QAction(TIGLViewerWindow);
        tiglExportConfigurationColladaAction->setObjectName(QStringLiteral("tiglExportConfigurationColladaAction"));
        drawPointAction = new QAction(TIGLViewerWindow);
        drawPointAction->setObjectName(QStringLiteral("drawPointAction"));
        drawVectorAction = new QAction(TIGLViewerWindow);
        drawVectorAction->setObjectName(QStringLiteral("drawVectorAction"));
        drawSystemsAction = new QAction(TIGLViewerWindow);
        drawSystemsAction->setObjectName(QStringLiteral("drawSystemsAction"));
        drawWingStructureAction = new QAction(TIGLViewerWindow);
        drawWingStructureAction->setObjectName(QStringLiteral("drawWingStructureAction"));
        tiglExportMeshedConfigSTL = new QAction(TIGLViewerWindow);
        tiglExportMeshedConfigSTL->setObjectName(QStringLiteral("tiglExportMeshedConfigSTL"));
        showReflectionLinesAction = new QAction(TIGLViewerWindow);
        showReflectionLinesAction->setObjectName(QStringLiteral("showReflectionLinesAction"));
        showReflectionLinesAction->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/gfx/reflections.png"), QSize(), QIcon::Normal, QIcon::Off);
        showReflectionLinesAction->setIcon(icon15);
        showReflectionLinesAction->setIconVisibleInMenu(false);
        drawComponentAction = new QAction(TIGLViewerWindow);
        drawComponentAction->setObjectName(QStringLiteral("drawComponentAction"));
        selectAllAction = new QAction(TIGLViewerWindow);
        selectAllAction->setObjectName(QStringLiteral("selectAllAction"));
        refreshAction = new QAction(TIGLViewerWindow);
        refreshAction->setObjectName(QStringLiteral("refreshAction"));
        drawTEDAction = new QAction(TIGLViewerWindow);
        drawTEDAction->setObjectName(QStringLiteral("drawTEDAction"));
        showCreatorAction = new QAction(TIGLViewerWindow);
        showCreatorAction->setObjectName(QStringLiteral("showCreatorAction"));
        showCreatorAction->setCheckable(true);
        centralwidget = new QWidget(TIGLViewerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        myOCC = new TIGLViewerWidget(centralwidget);
        myOCC->setObjectName(QStringLiteral("myOCC"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(70);
        sizePolicy1.setHeightForWidth(myOCC->sizePolicy().hasHeightForWidth());
        myOCC->setSizePolicy(sizePolicy1);
        myOCC->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(myOCC);

        TIGLViewerWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TIGLViewerWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1141, 20));
        fileMenu = new QMenu(menubar);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        recentFileMenu = new QMenu(fileMenu);
        recentFileMenu->setObjectName(QStringLiteral("recentFileMenu"));
        tiglMenu = new QMenu(fileMenu);
        tiglMenu->setObjectName(QStringLiteral("tiglMenu"));
        menuExport_to_IGES = new QMenu(tiglMenu);
        menuExport_to_IGES->setObjectName(QStringLiteral("menuExport_to_IGES"));
        menuExport_to_STEP = new QMenu(tiglMenu);
        menuExport_to_STEP->setObjectName(QStringLiteral("menuExport_to_STEP"));
        menuExport_to_VTK = new QMenu(tiglMenu);
        menuExport_to_VTK->setObjectName(QStringLiteral("menuExport_to_VTK"));
        menuExport_to_STL = new QMenu(tiglMenu);
        menuExport_to_STL->setObjectName(QStringLiteral("menuExport_to_STL"));
        menuExport_to_Collada = new QMenu(tiglMenu);
        menuExport_to_Collada->setObjectName(QStringLiteral("menuExport_to_Collada"));
        menuExport_to_BRep = new QMenu(tiglMenu);
        menuExport_to_BRep->setObjectName(QStringLiteral("menuExport_to_BRep"));
        cpacsMenu = new QMenu(menubar);
        cpacsMenu->setObjectName(QStringLiteral("cpacsMenu"));
        menuAircraft = new QMenu(cpacsMenu);
        menuAircraft->setObjectName(QStringLiteral("menuAircraft"));
        menuWings = new QMenu(cpacsMenu);
        menuWings->setObjectName(QStringLiteral("menuWings"));
        menuFuselages = new QMenu(cpacsMenu);
        menuFuselages->setObjectName(QStringLiteral("menuFuselages"));
        menuRotorcraft = new QMenu(cpacsMenu);
        menuRotorcraft->setObjectName(QStringLiteral("menuRotorcraft"));
        menuRotorBlades = new QMenu(cpacsMenu);
        menuRotorBlades->setObjectName(QStringLiteral("menuRotorBlades"));
        menuMisc_Geometry = new QMenu(cpacsMenu);
        menuMisc_Geometry->setObjectName(QStringLiteral("menuMisc_Geometry"));
        viewMenu = new QMenu(menubar);
        viewMenu->setObjectName(QStringLiteral("viewMenu"));
        viewDisplayMenu = new QMenu(viewMenu);
        viewDisplayMenu->setObjectName(QStringLiteral("viewDisplayMenu"));
        viewActionsMenu = new QMenu(viewMenu);
        viewActionsMenu->setObjectName(QStringLiteral("viewActionsMenu"));
        gridMenu = new QMenu(viewMenu);
        gridMenu->setObjectName(QStringLiteral("gridMenu"));
        helpMenu = new QMenu(menubar);
        helpMenu->setObjectName(QStringLiteral("helpMenu"));
        TIGLViewerWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TIGLViewerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TIGLViewerWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(TIGLViewerWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        TIGLViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBarView = new QToolBar(TIGLViewerWindow);
        toolBarView->setObjectName(QStringLiteral("toolBarView"));
        toolBarView->setOrientation(Qt::Vertical);
        TIGLViewerWindow->addToolBar(Qt::LeftToolBarArea, toolBarView);
        consoleDockWidget = new QDockWidget(TIGLViewerWindow);
        consoleDockWidget->setObjectName(QStringLiteral("consoleDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout2->setObjectName(QStringLiteral("verticalLayout2"));
        console = new Console(dockWidgetContents_2);
        console->setObjectName(QStringLiteral("console"));
        console->setBaseSize(QSize(0, 100));

        verticalLayout2->addWidget(console);

        consoleDockWidget->setWidget(dockWidgetContents_2);
        TIGLViewerWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), consoleDockWidget);
        creatorDockWidget = new QDockWidget(TIGLViewerWindow);
        creatorDockWidget->setObjectName(QStringLiteral("creatorDockWidget"));
        creatorDockWidget->setFloating(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        treeView = new QTreeView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMinimumSize(QSize(0, 0));
        treeView->header()->setCascadingSectionResizes(false);
        treeView->header()->setDefaultSectionSize(122);
        treeView->header()->setStretchLastSection(true);

        verticalLayout_2->addWidget(treeView);

        wingModificator = new TIGLViewerWingWidget(dockWidgetContents);
        wingModificator->setObjectName(QStringLiteral("wingModificator"));
        verticalLayout_4 = new QVBoxLayout(wingModificator);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        anchorLayout = new QHBoxLayout();
        anchorLayout->setObjectName(QStringLiteral("anchorLayout"));
        horizontalSpacer_4 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        anchorLayout->addItem(horizontalSpacer_4);

        labelAnchor = new QLabel(wingModificator);
        labelAnchor->setObjectName(QStringLiteral("labelAnchor"));
        labelAnchor->setMinimumSize(QSize(80, 0));
        labelAnchor->setMaximumSize(QSize(80, 16777215));

        anchorLayout->addWidget(labelAnchor);

        label_2 = new QLabel(wingModificator);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(20, 16777215));

        anchorLayout->addWidget(label_2);

        spinBoxAnchorX = new QDoubleSpinBox(wingModificator);
        spinBoxAnchorX->setObjectName(QStringLiteral("spinBoxAnchorX"));
        spinBoxAnchorX->setDecimals(3);
        spinBoxAnchorX->setMinimum(-1e+6);
        spinBoxAnchorX->setMaximum(1e+6);

        anchorLayout->addWidget(spinBoxAnchorX);

        label_3 = new QLabel(wingModificator);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(20, 16777215));

        anchorLayout->addWidget(label_3);

        spinBoxAnchorY = new QDoubleSpinBox(wingModificator);
        spinBoxAnchorY->setObjectName(QStringLiteral("spinBoxAnchorY"));
        spinBoxAnchorY->setDecimals(3);
        spinBoxAnchorY->setMinimum(-1e+6);
        spinBoxAnchorY->setMaximum(1e+6);

        anchorLayout->addWidget(spinBoxAnchorY);

        label_8 = new QLabel(wingModificator);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(20, 16777215));

        anchorLayout->addWidget(label_8);

        spinBoxAnchorZ = new QDoubleSpinBox(wingModificator);
        spinBoxAnchorZ->setObjectName(QStringLiteral("spinBoxAnchorZ"));
        spinBoxAnchorZ->setDecimals(3);
        spinBoxAnchorZ->setMinimum(-1e+6);
        spinBoxAnchorZ->setMaximum(1e+6);

        anchorLayout->addWidget(spinBoxAnchorZ);


        verticalLayout_4->addLayout(anchorLayout);

        orientationLayout = new QHBoxLayout();
        orientationLayout->setObjectName(QStringLiteral("orientationLayout"));
        horizontalSpacer_3 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        orientationLayout->addItem(horizontalSpacer_3);

        labelOrientation = new QLabel(wingModificator);
        labelOrientation->setObjectName(QStringLiteral("labelOrientation"));
        labelOrientation->setMinimumSize(QSize(80, 0));
        labelOrientation->setMaximumSize(QSize(80, 16777215));
        labelOrientation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        orientationLayout->addWidget(labelOrientation);

        comboBoxWingOrientation = new QComboBox(wingModificator);
        comboBoxWingOrientation->setObjectName(QStringLiteral("comboBoxWingOrientation"));

        orientationLayout->addWidget(comboBoxWingOrientation);

        labelSymmetry = new QLabel(wingModificator);
        labelSymmetry->setObjectName(QStringLiteral("labelSymmetry"));
        labelSymmetry->setMinimumSize(QSize(80, 0));
        labelSymmetry->setMaximumSize(QSize(80, 16777215));

        orientationLayout->addWidget(labelSymmetry);

        comboBoxSymmetry = new QComboBox(wingModificator);
        comboBoxSymmetry->setObjectName(QStringLiteral("comboBoxSymmetry"));

        orientationLayout->addWidget(comboBoxSymmetry);


        verticalLayout_4->addLayout(orientationLayout);

        sweepLayout = new QHBoxLayout();
        sweepLayout->setObjectName(QStringLiteral("sweepLayout"));
        btnExpendSweepDetails = new QPushButton(wingModificator);
        btnExpendSweepDetails->setObjectName(QStringLiteral("btnExpendSweepDetails"));
        btnExpendSweepDetails->setMaximumSize(QSize(20, 16777215));

        sweepLayout->addWidget(btnExpendSweepDetails);

        labelSweep = new QLabel(wingModificator);
        labelSweep->setObjectName(QStringLiteral("labelSweep"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelSweep->sizePolicy().hasHeightForWidth());
        labelSweep->setSizePolicy(sizePolicy2);
        labelSweep->setMinimumSize(QSize(80, 0));
        labelSweep->setMaximumSize(QSize(80, 16777215));

        sweepLayout->addWidget(labelSweep);

        spinBoxSweep = new QDoubleSpinBox(wingModificator);
        spinBoxSweep->setObjectName(QStringLiteral("spinBoxSweep"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spinBoxSweep->sizePolicy().hasHeightForWidth());
        spinBoxSweep->setSizePolicy(sizePolicy3);
        spinBoxSweep->setDecimals(3);
        spinBoxSweep->setMinimum(-89);
        spinBoxSweep->setMaximum(89);

        sweepLayout->addWidget(spinBoxSweep);

        widgetSweepDetails = new QWidget(wingModificator);
        widgetSweepDetails->setObjectName(QStringLiteral("widgetSweepDetails"));
        widgetSweepDetails->setEnabled(true);
        widgetSweepDetails->setMinimumSize(QSize(20, 0));
        horizontalLayout_5 = new QHBoxLayout(widgetSweepDetails);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelChord = new QLabel(widgetSweepDetails);
        labelChord->setObjectName(QStringLiteral("labelChord"));
        labelChord->setMinimumSize(QSize(80, 0));
        labelChord->setMaximumSize(QSize(80, 16777215));
        labelChord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelChord);

        spinBoxSweepChord = new QDoubleSpinBox(widgetSweepDetails);
        spinBoxSweepChord->setObjectName(QStringLiteral("spinBoxSweepChord"));
        spinBoxSweepChord->setDecimals(3);
        spinBoxSweepChord->setMaximum(1);
        spinBoxSweepChord->setSingleStep(0.01);

        horizontalLayout_5->addWidget(spinBoxSweepChord);

        labelMethod = new QLabel(widgetSweepDetails);
        labelMethod->setObjectName(QStringLiteral("labelMethod"));
        labelMethod->setMinimumSize(QSize(80, 0));
        labelMethod->setMaximumSize(QSize(80, 16777215));
        labelMethod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelMethod);

        comboBoxSweepMethod = new QComboBox(widgetSweepDetails);
        comboBoxSweepMethod->setObjectName(QStringLiteral("comboBoxSweepMethod"));

        horizontalLayout_5->addWidget(comboBoxSweepMethod);


        sweepLayout->addWidget(widgetSweepDetails);


        verticalLayout_4->addLayout(sweepLayout);

        dihedralLayout = new QHBoxLayout();
        dihedralLayout->setObjectName(QStringLiteral("dihedralLayout"));
        btnExpendDihedralDetails = new QPushButton(wingModificator);
        btnExpendDihedralDetails->setObjectName(QStringLiteral("btnExpendDihedralDetails"));
        btnExpendDihedralDetails->setMaximumSize(QSize(20, 16777215));

        dihedralLayout->addWidget(btnExpendDihedralDetails);

        labelDihedral = new QLabel(wingModificator);
        labelDihedral->setObjectName(QStringLiteral("labelDihedral"));
        sizePolicy2.setHeightForWidth(labelDihedral->sizePolicy().hasHeightForWidth());
        labelDihedral->setSizePolicy(sizePolicy2);
        labelDihedral->setMinimumSize(QSize(80, 0));
        labelDihedral->setMaximumSize(QSize(80, 16777215));

        dihedralLayout->addWidget(labelDihedral);

        spinBoxDihedral = new QDoubleSpinBox(wingModificator);
        spinBoxDihedral->setObjectName(QStringLiteral("spinBoxDihedral"));
        sizePolicy3.setHeightForWidth(spinBoxDihedral->sizePolicy().hasHeightForWidth());
        spinBoxDihedral->setSizePolicy(sizePolicy3);
        spinBoxDihedral->setDecimals(3);
        spinBoxDihedral->setMinimum(-89);
        spinBoxDihedral->setMaximum(89);

        dihedralLayout->addWidget(spinBoxDihedral);

        widgetDihedralDetails = new QWidget(wingModificator);
        widgetDihedralDetails->setObjectName(QStringLiteral("widgetDihedralDetails"));
        widgetDihedralDetails->setEnabled(true);
        widgetDihedralDetails->setMinimumSize(QSize(20, 0));
        horizontalLayout_6 = new QHBoxLayout(widgetDihedralDetails);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        labelDihedralChord = new QLabel(widgetDihedralDetails);
        labelDihedralChord->setObjectName(QStringLiteral("labelDihedralChord"));
        labelDihedralChord->setMinimumSize(QSize(80, 0));
        labelDihedralChord->setMaximumSize(QSize(80, 16777215));
        labelDihedralChord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(labelDihedralChord);

        spinBoxDihedralChord = new QDoubleSpinBox(widgetDihedralDetails);
        spinBoxDihedralChord->setObjectName(QStringLiteral("spinBoxDihedralChord"));
        spinBoxDihedralChord->setDecimals(3);
        spinBoxDihedralChord->setMaximum(1);
        spinBoxDihedralChord->setSingleStep(0.01);

        horizontalLayout_6->addWidget(spinBoxDihedralChord);


        dihedralLayout->addWidget(widgetDihedralDetails);


        verticalLayout_4->addLayout(dihedralLayout);

        areaLayout = new QHBoxLayout();
        areaLayout->setObjectName(QStringLiteral("areaLayout"));
        btnExpendAreaDetails = new QPushButton(wingModificator);
        btnExpendAreaDetails->setObjectName(QStringLiteral("btnExpendAreaDetails"));
        btnExpendAreaDetails->setMinimumSize(QSize(0, 0));
        btnExpendAreaDetails->setMaximumSize(QSize(20, 16777215));

        areaLayout->addWidget(btnExpendAreaDetails);

        labelArea = new QLabel(wingModificator);
        labelArea->setObjectName(QStringLiteral("labelArea"));
        labelArea->setMinimumSize(QSize(80, 0));
        labelArea->setMaximumSize(QSize(80, 16777215));

        areaLayout->addWidget(labelArea);

        checkBoxIsAreaConstant = new QCheckBox(wingModificator);
        checkBoxIsAreaConstant->setObjectName(QStringLiteral("checkBoxIsAreaConstant"));
        checkBoxIsAreaConstant->setMinimumSize(QSize(60, 0));
        checkBoxIsAreaConstant->setMaximumSize(QSize(60, 16777215));
        checkBoxIsAreaConstant->setLayoutDirection(Qt::RightToLeft);
        checkBoxIsAreaConstant->setTristate(false);

        areaLayout->addWidget(checkBoxIsAreaConstant);

        labelXY = new QLabel(wingModificator);
        labelXY->setObjectName(QStringLiteral("labelXY"));
        labelXY->setMaximumSize(QSize(20, 16777215));

        areaLayout->addWidget(labelXY);

        spinBoxAreaXY = new QDoubleSpinBox(wingModificator);
        spinBoxAreaXY->setObjectName(QStringLiteral("spinBoxAreaXY"));
        spinBoxAreaXY->setKeyboardTracking(true);
        spinBoxAreaXY->setDecimals(3);
        spinBoxAreaXY->setMinimum(0);
        spinBoxAreaXY->setMaximum(1e+6);

        areaLayout->addWidget(spinBoxAreaXY);

        widgetAreaDetails = new QWidget(wingModificator);
        widgetAreaDetails->setObjectName(QStringLiteral("widgetAreaDetails"));
        widgetAreaDetails->setEnabled(true);
        horizontalLayout_4 = new QHBoxLayout(widgetAreaDetails);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelXZ = new QLabel(widgetAreaDetails);
        labelXZ->setObjectName(QStringLiteral("labelXZ"));
        labelXZ->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(labelXZ);

        spinBoxAreaXZ = new QDoubleSpinBox(widgetAreaDetails);
        spinBoxAreaXZ->setObjectName(QStringLiteral("spinBoxAreaXZ"));
        spinBoxAreaXZ->setEnabled(true);
        spinBoxAreaXZ->setKeyboardTracking(true);
        spinBoxAreaXZ->setDecimals(3);
        spinBoxAreaXZ->setMaximum(1e+6);

        horizontalLayout_4->addWidget(spinBoxAreaXZ);

        labelYZ = new QLabel(widgetAreaDetails);
        labelYZ->setObjectName(QStringLiteral("labelYZ"));
        labelYZ->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(labelYZ);

        spinBoxAreaYZ = new QDoubleSpinBox(widgetAreaDetails);
        spinBoxAreaYZ->setObjectName(QStringLiteral("spinBoxAreaYZ"));
        spinBoxAreaYZ->setEnabled(true);
        spinBoxAreaYZ->setKeyboardTracking(true);
        spinBoxAreaYZ->setDecimals(3);
        spinBoxAreaYZ->setMaximum(1e+6);

        horizontalLayout_4->addWidget(spinBoxAreaYZ);

        labelT = new QLabel(widgetAreaDetails);
        labelT->setObjectName(QStringLiteral("labelT"));
        labelT->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(labelT);

        spinBoxAreaT = new QDoubleSpinBox(widgetAreaDetails);
        spinBoxAreaT->setObjectName(QStringLiteral("spinBoxAreaT"));
        spinBoxAreaT->setKeyboardTracking(true);
        spinBoxAreaT->setDecimals(3);
        spinBoxAreaT->setMaximum(1e+6);

        horizontalLayout_4->addWidget(spinBoxAreaT);


        areaLayout->addWidget(widgetAreaDetails);


        verticalLayout_4->addLayout(areaLayout);

        spanLayout = new QHBoxLayout();
        spanLayout->setObjectName(QStringLiteral("spanLayout"));
        horizontalSpacer = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        spanLayout->addItem(horizontalSpacer);

        labelSpan = new QLabel(wingModificator);
        labelSpan->setObjectName(QStringLiteral("labelSpan"));
        labelSpan->setMinimumSize(QSize(80, 0));
        labelSpan->setMaximumSize(QSize(80, 16777215));

        spanLayout->addWidget(labelSpan);

        checkBoxIsSpanConstant = new QCheckBox(wingModificator);
        checkBoxIsSpanConstant->setObjectName(QStringLiteral("checkBoxIsSpanConstant"));
        checkBoxIsSpanConstant->setMinimumSize(QSize(60, 0));
        checkBoxIsSpanConstant->setMaximumSize(QSize(60, 16777215));
        checkBoxIsSpanConstant->setLayoutDirection(Qt::RightToLeft);
        checkBoxIsSpanConstant->setTristate(false);

        spanLayout->addWidget(checkBoxIsSpanConstant);

        spinBoxSpan = new QDoubleSpinBox(wingModificator);
        spinBoxSpan->setObjectName(QStringLiteral("spinBoxSpan"));
        spinBoxSpan->setDecimals(3);
        spinBoxSpan->setMaximum(1e+6);

        spanLayout->addWidget(spinBoxSpan);


        verticalLayout_4->addLayout(spanLayout);

        aRLayout = new QHBoxLayout();
        aRLayout->setObjectName(QStringLiteral("aRLayout"));
        horizontalSpacer_2 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        aRLayout->addItem(horizontalSpacer_2);

        labelAR = new QLabel(wingModificator);
        labelAR->setObjectName(QStringLiteral("labelAR"));
        labelAR->setMinimumSize(QSize(80, 0));
        labelAR->setMaximumSize(QSize(80, 16777215));

        aRLayout->addWidget(labelAR);

        checkBoxIsARConstant = new QCheckBox(wingModificator);
        checkBoxIsARConstant->setObjectName(QStringLiteral("checkBoxIsARConstant"));
        checkBoxIsARConstant->setMinimumSize(QSize(60, 0));
        checkBoxIsARConstant->setMaximumSize(QSize(60, 16777215));
        checkBoxIsARConstant->setLayoutDirection(Qt::RightToLeft);
        checkBoxIsARConstant->setTristate(false);

        aRLayout->addWidget(checkBoxIsARConstant);

        spinBoxAR = new QDoubleSpinBox(wingModificator);
        spinBoxAR->setObjectName(QStringLiteral("spinBoxAR"));
        spinBoxAR->setDecimals(3);
        spinBoxAR->setMinimum(-1e+6);

        aRLayout->addWidget(spinBoxAR);


        verticalLayout_4->addLayout(aRLayout);

        aifoilLayout = new QHBoxLayout();
        aifoilLayout->setObjectName(QStringLiteral("aifoilLayout"));
        btnExpendAirfoilDetails = new QPushButton(wingModificator);
        btnExpendAirfoilDetails->setObjectName(QStringLiteral("btnExpendAirfoilDetails"));
        btnExpendAirfoilDetails->setMaximumSize(QSize(20, 16777215));

        aifoilLayout->addWidget(btnExpendAirfoilDetails);

        labelAirfoil = new QLabel(wingModificator);
        labelAirfoil->setObjectName(QStringLiteral("labelAirfoil"));
        labelAirfoil->setMinimumSize(QSize(80, 0));
        labelAirfoil->setMaximumSize(QSize(80, 16777215));

        aifoilLayout->addWidget(labelAirfoil);

        comboBoxAirfoil = new QComboBox(wingModificator);
        comboBoxAirfoil->setObjectName(QStringLiteral("comboBoxAirfoil"));

        aifoilLayout->addWidget(comboBoxAirfoil);

        widgetAirfoilDetails = new QWidget(wingModificator);
        widgetAirfoilDetails->setObjectName(QStringLiteral("widgetAirfoilDetails"));
        horizontalLayout_7 = new QHBoxLayout(widgetAirfoilDetails);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        btnAddAifoilToDB = new QPushButton(widgetAirfoilDetails);
        btnAddAifoilToDB->setObjectName(QStringLiteral("btnAddAifoilToDB"));

        horizontalLayout_7->addWidget(btnAddAifoilToDB);


        aifoilLayout->addWidget(widgetAirfoilDetails);


        verticalLayout_4->addLayout(aifoilLayout);

        standardizationLayout = new QHBoxLayout();
        standardizationLayout->setObjectName(QStringLiteral("standardizationLayout"));
        btnExpendStandardizationDetails = new QPushButton(wingModificator);
        btnExpendStandardizationDetails->setObjectName(QStringLiteral("btnExpendStandardizationDetails"));
        btnExpendStandardizationDetails->setMinimumSize(QSize(20, 0));
        btnExpendStandardizationDetails->setMaximumSize(QSize(20, 16777215));

        standardizationLayout->addWidget(btnExpendStandardizationDetails);

        labelStandardization = new QLabel(wingModificator);
        labelStandardization->setObjectName(QStringLiteral("labelStandardization"));
        labelStandardization->setMinimumSize(QSize(80, 0));
        labelStandardization->setMaximumSize(QSize(80, 16777215));

        standardizationLayout->addWidget(labelStandardization);

        comboBoxStdGlobal = new QComboBox(wingModificator);
        comboBoxStdGlobal->setObjectName(QStringLiteral("comboBoxStdGlobal"));

        standardizationLayout->addWidget(comboBoxStdGlobal);

        widgetStandardizationDetails = new QWidget(wingModificator);
        widgetStandardizationDetails->setObjectName(QStringLiteral("widgetStandardizationDetails"));
        horizontalLayout_8 = new QHBoxLayout(widgetStandardizationDetails);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        checkBoxStdAirfoils = new QCheckBox(widgetStandardizationDetails);
        checkBoxStdAirfoils->setObjectName(QStringLiteral("checkBoxStdAirfoils"));
        checkBoxStdAirfoils->setMinimumSize(QSize(80, 0));
        checkBoxStdAirfoils->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(checkBoxStdAirfoils);

        checkBoxStdSections = new QCheckBox(widgetStandardizationDetails);
        checkBoxStdSections->setObjectName(QStringLiteral("checkBoxStdSections"));
        checkBoxStdSections->setMinimumSize(QSize(80, 0));
        checkBoxStdSections->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(checkBoxStdSections);

        checkBoxStdPositionings = new QCheckBox(widgetStandardizationDetails);
        checkBoxStdPositionings->setObjectName(QStringLiteral("checkBoxStdPositionings"));
        checkBoxStdPositionings->setMinimumSize(QSize(80, 0));
        checkBoxStdPositionings->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(checkBoxStdPositionings);

        checkBoxStdAnchor = new QCheckBox(widgetStandardizationDetails);
        checkBoxStdAnchor->setObjectName(QStringLiteral("checkBoxStdAnchor"));
        checkBoxStdAnchor->setMinimumSize(QSize(80, 0));
        checkBoxStdAnchor->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_8->addWidget(checkBoxStdAnchor);


        standardizationLayout->addWidget(widgetStandardizationDetails);


        verticalLayout_4->addLayout(standardizationLayout);


        verticalLayout_2->addWidget(wingModificator);

        transforamtionModificator = new TIGLViewerTransformationWidget(dockWidgetContents);
        transforamtionModificator->setObjectName(QStringLiteral("transforamtionModificator"));
        verticalLayout_3 = new QVBoxLayout(transforamtionModificator);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        transformationLayout = new QVBoxLayout();
        transformationLayout->setObjectName(QStringLiteral("transformationLayout"));
        header = new QHBoxLayout();
        header->setObjectName(QStringLiteral("header"));
        label_5 = new QLabel(transforamtionModificator);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setMaximumSize(QSize(80, 16777215));

        header->addWidget(label_5);

        label_6 = new QLabel(transforamtionModificator);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        header->addWidget(label_6);

        label_7 = new QLabel(transforamtionModificator);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        header->addWidget(label_7);

        label_4 = new QLabel(transforamtionModificator);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        header->addWidget(label_4);


        transformationLayout->addLayout(header);

        scaling = new QHBoxLayout();
        scaling->setObjectName(QStringLiteral("scaling"));
        labelScaling = new QLabel(transforamtionModificator);
        labelScaling->setObjectName(QStringLiteral("labelScaling"));
        sizePolicy4.setHeightForWidth(labelScaling->sizePolicy().hasHeightForWidth());
        labelScaling->setSizePolicy(sizePolicy4);
        labelScaling->setMinimumSize(QSize(80, 0));
        labelScaling->setMaximumSize(QSize(80, 16777215));
        labelScaling->setBaseSize(QSize(0, 100));

        scaling->addWidget(labelScaling);

        spinBoxSX = new QDoubleSpinBox(transforamtionModificator);
        spinBoxSX->setObjectName(QStringLiteral("spinBoxSX"));
        spinBoxSX->setDecimals(3);
        spinBoxSX->setMinimum(0);
        spinBoxSX->setMaximum(10000);

        scaling->addWidget(spinBoxSX);

        spinBoxSY = new QDoubleSpinBox(transforamtionModificator);
        spinBoxSY->setObjectName(QStringLiteral("spinBoxSY"));
        spinBoxSY->setDecimals(3);
        spinBoxSY->setMinimum(0);
        spinBoxSY->setMaximum(10000);

        scaling->addWidget(spinBoxSY);

        spinBoxSZ = new QDoubleSpinBox(transforamtionModificator);
        spinBoxSZ->setObjectName(QStringLiteral("spinBoxSZ"));
        spinBoxSZ->setDecimals(3);
        spinBoxSZ->setMinimum(0);
        spinBoxSZ->setMaximum(10000);

        scaling->addWidget(spinBoxSZ);


        transformationLayout->addLayout(scaling);

        rotation = new QHBoxLayout();
        rotation->setObjectName(QStringLiteral("rotation"));
        labelRotation = new QLabel(transforamtionModificator);
        labelRotation->setObjectName(QStringLiteral("labelRotation"));
        sizePolicy4.setHeightForWidth(labelRotation->sizePolicy().hasHeightForWidth());
        labelRotation->setSizePolicy(sizePolicy4);
        labelRotation->setMinimumSize(QSize(80, 0));
        labelRotation->setMaximumSize(QSize(80, 16777215));
        labelRotation->setBaseSize(QSize(0, 100));

        rotation->addWidget(labelRotation);

        spinBoxRX = new QDoubleSpinBox(transforamtionModificator);
        spinBoxRX->setObjectName(QStringLiteral("spinBoxRX"));
        spinBoxRX->setDecimals(3);
        spinBoxRX->setMinimum(-10000);
        spinBoxRX->setMaximum(10000);

        rotation->addWidget(spinBoxRX);

        spinBoxRY = new QDoubleSpinBox(transforamtionModificator);
        spinBoxRY->setObjectName(QStringLiteral("spinBoxRY"));
        spinBoxRY->setDecimals(3);
        spinBoxRY->setMinimum(-10000);
        spinBoxRY->setMaximum(10000);

        rotation->addWidget(spinBoxRY);

        spinBoxRZ = new QDoubleSpinBox(transforamtionModificator);
        spinBoxRZ->setObjectName(QStringLiteral("spinBoxRZ"));
        spinBoxRZ->setDecimals(3);
        spinBoxRZ->setMinimum(-10000);
        spinBoxRZ->setMaximum(10000);

        rotation->addWidget(spinBoxRZ);


        transformationLayout->addLayout(rotation);

        translation = new QHBoxLayout();
        translation->setObjectName(QStringLiteral("translation"));
        labelTranslation = new QLabel(transforamtionModificator);
        labelTranslation->setObjectName(QStringLiteral("labelTranslation"));
        sizePolicy4.setHeightForWidth(labelTranslation->sizePolicy().hasHeightForWidth());
        labelTranslation->setSizePolicy(sizePolicy4);
        labelTranslation->setMinimumSize(QSize(80, 0));
        labelTranslation->setMaximumSize(QSize(80, 16777215));
        labelTranslation->setBaseSize(QSize(0, 100));

        translation->addWidget(labelTranslation);

        spinBoxTX = new QDoubleSpinBox(transforamtionModificator);
        spinBoxTX->setObjectName(QStringLiteral("spinBoxTX"));
        spinBoxTX->setDecimals(3);
        spinBoxTX->setMinimum(-10000);
        spinBoxTX->setMaximum(10000);

        translation->addWidget(spinBoxTX);

        spinBoxTY = new QDoubleSpinBox(transforamtionModificator);
        spinBoxTY->setObjectName(QStringLiteral("spinBoxTY"));
        sizePolicy3.setHeightForWidth(spinBoxTY->sizePolicy().hasHeightForWidth());
        spinBoxTY->setSizePolicy(sizePolicy3);
        spinBoxTY->setDecimals(3);
        spinBoxTY->setMinimum(-10000);
        spinBoxTY->setMaximum(10000);

        translation->addWidget(spinBoxTY);

        spinBoxTZ = new QDoubleSpinBox(transforamtionModificator);
        spinBoxTZ->setObjectName(QStringLiteral("spinBoxTZ"));
        spinBoxTZ->setDecimals(3);
        spinBoxTZ->setMinimum(-10000);
        spinBoxTZ->setMaximum(10000);

        translation->addWidget(spinBoxTZ);


        transformationLayout->addLayout(translation);


        verticalLayout_3->addLayout(transformationLayout);


        verticalLayout_2->addWidget(transforamtionModificator);

        positioningsModificator = new TIGLViewerPositioningsWidget(dockWidgetContents);
        positioningsModificator->setObjectName(QStringLiteral("positioningsModificator"));

        verticalLayout_2->addWidget(positioningsModificator);

        widgetApply = new QWidget(dockWidgetContents);
        widgetApply->setObjectName(QStringLiteral("widgetApply"));
        horizontalLayout_2 = new QHBoxLayout(widgetApply);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cancelButton = new QPushButton(widgetApply);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(0, 0));
        cancelButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(cancelButton);

        commitButton = new QPushButton(widgetApply);
        commitButton->setObjectName(QStringLiteral("commitButton"));

        horizontalLayout_2->addWidget(commitButton);


        verticalLayout_2->addWidget(widgetApply);

        creatorDockWidget->setWidget(dockWidgetContents);
        TIGLViewerWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), creatorDockWidget);

        menubar->addAction(fileMenu->menuAction());
        menubar->addAction(cpacsMenu->menuAction());
        menubar->addAction(viewMenu->menuAction());
        menubar->addAction(helpMenu->menuAction());
        fileMenu->addAction(newAction);
        fileMenu->addAction(openAction);
        fileMenu->addAction(recentFileMenu->menuAction());
        fileMenu->addAction(setBackgroundAction);
        fileMenu->addAction(openScriptAction);
        fileMenu->addSeparator();
        fileMenu->addAction(refreshAction);
        fileMenu->addSeparator();
        fileMenu->addAction(saveAction);
        fileMenu->addAction(saveScreenshotAction);
        fileMenu->addAction(tiglMenu->menuAction());
        fileMenu->addAction(closeAction);
        fileMenu->addSeparator();
        fileMenu->addAction(settingsAction);
        fileMenu->addAction(exitAction);
        tiglMenu->addAction(menuExport_to_IGES->menuAction());
        tiglMenu->addAction(menuExport_to_STEP->menuAction());
        tiglMenu->addAction(menuExport_to_BRep->menuAction());
        tiglMenu->addSeparator();
        tiglMenu->addAction(menuExport_to_VTK->menuAction());
        tiglMenu->addAction(menuExport_to_STL->menuAction());
        tiglMenu->addAction(menuExport_to_Collada->menuAction());
        menuExport_to_IGES->addAction(tiglExportIgesAction);
        menuExport_to_IGES->addAction(tiglExportFusedIgesAction);
        menuExport_to_STEP->addAction(tiglExportStepAction);
        menuExport_to_STEP->addAction(tiglExportFusedStepAction);
        menuExport_to_VTK->addAction(tiglExportMeshedWingVTK);
        menuExport_to_VTK->addAction(tiglExportMeshedWingVTKsimple);
        menuExport_to_VTK->addAction(tiglExportMeshedFuselageVTK);
        menuExport_to_VTK->addAction(tiglExportMeshedConfigVTKNoFuse);
        menuExport_to_VTK->addAction(tiglExportMeshedConfigVTK);
        menuExport_to_STL->addAction(tiglExportMeshedWingSTL);
        menuExport_to_STL->addAction(tiglExportMeshedFuselageSTL);
        menuExport_to_STL->addAction(tiglExportMeshedConfigSTL);
        menuExport_to_Collada->addAction(tiglExportWingColladaAction);
        menuExport_to_Collada->addAction(tiglExportFuselageColladaAction);
        menuExport_to_Collada->addAction(tiglExportConfigurationColladaAction);
        menuExport_to_BRep->addAction(tiglExportWingBRepAction);
        menuExport_to_BRep->addAction(tiglExportFuselageBRepAction);
        menuExport_to_BRep->addAction(tiglExportFusedConfigBRep);
        menuExport_to_BRep->addAction(tiglExportWingCurvesBRepAction);
        menuExport_to_BRep->addAction(tiglExportFuselageCurvesBRepAction);
        cpacsMenu->addAction(menuAircraft->menuAction());
        cpacsMenu->addAction(menuRotorcraft->menuAction());
        cpacsMenu->addAction(menuWings->menuAction());
        cpacsMenu->addAction(menuRotorBlades->menuAction());
        cpacsMenu->addAction(menuFuselages->menuAction());
        cpacsMenu->addAction(menuMisc_Geometry->menuAction());
        menuAircraft->addAction(showAllWingsAndFuselagesAction);
        menuAircraft->addAction(showAllWingsAndFuselagesSurfacePointsAction);
        menuAircraft->addAction(drawFusedAircraftAction);
        menuAircraft->addAction(showFusedAirplaneTriangulation);
        menuAircraft->addAction(drawIntersectionAction);
        menuAircraft->addAction(drawFarFieldAction);
        menuAircraft->addAction(drawSystemsAction);
        menuAircraft->addAction(drawComponentAction);
        menuWings->addAction(drawWingsAction);
        menuWings->addAction(drawFusedWingAction);
        menuWings->addAction(drawWingShellAction);
        menuWings->addAction(drawWingComponentSegmentAction);
        menuWings->addAction(drawWingStructureAction);
        menuWings->addAction(drawWingTriangulationAction);
        menuWings->addAction(drawWingProfilesAction);
        menuWings->addAction(drawWingGuideCurvesAction);
        menuWings->addSeparator();
        menuWings->addAction(drawWingSamplePointsAction);
        menuWings->addAction(drawWingOverlayCPACSProfilePointsAction);
        menuWings->addAction(drawWingCSPointAction);
        menuWings->addSeparator();
        menuWings->addAction(drawTEDAction);
        menuFuselages->addAction(drawFuselageAction);
        menuFuselages->addAction(drawFuselageProfilesAction);
        menuFuselages->addAction(drawFuselageGuideCurvesAction);
        menuFuselages->addAction(drawFuselageTriangulationAction);
        menuFuselages->addAction(drawFuselageSamplePointsAction);
        menuFuselages->addAction(drawFuselageSamplePointsAngleAction);
        menuFuselages->addAction(drawFusedFuselageAction);
        menuRotorcraft->addAction(drawRotorsAction);
        menuRotorcraft->addAction(drawRotorDisksAction);
        menuRotorcraft->addAction(showRotorPropertiesAction);
        menuRotorBlades->addAction(drawRotorBladesAction);
        menuRotorBlades->addAction(drawFusedRotorBladeAction);
        menuRotorBlades->addAction(drawRotorBladeShellAction);
        menuRotorBlades->addAction(drawRotorBladeComponentSegmentAction);
        menuRotorBlades->addAction(drawRotorBladeTriangulationAction);
        menuRotorBlades->addAction(drawRotorProfilesAction);
        menuRotorBlades->addAction(drawRotorBladeGuideCurvesAction);
        menuRotorBlades->addSeparator();
        menuRotorBlades->addAction(drawRotorBladeSamplePointsAction);
        menuRotorBlades->addAction(drawRotorBladeOverlayCPACSProfilePointsAction);
        menuRotorBlades->addAction(drawRotorBladeCSPointAction);
        menuMisc_Geometry->addAction(drawPointAction);
        menuMisc_Geometry->addAction(drawVectorAction);
        viewMenu->addAction(viewDisplayMenu->menuAction());
        viewMenu->addAction(viewActionsMenu->menuAction());
        viewMenu->addAction(gridMenu->menuAction());
        viewDisplayMenu->addAction(viewFrontAction);
        viewDisplayMenu->addAction(viewBackAction);
        viewDisplayMenu->addAction(viewTopAction);
        viewDisplayMenu->addAction(viewBottomAction);
        viewDisplayMenu->addAction(viewLeftAction);
        viewDisplayMenu->addAction(viewRightAction);
        viewDisplayMenu->addSeparator();
        viewDisplayMenu->addAction(viewAxoAction);
        viewDisplayMenu->addAction(viewGridAction);
        viewDisplayMenu->addSeparator();
        viewDisplayMenu->addAction(viewResetAction);
        viewDisplayMenu->addAction(viewZoomInAction);
        viewDisplayMenu->addAction(viewZoomOutAction);
        viewDisplayMenu->addSeparator();
        viewDisplayMenu->addAction(showConsoleAction);
        viewDisplayMenu->addAction(showCreatorAction);
        viewDisplayMenu->addAction(showWireframeAction);
        viewDisplayMenu->addAction(showReflectionLinesAction);
        viewActionsMenu->addAction(fitAction);
        viewActionsMenu->addAction(fitAllAction);
        viewActionsMenu->addAction(zoomAction);
        viewActionsMenu->addAction(panAction);
        viewActionsMenu->addAction(rotAction);
        gridMenu->addAction(gridOnAction);
        gridMenu->addSeparator();
        gridMenu->addAction(gridXYAction);
        gridMenu->addAction(gridXZAction);
        gridMenu->addAction(gridYZAction);
        gridMenu->addSeparator();
        gridMenu->addAction(gridRectAction);
        gridMenu->addAction(gridCircAction);
        helpMenu->addAction(aboutAction);
        helpMenu->addAction(aboutQtAction);
        toolBar->addAction(openAction);
        toolBar->addAction(saveAction);
        toolBar->addAction(closeAction);
        toolBar->addSeparator();
        toolBar->addAction(settingsAction);
        toolBar->addAction(refreshAction);
        toolBarView->addAction(selectAction);
        toolBarView->addAction(panAction);
        toolBarView->addAction(rotAction);
        toolBarView->addAction(zoomAction);
        toolBarView->addAction(fitAllAction);
        toolBarView->addSeparator();
        toolBarView->addAction(viewTopAction);
        toolBarView->addAction(viewLeftAction);
        toolBarView->addAction(viewFrontAction);
        toolBarView->addAction(viewAxoAction);
        toolBarView->addSeparator();
        toolBarView->addAction(showReflectionLinesAction);

        retranslateUi(TIGLViewerWindow);

        QMetaObject::connectSlotsByName(TIGLViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TIGLViewerWindow)
    {
        TIGLViewerWindow->setWindowTitle(QApplication::translate("TIGLViewerWindow", "MainWindow", Q_NULLPTR));
        newAction->setText(QApplication::translate("TIGLViewerWindow", "&New", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        newAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Create a new file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        newAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        openAction->setText(QApplication::translate("TIGLViewerWindow", "&Open...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        openAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Open an existing file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        openAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        openScriptAction->setText(QApplication::translate("TIGLViewerWindow", "Open Script", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        openScriptAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Open a script file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRecent_Files->setText(QApplication::translate("TIGLViewerWindow", "Recent Files", Q_NULLPTR));
        actionBlubb->setText(QApplication::translate("TIGLViewerWindow", "blubb", Q_NULLPTR));
        saveAction->setText(QApplication::translate("TIGLViewerWindow", "&Save", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Save the document to disk", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        saveAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        printAction->setText(QApplication::translate("TIGLViewerWindow", "&Print", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        printAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Print the document", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        printAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        setBackgroundAction->setText(QApplication::translate("TIGLViewerWindow", "&Load Background Image", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        setBackgroundAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Set Background Image from file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        setBackgroundAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+B", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        exitAction->setText(QApplication::translate("TIGLViewerWindow", "Exit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        exitAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Exit the application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        exitAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+Q", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        undoAction->setText(QApplication::translate("TIGLViewerWindow", "&Undo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        undoAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Undo the last operation", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        undoAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        redoAction->setText(QApplication::translate("TIGLViewerWindow", "&Redo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        redoAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Redo the last operation", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        redoAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        cutAction->setText(QApplication::translate("TIGLViewerWindow", "Cu&t", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cutAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Cut the current selection's contents to the clipboard", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        cutAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        copyAction->setText(QApplication::translate("TIGLViewerWindow", "&Copy", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        copyAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Copy the current selection's contents to the clipboard", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        copyAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pasteAction->setText(QApplication::translate("TIGLViewerWindow", "&Paste", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pasteAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Paste the clipboard's contents into the current selection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        pasteAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        showAllWingsAndFuselagesAction->setText(QApplication::translate("TIGLViewerWindow", "Show all Fuselages and Wings", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        showAllWingsAndFuselagesAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show all Fuselages and Wings", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        showAllWingsAndFuselagesAction->setWhatsThis(QApplication::translate("TIGLViewerWindow", "Show all Fuselages and Wings", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        showAllWingsAndFuselagesSurfacePointsAction->setText(QApplication::translate("TIGLViewerWindow", "Show sample Surface points on Fuselage and Wings", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showAllWingsAndFuselagesSurfacePointsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show sample Surface points on Fuselages and Wings", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        showAllWingsAndFuselagesSurfacePointsAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show sample Surface points on Fuselages and Wings", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawFusedAircraftAction->setText(QApplication::translate("TIGLViewerWindow", "Show the complete Aircraft fused (slow)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        drawFusedAircraftAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show the complete Aircraft fused", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawWingsAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawWingsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show a wing only", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawWingProfilesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing Profiles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawWingProfilesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the profiles of a wing", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawWingProfilesAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show the profiles of a wing", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawWingOverlayCPACSProfilePointsAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing overlay profile points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawWingOverlayCPACSProfilePointsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the points of a wing profile", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawWingTriangulationAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing triangulation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawWingTriangulationAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Shows the triangulation of a wing", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawWingSamplePointsAction->setText(QApplication::translate("TIGLViewerWindow", "Show Sample Wing points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawWingSamplePointsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show sample points on a wing", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawWingSamplePointsAction->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        drawFusedWingAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fused Wing", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFusedWingAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Shows a fused wing", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFusedWingAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Shows a fused wing", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawWingComponentSegmentAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing Component Segment", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        drawWingComponentSegmentAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Shows a wing component segment", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        drawWingComponentSegmentAction->setWhatsThis(QApplication::translate("TIGLViewerWindow", "Shows a wing component segment", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        drawRotorBladesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorBladesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show a rotor blade only", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawRotorProfilesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Profiles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorProfilesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the profiles of a rotor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawRotorProfilesAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show the profiles of a rotor", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawRotorBladeOverlayCPACSProfilePointsAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade overlay profile points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorBladeOverlayCPACSProfilePointsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the points of a rotor blade profile", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawRotorBladeTriangulationAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade triangulation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorBladeTriangulationAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Shows the triangulation of a rotor blade", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawRotorBladeSamplePointsAction->setText(QApplication::translate("TIGLViewerWindow", "Show Sample Rotor Blade points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorBladeSamplePointsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show sample points on a rotor blade", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawRotorBladeSamplePointsAction->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        drawFusedRotorBladeAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fused Rotor Blade", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFusedRotorBladeAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Shows a fused rotor blade", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFusedRotorBladeAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Shows a fused rotor blade", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawRotorBladeComponentSegmentAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade Component Segment", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        drawRotorBladeComponentSegmentAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Shows a rotor blade component segment", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        drawRotorBladeComponentSegmentAction->setWhatsThis(QApplication::translate("TIGLViewerWindow", "Shows a rotor blade component segment", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        drawRotorBladeCSPointAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade Component Segment Point", Q_NULLPTR));
        drawRotorBladeShellAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade Shells", Q_NULLPTR));
        drawAllRotorsWingsAndFuselagesAction->setText(QApplication::translate("TIGLViewerWindow", "Show all Rotors, Wings and Fuselages", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawAllRotorsWingsAndFuselagesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show all Rotors, Wings and Fuselages", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawRotorsAction->setText(QApplication::translate("TIGLViewerWindow", "Show a Rotor", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show only one rotor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawRotorDisksAction->setText(QApplication::translate("TIGLViewerWindow", "Show a Rotor Disk", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawRotorDisksAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show only one rotor disk", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        showRotorPropertiesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Properties...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showRotorPropertiesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show properties of a rotor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        drawFuselageAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fuselage", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFuselageAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Shows a fuselage", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFuselageAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Shows a fuselage.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawFuselageProfilesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fuselage Profiles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFuselageProfilesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the profiles of a fuselage", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFuselageProfilesAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show the profiles of a fuselage", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawFuselageTriangulationAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fuselage triangulation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFuselageTriangulationAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Shows the triangulation of a fuselage", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFuselageTriangulationAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Shows the triangulation of a fuselage.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawFuselageSamplePointsAction->setText(QApplication::translate("TIGLViewerWindow", "Show Sample Fuselage points", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFuselageSamplePointsAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show sample points on a fuselage", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFuselageSamplePointsAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show sample points on a fuselage.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawFuselageSamplePointsAngleAction->setText(QApplication::translate("TIGLViewerWindow", "Show Sample Fuselage point at Angle", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFuselageSamplePointsAngleAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show sample point on a fuselage at user defined angle and eta = 0.5", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFuselageSamplePointsAngleAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show sample point on a fuselage at user defined angle and eta = 0.5", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        drawFusedFuselageAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fused Fuselage", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawFusedFuselageAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show a fused fuselage", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        drawFusedFuselageAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show a fused fuselage.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportIgesAction->setText(QApplication::translate("TIGLViewerWindow", "Export Configuration", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportIgesAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export Model as IGES.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportFusedIgesAction->setText(QApplication::translate("TIGLViewerWindow", "Export Fused Configuration", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportFusedIgesAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export Fused Model as IGES.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportStepAction->setText(QApplication::translate("TIGLViewerWindow", "Export Configuration", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportStepAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export Model as STEP.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportStepWithMetaDataAction->setText(QApplication::translate("TIGLViewerWindow", "Export Model as STEP with CPACS MetaData", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportStepWithMetaDataAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export Model as STEP.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportMeshedWingSTL->setText(QApplication::translate("TIGLViewerWindow", "Export Wing", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportMeshedWingSTL->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export meshed Wing as STL.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportMeshedWingVTK->setText(QApplication::translate("TIGLViewerWindow", "Export Wing", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportMeshedWingVTK->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export meshed Wing as VTK.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportMeshedWingVTKsimple->setText(QApplication::translate("TIGLViewerWindow", "Export Wing (simple)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tiglExportMeshedWingVTKsimple->setToolTip(QApplication::translate("TIGLViewerWindow", "Export meshed Wing as simple VTK - no cpacs related export", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tiglExportMeshedWingVTKsimple->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export meshed Wing as simple VTK - no cpacs related export.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportMeshedFuselageVTK->setText(QApplication::translate("TIGLViewerWindow", "Export Fuselage", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportMeshedFuselageVTK->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export meshed Fuselage as VTK.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportMeshedFuselageVTKsimple->setText(QApplication::translate("TIGLViewerWindow", "Export Fuselage (simple)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tiglExportMeshedFuselageVTKsimple->setToolTip(QApplication::translate("TIGLViewerWindow", "Export meshed Fuselage as simple VTK - no cpacs realted export", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tiglExportMeshedFuselageVTKsimple->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export meshed Fuselage as simple VTK - no cpacs realted export.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        tiglExportMeshedFuselageSTL->setText(QApplication::translate("TIGLViewerWindow", "Export Fuselage", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tiglExportMeshedFuselageSTL->setStatusTip(QApplication::translate("TIGLViewerWindow", "Export meshed Fuselage as STL.", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        viewFrontAction->setText(QApplication::translate("TIGLViewerWindow", "Front", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewFrontAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View from front", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewFrontAction->setShortcut(QApplication::translate("TIGLViewerWindow", "1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewBackAction->setText(QApplication::translate("TIGLViewerWindow", "Back", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewBackAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View from the back", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewBackAction->setShortcut(QApplication::translate("TIGLViewerWindow", "2", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewTopAction->setText(QApplication::translate("TIGLViewerWindow", "Top", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewTopAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View from the top", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewTopAction->setShortcut(QApplication::translate("TIGLViewerWindow", "3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewBottomAction->setText(QApplication::translate("TIGLViewerWindow", "Bottom", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewBottomAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View from the bottom", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewBottomAction->setShortcut(QApplication::translate("TIGLViewerWindow", "4", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewLeftAction->setText(QApplication::translate("TIGLViewerWindow", "Left", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewLeftAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View from the left", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewLeftAction->setShortcut(QApplication::translate("TIGLViewerWindow", "5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewRightAction->setText(QApplication::translate("TIGLViewerWindow", "Right", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewRightAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View from the right", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewRightAction->setShortcut(QApplication::translate("TIGLViewerWindow", "6", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewAxoAction->setText(QApplication::translate("TIGLViewerWindow", "Axonometric", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewAxoAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Axonometric view", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewAxoAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewGridAction->setText(QApplication::translate("TIGLViewerWindow", "Grid", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewGridAction->setToolTip(QApplication::translate("TIGLViewerWindow", "View on the grid", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewResetAction->setText(QApplication::translate("TIGLViewerWindow", "Reset", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewResetAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Reset the view", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        viewZoomInAction->setText(QApplication::translate("TIGLViewerWindow", "Zoom in", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewZoomInAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Zoom in the view", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewZoomInAction->setShortcut(QApplication::translate("TIGLViewerWindow", "+", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        viewZoomOutAction->setText(QApplication::translate("TIGLViewerWindow", "Zoom out", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        viewZoomOutAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Zoom out the view", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        viewZoomOutAction->setShortcut(QApplication::translate("TIGLViewerWindow", "-", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        backgroundAction->setText(QApplication::translate("TIGLViewerWindow", "Change &Background", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        backgroundAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Change the background color", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        fitAction->setText(QApplication::translate("TIGLViewerWindow", "&Fit Window", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        fitAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Fit to window", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        fitAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        fitAllAction->setText(QApplication::translate("TIGLViewerWindow", "Fit &All", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        fitAllAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Fit contents to viewport", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        fitAllAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Alt+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        zoomAction->setText(QApplication::translate("TIGLViewerWindow", "&Zoom", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zoomAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Zoom in window", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        zoomAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        panAction->setText(QApplication::translate("TIGLViewerWindow", "&Translate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        panAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Window panning", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        panAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        rotAction->setText(QApplication::translate("TIGLViewerWindow", "&Rotate", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rotAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Rotate", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        rotAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        gridOnAction->setText(QApplication::translate("TIGLViewerWindow", "&Grid On", Q_NULLPTR));
        gridOnAction->setIconText(QApplication::translate("TIGLViewerWindow", "Show grid", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gridOnAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Turn the grid on/off", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        gridOnAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Turn the grid on/off", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        gridOnAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        gridOffAction->setText(QApplication::translate("TIGLViewerWindow", "Gri&d Off", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gridOffAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Turn the grid off", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        gridOffAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+J", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        gridXYAction->setText(QApplication::translate("TIGLViewerWindow", "XY Grid", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gridXYAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Grid on XY Plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        gridXZAction->setText(QApplication::translate("TIGLViewerWindow", "XZ Grid", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gridXZAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Grid on XZ Plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        gridXZAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+Y", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        gridYZAction->setText(QApplication::translate("TIGLViewerWindow", "YZ Grid", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gridYZAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Grid on YZ Plane", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        gridRectAction->setText(QApplication::translate("TIGLViewerWindow", "Rectangular", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        gridRectAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Rectangular grid", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        gridCircAction->setText(QApplication::translate("TIGLViewerWindow", "Polar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        gridCircAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Polar grid", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        aboutAction->setText(QApplication::translate("TIGLViewerWindow", "&About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        aboutAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the application's About box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        aboutQtAction->setText(QApplication::translate("TIGLViewerWindow", "About &Qt", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        aboutQtAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show the Qt library's About box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        showConsoleAction->setText(QApplication::translate("TIGLViewerWindow", "Console", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        showConsoleAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Alt+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        showScriptAction->setText(QApplication::translate("TIGLViewerWindow", "ScriptInput", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        showScriptAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Alt+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        showWireframeAction->setText(QApplication::translate("TIGLViewerWindow", "Wireframe", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        showWireframeAction->setStatusTip(QApplication::translate("TIGLViewerWindow", "Show wireframes", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        showWireframeAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+W", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        drawIntersectionAction->setText(QApplication::translate("TIGLViewerWindow", "Show Intersection Line", Q_NULLPTR));
        showFusedAirplaneTriangulation->setText(QApplication::translate("TIGLViewerWindow", "Show fused Airplane Triangulation (slow)", Q_NULLPTR));
        closeAction->setText(QApplication::translate("TIGLViewerWindow", "&Close Configuration", Q_NULLPTR));
        selectAction->setText(QApplication::translate("TIGLViewerWindow", "Select Components", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selectAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Select Components", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        settingsAction->setText(QApplication::translate("TIGLViewerWindow", "Settings", Q_NULLPTR));
        drawWingShellAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing Shells", Q_NULLPTR));
        tiglExportStructuredIgesAction->setText(QApplication::translate("TIGLViewerWindow", "Export Model as structed IGES", Q_NULLPTR));
        tiglExportStructuredIgesAction->setIconText(QApplication::translate("TIGLViewerWindow", "Export Model as IGES with CPACS metadata", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tiglExportStructuredIgesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Export Model as IGES with CPACS metadata", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        tiglExportWingColladaAction->setText(QApplication::translate("TIGLViewerWindow", "Export Wing", Q_NULLPTR));
        tiglExportFuselageColladaAction->setText(QApplication::translate("TIGLViewerWindow", "Export Fuselage", Q_NULLPTR));
        drawWingCSPointAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing Component Segment Point", Q_NULLPTR));
        tiglExportMeshedConfigVTK->setText(QApplication::translate("TIGLViewerWindow", "Export fused Configuration (slow)", Q_NULLPTR));
        tiglExportMeshedConfigVTKNoFuse->setText(QApplication::translate("TIGLViewerWindow", "Export Configuration (not fused)", Q_NULLPTR));
        drawFarFieldAction->setText(QApplication::translate("TIGLViewerWindow", "Draw Far Field", Q_NULLPTR));
        tiglExportFusedStepAction->setText(QApplication::translate("TIGLViewerWindow", "Export fused/trimmed Configuration", Q_NULLPTR));
        tiglExportWingBRepAction->setText(QApplication::translate("TIGLViewerWindow", "Export Wing", Q_NULLPTR));
        tiglExportFuselageBRepAction->setText(QApplication::translate("TIGLViewerWindow", "Export Fuselage", Q_NULLPTR));
        tiglExportFusedConfigBRep->setText(QApplication::translate("TIGLViewerWindow", "Export Fused Configuration (slow)", Q_NULLPTR));
        drawWingGuideCurvesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing Guide Curves", Q_NULLPTR));
        drawRotorBladeGuideCurvesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Rotor Blade Guide Curves", Q_NULLPTR));
        drawFuselageGuideCurvesAction->setText(QApplication::translate("TIGLViewerWindow", "Show Fuselage Guide Curves", Q_NULLPTR));
        tiglExportWingCurvesBRepAction->setText(QApplication::translate("TIGLViewerWindow", "Export Wing Curves", Q_NULLPTR));
        tiglExportFuselageCurvesBRepAction->setText(QApplication::translate("TIGLViewerWindow", "Export Fuselage Curves", Q_NULLPTR));
        actionCreate_Screenshot->setText(QApplication::translate("TIGLViewerWindow", "Create Screenshot", Q_NULLPTR));
        saveScreenshotAction->setText(QApplication::translate("TIGLViewerWindow", "Save Screenshot", Q_NULLPTR));
        tiglExportConfigurationColladaAction->setText(QApplication::translate("TIGLViewerWindow", "Export Configuration", Q_NULLPTR));
        drawPointAction->setText(QApplication::translate("TIGLViewerWindow", "Draw Point", Q_NULLPTR));
        drawVectorAction->setText(QApplication::translate("TIGLViewerWindow", "Draw Vector", Q_NULLPTR));
        drawSystemsAction->setText(QApplication::translate("TIGLViewerWindow", "Draw Systems", Q_NULLPTR));
        drawWingStructureAction->setText(QApplication::translate("TIGLViewerWindow", "Show Wing Structure", Q_NULLPTR));
        tiglExportMeshedConfigSTL->setText(QApplication::translate("TIGLViewerWindow", "Export Configuration", Q_NULLPTR));
        showReflectionLinesAction->setText(QApplication::translate("TIGLViewerWindow", "Reflection lines", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showReflectionLinesAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show reflection lines (zebra plot)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        showReflectionLinesAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Alt+R", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        drawComponentAction->setText(QApplication::translate("TIGLViewerWindow", "Draw any Component", Q_NULLPTR));
        selectAllAction->setText(QApplication::translate("TIGLViewerWindow", "Select all", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        selectAllAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        refreshAction->setText(QApplication::translate("TIGLViewerWindow", "Refresh", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        refreshAction->setShortcut(QApplication::translate("TIGLViewerWindow", "F5", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        drawTEDAction->setText(QApplication::translate("TIGLViewerWindow", "Show TED", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        drawTEDAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show Trailing Edge Device", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        drawTEDAction->setShortcut(QApplication::translate("TIGLViewerWindow", "J", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        showCreatorAction->setText(QApplication::translate("TIGLViewerWindow", "Creator", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        showCreatorAction->setToolTip(QApplication::translate("TIGLViewerWindow", "Show Creator Interface", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        showCreatorAction->setShortcut(QApplication::translate("TIGLViewerWindow", "Alt+M", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        fileMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&File", Q_NULLPTR));
        recentFileMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&Recent Files", Q_NULLPTR));
        tiglMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&CPACS Export", Q_NULLPTR));
        menuExport_to_IGES->setTitle(QApplication::translate("TIGLViewerWindow", "IGES", Q_NULLPTR));
        menuExport_to_STEP->setTitle(QApplication::translate("TIGLViewerWindow", "STEP", Q_NULLPTR));
        menuExport_to_VTK->setTitle(QApplication::translate("TIGLViewerWindow", "VTK", Q_NULLPTR));
        menuExport_to_STL->setTitle(QApplication::translate("TIGLViewerWindow", "STL", Q_NULLPTR));
        menuExport_to_Collada->setTitle(QApplication::translate("TIGLViewerWindow", "Collada", Q_NULLPTR));
        menuExport_to_BRep->setTitle(QApplication::translate("TIGLViewerWindow", "BRep", Q_NULLPTR));
        cpacsMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&Draw", Q_NULLPTR));
        menuAircraft->setTitle(QApplication::translate("TIGLViewerWindow", "Aircraft", Q_NULLPTR));
        menuWings->setTitle(QApplication::translate("TIGLViewerWindow", "Wings", Q_NULLPTR));
        menuFuselages->setTitle(QApplication::translate("TIGLViewerWindow", "Fuselages", Q_NULLPTR));
        menuRotorcraft->setTitle(QApplication::translate("TIGLViewerWindow", "Rotorcraft", Q_NULLPTR));
        menuRotorBlades->setTitle(QApplication::translate("TIGLViewerWindow", "Rotor blades", Q_NULLPTR));
        menuMisc_Geometry->setTitle(QApplication::translate("TIGLViewerWindow", "Misc Geometry", Q_NULLPTR));
        viewMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&View", Q_NULLPTR));
        viewDisplayMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&Display", Q_NULLPTR));
        viewActionsMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&Actions", Q_NULLPTR));
        gridMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&Grid", Q_NULLPTR));
        helpMenu->setTitle(QApplication::translate("TIGLViewerWindow", "&Help", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("TIGLViewerWindow", "File", Q_NULLPTR));
        toolBarView->setWindowTitle(QApplication::translate("TIGLViewerWindow", "Views", Q_NULLPTR));
        consoleDockWidget->setWindowTitle(QApplication::translate("TIGLViewerWindow", "TiGL Console", Q_NULLPTR));
        labelAnchor->setText(QApplication::translate("TIGLViewerWindow", "Anchor", Q_NULLPTR));
        label_2->setText(QApplication::translate("TIGLViewerWindow", "X:", Q_NULLPTR));
        label_3->setText(QApplication::translate("TIGLViewerWindow", "Y:", Q_NULLPTR));
        label_8->setText(QApplication::translate("TIGLViewerWindow", "Z:", Q_NULLPTR));
        labelOrientation->setText(QApplication::translate("TIGLViewerWindow", "Orientation", Q_NULLPTR));
        labelSymmetry->setText(QApplication::translate("TIGLViewerWindow", "Symmetry", Q_NULLPTR));
        btnExpendSweepDetails->setText(QApplication::translate("TIGLViewerWindow", "+", Q_NULLPTR));
        labelSweep->setText(QApplication::translate("TIGLViewerWindow", "Sweep", Q_NULLPTR));
        labelChord->setText(QApplication::translate("TIGLViewerWindow", "Chord %", Q_NULLPTR));
        labelMethod->setText(QApplication::translate("TIGLViewerWindow", "Method", Q_NULLPTR));
        btnExpendDihedralDetails->setText(QApplication::translate("TIGLViewerWindow", "+", Q_NULLPTR));
        labelDihedral->setText(QApplication::translate("TIGLViewerWindow", "Dihedral", Q_NULLPTR));
        labelDihedralChord->setText(QApplication::translate("TIGLViewerWindow", "Chord %", Q_NULLPTR));
        btnExpendAreaDetails->setText(QApplication::translate("TIGLViewerWindow", "+", Q_NULLPTR));
        labelArea->setText(QApplication::translate("TIGLViewerWindow", "Area", Q_NULLPTR));
        checkBoxIsAreaConstant->setText(QApplication::translate("TIGLViewerWindow", "Const", Q_NULLPTR));
        labelXY->setText(QApplication::translate("TIGLViewerWindow", "XY:", Q_NULLPTR));
        labelXZ->setText(QApplication::translate("TIGLViewerWindow", "XZ:", Q_NULLPTR));
        labelYZ->setText(QApplication::translate("TIGLViewerWindow", "YZ:", Q_NULLPTR));
        labelT->setText(QApplication::translate("TIGLViewerWindow", "T:", Q_NULLPTR));
        labelSpan->setText(QApplication::translate("TIGLViewerWindow", "Span", Q_NULLPTR));
        checkBoxIsSpanConstant->setText(QApplication::translate("TIGLViewerWindow", "Const", Q_NULLPTR));
        labelAR->setText(QApplication::translate("TIGLViewerWindow", "AR", Q_NULLPTR));
        checkBoxIsARConstant->setText(QApplication::translate("TIGLViewerWindow", "Const", Q_NULLPTR));
        btnExpendAirfoilDetails->setText(QApplication::translate("TIGLViewerWindow", "+", Q_NULLPTR));
        labelAirfoil->setText(QApplication::translate("TIGLViewerWindow", "Airfoils", Q_NULLPTR));
        btnAddAifoilToDB->setText(QApplication::translate("TIGLViewerWindow", "Add an airfoil in DB", Q_NULLPTR));
        btnExpendStandardizationDetails->setText(QApplication::translate("TIGLViewerWindow", "+", Q_NULLPTR));
        labelStandardization->setText(QApplication::translate("TIGLViewerWindow", "Creator Std.", Q_NULLPTR));
        checkBoxStdAirfoils->setText(QApplication::translate("TIGLViewerWindow", "Airfoils", Q_NULLPTR));
        checkBoxStdSections->setText(QApplication::translate("TIGLViewerWindow", "Sections", Q_NULLPTR));
        checkBoxStdPositionings->setText(QApplication::translate("TIGLViewerWindow", "Positions", Q_NULLPTR));
        checkBoxStdAnchor->setText(QApplication::translate("TIGLViewerWindow", "Anchor", Q_NULLPTR));
        label_5->setText(QApplication::translate("TIGLViewerWindow", "TRANSFORMATION", Q_NULLPTR));
        label_6->setText(QApplication::translate("TIGLViewerWindow", "X", Q_NULLPTR));
        label_7->setText(QApplication::translate("TIGLViewerWindow", "Y", Q_NULLPTR));
        label_4->setText(QApplication::translate("TIGLViewerWindow", "Z", Q_NULLPTR));
        labelScaling->setText(QApplication::translate("TIGLViewerWindow", "Scaling:", Q_NULLPTR));
        labelRotation->setText(QApplication::translate("TIGLViewerWindow", "Rotation:", Q_NULLPTR));
        labelTranslation->setText(QApplication::translate("TIGLViewerWindow", "Translation:", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("TIGLViewerWindow", "Cancel", Q_NULLPTR));
        commitButton->setText(QApplication::translate("TIGLViewerWindow", "Commit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TIGLViewerWindow: public Ui_TIGLViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERWINDOW_H
