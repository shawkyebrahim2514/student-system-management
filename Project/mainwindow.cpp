#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newstudentwindow.h"
#include "studentsearching.h"
#include "data.h"
#include "editstudentwindow.h"
#include "allstudentswindow.h"
#include <QMessageBox>
bool isLogin = false;
QString adminUserName;
QString adminPassword;
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


    QFile adminFile("database/Admin.txt");
    if(adminFile.exists()){
        adminFile.open(QFile::ReadOnly);
        QString line = adminFile.readLine();
        QStringList lineData = line.split(' ');
        adminUserName = lineData.at(0);
        adminPassword = lineData.at(1);
    }else{
        adminFile.open(QIODevice::WriteOnly);
        QTextStream out(&adminFile);
        adminUserName = "Admin";
        adminPassword = "Admin@1234";
        out << "Admin" << " " << "Admin@1234";
        adminFile.flush();
        adminFile.close();
    }


    dataDir.cd("database");
    QString line, ID;
    QStringList lineData, subjectData;
    foreach(QFileInfo val, dataDir.entryInfoList()){
        //QMessageBox::information(this,"fsf",val.fileName());
        if(val.fileName() == "Admin.txt") continue;
        QFile file(val.filePath());
        if(file.open(QFile::ReadOnly | QFile::Text)){
            ptrStudent = new student;
            // first line (ID and student name and student GPA)
            line = file.readLine();
            lineData = line.split('-');
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
    if(!isLogin){
        QString userName = QInputDialog::getText(this,"Admin user name","Enter your user name");
        if(userName != adminUserName){
            QMessageBox::warning(this,"Failed","User name is not correct!");
            return;
        }
        QString password = QInputDialog::getText(this,"Admin password","Enter your password");
        if(password != adminPassword){
            QMessageBox::warning(this,"Failed","Admin password is not correct!");
            return;
        }
        isLogin = true;
    }
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


void MainWindow::on_changeAdminBtn_clicked()
{
    QString userName = QInputDialog::getText(this,"Admin user name","Enter your user name");
    if(userName != adminUserName){
        QMessageBox::warning(this,"Failed","User name is not correct!");
        return;
    }
    QString password = QInputDialog::getText(this,"Admin password","Enter your password");
    if(password != adminPassword){
        QMessageBox::warning(this,"Failed","Admin password is not correct!");
        return;
    }
    QString newUserName = QInputDialog::getText(this,"Admin user name","Enter new user name");
    if(newUserName.isEmpty()){
        QMessageBox::warning(this,"Failed","Admin user name mustn't be empty");
        return;
    }
    QString newPassword = QInputDialog::getText(this,"Admin password","Enter new password");
    if(newPassword.isEmpty()){
        QMessageBox::warning(this,"Failed","Admin password mustn't be empty");
        return;
    }
    QMessageBox::information(this,"Changing username and password","Successfully changing");
    adminUserName = newUserName;
    adminPassword = newPassword;
    QFile adminFile("database/Admin.txt");
    adminFile.open(QFile::WriteOnly);
    QTextStream out(&adminFile);
    out << newUserName << ' ' << newPassword;
    adminFile.flush();
    adminFile.close();
}
