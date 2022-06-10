#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newstudentwindow.h"
#include "studentsearching.h"
#include "data.h"
#include "editstudentwindow.h"
#include "allstudentswindow.h"
#include <QMessageBox>
std::map<int, student>allData;
student *ptrStudent;
year *ptrYear;
std::map<QString,float> * ptrSemester;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dataDir;
    dataDir.mkpath("database");

    QFile styleFile(":/essential files/stylesheet.qss");
    styleFile.open(QFile::ReadOnly);
    QString style = styleFile.readAll();
    styleFile.close();
    qApp->setStyleSheet(style);


    dataDir.cd("database");
    QString line, ID;
    QStringList lineData, subjectData;
    foreach(QFileInfo val, dataDir.entryInfoList()){
        //QMessageBox::information(this,"hello",val.filePath());
        QFile file(val.filePath());
        if(file.open(QFile::ReadOnly | QFile::Text)){
            //QMessageBox::information(this,"hello",val.filePath());
            ptrStudent = new student;
            // first line (ID and student name and student GPA)
            line = file.readLine();
            lineData = line.split('-');
            //QMessageBox::information(this,"hello",lineData.at(2));
            ptrStudent->name = lineData.at(1);
            ptrStudent->GPA = lineData.at(2).toDouble();
            ID = lineData.at(0);
            // first year data (first is the first semester, second is the second semester)
            // first semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->firstYear.firstSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }
            // second semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->firstYear.secondSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }

            // second year data (first is the first semester, second is the second semester)
            // first semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->secondYear.firstSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }
            // second semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->secondYear.secondSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }

            // third year data (first is the first semester, second is the second semester)
            // first semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->thirdYear.firstSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }
            // second semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split(' ');
                ptrStudent->thirdYear.secondSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }

            // fourth year data (first is the first semester, second is the second semester)
            // first semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->fourthYear.firstSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }
            // second semester
            line = file.readLine();
            lineData = line.split(',');
            lineData.removeAt(lineData.count() - 1);
            for(auto& val : lineData){
                subjectData = val.split('-');
                ptrStudent->fourthYear.secondSemester[subjectData.at(0)] = subjectData.at(1).toDouble();
            }

            allData[ID.toInt()] = *ptrStudent;
        }
        file.close();
    }

    /*allData[20210184].firstYear.firstSemester["Programming 1"] = 3.55;
    allData[20210184].name = "shawky";*/
}

MainWindow::~MainWindow()
{
    for(auto& val : allData){
        QFile file("database/" + QString::number(val.first) + ".txt");
        file.open(QFile::WriteOnly);
        QTextStream in(&file);

        // first line in the file
        in << val.first << '-' << val.second.name << '-' << val.second.GPA << '\n';

        // first year
        for(auto subject : val.second.firstYear.firstSemester){
            in << subject.first << '-' << subject.second << ',';
        }
        in << '\n';
        for(auto subject : val.second.firstYear.secondSemester){
            in << subject.first<< '-' << subject.second << ',';
        }
        in << '\n';

        // second year
        for(auto subject : val.second.secondYear.firstSemester){
            in << subject.first << '-' << subject.second << ',';
        }
        in << '\n';
        for(auto subject : val.second.secondYear.secondSemester){
            in << subject.first << '-' << subject.second << ',';
        }
        in << '\n';

        // third year
        for(auto subject : val.second.thirdYear.firstSemester){
            in << subject.first << '-' << subject.second << ',';
        }
        in << '\n';
        for(auto subject : val.second.thirdYear.secondSemester){
            in << subject.first << '-' << subject.second << ',';
        }
        in << '\n';

       // fourth year
        for(auto subject : val.second.fourthYear.firstSemester){
            in << subject.first << '-' << subject.second << ',';
        }
        in << '\n';
        for(auto subject : val.second.fourthYear.secondSemester){
            in << subject.first << '-' << subject.second << ',';
        }

        file.flush();
        file.close();
    }
    delete ui;
}


void MainWindow::on_registerBtn_clicked()
{
    newStudentWindow screen;
    screen.exec();
    screen.show();
}


void MainWindow::on_searchBtn_clicked()
{
    studentSearching screen;
    screen.exec();
    screen.show();
}


void MainWindow::on_editStudentBtn_clicked()
{
    editStudentWindow screen;
    screen.exec();
    screen.show();
}


void MainWindow::on_allStudentsBtn_clicked()
{
    allStudentsWindow screen;
    screen.exec();
    screen.show();
}

