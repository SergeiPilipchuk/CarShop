#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;
class QTableView;
class QTextEdit;
class QSqlQueryModel;

class ReportDialog : public QDialog
{
    Q_OBJECT
public:
    ReportDialog(QWidget *parent = 0);
   // void setComponents(int flag);
    void setOrderID(QString str5);


	
private:
    QLineEdit *OrdDat,*K_FIO,*K_Tel,*O_ID,*K_ID;
    QPushButton *Print;
    QSqlDatabase db;

    QTableView *View2;
    QSqlQueryModel *model2;
    QSqlQuery *query;
    //QSqlQuery *query2;





    int OrdId;
};


#endif // ADDDIALOG_H
