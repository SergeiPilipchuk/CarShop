#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"
#include <QtGui>
#include <QtSql>
#include "procedurdialog.h"
//#include "detailsdialog.h"
#include "edddialog.h"
#include "newCardialog.h"
#include "newOrderdialog.h"
#include "Finddialog.h"
#include "Reportdialog.h"
#include "Sortdialog.h"

//#include "constants.h"

MainWindow::MainWindow(QWidget *parent):QWidget(parent){


    QLabel *lblOtnoshen=new QLabel("Select Otnoshenie");
    QLabel *lblView=new QLabel("Select View");
    QLabel *lblProcedur=new QLabel("Select Procedur");
    CmbBoxO=new QComboBox;
    CmbBoxP=new QComboBox;
    CmbBoxHP=new QComboBox;

    View=new QTableView;
    View->setSortingEnabled(true);


    db=QSqlDatabase::database("mydb");
    //db=QSqlDatabase::database("mydb");
    model=new QSqlQueryModel;
    query=new QSqlQuery(db);
    query2=new QSqlQuery(db);
    EditButton=new QPushButton("Edit");
    NewCarButton=new QPushButton("NewCar");
    NewOrderButton=new QPushButton("NewOrder");
    DeleteButton=new QPushButton("Delete");
    DetailsButton=new QPushButton("Details");
    SortByButton=new QPushButton("SortBy");
    FindButton=new QPushButton("Find");
    ReportButton=new QPushButton("Report");

 CmbBoxO->addItem(" ");
           CmbBoxO->addItem(QString("Cars"));
           CmbBoxO->addItem(QString("Models"));
           CmbBoxO->addItem(QString("Orders"));
           CmbBoxO->addItem(QString("Klients"));

           CmbBoxP->addItem(" ");
           CmbBoxP->addItem(QString("CarXarak"));
           CmbBoxP->addItem(QString("OrdKlient"));

           CmbBoxHP->addItem(" ");
           CmbBoxHP->addItem(QString("OrdersByDate"));

       connect(CmbBoxO,SIGNAL(activated(const QString &)),this,SLOT(Otnoshen_change(const QString &)));
        connect(CmbBoxP,SIGNAL(activated(const QString &)),this,SLOT(View_change(const QString &)));
        connect(CmbBoxHP,SIGNAL(activated(const QString &)),this,SLOT(Procedur_change(const QString &)));

    QHBoxLayout*buttonLayout1=new QHBoxLayout;
    buttonLayout1->addWidget(EditButton);
    buttonLayout1->addWidget(NewCarButton);
    buttonLayout1->addWidget(NewOrderButton);
    buttonLayout1->addWidget(DeleteButton);

    QHBoxLayout*buttonLayout2=new QHBoxLayout;
    buttonLayout2->addWidget(DetailsButton);
    buttonLayout2->addWidget(SortByButton);
    buttonLayout2->addWidget(FindButton);
    buttonLayout2->addWidget(ReportButton);


    QHBoxLayout*ComboLayout=new QHBoxLayout;
    ComboLayout->addWidget(lblOtnoshen);
    ComboLayout->addWidget(CmbBoxO);
    ComboLayout->addWidget(lblView);
    ComboLayout->addWidget(CmbBoxP);
    ComboLayout->addWidget(lblProcedur);
    ComboLayout->addWidget(CmbBoxHP);

    QVBoxLayout*Layout=new QVBoxLayout;
    Layout->addLayout(ComboLayout);
    Layout->addWidget(View);
    Layout->addLayout(buttonLayout1);
    Layout->addLayout(buttonLayout2);

   connect(DetailsButton,SIGNAL(clicked()),this,SLOT(Details()));
    connect(EditButton,SIGNAL(clicked()),this,SLOT(Edit()));
    connect(NewCarButton,SIGNAL(clicked()),this,SLOT(NewCar()));
    connect(NewOrderButton,SIGNAL(clicked()),this,SLOT(NewOrder()));
    connect(DeleteButton,SIGNAL(clicked()),this,SLOT(Delete()));
    connect(SortByButton,SIGNAL(clicked()),this,SLOT(Sort()));
    connect(FindButton,SIGNAL(clicked()),this,SLOT(Find()));
     connect(ReportButton,SIGNAL(clicked()),this,SLOT(Report()));


    procedurDialog=new ProcedurDialog(this);
    //detailsDialog = new DetailsDialog(this);
    eddDialog = new EddDialog(this);
    newCarDialog = new NewCarDialog(this);
    newOrderDialog= new NewOrderDialog(this);
    findDialog=new FindDialog(this);
    reportDialog=new ReportDialog(this);
    sortDialog=new SortDialog(this);

    setLayout(Layout);
    setWindowTitle("AVTOSALON");

};

void MainWindow::Otnoshen_change(const QString &OtnoshenName){

    int index1=CmbBoxP->findText(" ");
    CmbBoxP->setCurrentIndex(index1);
    int index2=CmbBoxHP->findText(" ");
    CmbBoxHP->setCurrentIndex(index2);
//QString str;
if (OtnoshenName=="Cars"){
    EditButton->setEnabled(true);
    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
    DeleteButton->setEnabled(true);
    DetailsButton->setEnabled(true);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);
    ReportButton->setEnabled(false);
     str_zapros=QString("SELECT * "
                              "FROM Cars ");}
                              else if (OtnoshenName=="Models"){
                              EditButton->setEnabled(false);
    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
                              DeleteButton->setEnabled(false);
                              DetailsButton->setEnabled(false);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);
                              ReportButton->setEnabled(false);


     str_zapros=QString("SELECT * "
                              "FROM Models ");}
                              else if (OtnoshenName=="Orders"){
    EditButton->setEnabled(false);
    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
    DeleteButton->setEnabled(true);
    DetailsButton->setEnabled(true);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);
    ReportButton->setEnabled(true);
     str_zapros=QString("SELECT * "
                              "FROM Orders ");}
                              else if (OtnoshenName=="Klients"){
    EditButton->setEnabled(false);
    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
    DeleteButton->setEnabled(true);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);

                              DetailsButton->setEnabled(false);
                              ReportButton->setEnabled(false);
     str_zapros=QString("SELECT * "
                              "FROM Klients ");}
    query->exec(str_zapros);
    model->setQuery(*query);
    View->setModel(model);//св€зываем виджет с моделью
    View->setSelectionMode(QAbstractItemView::SingleSelection);
    View->setSelectionBehavior(QAbstractItemView::SelectRows);
    //View->setSelectionBehavior(QAbstractItemView::SelectColumns);
    //View->setSortingEnabled(true);


}
void MainWindow::View_change(const QString &ViewName){

    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);

                              EditButton->setEnabled(false);
                              DeleteButton->setEnabled(false);
                              DetailsButton->setEnabled(false);
                              ReportButton->setEnabled(false);

    int index1=CmbBoxO->findText(" ");
    CmbBoxO->setCurrentIndex(index1);
    int index2=CmbBoxHP->findText(" ");
    CmbBoxHP->setCurrentIndex(index2);
//QString str;
if (ViewName=="CarXarak"){
     str_zapros=QString("SELECT * "
                              "FROM CarXarak ");}
                              else if (ViewName=="OrdKlient"){
     str_zapros=QString("SELECT * "
                              "FROM OrdKlient ");}

    query->exec(str_zapros);
    model->setQuery(*query);
    View->setModel(model);//св€зываем виджет с моделью
    View->setSelectionMode(QAbstractItemView::SingleSelection);
    View->setSelectionBehavior(QAbstractItemView::SelectRows);
    //View->setSelectionBehavior(QAbstractItemView::SelectColumns);
    //View->setSortingEnabled(true);


}

void MainWindow::Procedur_change(const QString &ProcedurName){

    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);

                              EditButton->setEnabled(false);
                              DeleteButton->setEnabled(false);
                              DetailsButton->setEnabled(false);
                              ReportButton->setEnabled(false);

    int index1=CmbBoxP->findText(" ");
    CmbBoxP->setCurrentIndex(index1);
    int index2=CmbBoxO->findText(" ");
    CmbBoxO->setCurrentIndex(index2);
procedurDialog->clear_pole();
procedurDialog->show();

QString d;
//QString str;
    if (procedurDialog->exec()==QDialog::Accepted){


 procedurDialog->get_Date(d);

if (ProcedurName=="OrdersByDate"){
     str_zapros=QString("EXEC OrdersByDate @Dat ='%1' ").arg(d);}

    query->exec(str_zapros);
    model->setQuery(*query);
    View->setModel(model);//св€зываем виджет с моделью
    View->setSelectionMode(QAbstractItemView::SingleSelection);
    View->setSelectionBehavior(QAbstractItemView::SelectRows);
    //View->setSelectionBehavior(QAbstractItemView::SelectColumns);
}
}

void MainWindow::Edit()
{
QString ID;
ID="0";
QModelIndex index=View->currentIndex();//получаем индекс выделенной строки тип-QModelIndex
int row=index.row();//тот же индекс выделенной строки, но уже типа инт
QSqlRecord record=model->record(row);//получает записи выделенной строки
 ID=record.value(0).toString();//тут все пон€тно
 if (!index.isValid()){QMessageBox::information(this,"Error","Stroka ne vydelina");return;}
 if (ID!="0"){
     if (CmbBoxO->currentText()=="Cars"){
     eddDialog->setCarID(ID);//ф-€ заполн€ет пол€ данными выделенного продукта
      int ires=eddDialog->exec();
      if (ires==QDialog::Rejected)return;
      }
  }
}
/*
void MainWindow::Details()
{
detailsDialog->setComponents(PRODUCT_DETAILS);//делает пол€ с данными не редактируемыми
QModelIndex index=View->currentIndex();//получаем индекс выделенной строки тип-QModelIndex
int row=index.row();//тот же индекс выделенной строки, но уже типа инт
QSqlRecord record=model->record(row);//получает записи выделенной строки
QString PrName=record.value(0).toString();//тут все пон€тно
detailsDialog->setProductName(PrName);//ф-€ заполн€ет пол€ данными выделенного продукта
    detailsDialog->show();
    // if (detailsDialog->exec()==QDialog::Accepted){}

}

*/
void MainWindow::NewCar()
{
    newCarDialog->clear_pole();
    int ires=newCarDialog->exec();
    if (ires==QDialog::Rejected)return;
    //QString str=CmbBox->currentText();
    //cat_change(str);


    // if (detailsDialog->exec()==QDialog::Accepted){}

}
void MainWindow::NewOrder()
{
    newOrderDialog->clear_pole();
    int ires=newOrderDialog->exec();
    if (ires==QDialog::Rejected)return;
    //QString str=CmbBox->currentText();
    //cat_change(str);


    // if (detailsDialog->exec()==QDialog::Accepted){}

}
void MainWindow::Delete(){
    int IDint;
    IDint=0;
    QString str;
    int res;
    bool rez;
    QModelIndex index=View->currentIndex();//получаем индекс выделенной строки тип-QModelIndex
    int row=index.row();//тот же индекс выделенной строки, но уже типа инт
    QSqlRecord record=model->record(row);//получает записи выделенной строки
    QString ID=record.value(0).toString();//значение первой €чейки в строке
    IDint=ID.toInt();
    if (!index.isValid()){QMessageBox::information(this,"Error","Stroka ne vydelina");return;}
    if (IDint!=0){
        //delete car
        if (CmbBoxO->currentText()=="Cars"){
            //1
            str=QString ("DELETE "
                         "FROM Details WHERE CarID='%1' ").arg(IDint);
            res=QMessageBox::question(this,"Delete","Do you really want to delete Details?",QMessageBox::Yes|QMessageBox::No);
            if (res==QMessageBox::Yes){
                rez=query->exec(str);
                if (rez)QMessageBox::information(this,"Vse super","Details succesfuly delete");
                else QMessageBox::information(this,"Error","Kukaracha");
            }
            //2
            str=QString ("DELETE "
                         "FROM Xarak_ki WHERE CarID='%1' ").arg(IDint);
            res=QMessageBox::question(this,"Delete","Do you really want to delete Xarak_ki?",QMessageBox::Yes|QMessageBox::No);
            if (res==QMessageBox::Yes){
                rez=query->exec(str);
                if (rez)QMessageBox::information(this,"Vse super","Xarak_ki succesfuly delete");
                else QMessageBox::information(this,"Error","Kukaracha");
            }
            //3
            str=QString ("DELETE "
                         "FROM Cars WHERE CarID='%1' ").arg(IDint);
            res=QMessageBox::question(this,"Delete","Do you really want to delete Car?",QMessageBox::Yes|QMessageBox::No);
            if (res==QMessageBox::Yes){
                rez=query->exec(str);
                if (rez)QMessageBox::information(this,"Vse super","Car succesfuly delete");
                else QMessageBox::information(this,"Error","Kukaracha");
            }

        }
        //delete oder

        if (CmbBoxO->currentText()=="Orders"){
            //1
            str=QString ("DELETE "
                         "FROM OrdCar WHERE OrderID='%1' ").arg(IDint);
            res=QMessageBox::question(this,"Delete","Do you really want to delete OrdCar?",QMessageBox::Yes|QMessageBox::No);
            if (res==QMessageBox::Yes){
                rez=query->exec(str);
                if (rez)QMessageBox::information(this,"Vse super","OrdCar succesfuly delete");
                else QMessageBox::information(this,"Error","Kukaracha");
            }
            //2
            str=QString ("DELETE "
                         "FROM Orders WHERE OrderID='%1' ").arg(IDint);
            res=QMessageBox::question(this,"Delete","Do you really want to delete Order?",QMessageBox::Yes|QMessageBox::No);
            if (res==QMessageBox::Yes){
                rez=query->exec(str);
                if (rez)QMessageBox::information(this,"Vse super","Order succesfuly delete");
                else QMessageBox::information(this,"Error","Kukaracha");
            }


        }
        //delet Klient

     if (CmbBoxO->currentText()=="Klients"){
         //1
         str=QString ("DELETE "
                      "FROM Orders WHERE KlientID='%1' ").arg(IDint);
         res=QMessageBox::question(this,"Delete","Do you really want to delete Orders with this Klient?",QMessageBox::Yes|QMessageBox::No);
         if (res==QMessageBox::Yes){
             rez=query->exec(str);
             if (rez)QMessageBox::information(this,"Vse super","Orders with this Klient succesfuly delete");
             else QMessageBox::information(this,"Error","Kukaracha");
         }
         //2
         str=QString ("DELETE "
                      "FROM Klients WHERE KlientID='%1' ").arg(IDint);
         res=QMessageBox::question(this,"Delete","Do you really want to delete Klient?",QMessageBox::Yes|QMessageBox::No);
         if (res==QMessageBox::Yes){
             rez=query->exec(str);
             if (rez)QMessageBox::information(this,"Vse super","Klient succesfuly delete");
             else QMessageBox::information(this,"Error","Kukaracha");
        }
    }

  }
    else QMessageBox::information(this,"Error","Vydelite stroky kotoryu xotite ydalit i nazmite delete");
}
/*
void MainWindow::Sort(){
    QModelIndex index=View->currentIndex();//получаем индекс выделенного столбца,wf тип-QModelIndex
    int row=index.column();//тот же индекс выделенного столбца, но уже типа инт
    QSqlRecord record=model->record(row);//получает записи выделенной строки
     QString Name=record.value(0).toString();//тут все пон€тно
     QString str_sort=str_zapros;
     QString s="ORDER BY ";
     s+=Name;
     str_sort+=s;
     query->exec(str_sort);
     model->setQuery(*query);
     View->setModel(model);//св€зываем виджет с моделью
     View->setSelectionMode(QAbstractItemView::SingleSelection);
     View->setSelectionBehavior(QAbstractItemView::SelectRows);
     View->setSelectionBehavior(QAbstractItemView::SelectColumns);


}*/
void MainWindow::Sort(){

    sortDialog->clear_pole();
    int stb;
    QString s;
    if (sortDialog->exec()==QDialog::Accepted){
        sortDialog->get_stolbec(stb);

        stb-=1;
        QString str_sort=str_zapros;
        if (CmbBoxO->currentText()=="Cars"){
            if (stb==0)s=QString(" ORDER BY CarID ");
            if (stb==1)s=QString(" ORDER BY ModelID ");
            if (stb==2)s=QString(" ORDER BY Marka ");
            if (stb==3)s=QString(" ORDER BY Strana ");
        }
        if (CmbBoxO->currentText()=="Orders"){
            if (stb==0)s=QString(" ORDER BY OrderID ");
            if (stb==1)s=QString(" ORDER BY KlientID ");
            if (stb==2)s=QString(" ORDER BY OrderDate ");
        }

        if (CmbBoxO->currentText()=="Models"){
            if (stb==0)s=QString(" ORDER BY ModelID ");
            if (stb==1)s=QString(" ORDER BY ModelName ");
        }

        if (CmbBoxO->currentText()=="Klients"){
            if (stb==0)s=QString(" ORDER BY KlientID ");
            if (stb==1)s=QString(" ORDER BY FIO ");
            if (stb==2)s=QString(" ORDER BY Tel ");
        }

        if (CmbBoxP->currentText()=="CarXarak"){
            if (stb==0)s=QString(" ORDER BY ModelName ");
            if (stb==1)s=QString(" ORDER BY Marka ");
            if (stb==2)s=QString(" ORDER BY Strana ");
            if (stb==3)s=QString(" ORDER BY Dvigatel ");
            if (stb==4)s=QString(" ORDER BY Korobka ");
            if (stb==5)s=QString(" ORDER BY Loshad_sil ");
            if (stb==6)s=QString(" ORDER BY Cvet ");
            if (stb==7)s=QString(" ORDER BY Kuzov ");
            if (stb==8)s=QString(" ORDER BY Cena ");
        }
        if (CmbBoxP->currentText()=="OrdKlient"){
            if (stb==0)s=QString(" ORDER BY OrderID ");
            if (stb==1)s=QString(" ORDER BY FIO ");
            if (stb==2)s=QString(" ORDER BY CarID ");
            if (stb==3)s=QString(" ORDER BY OrderDate ");
        }
        //SELECT M.ModelName,C.Marka,C.Strana,X.Dvigatel,X.Korobka,X.Loshad_sil,D.Cvet,D.Kuzov,D.Cena,C.CarID;
        if ((CmbBoxO->currentText()==" ")&(CmbBoxP->currentText()==" ")&(CmbBoxHP->currentText()==" ") ){
            if (stb==0)s=QString(" ORDER BY M.ModelName ");
            if (stb==1)s=QString(" ORDER BY C.Marka ");
            if (stb==2)s=QString(" ORDER BY C.Strana ");
            if (stb==3)s=QString(" ORDER BY X.Dvigatel ");
            if (stb==4)s=QString(" ORDER BY X.Korobka ");
            if (stb==5)s=QString(" ORDER BY X.Loshad_sil ");
            if (stb==6)s=QString(" ORDER BY D.Cvet ");
            if (stb==7)s=QString(" ORDER BY D.Kuzov ");
            if (stb==8)s=QString(" ORDER BY D.Cena ");
             if (stb==9)s=QString(" ORDER BY C.CarID ");

        }

        str_sort+=s;
        bool res=query2->exec(str_sort);
        if (!res)QMessageBox::information(this,"Error","Kukaracha1");

         model->setQuery(*query2);
         View->setModel(model);//св€зываем виджет с моделью
         View->setSelectionMode(QAbstractItemView::SingleSelection);
         View->setSelectionBehavior(QAbstractItemView::SelectRows);
         View->setSelectionBehavior(QAbstractItemView::SelectColumns);
    }

}

void MainWindow::Find(){
    NewCarButton->setEnabled(true);
    NewOrderButton->setEnabled(true);
    SortByButton->setEnabled(true);
    FindButton->setEnabled(true);

                              EditButton->setEnabled(false);
                              DeleteButton->setEnabled(false);
                              DetailsButton->setEnabled(false);
                              ReportButton->setEnabled(false);
    findDialog->clear_pole();
   // QString str;
    if (findDialog->exec()==QDialog::Accepted){
        findDialog->get_ss(str_zapros);

        bool res=query->exec(str_zapros);
        if (!res){QMessageBox::information(this,"Error","Kukaracha1");return;}
         model->setQuery(*query);
         View->setModel(model);//св€зываем виджет с моделью
         View->setSelectionMode(QAbstractItemView::SingleSelection);
         View->setSelectionBehavior(QAbstractItemView::SelectRows);
         View->setSelectionBehavior(QAbstractItemView::SelectColumns);
    }
    int index1=CmbBoxO->findText(" ");
    CmbBoxO->setCurrentIndex(index1);
    index1=CmbBoxP->findText(" ");
    CmbBoxP->setCurrentIndex(index1);
    int index2=CmbBoxHP->findText(" ");
    CmbBoxHP->setCurrentIndex(index2);
}
void MainWindow::Details(){

    QModelIndex index=View->currentIndex();//получаем индекс выделенной строки тип-QModelIndex
    int row=index.row();//тот же индекс выделенной строки, но уже типа инт
    QSqlRecord record=model->record(row);//получает записи выделенной строки
    QString ID=record.value(0).toString();//значение первой €чейки в строке
    int IDint=ID.toInt();
    bool res;
    QString str;
if (!index.isValid()){QMessageBox::information(this,"Error","Stroka ne vydelina");return;}

NewCarButton->setEnabled(true);
NewOrderButton->setEnabled(true);
SortByButton->setEnabled(false);
FindButton->setEnabled(true);

                          EditButton->setEnabled(false);
                          DeleteButton->setEnabled(false);
                          DetailsButton->setEnabled(false);
                          ReportButton->setEnabled(false);
    if (IDint!=0){
        if (CmbBoxO->currentText()=="Cars"){
            str=QString("SELECT M.ModelName,C.Marka,C.Strana,X.Dvigatel,X.Korobka,X.Loshad_sil,D.Cvet,D.Kuzov,D.Cena,C.CarID "
            "FROM Cars C,Models M,Xarak_ki X,Details D "
            "WHERE C.CarID=D.CarID AND C.CarID=X.CarID AND C.ModelID=M.ModelID AND C.CarID='%1' ").arg(IDint);
        }
        if (CmbBoxO->currentText()=="Orders"){
            str=QString("SELECT O.OrderID,K.FIO,K.Tel,OC.CarID,O.OrderDate "
            "FROM Orders O,Klients K,OrdCar OC "
            "WHERE O.OrderID=OC.OrderID AND O.KlientID=K.KlientID AND O.OrderID='%1' ").arg(IDint);
        }

        res=query->exec(str);
        if (!res){QMessageBox::information(this,"Error","Kukaracha1");return;}
         model->setQuery(*query);
         View->setModel(model);//св€зываем виджет с моделью
         View->setSelectionMode(QAbstractItemView::SingleSelection);
         View->setSelectionBehavior(QAbstractItemView::SelectRows);
         View->setSelectionBehavior(QAbstractItemView::SelectColumns);
    }
    int index1=CmbBoxO->findText(" ");
    CmbBoxO->setCurrentIndex(index1);
    index1=CmbBoxP->findText(" ");
    CmbBoxP->setCurrentIndex(index1);
    int index2=CmbBoxHP->findText(" ");
    CmbBoxHP->setCurrentIndex(index2);
}

void MainWindow::Report(){
    QString ID;
    ID="0";
    QModelIndex index=View->currentIndex();//получаем индекс выделенной строки тип-QModelIndex
    int row=index.row();//тот же индекс выделенной строки, но уже типа инт
    QSqlRecord record=model->record(row);//получает записи выделенной строки
     ID=record.value(0).toString();//тут все пон€тно
     if (!index.isValid()){QMessageBox::information(this,"Error","Stroka ne vydelina");return;}
     if (ID!="0"){
         if (CmbBoxO->currentText()=="Orders"){

         reportDialog->setOrderID(ID);//ф-€ заполн€ет пол€ данными выделенного продукта
          int ires=reportDialog->exec();
          if (ires==QDialog::Rejected)return;

          }
      }
}
