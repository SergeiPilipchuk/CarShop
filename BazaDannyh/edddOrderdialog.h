#ifndef EDDORDERDIALOG_H
#define EDDORDERDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class EddOrderDialog : public QDialog
{
    Q_OBJECT
public:
    EddOrderDialog(QWidget *parent = 0);
   // void setComponents(int flag);
    void setOrderID(QString str);
	
/*private slots:
    void edit();*/
private:
    QLineEdit *OrderID, *CarID;
    QPushButton *Ok,*Cancel;
    QSqlDatabase db;
    QSqlQuery *query;
    bool GetData(int &,int &);

    int OrdId;

};


#endif // ADDDIALOG_H
