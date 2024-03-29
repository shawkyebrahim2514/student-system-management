#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QInputDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_registerBtn_clicked();

    void on_searchBtn_clicked();

    void on_editStudentBtn_clicked();

    void on_allStudentsBtn_clicked();

    void on_changeAdminBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
