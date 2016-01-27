/********************************************************************************
** Form generated from reading UI file 'addeditstormnode.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEditStormNode
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *aliasLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *addressLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *privkeyLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *txhashLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *outputindexLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_Buttons;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddEditStormNode)
    {
        if (AddEditStormNode->objectName().isEmpty())
            AddEditStormNode->setObjectName(QStringLiteral("AddEditStormNode"));
        AddEditStormNode->resize(331, 387);
        AddEditStormNode->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        AddEditStormNode->setModal(true);
        verticalLayout = new QVBoxLayout(AddEditStormNode);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_9 = new QLabel(AddEditStormNode);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setWordWrap(true);

        verticalLayout->addWidget(label_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        label_4 = new QLabel(AddEditStormNode);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        aliasLineEdit = new QLineEdit(AddEditStormNode);
        aliasLineEdit->setObjectName(QStringLiteral("aliasLineEdit"));

        horizontalLayout_4->addWidget(aliasLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 0);
        label_6 = new QLabel(AddEditStormNode);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        addressLineEdit = new QLineEdit(AddEditStormNode);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        horizontalLayout_5->addWidget(addressLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_5 = new QLabel(AddEditStormNode);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        privkeyLineEdit = new QLineEdit(AddEditStormNode);
        privkeyLineEdit->setObjectName(QStringLiteral("privkeyLineEdit"));

        horizontalLayout_3->addWidget(privkeyLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(AddEditStormNode);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        txhashLineEdit = new QLineEdit(AddEditStormNode);
        txhashLineEdit->setObjectName(QStringLiteral("txhashLineEdit"));

        horizontalLayout_2->addWidget(txhashLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(-1, -1, -1, 0);
        label_8 = new QLabel(AddEditStormNode);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        outputindexLineEdit = new QLineEdit(AddEditStormNode);
        outputindexLineEdit->setObjectName(QStringLiteral("outputindexLineEdit"));

        horizontalLayout_8->addWidget(outputindexLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, -1, 0);

        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, -1, -1, 0);

        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName(QStringLiteral("horizontalLayout_Buttons"));
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
        label_9->setText(QApplication::translate("AddEditStormNode", "<html><head/><body><p>Enter an Alias (friendly name) for your Stormnode and its address (either clearnet IP and port or Tor onion address and port). The address should be in the format 123.456.789.123:31000 or akjdsafxjkhasdf.onion:31000. You must send exactly 10000 DRKSLK to the collateral address.</p></body></html>", 0));
        label_4->setText(QApplication::translate("AddEditStormNode", "Alias*", 0));
        label_6->setText(QApplication::translate("AddEditStormNode", "Address*", 0));
        label_5->setText(QApplication::translate("AddEditStormNode", "PrivKey*", 0));
        label_2->setText(QApplication::translate("AddEditStormNode", "TxHash*", 0));
        label_8->setText(QApplication::translate("AddEditStormNode", "Output Index*", 0));
        okButton->setText(QApplication::translate("AddEditStormNode", "&OK", 0));
        cancelButton->setText(QApplication::translate("AddEditStormNode", "&Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddEditStormNode: public Ui_AddEditStormNode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEDITSTORMNODE_H
