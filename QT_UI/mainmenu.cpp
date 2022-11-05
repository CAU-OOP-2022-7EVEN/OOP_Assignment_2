#include "mainmenu.h"
#include "ui_MainMenu.h"

#include "inf_int.h"


MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);

    sansPixmap[0].load(":/images/sans_1.png");
    sansPixmap[1].load(":/images/sans_2.png");
    sansPixmap[2].load(":/images/sans_err.png");

    updateSans();
}

MainMenu::~MainMenu() {
    delete ui;
}

bool checkValue(string input) {
    if(input.empty()){
        return false;
    }

    for(int i = 0; i < input.size(); i++){
        int cur = input[i] - '0';
        if(cur < 0 || cur > 9){
            return false;
        }
    }

    return true;
}

void MainMenu::on_btnPlus_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 + num2;
        ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

        updateSans();
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans();
    }
}

void MainMenu::on_btnMinus_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 - num2;
        ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

        updateSans();
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans();
    }
}

void MainMenu::on_btnMultiply_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 * num2;
        ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

        updateSans();
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans();
    }
}

void MainMenu::on_btnDivision_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 / num2;
        ui->labelResult->setText(QString(numResult.getResultChar().c_str()));

        updateSans();
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans();
    }
}

void MainMenu::updateSans() {
    if(sansFlag){
        sansFlag = false;
        ui->labelImage->setPixmap(sansPixmap[0].scaled(200, 200, Qt::KeepAspectRatio));
    }else{
        sansFlag = true;
        ui->labelImage->setPixmap(sansPixmap[1].scaled(200, 200, Qt::KeepAspectRatio));
    }
}