using namespace std;

#include "DateHandler.h"
#include <ctime>

DateHandler::DateHandler(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int DateHandler::getDay() {
    return day;
}

int DateHandler::getMonth() {
    return month;
}

int DateHandler::getYear() {
    return year;
}

void addDayHelper(struct tm* startDate, int days) {
    time_t seconds = mktime(startDate) + (days * 24 * 60 * 60);

    *startDate = *localtime(&seconds);
}

void DateHandler::addDay(int days) {
    struct tm date = {0, 0, 0};

    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    addDayHelper(&date, days);

    this->day = date.tm_mday;
    this->month = date.tm_mon + 1;
    this->year = date.tm_year + 1900;
}