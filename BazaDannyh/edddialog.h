#ifndef EDDDIALOG_H
#define EDDDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class EddDialog : public QDialog
{
    Q_OBJECT
public:
    EddDialog(QWidget *parent = 0);
   // void setComponents(int flag);
    void setCarID(QString str5);

	
public slots:
    void edit();
private:
    QLineEdit *Mark, *Stra,*ModName,*Dvig,*Loshad,*Cen;
    QPushButton *Ok,*Cancel;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlQuery *queryForOrdCar;
    QComboBox   *Korob, *Cve,*Kuz;
    bool GetData(QString &,QString &,QString &,double &,int &,QString &,int &,QString &,QString &);


    int CarId;
};


#endif // ADDDIALOG_H
