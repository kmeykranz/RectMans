#include "map.h"

Map::Map(QWidget *widget)
{
    map_.load("Images/map.png");
    map=new QLabel(widget);
    map->setPixmap(map_);
    map->setScaledContents(1);
    map->setFixedSize(3200,3200);
    map->show();
}

void Map::relMove(int a,int b)
{
    rel_x=x-a;
    rel_y=x-b;
}

void Map::draw()
{
    map->lower();
    map->move(CENTER_X+rel_x,CENTER_Y+rel_y);
}
