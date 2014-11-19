#ifndef FORM_H
#define FORM_H

class Form;

#include <QWidget>
#include <QSettings>

#include "Item.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(Item* itemParent, QSettings* pref = 0, QString nom = QString(), QWidget *parent = 0);
    ~Form();

    void Enregistrer(QSettings* pref);

private slots:
    void on_nom_textChanged(const QString &arg1);

    void on_desc_textChanged();

    void on_steam_toggled(bool checked);

    void on_path_textChanged(const QString &arg1);

    void on_parcourir_clicked();

    void on_gameID_textChanged(const QString &arg1);

    void on_bdd_clicked();

    void on_pwd_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    Item*   itemParent;

    QString nom;
    QString desc;
    QString path;
    QPixmap icon;
    bool    pwd;
    bool    steam;
    QString gameID;
};

#endif // FORM_H
