#include "enemy.h"

Enemy::Enemy(int x1,int y1,int spe,QWidget *widget)
{
    enemy_.load("Images/zombie.png");
    enemy_r.load("Images/zombie_r.png");

    x=x1;
    y=y1;
    speed=spe;
    enemy=new QLabel(widget);
    enemy->setPixmap(enemy_);
    enemy->setScaledContents(1);
    enemy->setFixedSize(100,100);
    enemy->show();
}

void Enemy::relMove(int a,int b)
{
    rel_x=x-a;
    rel_y=y-b;
}

void Enemy::draw()
{
    enemy->move(CENTER_X+rel_x,CENTER_Y+rel_y);
}

int Enemy::getY()
{
    return y;
}


void Enemy::Raise()
{
    enemy->raise();
}

void Enemy::Lower()
{
    enemy->lower();
}

void Enemy::chase(Player *p1, Player *p2)
{
    int Xp1=p1->getX(),Yp1=p1->getY(),Xp2=p2->getX(),Yp2=p2->getY();
    int disP1=(x-Xp1)*(x-Xp1)+(y-Yp1)*(y-Yp1);
    int disP2=(x-Xp2)*(x-Xp2)+(y-Yp2)*(y-Yp2);
    if(disP1<disP2){
        if(x<Xp1){
            x+=speed;
            enemy->setPixmap(enemy_r);
        }
        else if(x>Xp1){
            x-=speed;
            enemy->setPixmap(enemy_);
        }
        if(y<Yp1){
            y+=speed;
        }
        else if(y>Yp1){
            y-=speed;
        }
    }
    else{
        if(x<Xp2){
            x+=speed;
            enemy->setPixmap(enemy_r);
        }
        else if(x>Xp2){
            x-=speed;
            enemy->setPixmap(enemy_);
        }
        if(y<Yp2){
            y+=speed;
        }
        else if(y>Yp2){
            y-=speed;
        }
    }
}


