/********************************************************************************
** Form generated from reading UI file 'TIGLViewerErrorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIGLVIEWERERRORDIALOG_H
#define UI_TIGLVIEWERERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TIGLViewerErrorDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *iconLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLabel *errorMessageLabel;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *logBrowser;

    void setupUi(QDialog *TIGLViewerErrorDialog)
    {
        if (TIGLViewerErrorDialog->objectName().isEmpty())
            TIGLViewerErrorDialog->setObjectName(QStringLiteral("TIGLViewerErrorDialog"));
        TIGLViewerErrorDialog->setWindowModality(Qt::WindowModal);
        TIGLViewerErrorDialog->resize(500, 363);
        TIGLViewerErrorDialog->setMinimumSize(QSize(400, 0));
        TIGLViewerErrorDialog->setModal(true);
        verticalLayout_3 = new QVBoxLayout(TIGLViewerErrorDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        iconLabel = new QLabel(TIGLViewerErrorDialog);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));
        iconLabel->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iconLabel->sizePolicy().hasHeightForWidth());
        iconLabel->setSizePolicy(sizePolicy);
        iconLabel->setPixmap(QPixmap(QString::fromUtf8(":/gfx/error.png")));
        iconLabel->setScaledContents(false);
        iconLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(iconLabel);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        errorMessageLabel = new QLabel(TIGLViewerErrorDialog);
        errorMessageLabel->setObjectName(QStringLiteral("errorMessageLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(errorMessageLabel->sizePolicy().hasHeightForWidth());
        errorMessageLabel->setSizePolicy(sizePolicy1);
        errorMessageLabel->setMinimumSize(QSize(300, 0));
        errorMessageLabel->setTextFormat(Qt::RichText);
        errorMessageLabel->setScaledContents(false);
        errorMessageLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        errorMessageLabel->setWordWrap(true);
        errorMessageLabel->setMargin(0);

        horizontalLayout->addWidget(errorMessageLabel);


        verticalLayout_3->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(TIGLViewerErrorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_3->addWidget(buttonBox);

        groupBox = new QGroupBox(TIGLViewerErrorDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        logBrowser = new QTextBrowser(groupBox);
        logBrowser->setObjectName(QStringLiteral("logBrowser"));
        logBrowser->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(logBrowser);


        verticalLayout_3->addWidget(groupBox);


        retranslateUi(TIGLViewerErrorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TIGLViewerErrorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TIGLViewerErrorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TIGLViewerErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *TIGLViewerErrorDialog)
    {
        TIGLViewerErrorDialog->setWindowTitle(QApplication::translate("TIGLViewerErrorDialog", "Error", Q_NULLPTR));
        iconLabel->setText(QString());
        errorMessageLabel->setText(QApplication::translate("TIGLViewerErrorDialog", "TextLabel TextLabel TextLabel TextLabel TextLabel TextLabel asdfadsf asdf sdaf asfd dasfaf sadf fa asfd a TextLabel  fdas f adf asdf f dsafaf asfsd adf aTextLabel ", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TIGLViewerErrorDialog", "Error log", Q_NULLPTR));
        logBrowser->setHtml(QApplication::translate("TIGLViewerErrorDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TIGLViewerErrorDialog: public Ui_TIGLViewerErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIGLVIEWERERRORDIALOG_H
