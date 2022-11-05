#ifndef OOP_ASSIGNMENT_2_MAINMENU_H
#define OOP_ASSIGNMENT_2_MAINMENU_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget {
Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);

    ~MainMenu() override;

    bool sansFlag = false;

private:
    QPixmap sansPixmap[2];

    Ui::MainMenu *ui;

private slots:
    void on_btnPlus_clicked();
    void on_btnMinus_clicked();
    void on_btnMultiply_clicked();
    void on_btnDivision_clicked();
};


#endif //OOP_ASSIGNMENT_2_MAINMENU_H
