#include "detailsdialog.h"
#include "constants.h"

DetailsDialog::DetailsDialog(QWidget *parent):
        QDialog(parent)
{


    QLabel *ProductNamelbl = new QLabel("ProductName");
    ProductName = new QLineEdit;

    QLabel *Categorylbl = new QLabel("Category");
    Category = new QLineEdit;

    QLabel *Supplierlbl = new QLabel("Supplier");
    Supplier = new QLineEdit;

    QLabel *QuantityPerUnitlbl = new QLabel("QuantityPerUnit");
    QuantityPerUnit = new QLineEdit;


    First = new QPushButton("<<First");
    Prev = new QPushButton("<Prev");
    Next = new QPushButton("Next>");
    Last = new QPushButton("Last>>");
    Ok = new QPushButton("Ok");
    Cancel = new QPushButton("Cancel");

    db=QSqlDatabase::database("mydb");
    query=new QSqlQuery(db);

   // connect(CancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
   // connect(addBtn,SIGNAL(clicked()),this,SLOT(add()));


        QHBoxLayout*buttonLayout1=new QHBoxLayout;
        buttonLayout1->addWidget(First);
        buttonLayout1->addWidget(Prev);
        buttonLayout1->addWidget(Next);
        buttonLayout1->addWidget(Last);



        QGridLayout *layout = new QGridLayout;
    layout->addWidget(ProductNamelbl,0,0);
    layout->addWidget(ProductName,0,1);
    layout->addWidget(Categorylbl,1,0);
    layout->addWidget(Category,1,1);
    layout->addWidget(Supplierlbl,2,0);
    layout->addWidget(Supplier,2,1);
    layout->addWidget(QuantityPerUnitlbl,3,0);
    layout->addWidget(QuantityPerUnit,3,1);

    QHBoxLayout *buttonLayout2=new QHBoxLayout;
    buttonLayout2->addWidget(Ok);
    buttonLayout2->addWidget(Cancel);

	QVBoxLayout *vbox=new QVBoxLayout;
        vbox->addLayout(buttonLayout1);
        vbox->addLayout(layout);
        vbox->addLayout(buttonLayout2);


        /*connect(LoadImg,SIGNAL(clicked()),this,
                      SLOT(load()));*/

      // QString s=QString("Chocolade");
       //setProductName(s);

    setLayout(vbox);
    setWindowTitle("Details");
}
void DetailsDialog::setComponents(int flag){
    if (flag ==PRODUCT_DETAILS){
        ProductName->setEnabled(false);
    Category->setEnabled(false);
    Supplier->setEnabled(false);
    QuantityPerUnit->setEnabled(false);
    First->setEnabled(true);
    Prev->setEnabled(true);
    Next->setEnabled(true);
    Last->setEnabled(true);
    Ok->setEnabled(true);
    Cancel->setEnabled(true);
}
    else {
        ProductName->setEnabled(true);
    Category->setEnabled(true);
    Supplier->setEnabled(true);
    QuantityPerUnit->setEnabled(true);
    First->setEnabled(false);
    Prev->setEnabled(false);
    Next->setEnabled(false);
    Last->setEnabled(false);
    Ok->setEnabled(false);
    Cancel->setEnabled(false);

    }

}
void DetailsDialog::setProductName(QString str){
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
    Category->setText(Categ);
    Supplier->setText(Supl);
    QuantityPerUnit->setText(QString::number(Quant));



}

/*
void AddDialog::add()
{
    sfname = Fname->text();
    slname = Lname->text();
    QString str;
    str = math->text();
    imath = str.toInt();
    str = phys->text();
    iphys = str.toInt();
    str = rus->text();
    irus = str.toInt();

    Fname->clear();
    Lname->clear();
    math->clear();
    phys->clear();
    rus->clear();
    accept();
}

void AddDialog::get_marks(int &m, int &p, int &r)
{
    m = imath;
    p = iphys;
    r = irus;
}

void AddDialog::load(){
	QString fname = QFileDialog::getOpenFileName(this,
        tr("Open image"), "",
        tr("image (*.jpeg);;All Files (*)"));

	if (fname.isEmpty())
             return;

	QPixmap im(fname);
	image->setPixmap(im);
	photo_path=fname;
}
*/

