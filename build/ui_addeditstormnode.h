/********************************************************************************
** Form generated from reading UI file 'addeditstormnode.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEDITSTORMNODE_H
#define UI_ADDEDITSTORMNODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEditStormNode
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *aliasLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_Buttons;
    QSpacerItem *horizontalSpacer_1;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddEditStormNode)
    {
        if (AddEditStormNode->objectName().isEmpty())
            AddEditStormNode->setObjectName(QStringLiteral("AddEditStormNode"));
        AddEditStormNode->resize(540, 241);
        AddEditStormNode->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        AddEditStormNode->setModal(true);
        verticalLayout = new QVBoxLayout(AddEditStormNode);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        label_3 = new QLabel(AddEditStormNode);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setWordWrap(true);

        verticalLayout_2->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(AddEditStormNode);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        aliasLineEdit = new QLineEdit(AddEditStormNode);
        aliasLineEdit->setObjectName(QStringLiteral("aliasLineEdit"));
        aliasLineEdit->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));

        horizontalLayout->addWidget(aliasLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(AddEditStormNode);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        addressLineEdit = new QLineEdit(AddEditStormNode);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));
        addressLineEdit->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));

        horizontalLayout_2->addWidget(addressLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);

        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName(QStringLiteral("horizontalLayout_Buttons"));
        horizontalSpacer_1 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_1);

        statusLabel = new QLabel(AddEditStormNode);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        statusLabel->setTextFormat(Qt::PlainText);
        statusLabel->setWordWrap(true);

        horizontalLayout_Buttons->addWidget(statusLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);

        okButton = new QPushButton(AddEditStormNode);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));

        horizontalLayout_Buttons->addWidget(okButton);

        cancelButton = new QPushButton(AddEditStormNode);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_Buttons->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_Buttons);


        retranslateUi(AddEditStormNode);

        QMetaObject::connectSlotsByName(AddEditStormNode);
    } // setupUi

    void retranslateUi(QDialog *AddEditStormNode)
    {
        AddEditStormNode->setWindowTitle(QApplication::translate("AddEditStormNode", "Add/Edit Stormnode", 0));
        label_3->setText(QApplication::translate("AddEditStormNode", "<html><head/><body><p>Enter an Alias (friendly name) for your Stormnode and its address (either clearnet IP and port or Tor onion address and port).  The address should be in the format 123.456.789.123:9999 or akjdsafxjkhasdf.onion:9999.  A Stormnode private key and a collateral address will both be automatically generated for you.  You must send exactly 500 DRKSLK to the collateral address.</p></body></html>", 0));
        label->setText(QApplication::translate("AddEditStormNode", "Alias", 0));
        label_2->setText(QApplication::translate("AddEditStormNode", "Address", 0));
        statusLabel->setText(QString());
        okButton->setText(QApplication::translate("AddEditStormNode", "&OK", 0));
        cancelButton->setText(QApplication::translate("AddEditStormNode", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddEditStormNode: public Ui_AddEditStormNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITSTORMNODE_H
