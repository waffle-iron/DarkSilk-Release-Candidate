/********************************************************************************
** Form generated from reading UI file 'darksilkmarket.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DARKSILKMARKET_H
#define UI_DARKSILKMARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DarkSilkMarket
{
public:
    QVBoxLayout *topLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *darksilkMarketHeaderLabel;
    QHBoxLayout *horizontalLayout;
    QListWidget *categoriesListWidget;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *buyButton;
    QPushButton *viewDetailsButton;
    QPushButton *copyAddressButton;

    void setupUi(QWidget *DarkSilkMarket)
    {
        if (DarkSilkMarket->objectName().isEmpty())
            DarkSilkMarket->setObjectName(QStringLiteral("DarkSilkMarket"));
        DarkSilkMarket->resize(800, 565);
        DarkSilkMarket->setStyleSheet(QStringLiteral("#DarkSilkMarket { background-color: #000000; }"));
        topLayout = new QVBoxLayout(DarkSilkMarket);
        topLayout->setObjectName(QStringLiteral("topLayout"));
        topLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        darksilkMarketHeaderLabel = new QLabel(DarkSilkMarket);
        darksilkMarketHeaderLabel->setObjectName(QStringLiteral("darksilkMarketHeaderLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(darksilkMarketHeaderLabel->sizePolicy().hasHeightForWidth());
        darksilkMarketHeaderLabel->setSizePolicy(sizePolicy);
        darksilkMarketHeaderLabel->setMinimumSize(QSize(590, 148));
        darksilkMarketHeaderLabel->setMaximumSize(QSize(16777215, 148));
        darksilkMarketHeaderLabel->setScaledContents(true);

        verticalLayout_2->addWidget(darksilkMarketHeaderLabel);


        topLayout->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, 0, 0);
        categoriesListWidget = new QListWidget(DarkSilkMarket);
        new QListWidgetItem(categoriesListWidget);
        new QListWidgetItem(categoriesListWidget);
        new QListWidgetItem(categoriesListWidget);
        new QListWidgetItem(categoriesListWidget);
        new QListWidgetItem(categoriesListWidget);
        new QListWidgetItem(categoriesListWidget);
        categoriesListWidget->setObjectName(QStringLiteral("categoriesListWidget"));
        categoriesListWidget->setMinimumSize(QSize(150, 0));
        categoriesListWidget->setMaximumSize(QSize(150, 16777215));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        categoriesListWidget->setPalette(palette);
        categoriesListWidget->setStyleSheet(QStringLiteral("#categoriesListWidget { background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px; } #categoriesListWidget::item { margin: 20px; }"));
        categoriesListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        categoriesListWidget->setSortingEnabled(true);

        horizontalLayout->addWidget(categoriesListWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 0, 0);
        tableWidget = new QTableWidget(DarkSilkMarket);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, 10, 10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buyButton = new QPushButton(DarkSilkMarket);
        buyButton->setObjectName(QStringLiteral("buyButton"));

        horizontalLayout_2->addWidget(buyButton);

        viewDetailsButton = new QPushButton(DarkSilkMarket);
        viewDetailsButton->setObjectName(QStringLiteral("viewDetailsButton"));

        horizontalLayout_2->addWidget(viewDetailsButton);

        copyAddressButton = new QPushButton(DarkSilkMarket);
        copyAddressButton->setObjectName(QStringLiteral("copyAddressButton"));

        horizontalLayout_2->addWidget(copyAddressButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        topLayout->addLayout(horizontalLayout);


        retranslateUi(DarkSilkMarket);

        QMetaObject::connectSlotsByName(DarkSilkMarket);
    } // setupUi

    void retranslateUi(QWidget *DarkSilkMarket)
    {
        DarkSilkMarket->setWindowTitle(QApplication::translate("DarkSilkMarket", "DarkSilkMarket", 0));
        darksilkMarketHeaderLabel->setText(QString());

        const bool __sortingEnabled = categoriesListWidget->isSortingEnabled();
        categoriesListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = categoriesListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("DarkSilkMarket", "AUTOMOTIVE", 0));
        QListWidgetItem *___qlistwidgetitem1 = categoriesListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("DarkSilkMarket", "COMPUTERS", 0));
        QListWidgetItem *___qlistwidgetitem2 = categoriesListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("DarkSilkMarket", "FOOD", 0));
        QListWidgetItem *___qlistwidgetitem3 = categoriesListWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("DarkSilkMarket", "GEEK", 0));
        QListWidgetItem *___qlistwidgetitem4 = categoriesListWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("DarkSilkMarket", "MISC", 0));
        QListWidgetItem *___qlistwidgetitem5 = categoriesListWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("DarkSilkMarket", "NOVELTIES", 0));
        categoriesListWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DarkSilkMarket", "Until", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DarkSilkMarket", "Vendor", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DarkSilkMarket", "Price", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DarkSilkMarket", "Item Title", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DarkSilkMarket", "Id", 0));
        buyButton->setText(QApplication::translate("DarkSilkMarket", "&Buy Request", 0));
        viewDetailsButton->setText(QApplication::translate("DarkSilkMarket", "&View Details", 0));
        copyAddressButton->setText(QApplication::translate("DarkSilkMarket", "&Copy Address", 0));
    } // retranslateUi

};

namespace Ui {
    class DarkSilkMarket: public Ui_DarkSilkMarket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DARKSILKMARKET_H
