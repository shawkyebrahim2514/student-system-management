#include "newstudentwindow.h"
#include "ui_newstudentwindow.h"
#include "data.h"
#include <QMessageBox>
#include <QDoubleValidator>
extern std::map<int, student>allData;
extern student *ptrStudent;
extern year *ptrYear;
extern std::map<QString,float> * ptrSemester;
newStudentWindow::newStudentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newStudentWindow)
{
    ui->setupUi(this);
    ui->studentGPAArea->setValidator( new QDoubleValidator(0, 4, 2, this) );
    ui->IDArea->setValidator( new QIntValidator(0, 99999999,this) );
    ui->studentNameArea->setEnabled(false);
    ui->studentGPAArea->setEnabled(false);
    ui->registerBtn->setEnabled(false);
}

newStudentWindow::~newStudentWindow()
{
    delete ui;
}


void newStudentWindow::on_checkIDBtn_clicked()
{
    int tarID = ui->IDArea->text().toInt();
    if(ui->IDArea->text().size() != 8){
        QMessageBox::information(this,"Error","ID length must be 8 numbers only");
        return;
    }
    if(allData.count(tarID)){
        QMessageBox::information(this,"Error","This ID exists before!");
        return;
    }
    ui->studentNameArea->setEnabled(true);
    ui->studentGPAArea->setEnabled(true);
    ui->registerBtn->setEnabled(true);
    //ptrStudent = &allData[tarID];
    ID = tarID;
}



void newStudentWindow::on_IDArea_textEdited(const QString &arg1)
{
    ui->studentNameArea->setEnabled(false);
    ui->studentGPAArea->setEnabled(false);
    ui->registerBtn->setEnabled(false);
}

void newStudentWindow::on_registerBtn_clicked()
{
    QString studentGPA = ui->studentGPAArea->text();
    QString studentName = ui->studentNameArea->text();
    if(studentGPA.isEmpty() || studentName.isEmpty()){
        QMessageBox::warning(this,"Error","Enter valid inputs!");
        return;
    }
    //ptrStudent->name = studentName;
    //ptrStudent->GPA = studentGpA.toFloat();
    name = studentName;
    GPA = studentGPA.toFloat();
    auto *student = &allData[ID];
    student->name = name;
    student->GPA = GPA;
    ui->studentNameArea->setText("");
    ui->studentGPAArea->setText("");
    ui->IDArea->setText("");
    ui->studentNameArea->setEnabled(false);
    ui->studentGPAArea->setEnabled(false);
    ui->registerBtn->setEnabled(false);
    QMessageBox::information(this,"Registration", "Successefully registration");
}

