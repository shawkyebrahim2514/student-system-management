#ifndef STUDENTSEARCHING_H
#define STUDENTSEARCHING_H

#include <QDialog>
#include <QListWidget>
namespace Ui {
class studentSearching;
}

class studentSearching : public QDialog
{
    Q_OBJECT

public:
    QString yearName;
    explicit studentSearching(QWidget *parent = nullptr);
    ~studentSearching();

private slots:
    void on_firstYearBtn_clicked();

    void on_secondYearBtn_clicked();

    void on_thirdYearBtn_clicked();

    void on_fourthYearBtn_clicked();

    void on_checkIDBtn_clicked();

    void on_firstSemesterBtn_clicked();

    void on_secondSemesterBtn_clicked();

    void on_IDArea_textEdited(const QString &arg1);

    void on_subjectsArea_itemClicked(QListWidgetItem *item);

public:
    Ui::studentSearching *ui;
};

#endif // STUDENTSEARCHING_H
