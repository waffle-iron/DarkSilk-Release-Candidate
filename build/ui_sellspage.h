/********************************************************************************
** Form generated from reading UI file 'sellspage.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLSPAGE_H
#define UI_SELLSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellsPage
{
public:
    QVBoxLayout *topLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *listingsTableWidget;
    QLabel *label_2;
    QTableWidget *buysTableWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *createButton;
    QPushButton *cancelButton;
    QPushButton *acceptButton;
    QPushButton *rejectButton;
    QPushButton *copyAddressButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelEscrowButton;
    QPushButton *requestPaymentButton;
    QPushButton *refundButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;

    void setupUi(QWidget *SellsPage)
    {
        if (SellsPage->objectName().isEmpty())
            SellsPage->setObjectName(QStringLiteral("SellsPage"));
        SellsPage->resize(777, 517);
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
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        SellsPage->setPalette(palette);
        topLayout = new QVBoxLayout(SellsPage);
        topLayout->setObjectName(QStringLiteral("topLayout"));
        topLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(SellsPage);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        listingsTableWidget = new QTableWidget(SellsPage);
        if (listingsTableWidget->columnCount() < 5)
            listingsTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        listingsTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        listingsTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        listingsTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        listingsTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        listingsTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        listingsTableWidget->setObjectName(QStringLiteral("listingsTableWidget"));
        listingsTableWidget->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        listingsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listingsTableWidget->setAlternatingRowColors(true);
        listingsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listingsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        listingsTableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(listingsTableWidget);

        label_2 = new QLabel(SellsPage);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        buysTableWidget = new QTableWidget(SellsPage);
        if (buysTableWidget->columnCount() < 6)
            buysTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        buysTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        buysTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        buysTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        buysTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        buysTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        buysTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        buysTableWidget->setObjectName(QStringLiteral("buysTableWidget"));
        buysTableWidget->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        buysTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        buysTableWidget->setAlternatingRowColors(true);
        buysTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        buysTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        buysTableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(buysTableWidget);


        topLayout->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        createButton = new QPushButton(SellsPage);
        createButton->setObjectName(QStringLiteral("createButton"));

        horizontalLayout->addWidget(createButton);

        cancelButton = new QPushButton(SellsPage);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        acceptButton = new QPushButton(SellsPage);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        horizontalLayout->addWidget(acceptButton);

        rejectButton = new QPushButton(SellsPage);
        rejectButton->setObjectName(QStringLiteral("rejectButton"));

        horizontalLayout->addWidget(rejectButton);

        copyAddressButton = new QPushButton(SellsPage);
        copyAddressButton->setObjectName(QStringLiteral("copyAddressButton"));

        horizontalLayout->addWidget(copyAddressButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        topLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        cancelEscrowButton = new QPushButton(SellsPage);
        cancelEscrowButton->setObjectName(QStringLiteral("cancelEscrowButton"));

        horizontalLayout_2->addWidget(cancelEscrowButton);

        requestPaymentButton = new QPushButton(SellsPage);
        requestPaymentButton->setObjectName(QStringLiteral("requestPaymentButton"));

        horizontalLayout_2->addWidget(requestPaymentButton);

        refundButton = new QPushButton(SellsPage);
        refundButton->setObjectName(QStringLiteral("refundButton"));

        horizontalLayout_2->addWidget(refundButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        topLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_3 = new QLabel(SellsPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setWordWrap(true);

        horizontalLayout_3->addWidget(label_3);


        topLayout->addLayout(horizontalLayout_3);


        retranslateUi(SellsPage);

        QMetaObject::connectSlotsByName(SellsPage);
    } // setupUi

    void retranslateUi(QWidget *SellsPage)
    {
        SellsPage->setWindowTitle(QApplication::translate("SellsPage", "DarkSilkMarket Sells", 0));
        label->setText(QApplication::translate("SellsPage", "My Listings:", 0));
        QTableWidgetItem *___qtablewidgetitem = listingsTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SellsPage", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem1 = listingsTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SellsPage", "Expires", 0));
        QTableWidgetItem *___qtablewidgetitem2 = listingsTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SellsPage", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem3 = listingsTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SellsPage", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem4 = listingsTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SellsPage", "Status", 0));
        label_2->setText(QApplication::translate("SellsPage", "Buy Requests:", 0));
        QTableWidgetItem *___qtablewidgetitem5 = buysTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("SellsPage", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem6 = buysTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("SellsPage", "Status", 0));
        QTableWidgetItem *___qtablewidgetitem7 = buysTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("SellsPage", "Buyer", 0));
        QTableWidgetItem *___qtablewidgetitem8 = buysTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("SellsPage", "Item", 0));
        QTableWidgetItem *___qtablewidgetitem9 = buysTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("SellsPage", "Item Id", 0));
        QTableWidgetItem *___qtablewidgetitem10 = buysTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("SellsPage", "Request Id", 0));
        createButton->setText(QApplication::translate("SellsPage", "Create &Listing", 0));
        cancelButton->setText(QApplication::translate("SellsPage", "&Cancel Listing", 0));
        acceptButton->setText(QApplication::translate("SellsPage", "&Accept Buy", 0));
        rejectButton->setText(QApplication::translate("SellsPage", "&Reject Buy", 0));
        copyAddressButton->setText(QApplication::translate("SellsPage", "Copy &Buyer Address", 0));
        cancelEscrowButton->setText(QApplication::translate("SellsPage", "Ca&ncel Escrow", 0));
        requestPaymentButton->setText(QApplication::translate("SellsPage", "Request &Payment", 0));
        refundButton->setText(QApplication::translate("SellsPage", "Ref&und", 0));
        label_3->setText(QApplication::translate("SellsPage", "<html><head/><body><p>Note: Escrow may only be cancelled prior to the buyer completing &quot;escrow lock&quot;, which broadcasts the escrow transaction to the network.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class SellsPage: public Ui_SellsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLSPAGE_H
