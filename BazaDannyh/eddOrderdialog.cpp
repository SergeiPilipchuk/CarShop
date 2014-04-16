#include "edddOrderdialog.h"
#include "constants.h"
EddOrderDialog::EddOrderDialog(QWidget *parent):
        QDialog(parent)
{
    QLabel *CarIDlbl = new QLabel("CarID");
    CarID=new QLineEdit;

    QLabel *OrderIDlbl = new QLabel("OrderID");
    OrderID = new QLineEdit;

    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Cancel");

    db=QSqlDatabase::database("mydb");
    query=new QSqlQuery(db);

   connect(Cancel,SIGNAL(clicked()),this,SLOT(reject()));
   // connect(addBtn,SIGNAL(clicked()),this,SLOT(add()));

        QGridLayout *layout = new QGridLayout;
    layout->addWidget(CarIDlbl,0,0);
    layout->addWidget(CarID,0,1);
    layout->addWidget(OrderIDlbl,1,0);
    layout->addWidget(OrderID,1,1);


    QHBoxLayout *buttonLayout2=new QHBoxLayout;
    buttonLayout2->addWidget(Ok);
    buttonLayout2->addWidget(Cancel);

	QVBoxLayout *vbox=new QVBoxLayout;
        vbox->addLayout(layout);
        vbox->addLayout(buttonLayout2);


        /*connect(LoadImg,SIGNAL(clicked()),this,
                      SLOT(load()));*/


    setLayout(vbox);
    setWindowTitle("Edding Order");
}

void EddOrderDialog::setOrderID(QString str5){
    OrdId=str5.toInt();
    int index;

            QString query_str=QString("SELECT  "
                                      "FROM Orders "
                                      "WHERE OrderID='%1' ").arg(OrdId);
    bool res=query->exec(query_str);
    if (!res)QMessageBox::information(this,"Error","Kukaracha1");
   query->next();

//«аполн€ю пол€ в диалоговом окне начальными данными машины, которую мы хотим отредактировать
    int IndexMarka=query->record().indexOf("Marka");
    QString Marka=query->value(IndexMarka).toString();
    Mark->setText(Marka);

    int IndexStrana=query->record().indexOf("Strana");
    QString Strana=query->value(IndexStrana).toString();
    Stra->setText(Strana);

    int IndexCena=query->record().indexOf("Cena");
    int Cena=query->value(IndexCena).toInt();
    Cen->setText(QString::number(Cena));

    int IndexCvet=query->record().indexOf("Cvet");
    QString Cvet=query->value(IndexCvet).toString();
    index=Cve->findText(Cvet);
    Cve->setCurrentIndex(index);

    int IndexKuzov=query->record().indexOf("Kuzov");
    QString Kuzov=query->value(IndexKuzov).toString();
    index=Kuz->findText(Kuzov);
    Kuz->setCurrentIndex(index);

    int IndexLoshad_sil=query->record().indexOf("Loshad_sil");
    int Loshad_sil=query->value(IndexLoshad_sil).toInt();
    Loshad->setText(QString::number(Loshad_sil));

    int IndexDvigatel=query->record().indexOf("Dvigatel");
    int Dvigatel=query->value(IndexDvigatel).toInt();
    Dvig->setText(QString::number(Dvigatel));

    int IndexKorobka=query->record().indexOf("Korobka");
    QString Korobka=query->value(IndexKorobka).toString();
    index=Korob->findText(Korobka);
    Korob->setCurrentIndex(index);

    int IndexModelName=query->record().indexOf("ModelName");
    QString ModelName=query->value(IndexModelName).toString();
    ModName->setText(ModelName);

}
bool EddDialog::GetData(QString &Marka,QString &Strana,QString &Model,double &Dvigatel,int &loshad_sil,QString &Korobka,int &Cena,QString &Cvet,QString &Kuzov){
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
void EddDialog::edit(){
    bool rez;
    QString str;
    int OrdId;
    int res=QMessageBox::question(this,"Eddit","Do you really want to eddit Car?",QMessageBox::Yes|QMessageBox::No);
    if (res==QMessageBox::Yes){


   //теперь вставл€ем отредактированную машину
        QString Marka,Strana,Model,Korobka,Cvet,Kuzov;
       double Dvigatel;
        int loshad_sil,Cena,ModID,CaID;
        CaID=0;
        ModID=0;
        bool res2;


        bool res1=GetData(Marka,Strana,Model,Dvigatel,loshad_sil,Korobka,Cena,Cvet,Kuzov);
        if (!res1) {QMessageBox::information(this,"Error","Kukaracha Dannye ne shitalis"); return;}
        //провер€ю есть ли уже така€ модель в списке
        QString str=QString("SELECT * "
                            "FROM Models WHERE ModelName='%1' ").arg(Model);
        res1=query->exec(str);
        if (res1){query->next();
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
            else {QMessageBox::information(this,"Error","Kukaracha11"); return;}

            //и узнаю ее ID
            str=QString("SELECT * "
                                    "FROM Models WHERE ModelName='%1' ").arg(Model);
                res1=query->exec(str);
                if (res1){
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
        else {QMessageBox::information(this,"Error","Kukaracha12"); return;}
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
            else {QMessageBox::information(this,"Error","Kukaracha13"); return;}

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
        else {QMessageBox::information(this,"Error","Kukaracha14"); return;}

        //5)т.к CarID помен€дс€ надо его еще помен€ть в таблице OrdCar
        QString s=QString("SELECT * "
                          "FROM OrdCar WHERE CarID='%1' ").arg(CarId);

       queryForOrdCar->exec(s);
       while (queryForOrdCar->next()){
           OrdId=queryForOrdCar->value(1).toInt();
        query->prepare("INSERT INTO "
                       " OrdCar (CarID,OrderID) "
                       " VALUES (?,?)");
        query->addBindValue(CaID);
        query->addBindValue(OrdId);

        res2=query->exec();
        if (res2){
            QMessageBox::information(this,"Vse super","OrdCar was succesfully edded");
            accept(); }
        else {QMessageBox::information(this,"Error","Kukaracha15"); return;}}

       //DELETE старую машину
        //1
        str=QString ("DELETE "
                     "FROM Details WHERE CarID='%1' ").arg(CarId);
            rez=query->exec(str);
            if (rez)QMessageBox::information(this,"Vse super","Details succesfuly delete");
            else QMessageBox::information(this,"Error","Kukaracha");

        //2
        str=QString ("DELETE "
                     "FROM Xarak_ki WHERE CarID='%1' ").arg(CarId);
            rez=query->exec(str);
            if (rez)QMessageBox::information(this,"Vse super","Xarak_ki succesfuly delete");
            else QMessageBox::information(this,"Error","Kukaracha");

        //3
        str=QString ("DELETE "
                     "FROM Cars WHERE CarID='%1' ").arg(CarId);

            rez=query->exec(str);
            if (rez)QMessageBox::information(this,"Vse super","Car succesfuly delete");
            else QMessageBox::information(this,"Error","Kukaracha");

}
}
