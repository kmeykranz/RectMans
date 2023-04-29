#ifndef MAP_H
#define MAP_H

#include <QLabel>
#include <QPixmap>
#include "player.h"

class Map
{
public:
    Map(QWidget *widget);

    void relMove(int x,int y);
    void draw();
private:
    QLabel *map;
    QPixmap map_;

    int x=-1600,y=-1600;
    int rel_x=0,rel_y=0;
};

#endif // MAP_H
