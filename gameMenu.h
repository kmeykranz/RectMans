#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>
#include "gameEngine.h"

namespace Ui {
class GameMenu;
}

class GameMenu : public QWidget
{
    Q_OBJECT

public:
    explicit GameMenu(QWidget *parent = nullptr);
    ~GameMenu();

private slots:
    void on_serverStart_clicked();

    void on_clientStart_clicked();

private:
    Ui::GameMenu *ui;
    GameEngine *game;
};

#endif // GAMEMENU_H
