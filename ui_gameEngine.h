/********************************************************************************
** Form generated from reading UI file 'gameEngine.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEENGINE_H
#define UI_GAMEENGINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameEngine
{
public:

    void setupUi(QWidget *GameEngine)
    {
        if (GameEngine->objectName().isEmpty())
            GameEngine->setObjectName(QString::fromUtf8("GameEngine"));
        GameEngine->resize(800, 600);

        retranslateUi(GameEngine);

        QMetaObject::connectSlotsByName(GameEngine);
    } // setupUi

    void retranslateUi(QWidget *GameEngine)
    {
        GameEngine->setWindowTitle(QCoreApplication::translate("GameEngine", "GameEngine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameEngine: public Ui_GameEngine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEENGINE_H
