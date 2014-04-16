#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include <QtGui>
#include <QMainWindow>
#include <QtSql>
class QLineEdit;
class QSqlDatabase;
class QSqlQuery;
class DetailsDialog : public QDialog
{
    Q_OBJECT
public:
    DetailsDialog(QWidget *parent = 0);
   /* QString getFirstName(){return sfname;}
    QString getLastName(){return slname;}
    void get_marks(int &, int &, int &);
        QString get_Photo(){return photo_path;}*/
    void setComponents(int flag);
    void setProductName(QString str);

	
/*private slots:
    void add();
        void load();*/
private:
    QLineEdit *ProductName, *Category, *Supplier, *QuantityPerUnit;
    QPushButton *First, *Prev,*Next,*Last,*Ok,*Cancel;
    QSqlDatabase db;
    QSqlQuery *query;


    QString SProductName, SCategory,SSupplier;
    int IQuantityPerUnit;
};


#endif // ADDDIALOG_H
