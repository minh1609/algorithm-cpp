using namespace std;

#include "DateHandler.h"
#include <ctime>
#include <sstream>

DateHandler::DateHandler(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

DateHandler::DateHandler() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

DateHandler::DateHandler(string date) {
    stringstream ss(date);
    vector<int> result;

    while (ss.good()) {
        string tmp;
        getline(ss, tmp, '/');
        int num = stoi(tmp);
        result.push_back(num);
    }
    this->day = result[0];
    this->month = result[1];
    this->year = result[2];
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

void DateHandler::print() {
    cerr << day << "/" << month << "/" << year;
}

bool DateHandler::isSmallerOrEqual(DateHandler d2) {
    if (this->year < d2.getYear()) {
        return true;
    } else if (this->year == d2.getYear() && this->month <= d2.getMonth()) {
        return true;
    } else if (this->year == d2.getYear() && this->month == d2.getMonth() && this->day <= d2.getDay()) {
        return true;
    } else
        return false;
}