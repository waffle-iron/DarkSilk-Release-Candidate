/********************************************************************************
** Form generated from reading UI file 'statisticspage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSPAGE_H
#define UI_STATISTICSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsPage
{
public:
    QGridLayout *gridLayout;
    QFrame *gridFrame_2;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout_2;
    QLabel *label_14;
    QLabel *heightBox;
    QLabel *label_9;
    QLabel *diffBox2;
    QLabel *label3_2;
    QLabel *localBox;
    QLabel *label1_2;
    QLabel *connectionBox;
    QLabel *label_8;
    QLabel *volumeBox;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QLabel *label;
    QProgressBar *progressBar;
    QLabel *cBox;
    QPushButton *startButton;

    void setupUi(QWidget *StatisticsPage)
    {
        if (StatisticsPage->objectName().isEmpty())
            StatisticsPage->setObjectName(QStringLiteral("StatisticsPage"));
        StatisticsPage->setWindowModality(Qt::NonModal);
        StatisticsPage->resize(681, 505);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        StatisticsPage->setPalette(palette);
        StatisticsPage->setAutoFillBackground(true);
        StatisticsPage->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(StatisticsPage);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(52, -1, 22, -1);
        gridFrame_2 = new QFrame(StatisticsPage);
        gridFrame_2->setObjectName(QStringLiteral("gridFrame_2"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        gridFrame_2->setPalette(palette1);
        gridFrame_2->setAutoFillBackground(false);
        gridFrame_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        gridLayout_4 = new QGridLayout(gridFrame_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout_2->setHorizontalSpacing(78);
        formLayout_2->setVerticalSpacing(18);
        formLayout_2->setContentsMargins(-1, -1, 0, -1);
        label_14 = new QLabel(gridFrame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(80, 0, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_14->setPalette(palette2);
        label_14->setAutoFillBackground(false);
        label_14->setStyleSheet(QStringLiteral(""));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_14);

        heightBox = new QLabel(gridFrame_2);
        heightBox->setObjectName(QStringLiteral("heightBox"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        heightBox->setPalette(palette3);
        heightBox->setAutoFillBackground(false);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, heightBox);

        label_9 = new QLabel(gridFrame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_9->setPalette(palette4);
        label_9->setAutoFillBackground(false);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        diffBox2 = new QLabel(gridFrame_2);
        diffBox2->setObjectName(QStringLiteral("diffBox2"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        diffBox2->setPalette(palette5);
        diffBox2->setAutoFillBackground(false);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, diffBox2);

        label3_2 = new QLabel(gridFrame_2);
        label3_2->setObjectName(QStringLiteral("label3_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label3_2->sizePolicy().hasHeightForWidth());
        label3_2->setSizePolicy(sizePolicy);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label3_2->setPalette(palette6);
        label3_2->setAutoFillBackground(false);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label3_2);

        localBox = new QLabel(gridFrame_2);
        localBox->setObjectName(QStringLiteral("localBox"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        localBox->setPalette(palette7);
        localBox->setAutoFillBackground(false);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, localBox);

        label1_2 = new QLabel(gridFrame_2);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label1_2->setPalette(palette8);
        label1_2->setAutoFillBackground(false);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label1_2);

        connectionBox = new QLabel(gridFrame_2);
        connectionBox->setObjectName(QStringLiteral("connectionBox"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        connectionBox->setPalette(palette9);
        connectionBox->setAutoFillBackground(false);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, connectionBox);

        label_8 = new QLabel(gridFrame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_8->setPalette(palette10);
        label_8->setAutoFillBackground(false);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_8);

        volumeBox = new QLabel(gridFrame_2);
        volumeBox->setObjectName(QStringLiteral("volumeBox"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        volumeBox->setPalette(palette11);
        volumeBox->setAutoFillBackground(false);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, volumeBox);


        gridLayout_4->addLayout(formLayout_2, 2, 0, 2, 1);


        gridLayout->addWidget(gridFrame_2, 5, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 1, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 1, 1, 1);

        frame = new QFrame(StatisticsPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(260, 0));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame->setPalette(palette12);
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 231, 191));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label->setPalette(palette13);
        label->setAutoFillBackground(false);
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(60, 210, 151, 23));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        progressBar->setPalette(palette14);
        progressBar->setAutoFillBackground(false);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);
        cBox = new QLabel(frame);
        cBox->setObjectName(QStringLiteral("cBox"));
        cBox->setGeometry(QRect(90, 190, 91, 20));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        cBox->setPalette(palette15);
        cBox->setAutoFillBackground(false);
        startButton = new QPushButton(frame);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(60, 250, 151, 27));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setMaximumSize(QSize(16777214, 16777214));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        QBrush brush3(QColor(178, 178, 178, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        startButton->setPalette(palette16);
        startButton->setAutoFillBackground(false);
        startButton->setStyleSheet(QStringLiteral("background-color: rgb(80, 0, 120);"));
        startButton->setCheckable(false);
        startButton->setAutoDefault(false);
        startButton->setDefault(true);
        startButton->setFlat(false);

        gridLayout->addWidget(frame, 5, 0, 2, 1);


        retranslateUi(StatisticsPage);

        QMetaObject::connectSlotsByName(StatisticsPage);
    } // setupUi

    void retranslateUi(QWidget *StatisticsPage)
    {
        StatisticsPage->setWindowTitle(QApplication::translate("StatisticsPage", "Digging", 0));
        label_14->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">Block Height</span></p></body></html>", 0));
        heightBox->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">00000</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">PoS difficulty</span></p></body></html>", 0));
        diffBox2->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">0.0002</span></p></body></html>", 0));
        label3_2->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">Last block time</span></p></body></html>", 0));
        localBox->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">0 KH/s</span></p></body></html>", 0));
        label1_2->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">Connections</span></p></body></html>", 0));
        connectionBox->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">Total Supply</span></p></body></html>", 0));
        volumeBox->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p><span style=\" color:#ffffff;\">250</span></p></body></html>", 0));
        label->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; text-decoration: underline; color:#ffffff;\">DarkSilk Phases:</span><span style=\" color:#ffffff;\"><br/></span></p><p align=\"center\"><span style=\" color:#ffffff;\">1) Block 1 to 420,001 = PoW/PoS</span></p><p align=\"center\"><span style=\" color:#ffffff;\">2) Block 420,001+ = 100% PoS</span></p><p align=\"center\"><br/></p><p align=\"center\"><span style=\" font-size:12pt; text-decoration: underline; color:#ffffff;\">Current Phase:</span></p></body></html>", 0));
        cBox->setText(QApplication::translate("StatisticsPage", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">(1) PoW - PoS</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        startButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        startButton->setText(QApplication::translate("StatisticsPage", "Refresh Statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class StatisticsPage: public Ui_StatisticsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSPAGE_H
