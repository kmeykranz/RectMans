#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"

class Enemy
{
public:
    Enemy(int x1,int y1,int spe,QWidget *widget);
    void relMove(int a,int b);
    void draw();
    int getY();
    void Raise();
    void Lower();
    void chase(Player *p1,Player *p2);
private:
    QLabel *enemy;
    QPixmap enemy_;
    QPixmap enemy_r;
    int x=100,y=100,speed=3;
    int rel_x=0,rel_y=0;
};

#endif // ENEMY_H
