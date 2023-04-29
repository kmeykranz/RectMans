#include "gameMenu.h"
#include "ui_gameMenu.h"

GameMenu::GameMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("RectMans Menu");
    game=new GameEngine;
}

GameMenu::~GameMenu()
{
    delete ui;
    delete game;
}

void GameMenu::on_serverStart_clicked()
{
    game->Player1(ui->serverPort->text().toInt());
    game->show();
    this->hide();
}


void GameMenu::on_clientStart_clicked()
{
    game->Player2(ui->clientIP->text(),ui->clientPort->text());
    game->show();
    this->hide();
}

