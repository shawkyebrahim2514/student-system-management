#ifndef DATA_H
#define DATA_H
#include <string>
#include<map>
#include <QDialog>
struct year{
    std::map<QString,float>firstSemester,secondSemester;
};

struct student{
    QString name;
    float GPA;
    year firstYear,secondYear,thirdYear,fourthYear;
};

#endif // DATA_H
