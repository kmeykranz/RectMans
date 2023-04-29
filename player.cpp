#include "player.h"

Player::Player(int num,QWidget *widget)
{
    player=new QLabel(widget);
    player->setFixedSize(100,100);
    player->setScaledContents(1);
    if(num==1){
        loadBlue();
    }
    else if(num==2){
        loadRed();
    }
    player->setPixmap(player_l);
    player->show();
}

void Player::loadBlue()
{
    player_l.load("Images/blue_man.png");
    player_r.load("Images/blue_man_r.png");
}

void Player::loadRed()
{
    player_l.load("Images/red_man.png");
    player_r.load("Images/red_man_r.png");
}

void Player::move(int x_temp,int y_temp,int dir_temp)
{
    x=x_temp;
    y=y_temp;
    dir=dir_temp;
}

void Player::move(Dir move_dir)
{
    if(move_dir==left){
        x-=5;
        dir=1;
    }
    else if(move_dir==right){
        x+=5;
        dir=0;
    }
    else if(move_dir==up){
        y-=5;
    }
    else{
        y+=5;
    }
}

void Player::relMove(int player_x,int player_y)
{
    rel_x=x-player_x;
    rel_y=y-player_y;
}

void Player::draw(){
    if(dir==1){
        player->setPixmap(player_l);
    }
    else{
        player->setPixmap(player_r);
    }
    player->move(CENTER_X+rel_x,CENTER_Y+rel_y);
}

void Player::drawFace()
{
    if(dir==1){
        player->setPixmap(player_l);
    }
    else{
        player->setPixmap(player_r);
    }
}

int Player::getX()
{
    return x;
}
int Player::getY()
{
    return y;
}
int Player::getDir()
{
    return dir;
}

void Player::Raise()
{
    player->raise();
}

void Player::Lower()
{
    player->lower();
}
