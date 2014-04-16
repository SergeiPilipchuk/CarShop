#include "edddKlientdialog.h"
#include "constants.h"
EddKlientDialog::EddKlientDialog(QWidget *parent):
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


        /*connect(LoadImg,SIGNAL(clicked()),this,
                      SLOT(load()));*/


    setLayout(vbox);
    setWindowTitle("Edding");
}

/*
void EddDialog::setProductName(QString str){
            QString query_str=QString("SELECT S.CompanyName,C.CategoryName,P.UnitPrice,P.ProductName,P.QuantityPerUnit "
                                      "FROM Categories C, Products P,Suppliers S "
                                      "WHERE C.CategoryID=P.CategoryID "
                                      "AND P.SupplierID=S.SupplierID "
                                      "AND P.ProductName='%1' ").arg(str);
    bool res=query->exec(query_str);
    if (!res)QMessageBox::information(this,"Error","Kukaracha");
   query->next();
    int IndexProdName=query->record().indexOf("ProductName");
    QString ProdName=query->value(IndexProdName).toString();

    int IndexCategory=query->record().indexOf("CategoryName");
    QString Categ=query->value(IndexCategory).toString();
    int IndexSupplier=query->record().indexOf("CompanyName");
    QString Supl=query->value(IndexSupplier).toString();
    int IndexQuantityPerUnit=query->record().indexOf("QuantityPerUnit");
    int Quant=query->value(IndexQuantityPerUnit).toInt();
    ProductName->setText(ProdName);

    int index2=Category->findText(Categ);
    Category->setCurrentIndex(index2);

    int index=Supplier->findText(Supl);
    Supplier->setCurrentIndex(index);
    QuantityPerUnit->setText(QString::number(Quant));



}

*/
