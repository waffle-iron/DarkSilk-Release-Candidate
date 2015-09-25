/********************************************************************************
** Form generated from reading UI file 'marketlistingdetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKETLISTINGDETAILSDIALOG_H
#define UI_MARKETLISTINGDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MarketListingDetailsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *imageOneLabel;
    QLabel *imageTwoLabel;
    QVBoxLayout *verticalLayout_3;
    QLabel *titleLabel;
    QLabel *descriptionLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *priceLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *untilLabel;
    QLabel *sellerAddressLabel;
    QHBoxLayout *horizontalLayout_Buttons;
    QSpacerItem *horizontalSpacer_1;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *MarketListingDetailsDialog)
    {
        if (MarketListingDetailsDialog->objectName().isEmpty())
            MarketListingDetailsDialog->setObjectName(QStringLiteral("MarketListingDetailsDialog"));
        MarketListingDetailsDialog->resize(672, 584);
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
        MarketListingDetailsDialog->setPalette(palette);
        MarketListingDetailsDialog->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        MarketListingDetailsDialog->setModal(true);
        verticalLayout = new QVBoxLayout(MarketListingDetailsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 0, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 20, -1);
        imageOneLabel = new QLabel(MarketListingDetailsDialog);
        imageOneLabel->setObjectName(QStringLiteral("imageOneLabel"));
        imageOneLabel->setMinimumSize(QSize(250, 250));
        imageOneLabel->setMaximumSize(QSize(250, 250));
        imageOneLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(imageOneLabel);

        imageTwoLabel = new QLabel(MarketListingDetailsDialog);
        imageTwoLabel->setObjectName(QStringLiteral("imageTwoLabel"));
        imageTwoLabel->setMinimumSize(QSize(250, 250));
        imageTwoLabel->setMaximumSize(QSize(250, 250));
        imageTwoLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(imageTwoLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 0);
        titleLabel = new QLabel(MarketListingDetailsDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        titleLabel->setWordWrap(true);

        verticalLayout_3->addWidget(titleLabel);

        descriptionLabel = new QLabel(MarketListingDetailsDialog);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));
        QFont font1;
        font1.setPointSize(11);
        descriptionLabel->setFont(font1);
        descriptionLabel->setStyleSheet(QStringLiteral("background: rgb(0,0,0); color: rgb(255,255,255); border: 1px inset white; border-radius: 3px; margin: 0px;"));
        descriptionLabel->setWordWrap(true);

        verticalLayout_3->addWidget(descriptionLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(MarketListingDetailsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_4);

        priceLabel = new QLabel(MarketListingDetailsDialog);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        QFont font3;
        font3.setPointSize(14);
        priceLabel->setFont(font3);
        priceLabel->setStyleSheet(QStringLiteral("#priceLabel { color: #008800; }"));

        horizontalLayout_2->addWidget(priceLabel);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(MarketListingDetailsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        horizontalLayout_3->addWidget(label_5);

        untilLabel = new QLabel(MarketListingDetailsDialog);
        untilLabel->setObjectName(QStringLiteral("untilLabel"));

        horizontalLayout_3->addWidget(untilLabel);


        verticalLayout_3->addLayout(horizontalLayout_3);

        sellerAddressLabel = new QLabel(MarketListingDetailsDialog);
        sellerAddressLabel->setObjectName(QStringLiteral("sellerAddressLabel"));
        sellerAddressLabel->setFont(font2);

        verticalLayout_3->addWidget(sellerAddressLabel);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_Buttons = new QHBoxLayout();
        horizontalLayout_Buttons->setObjectName(QStringLiteral("horizontalLayout_Buttons"));
        horizontalSpacer_1 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_1);

        statusLabel = new QLabel(MarketListingDetailsDialog);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setFont(font2);
        statusLabel->setTextFormat(Qt::PlainText);
        statusLabel->setWordWrap(true);

        horizontalLayout_Buttons->addWidget(statusLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_Buttons->addItem(horizontalSpacer_2);

        okButton = new QPushButton(MarketListingDetailsDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_Buttons->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_Buttons);


        retranslateUi(MarketListingDetailsDialog);

        QMetaObject::connectSlotsByName(MarketListingDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *MarketListingDetailsDialog)
    {
        MarketListingDetailsDialog->setWindowTitle(QApplication::translate("MarketListingDetailsDialog", "Details", 0));
        imageOneLabel->setText(QApplication::translate("MarketListingDetailsDialog", "Image", 0));
        imageTwoLabel->setText(QApplication::translate("MarketListingDetailsDialog", "Image", 0));
        titleLabel->setText(QApplication::translate("MarketListingDetailsDialog", "Item Title", 0));
        descriptionLabel->setText(QApplication::translate("MarketListingDetailsDialog", "Description", 0));
        label_4->setText(QApplication::translate("MarketListingDetailsDialog", "Price", 0));
        priceLabel->setText(QApplication::translate("MarketListingDetailsDialog", "1.23456789", 0));
        label_5->setText(QApplication::translate("MarketListingDetailsDialog", "Good Until", 0));
        untilLabel->setText(QApplication::translate("MarketListingDetailsDialog", "12/31/2015 1:00:00 PM UTC", 0));
        sellerAddressLabel->setText(QApplication::translate("MarketListingDetailsDialog", "Sa0gdahiognkhbashrg809hroihgohlh", 0));
        statusLabel->setText(QString());
        okButton->setText(QApplication::translate("MarketListingDetailsDialog", "&OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MarketListingDetailsDialog: public Ui_MarketListingDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKETLISTINGDETAILSDIALOG_H
