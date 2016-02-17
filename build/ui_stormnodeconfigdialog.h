/********************************************************************************
** Form generated from reading UI file 'stormnodeconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORMNODECONFIGDIALOG_H
#define UI_STORMNODECONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StormNodeConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *detailText;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StormNodeConfigDialog)
    {
        if (StormNodeConfigDialog->objectName().isEmpty())
            StormNodeConfigDialog->setObjectName(QStringLiteral("StormNodeConfigDialog"));
        StormNodeConfigDialog->resize(620, 250);
        StormNodeConfigDialog->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(StormNodeConfigDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        detailText = new QTextEdit(StormNodeConfigDialog);
        detailText->setObjectName(QStringLiteral("detailText"));
        detailText->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        detailText->setReadOnly(true);

        verticalLayout->addWidget(detailText);

        buttonBox = new QDialogButtonBox(StormNodeConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(StormNodeConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StormNodeConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StormNodeConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StormNodeConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *StormNodeConfigDialog)
    {
        StormNodeConfigDialog->setWindowTitle(QApplication::translate("StormNodeConfigDialog", "Stormnode Configuration Template", 0));
#ifndef QT_NO_TOOLTIP
        detailText->setToolTip(QApplication::translate("StormNodeConfigDialog", "<html><head/><body><p>This pane shows an example darksilk.conf template with the necessary Stormnode settings.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class StormNodeConfigDialog: public Ui_StormNodeConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORMNODECONFIGDIALOG_H
