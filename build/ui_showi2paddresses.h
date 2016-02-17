/********************************************************************************
** Form generated from reading UI file 'showi2paddresses.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWI2PADDRESSES_H
#define UI_SHOWI2PADDRESSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowI2PAddresses
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_3;
    QTextEdit *privText;
    QLabel *label_4;
    QPlainTextEdit *pubText;
    QLabel *label_5;
    QLineEdit *b32Line;
    QHBoxLayout *horizontalLayout;
    QPushButton *privButton;
    QPushButton *pubButton;
    QPushButton *b32Button;

    void setupUi(QDialog *ShowI2PAddresses)
    {
        if (ShowI2PAddresses->objectName().isEmpty())
            ShowI2PAddresses->setObjectName(QStringLiteral("ShowI2PAddresses"));
        ShowI2PAddresses->resize(640, 450);
        ShowI2PAddresses->setMinimumSize(QSize(640, 450));
        ShowI2PAddresses->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(ShowI2PAddresses);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ShowI2PAddresses);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        label_3 = new QLabel(ShowI2PAddresses);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setWordWrap(true);

        verticalLayout->addWidget(label_3);

        privText = new QTextEdit(ShowI2PAddresses);
        privText->setObjectName(QStringLiteral("privText"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(privText->sizePolicy().hasHeightForWidth());
        privText->setSizePolicy(sizePolicy);
        privText->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        privText->setReadOnly(true);

        verticalLayout->addWidget(privText);

        label_4 = new QLabel(ShowI2PAddresses);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        pubText = new QPlainTextEdit(ShowI2PAddresses);
        pubText->setObjectName(QStringLiteral("pubText"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(pubText->sizePolicy().hasHeightForWidth());
        pubText->setSizePolicy(sizePolicy1);
        pubText->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        pubText->setReadOnly(true);

        verticalLayout->addWidget(pubText);

        label_5 = new QLabel(ShowI2PAddresses);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        b32Line = new QLineEdit(ShowI2PAddresses);
        b32Line->setObjectName(QStringLiteral("b32Line"));
        b32Line->setMouseTracking(false);
        b32Line->setAcceptDrops(false);
        b32Line->setReadOnly(true);

        verticalLayout->addWidget(b32Line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        privButton = new QPushButton(ShowI2PAddresses);
        privButton->setObjectName(QStringLiteral("privButton"));
        privButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));

        horizontalLayout->addWidget(privButton);

        pubButton = new QPushButton(ShowI2PAddresses);
        pubButton->setObjectName(QStringLiteral("pubButton"));
        pubButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));

        horizontalLayout->addWidget(pubButton);

        b32Button = new QPushButton(ShowI2PAddresses);
        b32Button->setObjectName(QStringLiteral("b32Button"));
        b32Button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));

        horizontalLayout->addWidget(b32Button);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(privText, pubText);
        QWidget::setTabOrder(pubText, b32Line);
        QWidget::setTabOrder(b32Line, privButton);
        QWidget::setTabOrder(privButton, pubButton);
        QWidget::setTabOrder(pubButton, b32Button);

        retranslateUi(ShowI2PAddresses);

        QMetaObject::connectSlotsByName(ShowI2PAddresses);
    } // setupUi

    void retranslateUi(QDialog *ShowI2PAddresses)
    {
        ShowI2PAddresses->setWindowTitle(QApplication::translate("ShowI2PAddresses", "Dialog", 0));
        label->setText(QApplication::translate("ShowI2PAddresses", "If you want to use a permanent I2P-address you have to set a 'mydestination' option in the configuration file:", 0));
        label_3->setText(QApplication::translate("ShowI2PAddresses", "Ready to save parameter (If you want to use this address save this text in the configuration file and keep it secret):", 0));
        label_4->setText(QApplication::translate("ShowI2PAddresses", "Address (you can publish it):", 0));
        label_5->setText(QApplication::translate("ShowI2PAddresses", "Short base32-address:", 0));
        privButton->setText(QApplication::translate("ShowI2PAddresses", "Copy \"mydestination\" parameter\n"
"to the clipboard", 0));
        pubButton->setText(QApplication::translate("ShowI2PAddresses", "Copy public address\n"
"to the clipboard", 0));
        b32Button->setText(QApplication::translate("ShowI2PAddresses", "Copy b32-address\n"
"to the clipboard", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowI2PAddresses: public Ui_ShowI2PAddresses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWI2PADDRESSES_H
