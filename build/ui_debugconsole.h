/********************************************************************************
** Form generated from reading UI file 'debugconsole.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGCONSOLE_H
#define UI_DEBUGCONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "trafficgraphwidget.h"

QT_BEGIN_NAMESPACE

class Ui_DEBUGConsole
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_info;
    QFormLayout *formLayout;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *clientName;
    QLabel *label_6;
    QLabel *clientVersion;
    QLabel *labelOpenSSL;
    QLabel *openSSLVersion;
    QLabel *label_berkeleyDBVersion;
    QLabel *berkeleyDBVersion;
    QLabel *labelBoostVersion;
    QLabel *boostVersion;
    QLabel *label_12;
    QLabel *buildDate;
    QLabel *label_13;
    QLabel *startupTime;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *numberOfConnections;
    QLabel *label_14;
    QLabel *stormnodeCount;
    QLabel *label_8;
    QCheckBox *isTestNet;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *numberOfBlocks;
    QLabel *label_2;
    QLabel *lastBlockTime;
    QSpacerItem *verticalSpacer_1;
    QLabel *labelMemoryPool;
    QLabel *labelCurrentNumTrans;
    QLabel *mempoolNumberTxs;
    QLabel *labelMemoryPoolUse;
    QLabel *mempoolSize;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelDebugLogfile;
    QPushButton *openDebugLogfileButton;
    QPushButton *showCLOptionsButton;
    QSpacerItem *verticalSpacer;
    QWidget *tab_console;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *messagesWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *clearButton;
    QWidget *tab_peers;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_101;
    QTableView *peerWidget;
    QLabel *banHeading;
    QTableView *banlistWidget;
    QLabel *peerHeading;
    QWidget *detailWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_30;
    QLabel *peerWhitelisted;
    QLabel *label_23;
    QLabel *peerDirection;
    QLabel *label_21;
    QLabel *peerVersion;
    QLabel *label_28;
    QLabel *peerSubversion;
    QLabel *label_4;
    QLabel *peerServices;
    QLabel *label_29;
    QLabel *peerHeight;
    QLabel *label_27;
    QLabel *peerSyncHeight;
    QLabel *label_25;
    QLabel *peerCommonHeight;
    QLabel *label_24;
    QLabel *peerBanScore;
    QLabel *label_22;
    QLabel *peerConnTime;
    QLabel *label_15;
    QLabel *peerLastSend;
    QLabel *label_19;
    QLabel *peerLastRecv;
    QLabel *label_18;
    QLabel *peerBytesSent;
    QLabel *label_20;
    QLabel *peerBytesRecv;
    QLabel *label_26;
    QLabel *peerPingTime;
    QLabel *peerPingWaitLabel;
    QLabel *peerPingWait;
    QLabel *label_timeoffset;
    QLabel *timeoffset;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    TrafficGraphWidget *trafficGraph;
    QHBoxLayout *horizontalLayout_2;
    QSlider *sldGraphRange;
    QLabel *lblGraphRange;
    QPushButton *btnClearTrafficGraph;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line;
    QLabel *label_16;
    QLabel *lblBytesIn;
    QHBoxLayout *horizontalLayout_5;
    QFrame *line_2;
    QLabel *label_17;
    QLabel *lblBytesOut;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *DEBUGConsole)
    {
        if (DEBUGConsole->objectName().isEmpty())
            DEBUGConsole->setObjectName(QStringLiteral("DEBUGConsole"));
        DEBUGConsole->resize(740, 496);
        DEBUGConsole->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(0, 0, 0);"));
        verticalLayout_2 = new QVBoxLayout(DEBUGConsole);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tabWidget = new QTabWidget(DEBUGConsole);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_info = new QWidget();
        tab_info->setObjectName(QStringLiteral("tab_info"));
        formLayout = new QFormLayout(tab_info);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_9 = new QLabel(tab_info);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_9->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        label_5 = new QLabel(tab_info);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        clientName = new QLabel(tab_info);
        clientName->setObjectName(QStringLiteral("clientName"));
        clientName->setCursor(QCursor(Qt::IBeamCursor));
        clientName->setTextFormat(Qt::PlainText);
        clientName->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(1, QFormLayout::FieldRole, clientName);

        label_6 = new QLabel(tab_info);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        clientVersion = new QLabel(tab_info);
        clientVersion->setObjectName(QStringLiteral("clientVersion"));
        clientVersion->setCursor(QCursor(Qt::IBeamCursor));
        clientVersion->setTextFormat(Qt::PlainText);
        clientVersion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(2, QFormLayout::FieldRole, clientVersion);

        labelOpenSSL = new QLabel(tab_info);
        labelOpenSSL->setObjectName(QStringLiteral("labelOpenSSL"));
        labelOpenSSL->setIndent(10);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelOpenSSL);

        openSSLVersion = new QLabel(tab_info);
        openSSLVersion->setObjectName(QStringLiteral("openSSLVersion"));
        openSSLVersion->setCursor(QCursor(Qt::IBeamCursor));
        openSSLVersion->setTextFormat(Qt::PlainText);
        openSSLVersion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(3, QFormLayout::FieldRole, openSSLVersion);

        label_berkeleyDBVersion = new QLabel(tab_info);
        label_berkeleyDBVersion->setObjectName(QStringLiteral("label_berkeleyDBVersion"));
        label_berkeleyDBVersion->setIndent(10);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_berkeleyDBVersion);

        berkeleyDBVersion = new QLabel(tab_info);
        berkeleyDBVersion->setObjectName(QStringLiteral("berkeleyDBVersion"));
        berkeleyDBVersion->setCursor(QCursor(Qt::IBeamCursor));
        berkeleyDBVersion->setTextFormat(Qt::PlainText);
        berkeleyDBVersion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(4, QFormLayout::FieldRole, berkeleyDBVersion);

        labelBoostVersion = new QLabel(tab_info);
        labelBoostVersion->setObjectName(QStringLiteral("labelBoostVersion"));
        labelBoostVersion->setIndent(10);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelBoostVersion);

        boostVersion = new QLabel(tab_info);
        boostVersion->setObjectName(QStringLiteral("boostVersion"));
        boostVersion->setCursor(QCursor(Qt::IBeamCursor));
        boostVersion->setTextFormat(Qt::PlainText);
        boostVersion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(5, QFormLayout::FieldRole, boostVersion);

        label_12 = new QLabel(tab_info);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_12);

        buildDate = new QLabel(tab_info);
        buildDate->setObjectName(QStringLiteral("buildDate"));
        buildDate->setCursor(QCursor(Qt::IBeamCursor));
        buildDate->setTextFormat(Qt::PlainText);
        buildDate->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(6, QFormLayout::FieldRole, buildDate);

        label_13 = new QLabel(tab_info);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_13);

        startupTime = new QLabel(tab_info);
        startupTime->setObjectName(QStringLiteral("startupTime"));
        startupTime->setCursor(QCursor(Qt::IBeamCursor));
        startupTime->setTextFormat(Qt::PlainText);
        startupTime->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(7, QFormLayout::FieldRole, startupTime);

        label_11 = new QLabel(tab_info);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_11);

        label_7 = new QLabel(tab_info);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_7);

        numberOfConnections = new QLabel(tab_info);
        numberOfConnections->setObjectName(QStringLiteral("numberOfConnections"));
        numberOfConnections->setCursor(QCursor(Qt::IBeamCursor));
        numberOfConnections->setTextFormat(Qt::PlainText);
        numberOfConnections->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(9, QFormLayout::FieldRole, numberOfConnections);

        label_14 = new QLabel(tab_info);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_14);

        stormnodeCount = new QLabel(tab_info);
        stormnodeCount->setObjectName(QStringLiteral("stormnodeCount"));
        stormnodeCount->setCursor(QCursor(Qt::IBeamCursor));
        stormnodeCount->setTextFormat(Qt::PlainText);
        stormnodeCount->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(10, QFormLayout::FieldRole, stormnodeCount);

        label_8 = new QLabel(tab_info);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_8);

        isTestNet = new QCheckBox(tab_info);
        isTestNet->setObjectName(QStringLiteral("isTestNet"));
        isTestNet->setEnabled(false);

        formLayout->setWidget(11, QFormLayout::FieldRole, isTestNet);

        label_10 = new QLabel(tab_info);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        formLayout->setWidget(12, QFormLayout::LabelRole, label_10);

        label_3 = new QLabel(tab_info);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_3);

        numberOfBlocks = new QLabel(tab_info);
        numberOfBlocks->setObjectName(QStringLiteral("numberOfBlocks"));
        numberOfBlocks->setCursor(QCursor(Qt::IBeamCursor));
        numberOfBlocks->setTextFormat(Qt::PlainText);
        numberOfBlocks->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(13, QFormLayout::FieldRole, numberOfBlocks);

        label_2 = new QLabel(tab_info);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(14, QFormLayout::LabelRole, label_2);

        lastBlockTime = new QLabel(tab_info);
        lastBlockTime->setObjectName(QStringLiteral("lastBlockTime"));
        lastBlockTime->setCursor(QCursor(Qt::IBeamCursor));
        lastBlockTime->setTextFormat(Qt::PlainText);
        lastBlockTime->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(14, QFormLayout::FieldRole, lastBlockTime);

        verticalSpacer_1 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(15, QFormLayout::LabelRole, verticalSpacer_1);

        labelMemoryPool = new QLabel(tab_info);
        labelMemoryPool->setObjectName(QStringLiteral("labelMemoryPool"));
        labelMemoryPool->setFont(font);

        formLayout->setWidget(16, QFormLayout::LabelRole, labelMemoryPool);

        labelCurrentNumTrans = new QLabel(tab_info);
        labelCurrentNumTrans->setObjectName(QStringLiteral("labelCurrentNumTrans"));

        formLayout->setWidget(17, QFormLayout::LabelRole, labelCurrentNumTrans);

        mempoolNumberTxs = new QLabel(tab_info);
        mempoolNumberTxs->setObjectName(QStringLiteral("mempoolNumberTxs"));
        mempoolNumberTxs->setCursor(QCursor(Qt::IBeamCursor));
        mempoolNumberTxs->setTextFormat(Qt::PlainText);
        mempoolNumberTxs->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(17, QFormLayout::FieldRole, mempoolNumberTxs);

        labelMemoryPoolUse = new QLabel(tab_info);
        labelMemoryPoolUse->setObjectName(QStringLiteral("labelMemoryPoolUse"));

        formLayout->setWidget(19, QFormLayout::LabelRole, labelMemoryPoolUse);

        mempoolSize = new QLabel(tab_info);
        mempoolSize->setObjectName(QStringLiteral("mempoolSize"));
        mempoolSize->setCursor(QCursor(Qt::IBeamCursor));
        mempoolSize->setTextFormat(Qt::PlainText);
        mempoolSize->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        formLayout->setWidget(19, QFormLayout::FieldRole, mempoolSize);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(20, QFormLayout::LabelRole, verticalSpacer_2);

        labelDebugLogfile = new QLabel(tab_info);
        labelDebugLogfile->setObjectName(QStringLiteral("labelDebugLogfile"));
        labelDebugLogfile->setFont(font);

        formLayout->setWidget(21, QFormLayout::LabelRole, labelDebugLogfile);

        openDebugLogfileButton = new QPushButton(tab_info);
        openDebugLogfileButton->setObjectName(QStringLiteral("openDebugLogfileButton"));
        openDebugLogfileButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));
        openDebugLogfileButton->setAutoDefault(false);

        formLayout->setWidget(22, QFormLayout::LabelRole, openDebugLogfileButton);

        showCLOptionsButton = new QPushButton(tab_info);
        showCLOptionsButton->setObjectName(QStringLiteral("showCLOptionsButton"));
        showCLOptionsButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(86, 0, 120);\n"
"alternate-background-color: rgb(86, 0, 120);"));
        showCLOptionsButton->setAutoDefault(false);

        formLayout->setWidget(23, QFormLayout::LabelRole, showCLOptionsButton);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(24, QFormLayout::LabelRole, verticalSpacer);

        tabWidget->addTab(tab_info, QString());
        tab_console = new QWidget();
        tab_console->setObjectName(QStringLiteral("tab_console"));
        verticalLayout_3 = new QVBoxLayout(tab_console);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        messagesWidget = new QTextEdit(tab_console);
        messagesWidget->setObjectName(QStringLiteral("messagesWidget"));
        messagesWidget->setMinimumSize(QSize(0, 100));
        messagesWidget->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        messagesWidget->setReadOnly(true);
        messagesWidget->setProperty("tabKeyNavigation", QVariant(false));
        messagesWidget->setProperty("columnCount", QVariant(2));

        verticalLayout_3->addWidget(messagesWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab_console);
        label->setObjectName(QStringLiteral("label"));
        label->setText(QStringLiteral(">"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(tab_console);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(lineEdit);

        clearButton = new QPushButton(tab_console);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setMaximumSize(QSize(24, 24));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon);
        clearButton->setShortcut(QStringLiteral("Ctrl+L"));
        clearButton->setAutoDefault(false);

        horizontalLayout->addWidget(clearButton);


        verticalLayout_3->addLayout(horizontalLayout);

        tabWidget->addTab(tab_console, QString());
        tab_peers = new QWidget();
        tab_peers->setObjectName(QStringLiteral("tab_peers"));
        gridLayout_2 = new QGridLayout(tab_peers);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_101 = new QVBoxLayout();
        verticalLayout_101->setSpacing(0);
        verticalLayout_101->setObjectName(QStringLiteral("verticalLayout_101"));
        peerWidget = new QTableView(tab_peers);
        peerWidget->setObjectName(QStringLiteral("peerWidget"));
        peerWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        peerWidget->setTabKeyNavigation(false);
        peerWidget->setSortingEnabled(true);
        peerWidget->horizontalHeader()->setHighlightSections(false);

        verticalLayout_101->addWidget(peerWidget);

        banHeading = new QLabel(tab_peers);
        banHeading->setObjectName(QStringLiteral("banHeading"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(banHeading->sizePolicy().hasHeightForWidth());
        banHeading->setSizePolicy(sizePolicy);
        banHeading->setMinimumSize(QSize(300, 32));
        banHeading->setMaximumSize(QSize(16777215, 32));
        QFont font1;
        font1.setPointSize(12);
        banHeading->setFont(font1);
        banHeading->setCursor(QCursor(Qt::IBeamCursor));
        banHeading->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        banHeading->setWordWrap(true);
        banHeading->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_101->addWidget(banHeading);

        banlistWidget = new QTableView(tab_peers);
        banlistWidget->setObjectName(QStringLiteral("banlistWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(banlistWidget->sizePolicy().hasHeightForWidth());
        banlistWidget->setSizePolicy(sizePolicy1);
        banlistWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        banlistWidget->setTabKeyNavigation(false);
        banlistWidget->setSortingEnabled(true);
        banlistWidget->horizontalHeader()->setHighlightSections(false);

        verticalLayout_101->addWidget(banlistWidget);


        gridLayout_2->addLayout(verticalLayout_101, 0, 0, 2, 1);

        peerHeading = new QLabel(tab_peers);
        peerHeading->setObjectName(QStringLiteral("peerHeading"));
        sizePolicy.setHeightForWidth(peerHeading->sizePolicy().hasHeightForWidth());
        peerHeading->setSizePolicy(sizePolicy);
        peerHeading->setMinimumSize(QSize(300, 32));
        QFont font2;
        font2.setPointSize(10);
        peerHeading->setFont(font2);
        peerHeading->setCursor(QCursor(Qt::IBeamCursor));
        peerHeading->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        peerHeading->setWordWrap(true);
        peerHeading->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(peerHeading, 0, 1, 1, 1);

        detailWidget = new QWidget(tab_peers);
        detailWidget->setObjectName(QStringLiteral("detailWidget"));
        detailWidget->setMinimumSize(QSize(300, 0));
        gridLayout_3 = new QGridLayout(detailWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_30 = new QLabel(detailWidget);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_3->addWidget(label_30, 0, 0, 1, 1);

        peerWhitelisted = new QLabel(detailWidget);
        peerWhitelisted->setObjectName(QStringLiteral("peerWhitelisted"));
        peerWhitelisted->setCursor(QCursor(Qt::IBeamCursor));
        peerWhitelisted->setTextFormat(Qt::PlainText);
        peerWhitelisted->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerWhitelisted, 0, 2, 1, 1);

        label_23 = new QLabel(detailWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_3->addWidget(label_23, 1, 0, 1, 1);

        peerDirection = new QLabel(detailWidget);
        peerDirection->setObjectName(QStringLiteral("peerDirection"));
        peerDirection->setCursor(QCursor(Qt::IBeamCursor));
        peerDirection->setTextFormat(Qt::PlainText);
        peerDirection->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerDirection, 1, 2, 1, 1);

        label_21 = new QLabel(detailWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 2, 0, 1, 1);

        peerVersion = new QLabel(detailWidget);
        peerVersion->setObjectName(QStringLiteral("peerVersion"));
        peerVersion->setCursor(QCursor(Qt::IBeamCursor));
        peerVersion->setTextFormat(Qt::PlainText);
        peerVersion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerVersion, 2, 2, 1, 1);

        label_28 = new QLabel(detailWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout_3->addWidget(label_28, 3, 0, 1, 1);

        peerSubversion = new QLabel(detailWidget);
        peerSubversion->setObjectName(QStringLiteral("peerSubversion"));
        peerSubversion->setCursor(QCursor(Qt::IBeamCursor));
        peerSubversion->setTextFormat(Qt::PlainText);
        peerSubversion->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerSubversion, 3, 2, 1, 1);

        label_4 = new QLabel(detailWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        peerServices = new QLabel(detailWidget);
        peerServices->setObjectName(QStringLiteral("peerServices"));
        peerServices->setCursor(QCursor(Qt::IBeamCursor));
        peerServices->setTextFormat(Qt::PlainText);
        peerServices->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerServices, 4, 2, 1, 1);

        label_29 = new QLabel(detailWidget);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_3->addWidget(label_29, 5, 0, 1, 1);

        peerHeight = new QLabel(detailWidget);
        peerHeight->setObjectName(QStringLiteral("peerHeight"));
        peerHeight->setCursor(QCursor(Qt::IBeamCursor));
        peerHeight->setTextFormat(Qt::PlainText);
        peerHeight->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerHeight, 5, 2, 1, 1);

        label_27 = new QLabel(detailWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_3->addWidget(label_27, 6, 0, 1, 1);

        peerSyncHeight = new QLabel(detailWidget);
        peerSyncHeight->setObjectName(QStringLiteral("peerSyncHeight"));
        peerSyncHeight->setCursor(QCursor(Qt::IBeamCursor));
        peerSyncHeight->setTextFormat(Qt::PlainText);
        peerSyncHeight->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerSyncHeight, 6, 2, 1, 1);

        label_25 = new QLabel(detailWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_3->addWidget(label_25, 7, 0, 1, 1);

        peerCommonHeight = new QLabel(detailWidget);
        peerCommonHeight->setObjectName(QStringLiteral("peerCommonHeight"));
        peerCommonHeight->setCursor(QCursor(Qt::IBeamCursor));
        peerCommonHeight->setTextFormat(Qt::PlainText);
        peerCommonHeight->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerCommonHeight, 7, 2, 1, 1);

        label_24 = new QLabel(detailWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_3->addWidget(label_24, 8, 0, 1, 1);

        peerBanScore = new QLabel(detailWidget);
        peerBanScore->setObjectName(QStringLiteral("peerBanScore"));
        peerBanScore->setCursor(QCursor(Qt::IBeamCursor));
        peerBanScore->setTextFormat(Qt::PlainText);
        peerBanScore->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerBanScore, 8, 2, 1, 1);

        label_22 = new QLabel(detailWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_3->addWidget(label_22, 9, 0, 1, 1);

        peerConnTime = new QLabel(detailWidget);
        peerConnTime->setObjectName(QStringLiteral("peerConnTime"));
        peerConnTime->setCursor(QCursor(Qt::IBeamCursor));
        peerConnTime->setTextFormat(Qt::PlainText);
        peerConnTime->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerConnTime, 9, 2, 1, 1);

        label_15 = new QLabel(detailWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 10, 0, 1, 1);

        peerLastSend = new QLabel(detailWidget);
        peerLastSend->setObjectName(QStringLiteral("peerLastSend"));
        peerLastSend->setCursor(QCursor(Qt::IBeamCursor));
        peerLastSend->setTextFormat(Qt::PlainText);
        peerLastSend->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerLastSend, 10, 2, 1, 1);

        label_19 = new QLabel(detailWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_3->addWidget(label_19, 11, 0, 1, 1);

        peerLastRecv = new QLabel(detailWidget);
        peerLastRecv->setObjectName(QStringLiteral("peerLastRecv"));
        peerLastRecv->setCursor(QCursor(Qt::IBeamCursor));
        peerLastRecv->setTextFormat(Qt::PlainText);
        peerLastRecv->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerLastRecv, 11, 2, 1, 1);

        label_18 = new QLabel(detailWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 12, 0, 1, 1);

        peerBytesSent = new QLabel(detailWidget);
        peerBytesSent->setObjectName(QStringLiteral("peerBytesSent"));
        peerBytesSent->setCursor(QCursor(Qt::IBeamCursor));
        peerBytesSent->setTextFormat(Qt::PlainText);
        peerBytesSent->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerBytesSent, 12, 2, 1, 1);

        label_20 = new QLabel(detailWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_3->addWidget(label_20, 13, 0, 1, 1);

        peerBytesRecv = new QLabel(detailWidget);
        peerBytesRecv->setObjectName(QStringLiteral("peerBytesRecv"));
        peerBytesRecv->setCursor(QCursor(Qt::IBeamCursor));
        peerBytesRecv->setTextFormat(Qt::PlainText);
        peerBytesRecv->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerBytesRecv, 13, 2, 1, 1);

        label_26 = new QLabel(detailWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_3->addWidget(label_26, 14, 0, 1, 1);

        peerPingTime = new QLabel(detailWidget);
        peerPingTime->setObjectName(QStringLiteral("peerPingTime"));
        peerPingTime->setCursor(QCursor(Qt::IBeamCursor));
        peerPingTime->setTextFormat(Qt::PlainText);
        peerPingTime->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerPingTime, 14, 2, 1, 1);

        peerPingWaitLabel = new QLabel(detailWidget);
        peerPingWaitLabel->setObjectName(QStringLiteral("peerPingWaitLabel"));

        gridLayout_3->addWidget(peerPingWaitLabel, 15, 0, 1, 1);

        peerPingWait = new QLabel(detailWidget);
        peerPingWait->setObjectName(QStringLiteral("peerPingWait"));
        peerPingWait->setCursor(QCursor(Qt::IBeamCursor));
        peerPingWait->setTextFormat(Qt::PlainText);
        peerPingWait->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(peerPingWait, 15, 2, 1, 1);

        label_timeoffset = new QLabel(detailWidget);
        label_timeoffset->setObjectName(QStringLiteral("label_timeoffset"));

        gridLayout_3->addWidget(label_timeoffset, 16, 0, 1, 1);

        timeoffset = new QLabel(detailWidget);
        timeoffset->setObjectName(QStringLiteral("timeoffset"));
        timeoffset->setCursor(QCursor(Qt::IBeamCursor));
        timeoffset->setTextFormat(Qt::PlainText);
        timeoffset->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout_3->addWidget(timeoffset, 16, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 17, 1, 1, 1);


        gridLayout_2->addWidget(detailWidget, 1, 1, 1, 1);

        tabWidget->addTab(tab_peers, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        trafficGraph = new TrafficGraphWidget(tab);
        trafficGraph->setObjectName(QStringLiteral("trafficGraph"));
        sizePolicy1.setHeightForWidth(trafficGraph->sizePolicy().hasHeightForWidth());
        trafficGraph->setSizePolicy(sizePolicy1);
        trafficGraph->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));

        verticalLayout_4->addWidget(trafficGraph);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sldGraphRange = new QSlider(tab);
        sldGraphRange->setObjectName(QStringLiteral("sldGraphRange"));
        sldGraphRange->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        sldGraphRange->setMinimum(1);
        sldGraphRange->setMaximum(288);
        sldGraphRange->setPageStep(12);
        sldGraphRange->setValue(6);
        sldGraphRange->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sldGraphRange);

        lblGraphRange = new QLabel(tab);
        lblGraphRange->setObjectName(QStringLiteral("lblGraphRange"));
        lblGraphRange->setMinimumSize(QSize(100, 0));
        lblGraphRange->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        lblGraphRange->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lblGraphRange);

        btnClearTrafficGraph = new QPushButton(tab);
        btnClearTrafficGraph->setObjectName(QStringLiteral("btnClearTrafficGraph"));
        btnClearTrafficGraph->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255); background-color: rgb(86, 0, 120);alternate-background-color: rgb(86, 0, 120);"));

        horizontalLayout_2->addWidget(btnClearTrafficGraph);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(10, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        line->setPalette(palette);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_4->addWidget(label_16);

        lblBytesIn = new QLabel(groupBox);
        lblBytesIn->setObjectName(QStringLiteral("lblBytesIn"));
        lblBytesIn->setMinimumSize(QSize(50, 0));
        lblBytesIn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(lblBytesIn);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        sizePolicy2.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy2);
        line_2->setMinimumSize(QSize(10, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush3(QColor(255, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        line_2->setPalette(palette1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_5->addWidget(label_17);

        lblBytesOut = new QLabel(groupBox);
        lblBytesOut->setObjectName(QStringLiteral("lblBytesOut"));
        lblBytesOut->setMinimumSize(QSize(50, 0));
        lblBytesOut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lblBytesOut);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 407, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_3->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(DEBUGConsole);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DEBUGConsole);
    } // setupUi

    void retranslateUi(QDialog *DEBUGConsole)
    {
        DEBUGConsole->setWindowTitle(QApplication::translate("DEBUGConsole", "DarkSilk - Debug window", 0));
        label_9->setText(QApplication::translate("DEBUGConsole", "DarkSilk Core", 0));
        label_5->setText(QApplication::translate("DEBUGConsole", "Client name", 0));
        clientName->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_6->setText(QApplication::translate("DEBUGConsole", "Client version", 0));
        clientVersion->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        labelOpenSSL->setText(QApplication::translate("DEBUGConsole", "Using OpenSSL version", 0));
        openSSLVersion->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_berkeleyDBVersion->setText(QApplication::translate("DEBUGConsole", "Berkeley DB version", 0));
        berkeleyDBVersion->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        labelBoostVersion->setText(QApplication::translate("DEBUGConsole", "Boost version", 0));
        boostVersion->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_12->setText(QApplication::translate("DEBUGConsole", "Build date", 0));
        buildDate->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_13->setText(QApplication::translate("DEBUGConsole", "Startup time", 0));
        startupTime->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_11->setText(QApplication::translate("DEBUGConsole", "Network", 0));
        label_7->setText(QApplication::translate("DEBUGConsole", "Number of connections", 0));
        numberOfConnections->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_14->setText(QApplication::translate("DEBUGConsole", "Number of Stormnodes", 0));
        stormnodeCount->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_8->setText(QApplication::translate("DEBUGConsole", "On testnet", 0));
        isTestNet->setText(QString());
        label_10->setText(QApplication::translate("DEBUGConsole", "Block chain", 0));
        label_3->setText(QApplication::translate("DEBUGConsole", "Current number of blocks", 0));
        numberOfBlocks->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_2->setText(QApplication::translate("DEBUGConsole", "Last block time", 0));
        lastBlockTime->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        labelMemoryPool->setText(QApplication::translate("DEBUGConsole", "Memory Pool", 0));
        labelCurrentNumTrans->setText(QApplication::translate("DEBUGConsole", "Current number of transactions", 0));
        mempoolNumberTxs->setText(QApplication::translate("DEBUGConsole", "0", 0));
        labelMemoryPoolUse->setText(QApplication::translate("DEBUGConsole", "Memory usage", 0));
        mempoolSize->setText(QApplication::translate("DEBUGConsole", "0 MB", 0));
        labelDebugLogfile->setText(QApplication::translate("DEBUGConsole", "Debug log file", 0));
#ifndef QT_NO_TOOLTIP
        openDebugLogfileButton->setToolTip(QApplication::translate("DEBUGConsole", "Open the DarkSilk debug log file from the current data directory. This can take a few seconds for large log files.", 0));
#endif // QT_NO_TOOLTIP
        openDebugLogfileButton->setText(QApplication::translate("DEBUGConsole", "&Open", 0));
#ifndef QT_NO_TOOLTIP
        showCLOptionsButton->setToolTip(QApplication::translate("DEBUGConsole", "Show the DarkSilk-Qt help message to get a list with possible DarkSilk command-line options.", 0));
#endif // QT_NO_TOOLTIP
        showCLOptionsButton->setText(QApplication::translate("DEBUGConsole", "&Show", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_info), QApplication::translate("DEBUGConsole", "&Information", 0));
#ifndef QT_NO_TOOLTIP
        clearButton->setToolTip(QApplication::translate("DEBUGConsole", "Clear console", 0));
#endif // QT_NO_TOOLTIP
        clearButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_console), QApplication::translate("DEBUGConsole", "&Console", 0));
        banHeading->setText(QApplication::translate("DEBUGConsole", "Banned peers", 0));
        peerHeading->setText(QApplication::translate("DEBUGConsole", "Select a peer to view detailed information.", 0));
        label_30->setText(QApplication::translate("DEBUGConsole", "Whitelisted", 0));
        peerWhitelisted->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_23->setText(QApplication::translate("DEBUGConsole", "Direction", 0));
        peerDirection->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_21->setText(QApplication::translate("DEBUGConsole", "Version", 0));
        peerVersion->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_28->setText(QApplication::translate("DEBUGConsole", "User Agent", 0));
        peerSubversion->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_4->setText(QApplication::translate("DEBUGConsole", "Services", 0));
        peerServices->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_29->setText(QApplication::translate("DEBUGConsole", "Starting Block", 0));
        peerHeight->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_27->setText(QApplication::translate("DEBUGConsole", "Synced Headers", 0));
        peerSyncHeight->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_25->setText(QApplication::translate("DEBUGConsole", "Synced Blocks", 0));
        peerCommonHeight->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_24->setText(QApplication::translate("DEBUGConsole", "Ban Score", 0));
        peerBanScore->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_22->setText(QApplication::translate("DEBUGConsole", "Connection Time", 0));
        peerConnTime->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_15->setText(QApplication::translate("DEBUGConsole", "Last Send", 0));
        peerLastSend->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_19->setText(QApplication::translate("DEBUGConsole", "Last Receive", 0));
        peerLastRecv->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_18->setText(QApplication::translate("DEBUGConsole", "Sent", 0));
        peerBytesSent->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_20->setText(QApplication::translate("DEBUGConsole", "Received", 0));
        peerBytesRecv->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_26->setText(QApplication::translate("DEBUGConsole", "Ping Time", 0));
        peerPingTime->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
#ifndef QT_NO_TOOLTIP
        peerPingWaitLabel->setToolTip(QApplication::translate("DEBUGConsole", "The duration of a currently outstanding ping.", 0));
#endif // QT_NO_TOOLTIP
        peerPingWaitLabel->setText(QApplication::translate("DEBUGConsole", "Ping Wait", 0));
        peerPingWait->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        label_timeoffset->setText(QApplication::translate("DEBUGConsole", "Time Offset", 0));
        timeoffset->setText(QApplication::translate("DEBUGConsole", "N/A", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_peers), QApplication::translate("DEBUGConsole", "&Peers", 0));
        btnClearTrafficGraph->setText(QApplication::translate("DEBUGConsole", "&Clear", 0));
        groupBox->setTitle(QApplication::translate("DEBUGConsole", "Totals", 0));
        label_16->setText(QApplication::translate("DEBUGConsole", "In:", 0));
        label_17->setText(QApplication::translate("DEBUGConsole", "Out:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DEBUGConsole", "&Network Traffic", 0));
    } // retranslateUi

};

namespace Ui {
    class DEBUGConsole: public Ui_DEBUGConsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGCONSOLE_H
