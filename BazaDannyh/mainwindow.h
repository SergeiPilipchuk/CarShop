#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
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

class QLabel;
class QPushButton;
class QTableView;
class buttonLayout;class QTextEdit;
class QSqlDatabase;
class QSqlQueryModel;
class QSqlQuery;
class MainWindow:public QWidget{
Q_OBJECT;
public:
MainWindow(QWidget * parent=0);
private slots:

        void Edit();
        void Details();
        void NewCar();
        void NewOrder();
        void Delete();
        void Sort();
        void Find();
        void Report();

private:
        QComboBox *CmbBoxO,*CmbBoxP,*CmbBoxHP;
        QTableView *View;
       // QLabel *lblPhoto;
        QSqlDatabase db;
        QSqlQueryModel *model;
        QSqlQuery *query;
         QSqlQuery *query2;
        QPushButton* DetailsButton,*EditButton,* NewCarButton,* NewOrderButton,*DeleteButton,* SortByButton,* FindButton;
         QPushButton* ReportButton;
         QString str_zapros;
         ProcedurDialog *procedurDialog;
        //DetailsDialog    *detailsDialog;
        EddDialog *eddDialog;
        NewCarDialog *newCarDialog;
        NewOrderDialog *newOrderDialog;
        FindDialog *findDialog;
        ReportDialog *reportDialog;
        SortDialog *sortDialog;

        //CentralWidget *cwgt;

    public slots:
            void Otnoshen_change(const QString &);
            void View_change(const QString &);
            void Procedur_change(const QString &);


	
};



#endif
