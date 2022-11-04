#include "mainmenu.h"
#include "ui_MainMenu.h"

#include "inf_int.h"


MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);

    sansPixmap[0].load(":/images/sans_1.png");
    sansPixmap[1].load(":/images/sans_2.png");

    ui->labelImage->setPixmap(sansPixmap[0].scaled(200, 200, Qt::KeepAspectRatio));
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::on_btnPlus_clicked() {
    inf_int num1(ui->inputNum1->text().toStdString().c_str());
    inf_int num2(ui->inputNum2->text().toStdString().c_str());
    inf_int numResult = num1 + num2;
    ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

    ui->labelImage->setPixmap(sansPixmap[1].scaled(200, 200, Qt::KeepAspectRatio));
}

void MainMenu::on_btnMinus_clicked() {
    inf_int num1(ui->inputNum1->text().toStdString().c_str());
    inf_int num2(ui->inputNum2->text().toStdString().c_str());
    inf_int numResult = num1 - num2;
    ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

    ui->labelImage->setPixmap(sansPixmap[1].scaled(200, 200, Qt::KeepAspectRatio));
}

void MainMenu::on_btnMultiply_clicked() {
    inf_int num1(ui->inputNum1->text().toStdString().c_str());
    inf_int num2(ui->inputNum2->text().toStdString().c_str());
    inf_int numResult = num1 * num2;
    ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

    ui->labelImage->setPixmap(sansPixmap[1].scaled(200, 200, Qt::KeepAspectRatio));
}

void MainMenu::on_btnDivision_clicked() {
    inf_int num1(ui->inputNum1->text().toStdString().c_str());
    inf_int num2(ui->inputNum2->text().toStdString().c_str());
    inf_int numResult = num1 / num2;
    ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

    ui->labelImage->setPixmap(sansPixmap[1].scaled(200, 200, Qt::KeepAspectRatio));
}