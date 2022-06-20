#ifndef EDITSTUDENTWINDOW_H
#define EDITSTUDENTWINDOW_H

#include <QDialog>
#include <QListWidget>
namespace Ui {
class editStudentWindow;
}

class editStudentWindow : public QDialog
{
    Q_OBJECT

public:
    QString yearName;
    explicit editStudentWindow(QWidget *parent = nullptr);
    ~editStudentWindow();

private slots:
    void on_checkIDBtn_clicked();

    void on_IDArea_textEdited(const QString &arg1);

    void on_changeNameOrIDBtn_clicked();

    void on_saveNameAndIDBtn_clicked();

    void on_firstYearBtn_clicked();

    void on_secondYearBtn_clicked();

    void on_thirdYearBtn_clicked();

    void on_fourthYearBtn_clicked();

    void on_firstSemesterBtn_clicked();

    void on_addNewSubjectBtn_clicked();

    void on_subjectsArea_itemClicked(QListWidgetItem *item);

    void on_updateSubjectBtn_clicked();

    void on_secondSemesterBtn_clicked();

    void on_deleteSubjectBtn_clicked();

    void on_deleteStudentBtn_clicked();

private:
    Ui::editStudentWindow *ui;
};

#endif // EDITSTUDENTWINDOW_H
