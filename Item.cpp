#include "Item.h"

//Représente un jeu dans la liste
Item::Item():
    QStandardItem   ("Nouveau Jeu"),
    jeu             (new Form(this))
{
}

Item::Item(QSettings* pref, QString nom):
    QStandardItem   (nom),
    jeu             (new Form(this, pref, nom))
{
}

Item::~Item()
{
    jeu->deleteLater();
}

//enregistre les donnée dans le fichier de config donné
void Item::Enregistrer(QSettings* pref)
{
    jeu->Enregistrer(pref);
}

//Change le nom affiché dans la liste
void Item::nom(QString nom)
{
    setText(nom);
}

//Change l'icon affiché dans la liste
void Item::icon(QPixmap icon)
{
    setIcon(QIcon(icon));
}

//Retourne le widget formulaire d'édition du jeu
QWidget* Item::getJeu()
{
    return jeu;
}
