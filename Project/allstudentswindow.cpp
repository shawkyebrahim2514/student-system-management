#include "allstudentswindow.h"
#include "ui_allstudentswindow.h"
#include "studentsearching.h"
#include "ui_studentsearching.h"
#include "data.h"
#include <QMessageBox>
extern std::map<int, student>allData;
allStudentsWindow::allStudentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allStudentsWindow)
{
    ui->setupUi(this);
    // each item can show 63 characters
    for(auto& val : allData){
        //QString tmp = QString::number(val.first) + QString(72,' ') + val.second.name;
        QString tmp = QString::number(val.first) + "    =>    " + val.second.name;
        ui->allStudentsArea->addItem(tmp);
    }
    for(int i = 0; i < ui->allStudentsArea->count(); i++){
        //ui->allStudentsArea->item(i)->setTextAlignment(Qt::AlignCenter);
    }
}

allStudentsWindow::~allStudentsWindow()
{
    delete ui;
}

void allStudentsWindow::on_allStudentsArea_itemClicked(QListWidgetItem *item)
{
    studentSearching screen;
    screen.ui->IDArea->setText(item->text().mid(0,8));
    screen.ui->checkIDBtn->clicked(true);
    screen.exec();
    screen.show();

}

