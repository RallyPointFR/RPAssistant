#ifndef ITEM_H
#define ITEM_H

class Item;

#include <QStandardItem>

#include "Form.h"

class Item : public QStandardItem
{
public:
    Item();
    Item(QSettings* pref, QString nom);
    ~Item();

    void Enregistrer(QSettings* pref);

    QWidget* getJeu();

    void nom(QString nom);
    void icon(QPixmap icon);

private:
    Form* jeu;
};

#endif // ITEM_H
