#include "newOrderdialog.h"

NewOrderDialog::NewOrderDialog(QWidget *parent):
        QDialog(parent)
{


    QLabel *Fiolbl = new QLabel("FIO");
    Fio = new QLineEdit;

    QLabel *Tellbl = new QLabel("Tel");
    Tel=new QLineEdit;

    QLabel *KlienIDlbl = new QLabel("KlientID");
    KlienID=new QLineEdit;

    QLabel *OrdIDlbl = new QLabel("OrderID");
    OrdID =new QLineEdit;

    QLabel *OrdDatelbl = new QLabel("OrderDate");
    OrdDate = new QLineEdit;

    QLabel *OrdCarIDlbl = new QLabel("OrdCarID");
    OrdCarID = new QLineEdit;


    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Cancel");

    db=QSqlDatabase::database("mydb");
    query=new QSqlQuery(db);

    QGroupBox* Klientbox=new QGroupBox("Klient");
    QGroupBox* Orderbox=new QGroupBox("Order");


   connect(Cancel,SIGNAL(clicked()),this,SLOT(reject()));
   // connect(addBtn,SIGNAL(clicked()),this,SLOT(add()));

        QGridLayout *layout1 = new QGridLayout;
    layout1->addWidget(Fiolbl,0,0);
    layout1->addWidget(Fio,0,1);
    layout1->addWidget(Tellbl,1,0);
    layout1->addWidget(Tel,1,1);
    layout1->addWidget(KlienIDlbl,2,0);
    layout1->addWidget(KlienID,2,1);

    Klientbox->setLayout(layout1);

    QGridLayout *layout2 = new QGridLayout;
layout2->addWidget(OrdIDlbl,0,0);
layout2->addWidget(OrdID,0,1);
layout2->addWidget(OrdDatelbl,1,0);
layout2->addWidget(OrdDate,1,1);
layout2->addWidget(OrdCarIDlbl,2,0);
layout2->addWidget(OrdCarID,2,1);

Orderbox->setLayout(layout2);

    QHBoxLayout *buttonLayout2=new QHBoxLayout;
    buttonLayout2->addWidget(Ok);
    buttonLayout2->addWidget(Cancel);

        QVBoxLayout *vbox=new QVBoxLayout;
        vbox->addWidget(Klientbox);
        vbox->addWidget(Orderbox);
        vbox->addLayout(buttonLayout2);

       connect(Ok,SIGNAL(clicked()),this,SLOT(insert()));


    setLayout(vbox);
    setWindowTitle("NewOrder");
}


bool NewOrderDialog::GetData(QString &Ffio,int & Ttel,int & KklienID,int &OordId,QString &OordDate,int &OordCarID){
    QString str;
    //Ffio
    Ffio=Fio->text();
    //Ttel
    str=Tel->text();
    Ttel=str.toInt();
    //KklienID
    str=KlienID->text();
    if (str.isEmpty()) KklienID=0;
    else KklienID=str.toInt();

    //OordId
    str=OrdID->text();
    if (str.isEmpty()) OordId=0;
    else OordId=str.toInt();


    //OrdDate
    OordDate=OrdDate->text();

    //OordCarID
    str=OrdCarID->text();
    OordCarID=str.toInt();
return true;
}

void NewOrderDialog::insert(){
    QString Ffio;
    QString OordDate;
    int Ttel,KklientID,OordId,OordCarID;
    bool res2;
    QString str;


    bool res=GetData(Ffio,Ttel,KklientID,OordId,OordDate,OordCarID);
    if (!res) {QMessageBox::information(this,"Error","Kukaracha"); return;}
    //1)если новый клиент то вставляем его
    if (KklientID==0)  {
        query->prepare("INSERT INTO "
                       " Klients (FIO,Tel) "
                       " VALUES (?,?)");
        query->addBindValue(Ffio);
        query->addBindValue(Ttel);
        res2=query->exec();
        if (res2){
            QMessageBox::information(this,"Vse super","New Klient was succesfully added");
            accept(); }
    else {QMessageBox::information(this,"Error","Kukaracha"); return;}

         //теперь узнаем его ID
            str=QString("SELECT * "
                                    "FROM Klients WHERE FIO='%1' AND Tel='%2' ").arg(Ffio).arg(Ttel);
                res=query->exec(str);
                if (res){
                    query->next();
                    KklientID=query->value(0).toInt();
                }
    }

    //2)вставляем заказ
        if (OordId!=0){
    /*query->prepare("INSERT INTO "
                   " Orders (OrderID,OrderDate,KlientID) "
                   " VALUES (?,?,?)");
    query->addBindValue(OordId);
    query->addBindValue(OordDate);
    query->addBindValue(KklientID);
    res2=query->exec();
    if (res2){
        QMessageBox::information(this,"Vse super","New Order was succesfully added");
        accept(); }
    else {QMessageBox::information(this,"Error","Kukaracha Order"); return;}*/

        }
        else {
            query->prepare("INSERT INTO "
                           " Orders (OrderDate,KlientID) "
                           " VALUES (?,?)");
            query->addBindValue(OordDate);
            query->addBindValue(KklientID);
            res2=query->exec();
            if (res2){
                QMessageBox::information(this,"Vse super","New Order was succesfully added");
                accept(); }
            else {QMessageBox::information(this,"Error","Kukaracha"); }

            //мы вставили заказ в Order теперь узнаем ее ID
                str=QString("SELECT * "
                            "FROM Orders WHERE KlientID='%1' AND OrderDate='%2' ").arg(KklientID).arg(OordDate);
                    res=query->exec(str);
                    if (res){
                        query->next();
                        OordId=query->value(0).toInt();
                    }
        }
    //3)вставляем в OrdCar
        query->prepare("INSERT INTO "
                       " OrdCar (CarID,OrderID) "
                       " VALUES (?,?)");
        query->addBindValue(OordCarID);
        query->addBindValue(OordId);
        res2=query->exec();
        if (res2){
            QMessageBox::information(this,"Vse super","New OrdCar was succesfully added");
            accept(); }
        else {QMessageBox::information(this,"Error","Kukaracha OrdCar"); return;}


}
void NewOrderDialog::clear_pole(){

    Fio->clear();
    Tel->clear();
    KlienID->clear();
    OrdID->clear();
    OrdDate->clear();
    OrdCarID->clear();
}
