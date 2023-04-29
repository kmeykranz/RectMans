/********************************************************************************
** Form generated from reading UI file 'gameMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMENU_H
#define UI_GAMEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMenu
{
public:
    QLineEdit *serverPort;
    QPushButton *serverStart;
    QLineEdit *clientPort;
    QPushButton *clientStart;
    QLineEdit *clientIP;

    void setupUi(QWidget *GameMenu)
    {
        if (GameMenu->objectName().isEmpty())
            GameMenu->setObjectName(QString::fromUtf8("GameMenu"));
        GameMenu->resize(400, 300);
        GameMenu->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	 font-family: \"Microsoft YaHei\";\n"
"	 font-size:10pt;\n"
"	 font-weight: bold;\n"
"}"));
        serverPort = new QLineEdit(GameMenu);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));
        serverPort->setGeometry(QRect(20, 80, 141, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(10);
        font.setBold(true);
        serverPort->setFont(font);
        serverStart = new QPushButton(GameMenu);
        serverStart->setObjectName(QString::fromUtf8("serverStart"));
        serverStart->setGeometry(QRect(170, 80, 61, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(11);
        font1.setBold(true);
        serverStart->setFont(font1);
        serverStart->setStyleSheet(QString::fromUtf8("  QPushButton {\n"
"      border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(90,194,198);\n"
"      min-width: 40px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:11pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
"  }\n"
" QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: #1fab89;\n"
"      min-width: 40px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:10pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
" }"));
        clientPort = new QLineEdit(GameMenu);
        clientPort->setObjectName(QString::fromUtf8("clientPort"));
        clientPort->setGeometry(QRect(180, 180, 121, 31));
        clientPort->setStyleSheet(QString::fromUtf8(""));
        clientStart = new QPushButton(GameMenu);
        clientStart->setObjectName(QString::fromUtf8("clientStart"));
        clientStart->setGeometry(QRect(310, 180, 62, 31));
        clientStart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"      border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(90,194,198);\n"
"      min-width: 60px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:10pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
"  }\n"
" QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: #1fab89;\n"
"      min-width: 60px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:9pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
" }"));
        clientIP = new QLineEdit(GameMenu);
        clientIP->setObjectName(QString::fromUtf8("clientIP"));
        clientIP->setGeometry(QRect(20, 180, 151, 31));
        clientIP->setFont(font);
        clientIP->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(GameMenu);

        QMetaObject::connectSlotsByName(GameMenu);
    } // setupUi

    void retranslateUi(QWidget *GameMenu)
    {
        GameMenu->setWindowTitle(QCoreApplication::translate("GameMenu", "Form", nullptr));
        serverPort->setPlaceholderText(QCoreApplication::translate("GameMenu", "Port\347\253\257\345\217\243", nullptr));
        serverStart->setText(QCoreApplication::translate("GameMenu", "Start", nullptr));
        clientPort->setPlaceholderText(QCoreApplication::translate("GameMenu", "Port\347\253\257\345\217\243", nullptr));
        clientStart->setText(QCoreApplication::translate("GameMenu", "Start", nullptr));
        clientIP->setPlaceholderText(QCoreApplication::translate("GameMenu", "IP\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameMenu: public Ui_GameMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMENU_H
