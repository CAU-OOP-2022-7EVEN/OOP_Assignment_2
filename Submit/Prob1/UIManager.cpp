#include <QApplication>
#include "UIManager.h"
#include "QT_UI/mainmenu.h"

void openMainMenu(int argc, char** argv){
    QApplication app(argc, argv);

    MainMenu mainMenu;
    mainMenu.show();

    app.exec();
}