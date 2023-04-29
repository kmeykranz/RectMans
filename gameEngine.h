#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Config.h"
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "server.h"
#include "client.h"
#include "player.h"
#include "map.h"
#include "object.h"
#include "enemy.h"
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class GameEngine; }
QT_END_NAMESPACE

class GameEngine : public QWidget
{
    Q_OBJECT

public:
    GameEngine(QWidget *parent = nullptr);
    ~GameEngine();
    void Player1(int port);
    void Player2(QString ip,QString port);
    void StartGame();
    void GameInit();
    void sameLoop();
private slots:
    void GameLoop1();
    void GameLoop2();
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

private:
    Ui::GameEngine *ui;
    QTimer *timer; //游戏主循环
    Server *server;
    Client *client;

    Player *player1;
    Player *player2;
    Map *map;
    Object *tree[TREE_NUM];
    Object *gun[3];
    Enemy *enemy[ENEMY_NUM];

    QPixmap *background;
};
#endif // GAMEENGINE_H
