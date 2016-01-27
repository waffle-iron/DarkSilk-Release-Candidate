/********************************************************************************
** Form generated from reading UI file 'i2poptionswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_I2POPTIONSWIDGET_H
#define UI_I2POPTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_I2POptionsWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBoxUseI2POnly;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label;
    QHBoxLayout *horizontalLayout_16;
    QLabel *labelSAMHost;
    QLineEdit *lineEditSAMHost;
    QLabel *labelSAMPort;
    QSpinBox *spinBoxSAMPort;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_17;
    QLabel *labelTunnelName;
    QLineEdit *lineEditTunnelName;
    QSpacerItem *horizontalSpacer_18;
    QPushButton *pushButtonCurrentI2PAddress;
    QPushButton *pushButtonGenerateI2PAddress;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBoxInbound;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelInboundQuantity;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxInboundQuantity;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelInboundLength;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *spinBoxInboundLength;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelInboundLengthVariance;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *spinBoxInboundLengthVariance;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelInboundBackupQuality;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBoxInboundBackupQuality;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelInboundAllowZeroHop;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBoxInboundAllowZeroHop;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelInboundIPRestriction;
    QSpacerItem *horizontalSpacer_6;
    QSpinBox *spinBoxInboundIPRestriction;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_14;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxOutbound;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelOutboundQuantity;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *spinBoxOutboundQuantity;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelOutboundLength;
    QSpacerItem *horizontalSpacer_8;
    QSpinBox *spinBoxOutboundLength;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelOutboundLengthVariance;
    QSpacerItem *horizontalSpacer_9;
    QSpinBox *spinBoxOutboundLengthVariance;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelOutboundBackupQuantity;
    QSpacerItem *horizontalSpacer_10;
    QSpinBox *spinBoxOutboundBackupQuantity;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelAllowZeroHop;
    QSpacerItem *horizontalSpacer_11;
    QCheckBox *checkBoxAllowZeroHop;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelOutboundIPRestriction;
    QSpacerItem *horizontalSpacer_12;
    QSpinBox *spinBoxOutboundIPRestriction;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelOutboundPriority;
    QSpacerItem *horizontalSpacer_13;
    QSpinBox *spinBoxOutboundPriority;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *I2POptionsWidget)
    {
        if (I2POptionsWidget->objectName().isEmpty())
            I2POptionsWidget->setObjectName(QStringLiteral("I2POptionsWidget"));
        I2POptionsWidget->resize(566, 414);
        I2POptionsWidget->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        verticalLayout_5 = new QVBoxLayout(I2POptionsWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        checkBoxUseI2POnly = new QCheckBox(I2POptionsWidget);
        checkBoxUseI2POnly->setObjectName(QStringLiteral("checkBoxUseI2POnly"));
        checkBoxUseI2POnly->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_15->addWidget(checkBoxUseI2POnly);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);

        label = new QLabel(I2POptionsWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setOpenExternalLinks(true);
        label->setTextInteractionFlags(Qt::TextBrowserInteraction);

        horizontalLayout_15->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        labelSAMHost = new QLabel(I2POptionsWidget);
        labelSAMHost->setObjectName(QStringLiteral("labelSAMHost"));

        horizontalLayout_16->addWidget(labelSAMHost);

        lineEditSAMHost = new QLineEdit(I2POptionsWidget);
        lineEditSAMHost->setObjectName(QStringLiteral("lineEditSAMHost"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditSAMHost->sizePolicy().hasHeightForWidth());
        lineEditSAMHost->setSizePolicy(sizePolicy);
        lineEditSAMHost->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_16->addWidget(lineEditSAMHost);

        labelSAMPort = new QLabel(I2POptionsWidget);
        labelSAMPort->setObjectName(QStringLiteral("labelSAMPort"));

        horizontalLayout_16->addWidget(labelSAMPort);

        spinBoxSAMPort = new QSpinBox(I2POptionsWidget);
        spinBoxSAMPort->setObjectName(QStringLiteral("spinBoxSAMPort"));
        spinBoxSAMPort->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxSAMPort->setMinimum(1);
        spinBoxSAMPort->setMaximum(65535);
        spinBoxSAMPort->setValue(7656);

        horizontalLayout_16->addWidget(spinBoxSAMPort);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_17);


        verticalLayout_5->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        labelTunnelName = new QLabel(I2POptionsWidget);
        labelTunnelName->setObjectName(QStringLiteral("labelTunnelName"));

        horizontalLayout_17->addWidget(labelTunnelName);

        lineEditTunnelName = new QLineEdit(I2POptionsWidget);
        lineEditTunnelName->setObjectName(QStringLiteral("lineEditTunnelName"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditTunnelName->sizePolicy().hasHeightForWidth());
        lineEditTunnelName->setSizePolicy(sizePolicy1);
        lineEditTunnelName->setMinimumSize(QSize(0, 0));
        lineEditTunnelName->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_17->addWidget(lineEditTunnelName);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_18);

        pushButtonCurrentI2PAddress = new QPushButton(I2POptionsWidget);
        pushButtonCurrentI2PAddress->setObjectName(QStringLiteral("pushButtonCurrentI2PAddress"));
        pushButtonCurrentI2PAddress->setStyleSheet(QStringLiteral("background: rgb(86,0,120); color: rgb(255,255,255); border: 1px inset grey; border-radius: 1px; margin: 0px;"));

        horizontalLayout_17->addWidget(pushButtonCurrentI2PAddress);

        pushButtonGenerateI2PAddress = new QPushButton(I2POptionsWidget);
        pushButtonGenerateI2PAddress->setObjectName(QStringLiteral("pushButtonGenerateI2PAddress"));
        pushButtonGenerateI2PAddress->setStyleSheet(QStringLiteral("background: rgb(86,0,120); color: rgb(255,255,255); border: 1px inset grey; border-radius: 1px; margin: 0px;"));

        horizontalLayout_17->addWidget(pushButtonGenerateI2PAddress);


        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBoxInbound = new QGroupBox(I2POptionsWidget);
        groupBoxInbound->setObjectName(QStringLiteral("groupBoxInbound"));
        groupBoxInbound->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(groupBoxInbound);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelInboundQuantity = new QLabel(groupBoxInbound);
        labelInboundQuantity->setObjectName(QStringLiteral("labelInboundQuantity"));

        horizontalLayout->addWidget(labelInboundQuantity);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBoxInboundQuantity = new QSpinBox(groupBoxInbound);
        spinBoxInboundQuantity->setObjectName(QStringLiteral("spinBoxInboundQuantity"));
        spinBoxInboundQuantity->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxInboundQuantity->setMinimum(1);
        spinBoxInboundQuantity->setMaximum(16);
        spinBoxInboundQuantity->setValue(2);

        horizontalLayout->addWidget(spinBoxInboundQuantity);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelInboundLength = new QLabel(groupBoxInbound);
        labelInboundLength->setObjectName(QStringLiteral("labelInboundLength"));

        horizontalLayout_2->addWidget(labelInboundLength);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        spinBoxInboundLength = new QSpinBox(groupBoxInbound);
        spinBoxInboundLength->setObjectName(QStringLiteral("spinBoxInboundLength"));
        spinBoxInboundLength->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxInboundLength->setMinimum(0);
        spinBoxInboundLength->setMaximum(7);
        spinBoxInboundLength->setValue(2);

        horizontalLayout_2->addWidget(spinBoxInboundLength);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelInboundLengthVariance = new QLabel(groupBoxInbound);
        labelInboundLengthVariance->setObjectName(QStringLiteral("labelInboundLengthVariance"));

        horizontalLayout_3->addWidget(labelInboundLengthVariance);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        spinBoxInboundLengthVariance = new QSpinBox(groupBoxInbound);
        spinBoxInboundLengthVariance->setObjectName(QStringLiteral("spinBoxInboundLengthVariance"));
        spinBoxInboundLengthVariance->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxInboundLengthVariance->setMinimum(-7);
        spinBoxInboundLengthVariance->setMaximum(7);

        horizontalLayout_3->addWidget(spinBoxInboundLengthVariance);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelInboundBackupQuality = new QLabel(groupBoxInbound);
        labelInboundBackupQuality->setObjectName(QStringLiteral("labelInboundBackupQuality"));

        horizontalLayout_4->addWidget(labelInboundBackupQuality);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        spinBoxInboundBackupQuality = new QSpinBox(groupBoxInbound);
        spinBoxInboundBackupQuality->setObjectName(QStringLiteral("spinBoxInboundBackupQuality"));
        spinBoxInboundBackupQuality->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_4->addWidget(spinBoxInboundBackupQuality);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelInboundAllowZeroHop = new QLabel(groupBoxInbound);
        labelInboundAllowZeroHop->setObjectName(QStringLiteral("labelInboundAllowZeroHop"));

        horizontalLayout_5->addWidget(labelInboundAllowZeroHop);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        checkBoxInboundAllowZeroHop = new QCheckBox(groupBoxInbound);
        checkBoxInboundAllowZeroHop->setObjectName(QStringLiteral("checkBoxInboundAllowZeroHop"));
        checkBoxInboundAllowZeroHop->setChecked(true);

        horizontalLayout_5->addWidget(checkBoxInboundAllowZeroHop);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelInboundIPRestriction = new QLabel(groupBoxInbound);
        labelInboundIPRestriction->setObjectName(QStringLiteral("labelInboundIPRestriction"));

        horizontalLayout_6->addWidget(labelInboundIPRestriction);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        spinBoxInboundIPRestriction = new QSpinBox(groupBoxInbound);
        spinBoxInboundIPRestriction->setObjectName(QStringLiteral("spinBoxInboundIPRestriction"));
        spinBoxInboundIPRestriction->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxInboundIPRestriction->setMaximum(4);
        spinBoxInboundIPRestriction->setValue(2);

        horizontalLayout_6->addWidget(spinBoxInboundIPRestriction);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(groupBoxInbound);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_14->addLayout(verticalLayout_4);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_14);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBoxOutbound = new QGroupBox(I2POptionsWidget);
        groupBoxOutbound->setObjectName(QStringLiteral("groupBoxOutbound"));
        groupBoxOutbound->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(groupBoxOutbound);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelOutboundQuantity = new QLabel(groupBoxOutbound);
        labelOutboundQuantity->setObjectName(QStringLiteral("labelOutboundQuantity"));

        horizontalLayout_7->addWidget(labelOutboundQuantity);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        spinBoxOutboundQuantity = new QSpinBox(groupBoxOutbound);
        spinBoxOutboundQuantity->setObjectName(QStringLiteral("spinBoxOutboundQuantity"));
        spinBoxOutboundQuantity->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxOutboundQuantity->setMinimum(1);
        spinBoxOutboundQuantity->setValue(2);

        horizontalLayout_7->addWidget(spinBoxOutboundQuantity);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelOutboundLength = new QLabel(groupBoxOutbound);
        labelOutboundLength->setObjectName(QStringLiteral("labelOutboundLength"));

        horizontalLayout_8->addWidget(labelOutboundLength);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        spinBoxOutboundLength = new QSpinBox(groupBoxOutbound);
        spinBoxOutboundLength->setObjectName(QStringLiteral("spinBoxOutboundLength"));
        spinBoxOutboundLength->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxOutboundLength->setMaximum(7);
        spinBoxOutboundLength->setValue(2);

        horizontalLayout_8->addWidget(spinBoxOutboundLength);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelOutboundLengthVariance = new QLabel(groupBoxOutbound);
        labelOutboundLengthVariance->setObjectName(QStringLiteral("labelOutboundLengthVariance"));

        horizontalLayout_9->addWidget(labelOutboundLengthVariance);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        spinBoxOutboundLengthVariance = new QSpinBox(groupBoxOutbound);
        spinBoxOutboundLengthVariance->setObjectName(QStringLiteral("spinBoxOutboundLengthVariance"));
        spinBoxOutboundLengthVariance->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxOutboundLengthVariance->setMinimum(-7);
        spinBoxOutboundLengthVariance->setMaximum(7);

        horizontalLayout_9->addWidget(spinBoxOutboundLengthVariance);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        labelOutboundBackupQuantity = new QLabel(groupBoxOutbound);
        labelOutboundBackupQuantity->setObjectName(QStringLiteral("labelOutboundBackupQuantity"));

        horizontalLayout_10->addWidget(labelOutboundBackupQuantity);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        spinBoxOutboundBackupQuantity = new QSpinBox(groupBoxOutbound);
        spinBoxOutboundBackupQuantity->setObjectName(QStringLiteral("spinBoxOutboundBackupQuantity"));
        spinBoxOutboundBackupQuantity->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_10->addWidget(spinBoxOutboundBackupQuantity);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelAllowZeroHop = new QLabel(groupBoxOutbound);
        labelAllowZeroHop->setObjectName(QStringLiteral("labelAllowZeroHop"));

        horizontalLayout_11->addWidget(labelAllowZeroHop);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        checkBoxAllowZeroHop = new QCheckBox(groupBoxOutbound);
        checkBoxAllowZeroHop->setObjectName(QStringLiteral("checkBoxAllowZeroHop"));
        checkBoxAllowZeroHop->setChecked(true);

        horizontalLayout_11->addWidget(checkBoxAllowZeroHop);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        labelOutboundIPRestriction = new QLabel(groupBoxOutbound);
        labelOutboundIPRestriction->setObjectName(QStringLiteral("labelOutboundIPRestriction"));

        horizontalLayout_12->addWidget(labelOutboundIPRestriction);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);

        spinBoxOutboundIPRestriction = new QSpinBox(groupBoxOutbound);
        spinBoxOutboundIPRestriction->setObjectName(QStringLiteral("spinBoxOutboundIPRestriction"));
        spinBoxOutboundIPRestriction->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxOutboundIPRestriction->setMaximum(4);
        spinBoxOutboundIPRestriction->setValue(2);

        horizontalLayout_12->addWidget(spinBoxOutboundIPRestriction);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        labelOutboundPriority = new QLabel(groupBoxOutbound);
        labelOutboundPriority->setObjectName(QStringLiteral("labelOutboundPriority"));

        horizontalLayout_13->addWidget(labelOutboundPriority);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);

        spinBoxOutboundPriority = new QSpinBox(groupBoxOutbound);
        spinBoxOutboundPriority->setObjectName(QStringLiteral("spinBoxOutboundPriority"));
        spinBoxOutboundPriority->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        spinBoxOutboundPriority->setMinimum(-25);
        spinBoxOutboundPriority->setMaximum(25);

        horizontalLayout_13->addWidget(spinBoxOutboundPriority);


        verticalLayout_2->addLayout(horizontalLayout_13);


        verticalLayout_3->addWidget(groupBoxOutbound);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_14->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_14);

        QWidget::setTabOrder(checkBoxUseI2POnly, lineEditSAMHost);
        QWidget::setTabOrder(lineEditSAMHost, spinBoxSAMPort);
        QWidget::setTabOrder(spinBoxSAMPort, lineEditTunnelName);
        QWidget::setTabOrder(lineEditTunnelName, pushButtonCurrentI2PAddress);
        QWidget::setTabOrder(pushButtonCurrentI2PAddress, pushButtonGenerateI2PAddress);
        QWidget::setTabOrder(pushButtonGenerateI2PAddress, spinBoxInboundQuantity);
        QWidget::setTabOrder(spinBoxInboundQuantity, spinBoxInboundLength);
        QWidget::setTabOrder(spinBoxInboundLength, spinBoxInboundLengthVariance);
        QWidget::setTabOrder(spinBoxInboundLengthVariance, spinBoxInboundBackupQuality);
        QWidget::setTabOrder(spinBoxInboundBackupQuality, checkBoxInboundAllowZeroHop);
        QWidget::setTabOrder(checkBoxInboundAllowZeroHop, spinBoxInboundIPRestriction);
        QWidget::setTabOrder(spinBoxInboundIPRestriction, spinBoxOutboundQuantity);
        QWidget::setTabOrder(spinBoxOutboundQuantity, spinBoxOutboundLength);
        QWidget::setTabOrder(spinBoxOutboundLength, spinBoxOutboundLengthVariance);
        QWidget::setTabOrder(spinBoxOutboundLengthVariance, spinBoxOutboundBackupQuantity);
        QWidget::setTabOrder(spinBoxOutboundBackupQuantity, checkBoxAllowZeroHop);
        QWidget::setTabOrder(checkBoxAllowZeroHop, spinBoxOutboundIPRestriction);
        QWidget::setTabOrder(spinBoxOutboundIPRestriction, spinBoxOutboundPriority);

        retranslateUi(I2POptionsWidget);

        QMetaObject::connectSlotsByName(I2POptionsWidget);
    } // setupUi

    void retranslateUi(QWidget *I2POptionsWidget)
    {
        I2POptionsWidget->setWindowTitle(QApplication::translate("I2POptionsWidget", "Form", 0));
        checkBoxUseI2POnly->setText(QApplication::translate("I2POptionsWidget", "Use I2P only (-onlynet=native_i2p)", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("I2POptionsWidget", "http://www.i2p2.i2p/i2cp.html#options", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("I2POptionsWidget", "<a href=\"http://www.i2p2.i2p/i2cp.html#options\">Help</a>", 0));
        labelSAMHost->setText(QApplication::translate("I2POptionsWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">SAM host</span></p></body></html>", 0));
        lineEditSAMHost->setText(QApplication::translate("I2POptionsWidget", "127.0.0.1", 0));
        labelSAMPort->setText(QApplication::translate("I2POptionsWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">SAM port</span></p></body></html>", 0));
        labelTunnelName->setText(QApplication::translate("I2POptionsWidget", "<html><head/><body><p><span style=\" color:#ffffff;\">Tunnel name</span></p></body></html>", 0));
        lineEditTunnelName->setText(QApplication::translate("I2POptionsWidget", "DarkSilk-client", 0));
        pushButtonCurrentI2PAddress->setText(QApplication::translate("I2POptionsWidget", "Current\n"
"I2P-address...", 0));
        pushButtonGenerateI2PAddress->setText(QApplication::translate("I2POptionsWidget", "Generate\n"
"I2P-address...", 0));
        groupBoxInbound->setTitle(QApplication::translate("I2POptionsWidget", "I2CP options of inbound tunnels", 0));
        labelInboundQuantity->setText(QApplication::translate("I2POptionsWidget", "inbound.quantity ", 0));
        labelInboundLength->setText(QApplication::translate("I2POptionsWidget", "inbound.length ", 0));
        labelInboundLengthVariance->setText(QApplication::translate("I2POptionsWidget", "inbound.lengthVariance", 0));
        labelInboundBackupQuality->setText(QApplication::translate("I2POptionsWidget", "inbound.backupQuantity ", 0));
        labelInboundAllowZeroHop->setText(QApplication::translate("I2POptionsWidget", "inbound.allowZeroHop ", 0));
        labelInboundIPRestriction->setText(QApplication::translate("I2POptionsWidget", "inbound.IPRestriction", 0));
        groupBoxOutbound->setTitle(QApplication::translate("I2POptionsWidget", "I2CP options of outbound tunnels", 0));
        labelOutboundQuantity->setText(QApplication::translate("I2POptionsWidget", "outbound.quantity ", 0));
        labelOutboundLength->setText(QApplication::translate("I2POptionsWidget", "outbound.length ", 0));
        labelOutboundLengthVariance->setText(QApplication::translate("I2POptionsWidget", "outbound.lengthVariance", 0));
        labelOutboundBackupQuantity->setText(QApplication::translate("I2POptionsWidget", "outbound.backupQuantity", 0));
        labelAllowZeroHop->setText(QApplication::translate("I2POptionsWidget", "outbound.allowZeroHop ", 0));
        labelOutboundIPRestriction->setText(QApplication::translate("I2POptionsWidget", "outbound.IPRestriction", 0));
        labelOutboundPriority->setText(QApplication::translate("I2POptionsWidget", "outbound.priority", 0));
    } // retranslateUi

};

namespace Ui {
    class I2POptionsWidget: public Ui_I2POptionsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_I2POPTIONSWIDGET_H
