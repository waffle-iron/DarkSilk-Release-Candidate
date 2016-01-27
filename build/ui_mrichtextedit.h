/********************************************************************************
** Form generated from reading UI file 'mrichtextedit.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRICHTEXTEDIT_H
#define UI_MRICHTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRichTextEdit
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *f_toolbar;
    QHBoxLayout *horizontalLayout;
    QComboBox *f_paragraph;
    QFrame *line_4;
    QToolButton *f_undo;
    QToolButton *f_redo;
    QToolButton *f_cut;
    QToolButton *f_copy;
    QToolButton *f_paste;
    QFrame *line;
    QToolButton *f_link;
    QFrame *line_3;
    QToolButton *f_bold;
    QToolButton *f_italic;
    QToolButton *f_underline;
    QToolButton *f_strikeout;
    QFrame *line_5;
    QToolButton *f_list_bullet;
    QToolButton *f_list_ordered;
    QToolButton *f_indent_dec;
    QToolButton *f_indent_inc;
    QFrame *line_2;
    QToolButton *f_bgcolor;
    QComboBox *f_fontsize;
    QFrame *line_6;
    QSpacerItem *horizontalSpacer;
    QTextEdit *f_textedit;

    void setupUi(QWidget *MRichTextEdit)
    {
        if (MRichTextEdit->objectName().isEmpty())
            MRichTextEdit->setObjectName(QStringLiteral("MRichTextEdit"));
        MRichTextEdit->resize(819, 312);
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
        MRichTextEdit->setPalette(palette);
        MRichTextEdit->setWindowTitle(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MRichTextEdit);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        f_toolbar = new QWidget(MRichTextEdit);
        f_toolbar->setObjectName(QStringLiteral("f_toolbar"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_toolbar->setPalette(palette1);
        f_toolbar->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        horizontalLayout = new QHBoxLayout(f_toolbar);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        f_paragraph = new QComboBox(f_toolbar);
        f_paragraph->setObjectName(QStringLiteral("f_paragraph"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_paragraph->setPalette(palette2);
        f_paragraph->setFocusPolicy(Qt::ClickFocus);
        f_paragraph->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        f_paragraph->setEditable(true);

        horizontalLayout->addWidget(f_paragraph);

        line_4 = new QFrame(f_toolbar);
        line_4->setObjectName(QStringLiteral("line_4"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        line_4->setPalette(palette3);
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        f_undo = new QToolButton(f_toolbar);
        f_undo->setObjectName(QStringLiteral("f_undo"));
        f_undo->setEnabled(false);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_undo->setPalette(palette4);
        f_undo->setFocusPolicy(Qt::ClickFocus);
        f_undo->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        QString iconThemeName = QStringLiteral("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_undo->setIcon(icon);
        f_undo->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_undo);

        f_redo = new QToolButton(f_toolbar);
        f_redo->setObjectName(QStringLiteral("f_redo"));
        f_redo->setEnabled(false);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_redo->setPalette(palette5);
        f_redo->setFocusPolicy(Qt::ClickFocus);
        f_redo->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        iconThemeName = QStringLiteral("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_redo->setIcon(icon1);
        f_redo->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_redo);

        f_cut = new QToolButton(f_toolbar);
        f_cut->setObjectName(QStringLiteral("f_cut"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_cut->setPalette(palette6);
        f_cut->setFocusPolicy(Qt::ClickFocus);
        f_cut->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        iconThemeName = QStringLiteral("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_cut->setIcon(icon2);
        f_cut->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_cut);

        f_copy = new QToolButton(f_toolbar);
        f_copy->setObjectName(QStringLiteral("f_copy"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_copy->setPalette(palette7);
        f_copy->setFocusPolicy(Qt::ClickFocus);
        f_copy->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        iconThemeName = QStringLiteral("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_copy->setIcon(icon3);
        f_copy->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_copy);

        f_paste = new QToolButton(f_toolbar);
        f_paste->setObjectName(QStringLiteral("f_paste"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_paste->setPalette(palette8);
        f_paste->setFocusPolicy(Qt::ClickFocus);
        f_paste->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        iconThemeName = QStringLiteral("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_paste->setIcon(icon4);
        f_paste->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_paste);

        line = new QFrame(f_toolbar);
        line->setObjectName(QStringLiteral("line"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        line->setPalette(palette9);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        f_link = new QToolButton(f_toolbar);
        f_link->setObjectName(QStringLiteral("f_link"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_link->setPalette(palette10);
        f_link->setFocusPolicy(Qt::ClickFocus);
        f_link->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        iconThemeName = QStringLiteral("applications-internet");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_link->setIcon(icon5);
        f_link->setIconSize(QSize(16, 16));
        f_link->setCheckable(true);

        horizontalLayout->addWidget(f_link);

        line_3 = new QFrame(f_toolbar);
        line_3->setObjectName(QStringLiteral("line_3"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        line_3->setPalette(palette11);
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        f_bold = new QToolButton(f_toolbar);
        f_bold->setObjectName(QStringLiteral("f_bold"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_bold->setPalette(palette12);
        f_bold->setFocusPolicy(Qt::ClickFocus);
#ifndef QT_NO_TOOLTIP
        f_bold->setToolTip(QStringLiteral("Bold (CTRL+B)"));
#endif // QT_NO_TOOLTIP
        f_bold->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        iconThemeName = QStringLiteral("format-text-bold");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_bold->setIcon(icon6);
        f_bold->setIconSize(QSize(16, 16));
        f_bold->setCheckable(true);

        horizontalLayout->addWidget(f_bold);

        f_italic = new QToolButton(f_toolbar);
        f_italic->setObjectName(QStringLiteral("f_italic"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_italic->setPalette(palette13);
        f_italic->setFocusPolicy(Qt::ClickFocus);
        f_italic->setStyleSheet(QStringLiteral(""));
        QIcon icon7;
        iconThemeName = QStringLiteral("format-text-italic");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_italic->setIcon(icon7);
        f_italic->setIconSize(QSize(16, 16));
        f_italic->setCheckable(true);

        horizontalLayout->addWidget(f_italic);

        f_underline = new QToolButton(f_toolbar);
        f_underline->setObjectName(QStringLiteral("f_underline"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_underline->setPalette(palette14);
        f_underline->setFocusPolicy(Qt::ClickFocus);
        f_underline->setStyleSheet(QStringLiteral(""));
        QIcon icon8;
        iconThemeName = QStringLiteral("format-text-underline");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_underline->setIcon(icon8);
        f_underline->setIconSize(QSize(16, 16));
        f_underline->setCheckable(true);

        horizontalLayout->addWidget(f_underline);

        f_strikeout = new QToolButton(f_toolbar);
        f_strikeout->setObjectName(QStringLiteral("f_strikeout"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush5(QColor(80, 0, 120, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Light, brush);
        palette15.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette15.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_strikeout->setPalette(palette15);
        f_strikeout->setStyleSheet(QLatin1String("background-color: rgb(80, 0, 120);\n"
"color: rgb(255, 255, 255);"));
        f_strikeout->setCheckable(true);

        horizontalLayout->addWidget(f_strikeout);

        line_5 = new QFrame(f_toolbar);
        line_5->setObjectName(QStringLiteral("line_5"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        line_5->setPalette(palette16);
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        f_list_bullet = new QToolButton(f_toolbar);
        f_list_bullet->setObjectName(QStringLiteral("f_list_bullet"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_list_bullet->setPalette(palette17);
        f_list_bullet->setFocusPolicy(Qt::ClickFocus);
        f_list_bullet->setStyleSheet(QLatin1String("background-color: rgb(80, 0, 120);\n"
"color: rgb(255, 255, 255);"));
        f_list_bullet->setIconSize(QSize(16, 16));
        f_list_bullet->setCheckable(true);

        horizontalLayout->addWidget(f_list_bullet);

        f_list_ordered = new QToolButton(f_toolbar);
        f_list_ordered->setObjectName(QStringLiteral("f_list_ordered"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Light, brush);
        palette18.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette18.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_list_ordered->setPalette(palette18);
        f_list_ordered->setFocusPolicy(Qt::ClickFocus);
        f_list_ordered->setStyleSheet(QLatin1String("background-color: rgb(80, 0, 120);\n"
"color: rgb(255, 255, 255);"));
        f_list_ordered->setIconSize(QSize(16, 16));
        f_list_ordered->setCheckable(true);

        horizontalLayout->addWidget(f_list_ordered);

        f_indent_dec = new QToolButton(f_toolbar);
        f_indent_dec->setObjectName(QStringLiteral("f_indent_dec"));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Light, brush);
        palette19.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette19.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette19.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette19.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette19.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette19.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette19.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette19.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette19.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette19.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette19.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette19.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette19.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette19.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette19.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette19.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette19.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette19.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_indent_dec->setPalette(palette19);
        f_indent_dec->setFocusPolicy(Qt::ClickFocus);
        f_indent_dec->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        iconThemeName = QStringLiteral("format-indent-less");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_indent_dec->setIcon(icon9);
        f_indent_dec->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_indent_dec);

        f_indent_inc = new QToolButton(f_toolbar);
        f_indent_inc->setObjectName(QStringLiteral("f_indent_inc"));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Light, brush);
        palette20.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette20.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette20.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette20.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette20.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette20.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette20.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette20.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette20.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_indent_inc->setPalette(palette20);
        f_indent_inc->setFocusPolicy(Qt::ClickFocus);
        f_indent_inc->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        iconThemeName = QStringLiteral("format-indent-more");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        f_indent_inc->setIcon(icon10);
        f_indent_inc->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_indent_inc);

        line_2 = new QFrame(f_toolbar);
        line_2->setObjectName(QStringLiteral("line_2"));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Light, brush);
        palette21.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette21.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette21.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette21.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette21.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette21.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette21.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette21.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette21.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette21.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette21.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette21.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette21.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette21.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette21.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette21.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        line_2->setPalette(palette21);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        f_bgcolor = new QToolButton(f_toolbar);
        f_bgcolor->setObjectName(QStringLiteral("f_bgcolor"));
        f_bgcolor->setMinimumSize(QSize(16, 16));
        f_bgcolor->setMaximumSize(QSize(16, 16));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette22.setBrush(QPalette::Active, QPalette::Button, brush);
        palette22.setBrush(QPalette::Active, QPalette::Light, brush);
        palette22.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette22.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette22.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette22.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette22.setBrush(QPalette::Active, QPalette::Base, brush);
        palette22.setBrush(QPalette::Active, QPalette::Window, brush);
        palette22.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette22.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette22.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette22.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette22.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette22.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette22.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette22.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette22.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette22.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette22.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette22.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_bgcolor->setPalette(palette22);
        f_bgcolor->setFocusPolicy(Qt::ClickFocus);
        f_bgcolor->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        f_bgcolor->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(f_bgcolor);

        f_fontsize = new QComboBox(f_toolbar);
        f_fontsize->setObjectName(QStringLiteral("f_fontsize"));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette23.setBrush(QPalette::Active, QPalette::Button, brush);
        palette23.setBrush(QPalette::Active, QPalette::Light, brush);
        palette23.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette23.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette23.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette23.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette23.setBrush(QPalette::Active, QPalette::Base, brush);
        palette23.setBrush(QPalette::Active, QPalette::Window, brush);
        palette23.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette23.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette23.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette23.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette23.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette23.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette23.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette23.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette23.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette23.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette23.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette23.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette23.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette23.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette23.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette23.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette23.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette23.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_fontsize->setPalette(palette23);
        f_fontsize->setFocusPolicy(Qt::ClickFocus);
        f_fontsize->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        f_fontsize->setEditable(true);

        horizontalLayout->addWidget(f_fontsize);

        line_6 = new QFrame(f_toolbar);
        line_6->setObjectName(QStringLiteral("line_6"));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Light, brush);
        palette24.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette24.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette24.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette24.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette24.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette24.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette24.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette24.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette24.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette24.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette24.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        line_6->setPalette(palette24);
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        f_paragraph->raise();
        line_4->raise();
        f_undo->raise();
        f_redo->raise();
        f_cut->raise();
        f_copy->raise();
        f_paste->raise();
        line->raise();
        f_link->raise();
        line_3->raise();
        f_italic->raise();
        f_underline->raise();
        line_2->raise();
        f_fontsize->raise();
        line_5->raise();
        f_list_bullet->raise();
        f_list_ordered->raise();
        f_indent_dec->raise();
        f_indent_inc->raise();
        f_bold->raise();
        f_bgcolor->raise();
        f_strikeout->raise();
        line_6->raise();

        verticalLayout->addWidget(f_toolbar);

        f_textedit = new QTextEdit(MRichTextEdit);
        f_textedit->setObjectName(QStringLiteral("f_textedit"));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette25.setBrush(QPalette::Active, QPalette::Button, brush);
        palette25.setBrush(QPalette::Active, QPalette::Light, brush);
        palette25.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette25.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette25.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette25.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush);
        palette25.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette25.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette25.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette25.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette25.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette25.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette25.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette25.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette25.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        f_textedit->setPalette(palette25);
        f_textedit->setStyleSheet(QStringLiteral(""));
        f_textedit->setAutoFormatting(QTextEdit::AutoNone);
        f_textedit->setTabChangesFocus(true);

        verticalLayout->addWidget(f_textedit);


        retranslateUi(MRichTextEdit);

        QMetaObject::connectSlotsByName(MRichTextEdit);
    } // setupUi

    void retranslateUi(QWidget *MRichTextEdit)
    {
#ifndef QT_NO_TOOLTIP
        f_paragraph->setToolTip(QApplication::translate("MRichTextEdit", "Paragraph formatting", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        f_undo->setToolTip(QApplication::translate("MRichTextEdit", "Undo (CTRL+Z)", 0));
#endif // QT_NO_TOOLTIP
        f_undo->setText(QApplication::translate("MRichTextEdit", "Undo", 0));
#ifndef QT_NO_TOOLTIP
        f_redo->setToolTip(QApplication::translate("MRichTextEdit", "Redo", 0));
#endif // QT_NO_TOOLTIP
        f_redo->setText(QApplication::translate("MRichTextEdit", "Redo", 0));
#ifndef QT_NO_TOOLTIP
        f_cut->setToolTip(QApplication::translate("MRichTextEdit", "Cut (CTRL+X)", 0));
#endif // QT_NO_TOOLTIP
        f_cut->setText(QApplication::translate("MRichTextEdit", "Cut", 0));
#ifndef QT_NO_TOOLTIP
        f_copy->setToolTip(QApplication::translate("MRichTextEdit", "Copy (CTRL+C)", 0));
#endif // QT_NO_TOOLTIP
        f_copy->setText(QApplication::translate("MRichTextEdit", "Copy", 0));
#ifndef QT_NO_TOOLTIP
        f_paste->setToolTip(QApplication::translate("MRichTextEdit", "Paste (CTRL+V)", 0));
#endif // QT_NO_TOOLTIP
        f_paste->setText(QApplication::translate("MRichTextEdit", "Paste", 0));
#ifndef QT_NO_TOOLTIP
        f_link->setToolTip(QApplication::translate("MRichTextEdit", "Link (CTRL+L)", 0));
#endif // QT_NO_TOOLTIP
        f_link->setText(QApplication::translate("MRichTextEdit", "Link", 0));
        f_bold->setText(QApplication::translate("MRichTextEdit", "Bold", 0));
#ifndef QT_NO_TOOLTIP
        f_italic->setToolTip(QApplication::translate("MRichTextEdit", "Italic (CTRL+I)", 0));
#endif // QT_NO_TOOLTIP
        f_italic->setText(QApplication::translate("MRichTextEdit", "Italic", 0));
#ifndef QT_NO_TOOLTIP
        f_underline->setToolTip(QApplication::translate("MRichTextEdit", "Underline (CTRL+U)", 0));
#endif // QT_NO_TOOLTIP
        f_underline->setText(QApplication::translate("MRichTextEdit", "Underline", 0));
        f_strikeout->setText(QApplication::translate("MRichTextEdit", "Strike Out", 0));
#ifndef QT_NO_TOOLTIP
        f_list_bullet->setToolTip(QApplication::translate("MRichTextEdit", "Bullet list (CTRL+-)", 0));
#endif // QT_NO_TOOLTIP
        f_list_bullet->setText(QApplication::translate("MRichTextEdit", "Bullet list", 0));
#ifndef QT_NO_TOOLTIP
        f_list_ordered->setToolTip(QApplication::translate("MRichTextEdit", "Ordered list (CTRL+=)", 0));
#endif // QT_NO_TOOLTIP
        f_list_ordered->setText(QApplication::translate("MRichTextEdit", "Ordered list", 0));
#ifndef QT_NO_TOOLTIP
        f_indent_dec->setToolTip(QApplication::translate("MRichTextEdit", "Decrease indentation (CTRL+,)", 0));
#endif // QT_NO_TOOLTIP
        f_indent_dec->setText(QApplication::translate("MRichTextEdit", "Decrease indentation", 0));
#ifndef QT_NO_TOOLTIP
        f_indent_inc->setToolTip(QApplication::translate("MRichTextEdit", "Increase indentation (CTRL+.)", 0));
#endif // QT_NO_TOOLTIP
        f_indent_inc->setText(QApplication::translate("MRichTextEdit", "Increase indentation", 0));
#ifndef QT_NO_TOOLTIP
        f_bgcolor->setToolTip(QApplication::translate("MRichTextEdit", "Text background color", 0));
#endif // QT_NO_TOOLTIP
        f_bgcolor->setText(QApplication::translate("MRichTextEdit", ".", 0));
#ifndef QT_NO_TOOLTIP
        f_fontsize->setToolTip(QApplication::translate("MRichTextEdit", "Font size", 0));
#endif // QT_NO_TOOLTIP
        Q_UNUSED(MRichTextEdit);
    } // retranslateUi

};

namespace Ui {
    class MRichTextEdit: public Ui_MRichTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRICHTEXTEDIT_H
