#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow;

#include <QMainWindow>
#include <QStandardItemModel>
#include <QCloseEvent>

#include "Item.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* e); //Event de fermeture

private slots:
    void on_ajouter_clicked(); //Ajouter un jeu

    void on_retirer_clicked(); //Retirer un jeu

    void on_listView_doubleClicked(const QModelIndex &index); //Double click dans la liste

    void on_pushButton_clicked(); //Parcourir pour steam

    void on_steamPath_textChanged(const QString &arg1); //Edition manuel du path steam

private:
    void loadWidget(QWidget* widget); //Chargement du widget central

    Ui::MainWindow *ui; //Interface
    QStandardItemModel* model; //Model pour la liste
    QWidget* currentWidget; //Widget actuellement au centre

    QString steamPath; //Path steam
};

#endif // MAINWINDOW_H
