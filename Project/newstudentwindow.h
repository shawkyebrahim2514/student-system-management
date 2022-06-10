#ifndef NEWSTUDENTWINDOW_H
#define NEWSTUDENTWINDOW_H

#include <QDialog>
#include <QListWidget>
namespace Ui {
class newStudentWindow;
}

class newStudentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newStudentWindow(QWidget *parent = nullptr);
    ~newStudentWindow();

private slots:
    void on_IDArea_textEdited(const QString &arg1);

    void on_registerBtn_clicked();

    void on_checkIDBtn_clicked();

private:
    Ui::newStudentWindow *ui;
};

#endif // NEWSTUDENTWINDOW_H
