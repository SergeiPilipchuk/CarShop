#include "newCardialog.h"

NewCarDialog::NewCarDialog(QWidget *parent):
        QDialog(parent)
{

    QLabel *Marklbl = new QLabel("Marka");
    Mark = new QLineEdit;

    QLabel *Stralbl = new QLabel("Strana");
    Stra=new QLineEdit;

    QLabel *ModNamelbl = new QLabel("Model");
    ModName =new QLineEdit;

    QLabel *Dviglbl = new QLabel("Dvigatel");
    Dvig = new QLineEdit;
    QLabel *Loshadlbl = new QLabel("Loshad_sil");
    Loshad = new QLineEdit;
    QLabel *Cenlbl = new QLabel("Cena");
    Cen = new QLineEdit;

    QLabel *Koroblbl = new QLabel("Korobka");
    Korob=new QComboBox;
    QLabel *Cvelbl = new QLabel("Cvet");
    Cve=new QComboBox;
    QLabel *Kuzlbl = new QLabel("Kuzov");
    Kuz=new QComboBox;

    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Cancel");

    db=QSqlDatabase::database("mydb");
    query=new QSqlQuery(db);

    query->exec("SELECT Korobka FROM Xarak_ki GROUP BY Korobka");
    while(query->next()){
        Korob->addItem(query->value(0).toString());}

    query->exec("SELECT Cvet FROM Details GROUP BY Cvet");
    while(query->next()){
        Cve->addItem(query->value(0).toString());}

    query->exec("SELECT Kuzov FROM Details GROUP BY Kuzov");
    while(query->next()){
        Kuz->addItem(query->value(0).toString());}

   connect(Cancel,SIGNAL(clicked()),this,SLOT(reject()));
   // connect(addBtn,SIGNAL(clicked()),this,SLOT(add()));

        QGridLayout *layout = new QGridLayout;
    layout->addWidget(Marklbl,0,0);
    layout->addWidget(Mark,0,1);
    layout->addWidget(Stralbl,1,0);
    layout->addWidget(Stra,1,1);
    layout->addWidget(ModNamelbl,2,0);
    layout->addWidget(ModName,2,1);
    layout->addWidget(Dviglbl,3,0);
    layout->addWidget(Dvig,3,1);
    layout->addWidget(Loshadlbl,4,0);
    layout->addWidget(Loshad,4,1);
    layout->addWidget(Koroblbl,5,0);
    layout->addWidget(Korob,5,1);
    layout->addWidget(Cenlbl,6,0);
    layout->addWidget(Cen,6,1);
    layout->addWidget(Cvelbl,7,0);
    layout->addWidget(Cve,7,1);
    layout->addWidget(Kuzlbl,8,0);
    layout->addWidget(Kuz,8,1);

    QHBoxLayout *buttonLayout2=new QHBoxLayout;
    buttonLayout2->addWidget(Ok);
    buttonLayout2->addWidget(Cancel);

        QVBoxLayout *vbox=new QVBoxLayout;
        vbox->addLayout(layout);
        vbox->addLayout(buttonLayout2);

       connect(Ok,SIGNAL(clicked()),this,SLOT(insert()));


    setLayout(vbox);
    setWindowTitle("NewCar");
}


bool NewCarDialog::GetData(QString &Marka,QString &Strana,QString &Model,double &Dvigatel,int &loshad_sil,QString &Korobka,int &Cena,QString &Cvet,QString &Kuzov){
    //Marka
    Marka=Mark->text();
    if (Marka.isEmpty()){
        QMessageBox::warning(this,"Error","Marka Name can't be empty");
        return false;
    }
    //Strana
    Strana=Stra->text();

    //Model
    Model=ModName->text();
    if (Model.isEmpty()){
        QMessageBox::warning(this,"Error","Model Name can't be empty");
        return false;
    }

    //Model
    Model=ModName->text();
    if (Model.isEmpty()){
        QMessageBox::warning(this,"Error","Model Name can't be empty");
        return false;
    }

    //Dvigatel
    QString str=Dvig->text();
    bool res;
    Dvigatel=str.toDouble(&res);
    if (!res||Dvigatel<0){
        Dvigatel=0;
        QMessageBox::warning(this,"Error","Dvigatel must contain positive double value");
        Dvig->setText(QString::number(0));
        return false;
    }
    //loshad_sil
    str=Loshad->text();

    loshad_sil=str.toInt(&res);
    if (!res||loshad_sil<0){
        loshad_sil=0;
        QMessageBox::warning(this,"Error","Loshad_sil must contain positive int value");
        Loshad->setText(QString::number(0));
        return false;
    }
    //Korobka
    Korobka=Korob->currentText();

    //Cena
    str=Cen->text();

    Cena=str.toInt(&res);
    if (!res||Cena<0){
        Cena=0;
        QMessageBox::warning(this,"Error","Cena must contain positive int value");
        Cen->setText(QString::number(0));
        return false;
    }

    //Cvet
    Cvet=Cve->currentText();
    //Kuzov
    Kuzov=Kuz->currentText();
return true;
}

void NewCarDialog::insert(){

    QString Marka,Strana,Model,Korobka,Cvet,Kuzov;
   double Dvigatel;
    int loshad_sil,Cena,ModID,CaID;
    CaID=0;
    ModID=0;
    bool res2;


    bool res=GetData(Marka,Strana,Model,Dvigatel,loshad_sil,Korobka,Cena,Cvet,Kuzov);
    if (!res) {QMessageBox::information(this,"Error","Kukaracha"); return;}
    //провер€ю есть ли уже така€ модель в списке
    QString str=QString("SELECT * "
                        "FROM Models WHERE ModelName='%1' ").arg(Model);
    res=query->exec(str);
    if (res){query->next();
        ModID=query->value(0).toInt();//если есть то записываю ее ID
    }
    //1)если такой модели нет, то вставл€ю ее
    if (ModID==0){
        query->prepare("INSERT INTO "
                       " Models (ModelName) "
                       " VALUES (?)");
        query->addBindValue(Model);
        res2=query->exec();
        if (res2){
            QMessageBox::information(this,"Vse super","New Model was succesfully added");
            accept(); }
        else {QMessageBox::information(this,"Error","Kukaracha"); return;}

        //и узнаю ее ID
        str=QString("SELECT * "
                                "FROM Models WHERE ModelName='%1' ").arg(Model);
            res=query->exec(str);
            if (res){
                query->next();
                ModID=query->value(0).toInt();
            }
    }

    //2)¬—“ј¬Ћя≈ћ ћјЎ»Ќ”
    query->prepare("INSERT INTO "
                   " Cars (ModelID,Marka,Strana) "
                   " VALUES (?,?,?)");
    query->addBindValue(ModID);
    query->addBindValue(Marka);
    query->addBindValue(Strana);
    res2=query->exec();
    if (res2){
        QMessageBox::information(this,"Vse super","New Car was succesfully added");
        accept(); }
    else {QMessageBox::information(this,"Error","Kukaracha"); return;}
    //мы вставили машину в Cars теперь узнаем ее ID
        str=QString("SELECT * "
                                "FROM Cars");
            res=query->exec(str);

            if (res){
                query->last();
                CaID=query->value(0).toInt();
            }
    //3)вставл€ем характеристики машины
        query->prepare("INSERT INTO "
                       " Xarak_ki (Loshad_sil,CarID,Dvigatel,Korobka) "
                       " VALUES (?,?,?,?)");
        if (Loshad->text().isEmpty()) {
            query->addBindValue(QVariant(QVariant::Int));//задает NULL значение дл€ int
        }
         else query->addBindValue(loshad_sil);

        query->addBindValue(CaID);
        query->addBindValue(Dvigatel);
        query->addBindValue(Korobka);
        res2=query->exec();
        if (res2){
            QMessageBox::information(this,"Vse super","New Xarak_ki was succesfully added");
            accept(); }
        else {QMessageBox::information(this,"Error","Kukaracha"); return;}
       //4)вставл€ем details машины
                query->prepare("INSERT INTO "
                               " Details (Cena,CarID,Cvet,Kuzov) "
                               " VALUES (?,?,?,?)");
                if (Cen->text().isEmpty()) {
                    query->addBindValue(QVariant(QVariant::Int));//задает NULL значение дл€ int
                }
                 else query->addBindValue(Cena);

                query->addBindValue(CaID);
                query->addBindValue(Cvet);
                query->addBindValue(Kuzov);

                res2=query->exec();
    if (res2){
        QMessageBox::information(this,"Vse super","New Details was succesfully added");
        accept(); }
    else {QMessageBox::information(this,"Error","Kukaracha"); return;}


}
void NewCarDialog::clear_pole(){
    Mark->clear();
    Stra->clear();
    ModName->clear();
    Dvig->clear();
    Loshad->clear();
    Cen->clear();
}
