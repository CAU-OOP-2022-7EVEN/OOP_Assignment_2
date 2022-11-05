#include "mainmenu.h"
#include "ui_MainMenu.h"

#include "inf_int.h"


MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);

    QPalette rightPalette = QPalette();
    rightPalette.setColor(QPalette::Window, Qt::black);
    ui->layoutRightImageContainer->setAutoFillBackground(true);
    ui->layoutRightImageContainer->setPalette(rightPalette);

    ui->labelResult->setWordWrap(true);

    sansPixmap[0].load(":/images/sans_1.png");
    sansPixmap[1].load(":/images/sans_2.png");
    sansPixmap[2].load(":/images/sans_err.png");

    updateSans(false);
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

        string strResult = "";
        string strResultBase = numResult.getResultChar();
        for(int i = 1; i <= strResultBase.size(); i++){
            strResult += strResultBase[i - 1];
            if(!(i % 60)){
                strResult += "\n";
            }
        }
        ui->labelResult->setText(QString(strResult.c_str()));

        updateSans(false);
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans(true);
    }
}

void MainMenu::on_btnMinus_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 - num2;

        string strResult = "";
        string strResultBase = numResult.getResultChar();
        for(int i = 1; i <= strResultBase.size(); i++){
            strResult += strResultBase[i - 1];
            if(!(i % 60)){
                strResult += "\n";
            }
        }
        ui->labelResult->setText(QString(strResult.c_str()));

        updateSans(false);
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans(true);
    }
}

void MainMenu::on_btnMultiply_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 * num2;

        string strResult = "";
        string strResultBase = numResult.getResultChar();
        for(int i = 1; i <= strResultBase.size(); i++){
            strResult += strResultBase[i - 1];
            if(!(i % 60)){
                strResult += "\n";
            }
        }
        ui->labelResult->setText(QString(strResult.c_str()));

        updateSans(false);
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans(true);
    }
}

void MainMenu::on_btnDivision_clicked() {
    string inputNum1 = ui->inputNum1->text().toStdString();
    string inputNum2 = ui->inputNum2->text().toStdString();

    if(checkValue(inputNum1) && checkValue(inputNum2)){
        inf_int num1(inputNum1.c_str());
        inf_int num2(inputNum2.c_str());
        inf_int numResult = num1 / num2;

        string strResult = "";
        string strResultBase = numResult.getResultChar();
        for(int i = 1; i <= strResultBase.size(); i++){
            strResult += strResultBase[i - 1];
            if(!(i % 60)){
                strResult += "\n";
            }
        }
        ui->labelResult->setText(QString(strResult.c_str()));

        if(numResult.getResultChar() != "NaN"){
            updateSans(false);
        }else{
            updateSans(true);
        }
    }else{
        ui->labelResult->setText(QString("Wrong Input"));

        updateSans(true);
    }
}

void MainMenu::updateSans(bool isError) {
    if(isError){
        ui->labelImage->setPixmap(sansPixmap[2].scaled(200, 200, Qt::KeepAspectRatio));
        return;
    }

    if(sansFlag){
        sansFlag = false;
        ui->labelImage->setPixmap(sansPixmap[0].scaled(200, 200, Qt::KeepAspectRatio));
    }else{
        sansFlag = true;
        ui->labelImage->setPixmap(sansPixmap[1].scaled(200, 200, Qt::KeepAspectRatio));
    }
}