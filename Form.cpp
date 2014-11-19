#include <QFileDialog>
#include <QDesktopServices>

#include "Form.h"
#include "ui_Form.h"

Form::Form(Item *itemParent, QSettings* pref, QString nom, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    itemParent(itemParent),
    pwd(false),
    steam(false)
{
    ui->setupUi(this);

    //Si il y a un fichier de conf donné, on met directement en place le formulaire
    if(pref != 0)
    {
        this->nom = nom;
        ui->nom->setText(nom);

        desc = pref->value(nom + "/desc").toString();
        ui->desc->setPlainText(desc);

        steam = pref->value(nom + "/steam").toBool();
        ui->steam->setChecked(steam);

        on_steam_toggled(steam);

        path = pref->value(nom + "/path").toString();
        ui->path->setText(path);

        gameID = pref->value(nom + "/gameID").toString();
        ui->gameID->setText(gameID);

        pwd = pref->value(nom + "/pwd").toBool();
        ui->pwd->setChecked(pwd);

        itemParent->icon(QPixmap("icons/" + nom + ".png"));
        ui->Icon->setPixmap(QPixmap("icons/" + nom + ".png").scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

Form::~Form()
{
    delete ui;
}

//Enregistre les modif
void Form::Enregistrer(QSettings* pref)
{
    pref->setValue(nom + "/desc", QVariant(desc));
    pref->setValue(nom + "/path", QVariant(path));
    pref->setValue(nom + "/pwd", QVariant(pwd));
    pref->setValue(nom + "/steam", QVariant(steam));
    pref->setValue(nom + "/gameID", QVariant(gameID));
    icon.save("icons/" + nom + ".png", 0, 100);
}

//Quand on change le nom
void Form::on_nom_textChanged(const QString &arg1)
{
    nom = arg1;
    itemParent->nom(nom);
}

//Quand on change la desc
void Form::on_desc_textChanged()
{
    desc = ui->desc->toPlainText();
}

//Si on check Steam
void Form::on_steam_toggled(bool checked)
{
    steam = checked;

    if(checked)
        ui->path->setText("Steam");
    else
        ui->path->setText("");

    ui->path->setEnabled(!checked);
    ui->parcourir->setEnabled(!checked);
    ui->gameID->setEnabled(checked);
    ui->bdd->setEnabled(checked);
}

//Quand on modifie le path
void Form::on_path_textChanged(const QString &arg1)
{
    path = arg1;
}

//Quand on clic sur parcourir pour le path
void Form::on_parcourir_clicked()
{
    path = QFileDialog::getOpenFileName(this, "Exe d'un jeu", "", "Executables (*.exe)");
    ui->path->setText(path);
}

//Quand on modifie le gameID
void Form::on_gameID_textChanged(const QString &arg1)
{
    gameID = arg1;
}

//Quand on click sur le bouton pour acceder à la bdd steam (lance un navigateur)
void Form::on_bdd_clicked()
{
    QDesktopServices::openUrl(QUrl("https://steamdb.info/search/"));
}

//Si on check pour le mdp
void Form::on_pwd_toggled(bool checked)
{
    pwd = checked;
}

//Quand on click sur parcourir pour l'icon
void Form::on_pushButton_clicked()
{
    icon = QPixmap(QFileDialog::getOpenFileName(this, "icon du jeu", "", "")).scaled(48, 48, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->Icon->setPixmap(icon);
    itemParent->icon(icon);
}
