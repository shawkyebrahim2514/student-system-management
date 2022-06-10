#ifndef ALLSTUDENTSWINDOW_H
#define ALLSTUDENTSWINDOW_H

#include <QDialog>
#include <QListWidget>
namespace Ui {
class allStudentsWindow;
}

class allStudentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit allStudentsWindow(QWidget *parent = nullptr);
    ~allStudentsWindow();

private slots:
    void on_allStudentsArea_itemClicked(QListWidgetItem *item);

private:
    Ui::allStudentsWindow *ui;
};

#endif // ALLSTUDENTSWINDOW_H
