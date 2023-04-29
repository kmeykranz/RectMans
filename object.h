#ifndef OBJECT_H
#define OBJECT_H
#include "player.h"

class Object
{
public:
    Object(int x_temp,int y_temp,int num,QWidget *widget);
    void relMove(int a,int b);
    void draw();
    void equip();
    void equip2(int x_temp,int y_temp);
    int getX();
    int getY();
    void Raise();
    void Lower();
    void changeX(int a);
    void changeY(int a);
    bool IsEquipped();
private:
    QLabel *obj;
    QPixmap obj_;
    int x,y;
    int rel_x,rel_y;
    int x2,y2;
    int isEquipped=0;
};

#endif // OBJECT_H
