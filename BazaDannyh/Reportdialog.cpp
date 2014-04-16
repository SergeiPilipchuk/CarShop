#include "Reportdialog.h"
#include "constants.h"

ReportDialog::ReportDialog(QWidget *parent):
        QDialog(parent)
{

    QLabel *O_IDlbl = new QLabel("OrderID");
    O_ID = new QLineEdit;

    QLabel *K_FIOlbl = new QLabel("FIO");
    K_FIO=new QLineEdit;

    QLabel *K_Tellbl = new QLabel("Tel");
    K_Tel=new QLineEdit;

    QLabel *OrdDatlbl = new QLabel("OrderData");
    OrdDat = new QLineEdit;

    QLabel *K_IDlbl = new QLabel("KlientID");
    K_ID = new QLineEdit;

    Print = new QPushButton("Print");

     View2=new QTableView;
    db=QSqlDatabase::database("mydb");
    model2=new QSqlQueryModel;
    query=new QSqlQuery(db);
    //query2=new QSqlQuery(db);



        QGridLayout *layout = new QGridLayout;
    layout->addWidget(O_IDlbl,0,0);
    layout->addWidget(O_ID,0,1);
    layout->addWidget(K_FIOlbl,1,0);
    layout->addWidget(K_FIO,1,1);
    layout->addWidget(K_Tellbl,2,0);
    layout->addWidget(K_Tel,2,1);
    layout->addWidget(OrdDatlbl,3,0);
    layout->addWidget(OrdDat,3,1);
    layout->addWidget(K_IDlbl,4,0);
    layout->addWidget(K_ID,4,1);

    QVBoxLayout*Layout2=new QVBoxLayout;
    Layout2->addLayout(layout);
    Layout2->addWidget(View2);
    Layout2->addWidget(Print);

    O_ID->setEnabled(false);
    K_FIO->setEnabled(false);
    K_Tel->setEnabled(false);
    OrdDat->setEnabled(false);
     K_ID->setEnabled(false);

   // ReportDialog::setOrderID(sss);
    //table();

    setLayout(Layout2);
    setWindowTitle("Report");
}


void ReportDialog::setOrderID(QString str5){
    OrdId=str5.toInt();


            QString query_str=QString("SELECT O.OrderID,K.FIO,K.Tel,K.KlientID,O.OrderDate "
                                      "FROM Orders O,Klients K,OrdCar OC "
                                      "WHERE O.OrderID=OC.OrderID AND O.KlientID=K.KlientID "
                                      "AND O.OrderID='%1' ").arg(OrdId);
    bool res=query->exec(query_str);
    if (!res)QMessageBox::information(this,"Error","Kukaracha1");
   query->next();

//Заполняю поля в диалоговом окне данными


   O_ID->setText(QString::number(OrdId));

    int IndexFIO=query->record().indexOf("FIO");
    QString FIO=query->value(IndexFIO).toString();
    K_FIO->setText(FIO);

    int IndexTel=query->record().indexOf("Tel");
    int Tel=query->value(IndexTel).toInt();
    K_Tel->setText(QString::number(Tel));

    int IndexOrdDat=query->record().indexOf("OrderDate");
    QString Date=query->value(IndexOrdDat).toString();
    OrdDat->setText(Date);

    int IndexTK_ID=query->record().indexOf("KlientID");
    int KlientID=query->value(IndexTK_ID).toInt();
    K_ID->setText(QString::number(KlientID));

    QString str=QString("SELECT M.ModelName,C.Marka,C.Strana,X.Dvigatel,X.Korobka,X.Loshad_sil,D.Cvet,D.Kuzov,D.Cena,C.CarID "
                              "FROM Orders O,Cars C,OrdCar OC,Models M,Details D,Xarak_ki X "
                              "WHERE O.OrderID=OC.OrderID AND OC.CarID=C.CarID AND C.CarID=D.CarID AND C.CarID=X.CarID AND C.ModelID=M.ModelID AND O.OrderID='%1' ").arg(OrdId);
 res=query->exec(str);
if (!res)QMessageBox::information(this,"Error","Kukaracha1");

model2->setQuery(*query);
View2->setModel(model2);//связываем виджет с моделью
View2->setSelectionMode(QAbstractItemView::SingleSelection);
View2->setSelectionBehavior(QAbstractItemView::SelectRows);


}

