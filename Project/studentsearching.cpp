#include "studentsearching.h"
#include "ui_studentsearching.h"
#include "data.h"
#include <QMessageBox>
extern std::map<int, student>allData;
extern student *ptrStudent;
extern year *ptrYear;
extern std::map<QString,float> * ptrSemester;
studentSearching::studentSearching(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentSearching)
{
    ui->setupUi(this);
    ui->IDArea->setValidator( new QIntValidator(0, 99999999,this) );
    ui->firstYearBtn->setEnabled(false);
    ui->secondYearBtn->setEnabled(false);
    ui->thirdYearBtn->setEnabled(false);
    ui->fourthYearBtn->setEnabled(false);
    ui->firstSemesterBtn->setEnabled(false);
    ui->secondSemesterBtn->setEnabled(false);
    ui->subjectsArea->clear();
}

studentSearching::~studentSearching()
{
    delete ui;
}

void studentSearching::on_checkIDBtn_clicked()
{
    int tarID = ui->IDArea->text().toInt();
    if(ui->IDArea->text().size() != 8){
        QMessageBox::information(this,"Error","ID length must be 8 numbers only");
        return;
    }
    if(!allData.count(tarID)){
        QMessageBox::information(this,"Error","This ID doesn't exist!");
        return;
    }
    ui->firstYearBtn->setEnabled(true);
    ui->secondYearBtn->setEnabled(true);
    ui->thirdYearBtn->setEnabled(true);
    ui->fourthYearBtn->setEnabled(true);
    ptrStudent = &allData[tarID];
    ui->studentGPALabel->setText("GPA: " + QString::number(ptrStudent->GPA));
    ui->studentNameLabel->setText(ptrStudent->name);
}


void studentSearching::on_firstYearBtn_clicked()
{
    ptrYear = &ptrStudent->firstYear;
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectsArea->clear();
}


void studentSearching::on_secondYearBtn_clicked()
{
    ptrYear = &ptrStudent->secondYear;
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectsArea->clear();
}


void studentSearching::on_thirdYearBtn_clicked()
{
    ptrYear = &ptrStudent->thirdYear;
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectsArea->clear();
}


void studentSearching::on_fourthYearBtn_clicked()
{
    ptrYear = &ptrStudent->fourthYear;
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectsArea->clear();
}


void studentSearching::on_firstSemesterBtn_clicked()
{
    ptrSemester = &ptrYear->firstSemester;
    ui->subjectsArea->clear();
    for(auto& val : *ptrSemester){
        ui->subjectsArea->addItem(val.first);
    }
    for(int i = 0; i < ui->subjectsArea->count(); i++){
        ui->subjectsArea->item(i)->setTextAlignment(Qt::AlignCenter);
    }
}


void studentSearching::on_secondSemesterBtn_clicked()
{
    ptrSemester = &ptrYear->secondSemester;
    ui->subjectsArea->clear();
    for(auto& val : *ptrSemester){
        ui->subjectsArea->addItem(val.first);
    }
    for(int i = 0; i < ui->subjectsArea->count(); i++){
        ui->subjectsArea->item(i)->setTextAlignment(Qt::AlignCenter);
    }
}


void studentSearching::on_subjectsArea_itemClicked(QListWidgetItem *item)
{
    QMessageBox::information(this,"Subject info","Subject: ( "+ item->text() + " )\nGrade: ( " + QString::number((*ptrSemester)[item->text()]) + " )");
}


void studentSearching::on_IDArea_textEdited(const QString &arg1)
{
    ui->firstYearBtn->setEnabled(false);
    ui->secondYearBtn->setEnabled(false);
    ui->thirdYearBtn->setEnabled(false);
    ui->fourthYearBtn->setEnabled(false);
    ui->firstSemesterBtn->setEnabled(false);
    ui->secondSemesterBtn->setEnabled(false);
    ui->studentNameLabel->setText("Student name");
    ui->studentGPALabel->setText("Student GPA");
    ui->subjectsArea->clear();
}
