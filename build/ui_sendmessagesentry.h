/********************************************************************************
** Form generated from reading UI file 'sendmessagesentry.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMESSAGESENTRY_H
#define UI_SENDMESSAGESENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include "qvalidatedlineedit.h"
#include "qvalidatedtextedit.h"

QT_BEGIN_NAMESPACE

class Ui_SendMessagesEntry
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *sendToLayout;
    QValidatedLineEdit *sendTo;
    QToolButton *addressBookButton;
    QToolButton *pasteButton;
    QToolButton *deleteButton;
    QLabel *messageLabel;
    QLabel *label_2;
    QValidatedTextEdit *messageText;
    QValidatedLineEdit *addAsLabel;
    QLabel *label_4;
    QLabel *publicKeyLabel;
    QValidatedLineEdit *publicKey;

    void setupUi(QFrame *SendMessagesEntry)
    {
        if (SendMessagesEntry->objectName().isEmpty())
            SendMessagesEntry->setObjectName(QStringLiteral("SendMessagesEntry"));
        SendMessagesEntry->resize(729, 236);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        SendMessagesEntry->setPalette(palette);
        SendMessagesEntry->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        SendMessagesEntry->setFrameShape(QFrame::StyledPanel);
        SendMessagesEntry->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(SendMessagesEntry);
        gridLayout->setSpacing(12);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sendToLayout = new QHBoxLayout();
        sendToLayout->setSpacing(0);
        sendToLayout->setObjectName(QStringLiteral("sendToLayout"));
        sendTo = new QValidatedLineEdit(SendMessagesEntry);
        sendTo->setObjectName(QStringLiteral("sendTo"));
        sendTo->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        sendTo->setMaxLength(34);

        sendToLayout->addWidget(sendTo);

        addressBookButton = new QToolButton(SendMessagesEntry);
        addressBookButton->setObjectName(QStringLiteral("addressBookButton"));
        addressBookButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/address-book"), QSize(), QIcon::Normal, QIcon::Off);
        addressBookButton->setIcon(icon);

        sendToLayout->addWidget(addressBookButton);

        pasteButton = new QToolButton(SendMessagesEntry);
        pasteButton->setObjectName(QStringLiteral("pasteButton"));
        pasteButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/editpaste"), QSize(), QIcon::Normal, QIcon::Off);
        pasteButton->setIcon(icon1);

        sendToLayout->addWidget(pasteButton);

        deleteButton = new QToolButton(SendMessagesEntry);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);

        sendToLayout->addWidget(deleteButton);


        gridLayout->addLayout(sendToLayout, 3, 2, 1, 1);

        messageLabel = new QLabel(SendMessagesEntry);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        messageLabel->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(messageLabel, 6, 0, 1, 1);

        label_2 = new QLabel(SendMessagesEntry);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        messageText = new QValidatedTextEdit(SendMessagesEntry);
        messageText->setObjectName(QStringLiteral("messageText"));
        messageText->setMouseTracking(true);
        messageText->setFocusPolicy(Qt::WheelFocus);
        messageText->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        messageText->setTabChangesFocus(false);

        gridLayout->addWidget(messageText, 6, 2, 1, 1);

        addAsLabel = new QValidatedLineEdit(SendMessagesEntry);
        addAsLabel->setObjectName(QStringLiteral("addAsLabel"));
        addAsLabel->setEnabled(true);
        addAsLabel->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));

        gridLayout->addWidget(addAsLabel, 4, 2, 1, 1);

        label_4 = new QLabel(SendMessagesEntry);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        publicKeyLabel = new QLabel(SendMessagesEntry);
        publicKeyLabel->setObjectName(QStringLiteral("publicKeyLabel"));
        publicKeyLabel->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(publicKeyLabel, 5, 0, 1, 1);

        publicKey = new QValidatedLineEdit(SendMessagesEntry);
        publicKey->setObjectName(QStringLiteral("publicKey"));
        publicKey->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));

        gridLayout->addWidget(publicKey, 5, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        messageLabel->setBuddy(messageText);
        label_2->setBuddy(sendTo);
        label_4->setBuddy(addAsLabel);
        publicKeyLabel->setBuddy(publicKey);
#endif // QT_NO_SHORTCUT

        retranslateUi(SendMessagesEntry);

        QMetaObject::connectSlotsByName(SendMessagesEntry);
    } // setupUi

    void retranslateUi(QFrame *SendMessagesEntry)
    {
        SendMessagesEntry->setWindowTitle(QApplication::translate("SendMessagesEntry", "Form", 0));
#ifndef QT_NO_TOOLTIP
        sendTo->setToolTip(QApplication::translate("SendMessagesEntry", "The address to send the payment to  (e.g. D6f2HnKGapfyWv9RqLXTvJV8qjDvRCqyLK)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressBookButton->setToolTip(QApplication::translate("SendMessagesEntry", "Choose address from address book", 0));
#endif // QT_NO_TOOLTIP
        addressBookButton->setText(QString());
        addressBookButton->setShortcut(QApplication::translate("SendMessagesEntry", "Alt+A", 0));
#ifndef QT_NO_TOOLTIP
        pasteButton->setToolTip(QApplication::translate("SendMessagesEntry", "Paste address from clipboard", 0));
#endif // QT_NO_TOOLTIP
        pasteButton->setText(QString());
        pasteButton->setShortcut(QApplication::translate("SendMessagesEntry", "Alt+P", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("SendMessagesEntry", "Remove this recipient", 0));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
        messageLabel->setText(QApplication::translate("SendMessagesEntry", "&Message:", 0));
        label_2->setText(QApplication::translate("SendMessagesEntry", "Send &To:", 0));
#ifndef QT_NO_TOOLTIP
        addAsLabel->setToolTip(QApplication::translate("SendMessagesEntry", "Enter a label for this address to add it to your address book", 0));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("SendMessagesEntry", "&Label:", 0));
        publicKeyLabel->setText(QApplication::translate("SendMessagesEntry", "&Public Key:", 0));
    } // retranslateUi

};

namespace Ui {
    class SendMessagesEntry: public Ui_SendMessagesEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMESSAGESENTRY_H
