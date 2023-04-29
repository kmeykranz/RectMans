#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <QLabel>
#include "Config.h"
enum Dir{
    left,
    right,
    up,
    down
};

class Player
{
public:
    Player(int num,QWidget *widget);
    void loadBlue();
    void loadRed();
    void move(int x_temp,int y_temp,int dir_temp);
    void move(Dir move_dir);
    void relMove(int player_x, int player_y);
    void draw();
    void drawFace();
    int getX();
    int getY();
    int getDir();
    void Raise();
    void Lower();
private:
    QLabel *player;
    int x,y,dir;
    int rel_x=0,rel_y=0;//相对位置
    QPixmap player_l;
    QPixmap player_r;
};

#endif // PLAYER_H
