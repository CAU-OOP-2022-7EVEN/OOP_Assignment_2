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
    ui->labelResult->setText("Plus Clicked");
}

void MainMenu::on_btnMinus_clicked() {
    ui->labelResult->setText("Minus Clicked");
}

void MainMenu::on_btnMultiply_clicked() {
    ui->labelResult->setText("Multiply Clicked");
}

void MainMenu::on_btnDivision_clicked() {
    ui->labelResult->setText("Division Clicked");
}