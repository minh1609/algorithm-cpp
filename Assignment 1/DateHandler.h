#ifndef DATEHANDLER_H
#define DATEHANDLER_H

using namespace std;

#include <ctime>
//Add, substract days from date
class DateHandler {
   private:
    int day;
    int month;
    int year;

   public:
    DateHandler(int day, int month, int year);
    DateHandler();

    int getDay();
    int getYear();
    int getMonth();

    //add day to date, day < 0 to substract
    void addDay(int day);

    //compare date to date
    int compare(DateHandler d2);

    void print();
};

#endif