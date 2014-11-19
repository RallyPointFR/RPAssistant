#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //Init de l'appli
    QApplication a(argc, argv);

    //Déclaration et affichage de la main window
    MainWindow w;
    w.show();

    //exec de l'appli
    return a.exec();
}
