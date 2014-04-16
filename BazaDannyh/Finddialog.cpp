#include "Finddialog.h"

FindDialog::FindDialog(QWidget *parent):
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
    QLabel *Cenlbl = new QLabel("Cena ot");
    Cen = new QLineEdit;
    QLabel *Cen2lbl = new QLabel("do");
    Cen2 = new QLineEdit;

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

    Korob->addItem(" ");
    query->exec("SELECT Korobka FROM Xarak_ki GROUP BY Korobka");
    while(query->next()){
        Korob->addItem(query->value(0).toString());}


    Cve->addItem(" ");
    query->exec("SELECT Cvet FROM Details GROUP BY Cvet");
    while(query->next()){
        Cve->addItem(query->value(0).toString());}


    Kuz->addItem(" ");
    query->exec("SELECT Kuzov FROM Details GROUP BY Kuzov");
    while(query->next()){
        Kuz->addItem(query->value(0).toString());}


   connect(Cancel,SIGNAL(clicked()),this,SLOT(reject()));
   // connect(addBtn,SIGNAL(clicked()),this,SLOT(add()));

    QHBoxLayout *Cenabox=new QHBoxLayout;
    Cenabox->addWidget(Cen);
    Cenabox->addWidget(Cen2lbl);
    Cenabox->addWidget(Cen2);

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
    layout->addLayout(Cenabox,6,1);
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

       connect(Ok,SIGNAL(clicked()),this,SLOT(find()));


    setLayout(vbox);
    setWindowTitle("Find");
}


bool FindDialog::GetData(QString &Marka,QString &Strana,QString &Model,double &Dvigatel,int &loshad_sil,QString &Korobka,int &Cena,QString &Cvet,QString &Kuzov,int &Cena2){
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

    //Cena2
    str=Cen2->text();

    Cena2=str.toInt(&res);
    if (!res||Cena2<0){
        Cena2=0;
        QMessageBox::warning(this,"Error","Cena must contain positive int value");
        Cen2->setText(QString::number(0));
        return false;
    }

    //Cvet
    Cvet=Cve->currentText();
    //Kuzov
    Kuzov=Kuz->currentText();
return true;
}

void FindDialog::find(){

    QString Marka,Strana,Model,Korobka,Cvet,Kuzov;
   double Dvigatel;
    int loshad_sil,Cena,Cena2,ModID,CaID;
    CaID=0;
    ModID=0;
    bool res2;


    bool res=GetData(Marka,Strana,Model,Dvigatel,loshad_sil,Korobka,Cena,Cvet,Kuzov,Cena2);
    if (!res) {QMessageBox::information(this,"Error","Kukaracha"); return;}
    QString str=QString("SELECT M.ModelName,C.Marka,C.Strana,X.Dvigatel,X.Korobka,X.Loshad_sil,D.Cvet,D.Kuzov,D.Cena,C.CarID "
                        "FROM Cars C,Models M,Details D,Xarak_ki X ");
    QString s=QString("WHERE C.CarID=D.CarID AND C.CarID=X.CarID AND C.ModelID=M.ModelID ");

    if (Marka!=" ")s+=QString("AND C.Marka='%1' ").arg(Marka);
    if (Strana!=" ")s+=QString("AND C.Strana='%1' ").arg(Strana);
    if (Model!=" ")s+=QString("AND M.Model='%1' ").arg(Model);
    if (Dvigatel!=0)s+=QString("AND X.Dvigatel='%1' ").arg(Dvigatel);
    if (loshad_sil!=0)s+=QString("AND X.Loshad_sil='%1' ").arg(loshad_sil);
    if (Korobka!=" ")s+=QString("AND X.Korobka='%1' ").arg(Korobka);
    if (Cena!=0)s+=QString("AND D.Cena>='%1' ").arg(Cena);
    if (Cena2!=0)s+=QString("AND D.Cena<='%1' ").arg(Cena2);
    if (Cvet!=" ")s+=QString("AND D.Cvet='%1' ").arg(Cvet);
    if (Kuzov!=" ")s+=QString("AND D.Kuzov='%1' ").arg(Kuzov);
    str+=s;
    ss=str;
accept();

}
void FindDialog::clear_pole(){
    Mark->setText(" ");
    Stra->setText(" ");
    Cen->setText(QString::number(0));
    Dvig->setText(QString::number(0));
    ModName->setText(" ");
    Loshad->setText(QString::number(0));
    Cen2->setText(QString::number(0));

    int index1=Korob->findText(" ");
    Korob->setCurrentIndex(index1);

    index1=Cve->findText(" ");
    Cve->setCurrentIndex(index1);

    index1=Kuz->findText(" ");
    Kuz->setCurrentIndex(index1);
}
