/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *layoutRightContainer;
    QVBoxLayout *layoutRight;
    QLabel *labelResult;
    QWidget *layoutLeftContainer;
    QWidget *layoutLeftInputContainer;
    QVBoxLayout *layoutLeftInput;
    QLabel *labelNum1;
    QLineEdit *inputNum1;
    QLabel *labelNum2;
    QLineEdit *inputNum2;
    QWidget *layoutLeftBtnContainer;
    QVBoxLayout *layoutLeftBtn;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QPushButton *btnMultiply;
    QPushButton *btnDivision;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 300);
        layoutRightContainer = new QWidget(MainMenu);
        layoutRightContainer->setObjectName(QString::fromUtf8("layoutRightContainer"));
        layoutRightContainer->setGeometry(QRect(400, 0, 400, 300));
        layoutRight = new QVBoxLayout(layoutRightContainer);
        layoutRight->setObjectName(QString::fromUtf8("layoutRight"));
        layoutRight->setContentsMargins(0, 0, 0, 0);
        labelResult = new QLabel(layoutRightContainer);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));

        layoutRight->addWidget(labelResult);

        layoutLeftContainer = new QWidget(MainMenu);
        layoutLeftContainer->setObjectName(QString::fromUtf8("layoutLeftContainer"));
        layoutLeftContainer->setGeometry(QRect(0, 0, 400, 300));
        layoutLeftInputContainer = new QWidget(layoutLeftContainer);
        layoutLeftInputContainer->setObjectName(QString::fromUtf8("layoutLeftInputContainer"));
        layoutLeftInputContainer->setGeometry(QRect(0, 0, 400, 100));
        layoutLeftInput = new QVBoxLayout(layoutLeftInputContainer);
        layoutLeftInput->setObjectName(QString::fromUtf8("layoutLeftInput"));
        layoutLeftInput->setContentsMargins(0, 0, 0, 0);
        labelNum1 = new QLabel(layoutLeftInputContainer);
        labelNum1->setObjectName(QString::fromUtf8("labelNum1"));

        layoutLeftInput->addWidget(labelNum1);

        inputNum1 = new QLineEdit(layoutLeftInputContainer);
        inputNum1->setObjectName(QString::fromUtf8("inputNum1"));

        layoutLeftInput->addWidget(inputNum1);

        labelNum2 = new QLabel(layoutLeftInputContainer);
        labelNum2->setObjectName(QString::fromUtf8("labelNum2"));

        layoutLeftInput->addWidget(labelNum2);

        inputNum2 = new QLineEdit(layoutLeftInputContainer);
        inputNum2->setObjectName(QString::fromUtf8("inputNum2"));

        layoutLeftInput->addWidget(inputNum2);

        layoutLeftBtnContainer = new QWidget(layoutLeftContainer);
        layoutLeftBtnContainer->setObjectName(QString::fromUtf8("layoutLeftBtnContainer"));
        layoutLeftBtnContainer->setGeometry(QRect(0, 150, 400, 150));
        layoutLeftBtn = new QVBoxLayout(layoutLeftBtnContainer);
        layoutLeftBtn->setObjectName(QString::fromUtf8("layoutLeftBtn"));
        layoutLeftBtn->setContentsMargins(0, 0, 0, 0);
        btnPlus = new QPushButton(layoutLeftBtnContainer);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));

        layoutLeftBtn->addWidget(btnPlus);

        btnMinus = new QPushButton(layoutLeftBtnContainer);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));

        layoutLeftBtn->addWidget(btnMinus);

        btnMultiply = new QPushButton(layoutLeftBtnContainer);
        btnMultiply->setObjectName(QString::fromUtf8("btnMultiply"));

        layoutLeftBtn->addWidget(btnMultiply);

        btnDivision = new QPushButton(layoutLeftBtnContainer);
        btnDivision->setObjectName(QString::fromUtf8("btnDivision"));

        layoutLeftBtn->addWidget(btnDivision);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        labelResult->setText(QCoreApplication::translate("MainMenu", "Wa! Sans! RESULT_VIEW", nullptr));
        labelNum1->setText(QCoreApplication::translate("MainMenu", "Number 1", nullptr));
        labelNum2->setText(QCoreApplication::translate("MainMenu", "Number 2", nullptr));
        btnPlus->setText(QCoreApplication::translate("MainMenu", "Plus (+)", nullptr));
        btnMinus->setText(QCoreApplication::translate("MainMenu", "Minus (-)", nullptr));
        btnMultiply->setText(QCoreApplication::translate("MainMenu", "Multiply (*)", nullptr));
        btnDivision->setText(QCoreApplication::translate("MainMenu", "Division (/)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
