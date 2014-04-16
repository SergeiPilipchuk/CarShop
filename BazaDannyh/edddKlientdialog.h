#ifndef EDDKLIENTDIALOG_H
#define EDDKLIENTDIALOG_H

#include <QtGui>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;

class EddKlientDialog : public QDialog
{
    Q_OBJECT
public:
    EddKlientDialog(QWidget *parent = 0);
   // void setComponents(int flag);
    void setCarID(QString str);
	
/*private slots:
    void edit();*/
private:
    QLineEdit *Mark, *Stra,*ModName,*Dvig,*Loshad,*Cen;
    QPushButton *Ok,*Cancel;
    QSqlDatabase db;
    QSqlQuery *query;
    QComboBox   *Korob, *Cve,*Kuz;

    QString SProductName, SCategory,SSupplier;
    int IQuantityPerUnit;
};


#endif // ADDDIALOG_H
