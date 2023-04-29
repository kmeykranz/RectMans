#include "gameEngine.h"
#include "ui_gameEngine.h"

GameEngine::GameEngine(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameEngine)
{
    ui->setupUi(this);
    this->setFixedSize(WIDTH,HEIGHT);
}

GameEngine::~GameEngine()
{
    delete ui;
}

void GameEngine::Player1(int port)
{
    this->setWindowTitle("Player 1");
    server=new Server();
    server->Connect(port);

    player2=new Player(2,this);
    player1=new Player(1,this);
    GameInit();

    //开启游戏主循环1
    timer=new QTimer;
    connect(timer,&QTimer::timeout,this,&GameEngine::GameLoop1);
    timer->start(1000/30);
}

void GameEngine::Player2(QString ip,QString port)
{
    this->setWindowTitle("Player 2");
    client=new Client();
    client->Connect(ip,port);

    player2=new Player(1,this);
    player1=new Player(2,this);
    GameInit();

    //开启游戏主循环2
    timer=new QTimer;
    connect(timer,&QTimer::timeout,this,&GameEngine::GameLoop2);
    timer->start(1000/30);
}

//游戏初始化
void GameEngine::GameInit()
{
    map=new Map(this);
    for(int i=1;i<TREE_NUM;i++){
        tree[i]=new Object(QRandomGenerator::global()->bounded(-1400,1400),
                           QRandomGenerator::global()->bounded(-1400,1400),1,this);
    }
//    for(int i=0;i<3;i++){
//        gun[i]=new Object(QRandomGenerator::global()->bounded(-1000,1000),
//                          QRandomGenerator::global()->bounded(-1000,1000),2,this);
//    }
    for(int i=0;i<ENEMY_NUM;i++){
        enemy[i]=new Enemy(QRandomGenerator::global()->bounded(-1600,1600),
                           QRandomGenerator::global()->bounded(-1600,1600),
                           QRandomGenerator::global()->bounded(1,3),this);
    }
    player1->move(CENTER_X,CENTER_Y,1);
    player1->draw();
}

//玩家一主循环
void GameEngine::GameLoop1()
{
    server->sendData(player1->getX(),player1->getY(),player1->getDir());
    player2->move(server->getX(),server->getY(),server->getDir());
    sameLoop();
}
//玩家二主循环
void GameEngine::GameLoop2()
{
    client->sendData(player1->getX(),player1->getY(),player1->getDir());
    player2->move(client->getX(),client->getY(),client->getDir());
    sameLoop();
}
//通用循环
void GameEngine::sameLoop()
{
    player1->drawFace();
    player2->relMove(player1->getX(),player1->getY());
    player2->draw();

    for(int i=0;i<ENEMY_NUM;i++){
        enemy[i]->chase(player1,player2);
        enemy[i]->relMove(player1->getX(),player1->getY());
        enemy[i]->draw();
    }

//    for(int i=0;i<3;i++){
//        if(player1->getX()<gun[i]->getX()+50&&player1->getX()>gun[i]->getX()&&
//                player1->getY()<gun[i]->getY()+50&&player1->getY()>gun[i]->getY()){
//            gun[i]->equip();
//        }
//        if(player2->getX()<gun[i]->getX()+50&&player2->getX()>gun[i]->getX()&&
//                player2->getY()<gun[i]->getY()+50&&player2->getY()>gun[i]->getY()){
//            gun[i]->equip2(player2->getX(),player2->getY());
//        }
//        gun[i]->relMove(player1->getX(),player1->getY());
//        gun[i]->draw();
//    }

    for(int i=1;i<TREE_NUM;i++){
        tree[i]->relMove(player1->getX(),player1->getY());
        tree[i]->draw();

        if((tree[i]->getY()<player1->getY()+70&&tree[i]->getY()>player1->getY()-45)||
                (tree[i]->getY()<player2->getY()+70&&tree[i]->getY()>player2->getY()-45)){
            tree[i]->Raise();
            if(tree[i]->getY()<player1->getY()-45){
                player1->Raise();
            }
            if(tree[i]->getY()<player2->getY()-45){
                player2->Raise();
            }
        }
        else{
            tree[i]->Lower();
        }

    }
    map->relMove(player1->getX(),player1->getY());
    map->draw();
}

void GameEngine::keyPressEvent(QKeyEvent *e)
{
    switch(e->key()){
    case Qt::Key_A:
        //移动时，将自己的位置变化传输给对方，并将在对方传来的位置上加上于自己的相对位置
        player1->move(left);
        break;
    case Qt::Key_D:
        player1->move(right);
        break;
    case Qt::Key_W:
        player1->move(up);
        break;
    case Qt::Key_S:
        player1->move(down);
        break;
    case Qt::Key_Escape:
        exit(-1);
        break;
    }
}

void GameEngine::keyReleaseEvent(QKeyEvent *e)
{

}

