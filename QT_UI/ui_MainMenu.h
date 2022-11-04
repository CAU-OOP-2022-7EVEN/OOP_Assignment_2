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
    QVBoxLayout *layoutLeft;
    QLabel *labelNum1;
    QLineEdit *inputNum1;
    QLabel *labelNum2;
    QLineEdit *inputNum2;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QPushButton *btnMultiply;
    QPushButton *btnDivision;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 400);
        layoutRightContainer = new QWidget(MainMenu);
        layoutRightContainer->setObjectName(QString::fromUtf8("layoutRightContainer"));
        layoutRightContainer->setGeometry(QRect(400, 0, 400, 400));
        layoutRight = new QVBoxLayout(layoutRightContainer);
        layoutRight->setObjectName(QString::fromUtf8("layoutRight"));
        layoutRight->setContentsMargins(0, 0, 0, 0);
        labelResult = new QLabel(layoutRightContainer);
        labelResult->setObjectName(QString::fromUtf8("labelResult"));

        layoutRight->addWidget(labelResult);

        layoutLeftContainer = new QWidget(MainMenu);
        layoutLeftContainer->setObjectName(QString::fromUtf8("layoutLeftContainer"));
        layoutLeftContainer->setGeometry(QRect(0, 0, 400, 400));
        layoutLeft = new QVBoxLayout(layoutLeftContainer);
        layoutLeft->setObjectName(QString::fromUtf8("layoutLeft"));
        layoutLeft->setContentsMargins(0, 0, 0, 0);
        labelNum1 = new QLabel(layoutLeftContainer);
        labelNum1->setObjectName(QString::fromUtf8("labelNum1"));

        layoutLeft->addWidget(labelNum1);

        inputNum1 = new QLineEdit(layoutLeftContainer);
        inputNum1->setObjectName(QString::fromUtf8("inputNum1"));

        layoutLeft->addWidget(inputNum1);

        labelNum2 = new QLabel(layoutLeftContainer);
        labelNum2->setObjectName(QString::fromUtf8("labelNum2"));

        layoutLeft->addWidget(labelNum2);

        inputNum2 = new QLineEdit(layoutLeftContainer);
        inputNum2->setObjectName(QString::fromUtf8("inputNum2"));

        layoutLeft->addWidget(inputNum2);

        btnPlus = new QPushButton(layoutLeftContainer);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));

        layoutLeft->addWidget(btnPlus);

        btnMinus = new QPushButton(layoutLeftContainer);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));

        layoutLeft->addWidget(btnMinus);

        btnMultiply = new QPushButton(layoutLeftContainer);
        btnMultiply->setObjectName(QString::fromUtf8("btnMultiply"));

        layoutLeft->addWidget(btnMultiply);

        btnDivision = new QPushButton(layoutLeftContainer);
        btnDivision->setObjectName(QString::fromUtf8("btnDivision"));

        layoutLeft->addWidget(btnDivision);


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
