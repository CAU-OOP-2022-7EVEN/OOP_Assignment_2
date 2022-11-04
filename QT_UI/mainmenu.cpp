#include "mainmenu.h"
#include "ui_MainMenu.h"


MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::on_btnPlus_clicked() {

}

void MainMenu::on_btnMinus_clicked() {

}

void MainMenu::on_btnMultiply_clicked() {

}

void MainMenu::on_btnDivision_clicked() {

}