#include "gameMenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameMenu w;
    w.show();
    return a.exec();
}
