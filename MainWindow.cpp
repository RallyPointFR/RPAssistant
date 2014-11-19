#include <QFileDialog>
#include <QDebug>

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow (parent),
    ui          (new Ui::MainWindow),
    model       (new QStandardItemModel),
    currentWidget(0)
{
    //Mis en place de l'interface
    ui->setupUi(this);
    //Définition du model pour la liste
    ui->listView->setModel(model);

    //Chargement de la liste existante
    QSettings pref("pref.ini", QSettings::IniFormat);

    QStringList listeJeux(pref.childGroups());

    for(register int i = 0; i < listeJeux.length(); i++)
        model->appendRow(new Item(&pref, listeJeux[i]));

    //Chargement du path vers steam (si non existant : val par défaut)
    steamPath = pref.value("steamPath", QVariant("C:/Program Files (x86)/Steam/Steam.exe")).toString();
    ui->steamPath->setText(steamPath);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Event de fermeture : on enregistre toute les modifs
void MainWindow::closeEvent(QCloseEvent* e)
{
    setEnabled(false);

    QSettings pref("pref.ini", QSettings::IniFormat);

    QStringList mails   (pref.value("email").toStringList());

    pref.clear();

    pref.setValue("steamPath", QVariant(steamPath));
    pref.setValue("email", QVariant(mails));

    QList<QStandardItem*> list (model->takeColumn(0));

    for(register int i = 0; i < list.length(); i++)
    {
        static_cast<Item*>(list[i])->Enregistrer(&pref);
    }

    e->accept();
}

//on ajoute un nouveau jeu
void MainWindow::on_ajouter_clicked()
{
    Item* newItem(new Item);
    model->appendRow(newItem);

    loadWidget(newItem->getJeu());
}

//On retire le jeu selectionné
void MainWindow::on_retirer_clicked()
{
    model->removeRow(ui->listView->currentIndex().row());
    Item* rechargement (static_cast<Item*>(model->item(0)));
    if(rechargement != 0)
        loadWidget(rechargement->getJeu());
    else
        loadWidget(0);
}

//Quand on double click sur un jeu, on charge son formulaire d'édition
void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    loadWidget(static_cast<Item*>(model->itemFromIndex(index))->getJeu());
}

//Charge le widget donné en paramètre dans la zone centrale de l'appli
void MainWindow::loadWidget(QWidget* widget)
{
    if(currentWidget != 0)
    {
        ui->frame->layout()->removeWidget(currentWidget);
        currentWidget->hide();
        currentWidget->setParent(0);
    }

    if(widget != 0)
    {
        ui->frame->layout()->addWidget(widget);
        widget->show();
    }

    currentWidget = widget;
}

//Bouton parcourir du path steam
void MainWindow::on_pushButton_clicked()
{
    ui->steamPath->setText(QFileDialog::getOpenFileName(this, "Executable Steam"));
}

void MainWindow::on_steamPath_textChanged(const QString &arg1)
{
    steamPath = arg1;
}
