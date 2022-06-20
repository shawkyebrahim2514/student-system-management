#include "editstudentwindow.h"
#include "ui_editstudentwindow.h"
#include "data.h"
#include <QMessageBox>
#include <QFile>
extern std::map<int, student>allData;
extern student *ptrStudent;
extern year *ptrYear;
extern std::map<QString,float> * ptrSemester;
editStudentWindow::editStudentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editStudentWindow)
{
    ui->setupUi(this);
    ui->studentGPAArea->setValidator( new QDoubleValidator(0, 4, 2, this) );
    ui->IDArea->setValidator( new QIntValidator(0, 99999999,this) );
    ui->subjectGradeArea->setValidator( new QIntValidator(0, 100,this) );
    ui->horizontalLayout->setEnabled(false);
    ui->changeNameOrIDBtn->setEnabled(false);
    ui->studentNameArea->setEnabled(false);
    ui->studentGPAArea->setEnabled(false);
    ui->saveNameAndIDBtn->setEnabled(false);
    ui->firstYearBtn->setEnabled(false);
    ui->secondYearBtn->setEnabled(false);
    ui->thirdYearBtn->setEnabled(false);
    ui->fourthYearBtn->setEnabled(false);
    ui->firstSemesterBtn->setEnabled(false);
    ui->secondSemesterBtn->setEnabled(false);
    ui->subjectNameArea->setEnabled(false);
    ui->subjectGradeArea->setEnabled(false);
    ui->updateSubjectBtn->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->deleteStudentBtn->setEnabled(false);
}

editStudentWindow::~editStudentWindow()
{
    delete ui;
}

void editStudentWindow::on_checkIDBtn_clicked()
{
    int tarID = ui->IDArea->text().toInt();
    if(ui->IDArea->text().size() != 8){
        QMessageBox::information(this,"Error","ID length must be 8 numbers only");
        return;
    }
    if(!allData.count(tarID)){
        QMessageBox::warning(this,"Error","This ID doesn't exist!");
        return;
    }
    ptrStudent = &allData[tarID];
    ui->studentGPAArea->setText(QString::number(ptrStudent->GPA));
    ui->studentNameArea->setText(ptrStudent->name);
    ui->changeNameOrIDBtn->setEnabled(true);
    ui->firstYearBtn->setEnabled(true);
    ui->secondYearBtn->setEnabled(true);
    ui->thirdYearBtn->setEnabled(true);
    ui->fourthYearBtn->setEnabled(true);
    ui->deleteStudentBtn->setEnabled(true);
}


void editStudentWindow::on_IDArea_textEdited(const QString &arg1)
{
    ui->changeNameOrIDBtn->setEnabled(false);
    ui->studentNameArea->setEnabled(false);
    ui->studentGPAArea->setEnabled(false);
    ui->saveNameAndIDBtn->setEnabled(false);
    ui->firstYearBtn->setEnabled(false);
    ui->secondYearBtn->setEnabled(false);
    ui->thirdYearBtn->setEnabled(false);
    ui->fourthYearBtn->setEnabled(false);
    ui->firstSemesterBtn->setEnabled(false);
    ui->secondSemesterBtn->setEnabled(false);
    ui->subjectNameArea->setEnabled(false);
    ui->subjectGradeArea->setEnabled(false);
    ui->updateSubjectBtn->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->subjectsArea->clear();
    ui->studentNameArea->setText("");
    ui->studentGPAArea->setText("");
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    ui->deleteSubjectBtn->setEnabled(false);
    ui->deleteStudentBtn->setEnabled(false);
}


void editStudentWindow::on_changeNameOrIDBtn_clicked()
{
    ui->studentNameArea->setEnabled(true);
    ui->studentGPAArea->setEnabled(true);
    ui->saveNameAndIDBtn->setEnabled(true);
}


void editStudentWindow::on_saveNameAndIDBtn_clicked()
{
    QString studentName = ui->studentNameArea->text();
    if(studentName.isEmpty() || ui->studentGPAArea->text().isEmpty()){
        QMessageBox::warning(this,"Error","Enter valid inputs!");
        return;
    }
    float studentGPA = ui->studentGPAArea->text().toFloat();
    ptrStudent->name = studentName;
    ptrStudent->GPA = studentGPA;
    ui->studentNameArea->setEnabled(false);
    ui->studentGPAArea->setEnabled(false);
    ui->saveNameAndIDBtn->setEnabled(false);
    QMessageBox::information(this,"changing name and ID","Successfully changing");
}


void editStudentWindow::on_firstYearBtn_clicked()
{
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectNameArea->setEnabled(false);
    ui->subjectGradeArea->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->updateSubjectBtn->setEnabled(false);
    ptrYear = &ptrStudent->firstYear;
    ui->subjectsArea->clear();
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    yearName = "First year";
    ui->yearAndSemesterLabel->setText(yearName);
}


void editStudentWindow::on_secondYearBtn_clicked()
{
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectNameArea->setEnabled(false);
    ui->subjectGradeArea->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->updateSubjectBtn->setEnabled(false);
    ptrYear = &ptrStudent->secondYear;
    ui->subjectsArea->clear();
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    yearName = "Second year";
    ui->yearAndSemesterLabel->setText(yearName);
}


void editStudentWindow::on_thirdYearBtn_clicked()
{
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectNameArea->setEnabled(false);
    ui->subjectGradeArea->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->updateSubjectBtn->setEnabled(false);
    ptrYear = &ptrStudent->thirdYear;
    ui->subjectsArea->clear();
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    yearName = "Third year";
    ui->yearAndSemesterLabel->setText(yearName);
}


void editStudentWindow::on_fourthYearBtn_clicked()
{
    ui->firstSemesterBtn->setEnabled(true);
    ui->secondSemesterBtn->setEnabled(true);
    ui->subjectNameArea->setEnabled(false);
    ui->subjectGradeArea->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->updateSubjectBtn->setEnabled(false);
    ptrYear = &ptrStudent->fourthYear;
    ui->subjectsArea->clear();
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    yearName = "Fourth year";
    ui->yearAndSemesterLabel->setText(yearName);
}


void editStudentWindow::on_firstSemesterBtn_clicked()
{
    ui->subjectNameArea->setEnabled(true);
    ui->subjectGradeArea->setEnabled(true);
    ui->addNewSubjectBtn->setEnabled(true);
    ui->updateSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ptrSemester = &ptrYear->firstSemester;
    ui->subjectsArea->clear();
    for(auto& val : *ptrSemester){
        ui->subjectsArea->addItem(val.first);
    }
    for(int i = 0; i < ui->subjectsArea->count(); i++){
        ui->subjectsArea->item(i)->setTextAlignment(Qt::AlignCenter);
    }
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    ui->yearAndSemesterLabel->setText(yearName + " - First semester");
}


void editStudentWindow::on_secondSemesterBtn_clicked()
{
    ui->subjectNameArea->setEnabled(true);
    ui->subjectGradeArea->setEnabled(true);
    ui->addNewSubjectBtn->setEnabled(true);
    ui->updateSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ptrSemester = &ptrYear->secondSemester;
    ui->subjectsArea->clear();
    for(auto& val : *ptrSemester){
        ui->subjectsArea->addItem(val.first);
    }
    for(int i = 0; i < ui->subjectsArea->count(); i++){
        ui->subjectsArea->item(i)->setTextAlignment(Qt::AlignCenter);
    }
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    ui->yearAndSemesterLabel->setText(yearName + " - Second semester");
}


void editStudentWindow::on_subjectsArea_itemClicked(QListWidgetItem *item)
{
    ui->updateSubjectBtn->setEnabled(true);
    ui->deleteSubjectBtn->setEnabled(true);
    ui->addNewSubjectBtn->setEnabled(false);
    ui->subjectNameArea->setText(item->text());
    ui->subjectGradeArea->setText(QString::number((*ptrSemester)[item->text()]));
}


void editStudentWindow::on_updateSubjectBtn_clicked()
{
    // update current name in the list
    QString oldSubjectName = ui->subjectsArea->currentItem()->text();
    QString newSubjectName = ui->subjectNameArea->text().toLower();
    float subjectGrade = ui->subjectGradeArea->text().toFloat();
    if(newSubjectName.isEmpty()){
        QMessageBox::warning(this,"Error","Enter valid inputs!");
        return;
    }
    (*ptrSemester)[oldSubjectName] = subjectGrade;
    if(oldSubjectName != newSubjectName){
        auto subjectPtr = (*ptrSemester).extract(oldSubjectName);
        subjectPtr.key() = newSubjectName;
        (*ptrSemester).insert(std::move(subjectPtr));
    }
    ui->subjectsArea->currentItem()->setText(newSubjectName);
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    ui->updateSubjectBtn->setEnabled(false);
    ui->deleteSubjectBtn->setEnabled(false);
    ui->addNewSubjectBtn->setEnabled(true);
    QMessageBox::information(this,"Updating subjects","successfully changing\nOld name: ( " + oldSubjectName + " ) - New name: ( " + newSubjectName + " )\nIts grade: ( " + QString::number(subjectGrade) + " )");
}



void editStudentWindow::on_addNewSubjectBtn_clicked()
{
    // add new item to the list
    QString subjectName = ui->subjectNameArea->text().toLower();
    float subjectGrade = ui->subjectGradeArea->text().toFloat();
    if(subjectName.isEmpty()){
        QMessageBox::warning(this,"Error","Enter valid inputs!");
        return;
    }
    (*ptrSemester)[subjectName] = subjectGrade;
    ui->subjectsArea->addItem(subjectName);
    ui->subjectsArea->item(ui->subjectsArea->count() - 1)->setTextAlignment(Qt::AlignCenter);
    ui->subjectNameArea->setText("");
    ui->subjectGradeArea->setText("");
    QMessageBox::information(this,"Adding subjects","successfully adding\nNew subject: ( " + subjectName + " )\nIts grade: ( " + QString::number(subjectGrade) + " )");
}


void editStudentWindow::on_deleteSubjectBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete subject", "Are you sure to delete this subject?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QString subjectName = ui->subjectNameArea->text();
        (*ptrSemester).erase(subjectName);
        qDeleteAll(ui->subjectsArea->selectedItems());
        ui->subjectNameArea->setText("");
        ui->subjectGradeArea->setText("");
        ui->updateSubjectBtn->setEnabled(false);
        ui->deleteSubjectBtn->setEnabled(false);
        ui->addNewSubjectBtn->setEnabled(true);
    }
}


void editStudentWindow::on_deleteStudentBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete student", "Are you sure to delete this student?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        allData.erase(ui->IDArea->text().toInt());
        QFile file("database/" + ui->IDArea->text() + ".txt");
        file.remove();
        QMessageBox::information(this,"Delete student","successfully deletion");
        ui->IDArea->setText("");
        editStudentWindow::on_IDArea_textEdited("");
    }
}

