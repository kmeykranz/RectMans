#include "object.h"

Object::Object(int x_temp,int y_temp,int num,QWidget *widget)
{
    obj=new QLabel(widget);
    if(num==1){
    obj_.load("Images/tree.png");
    obj->setFixedSize(150,150);
    }
    else{
        obj_.load("Images/gun.png");
        obj->setFixedSize(100,100);
    }
    obj->setPixmap(obj_);
    obj->setScaledContents(1);
    x=x_temp;
    y=y_temp;
    obj->show();
}

void Object::relMove(int a,int b)
{
    rel_x=x-a;
    rel_y=y-b;
}

void Object::draw()
{
    if(isEquipped==1){
        obj->move(CENTER_X,CENTER_Y+20);
    }
    else if(isEquipped==2){
        obj->move(x2+rel_x,y2+rel_y);
    }
    else{
    obj->move(CENTER_X+rel_x,CENTER_Y+rel_y);
    }
}

int Object::getY()
{
    return y;
}

void Object::Raise()
{
    obj->raise();
}

void Object::Lower()
{
    obj->lower();
}

bool Object::IsEquipped()
{
    return isEquipped;
}

void Object::equip()
{
    isEquipped=1;
}

void Object::equip2(int x_temp,int y_temp)
{
    x2=x_temp;
    y2=y_temp;
    isEquipped=2;
}

int Object::getX()
{
    return x;
}



