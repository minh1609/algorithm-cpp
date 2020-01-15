#include <ctime>
#include <iostream>
#include <string>

using namespace std;

//add day to startDate
void addDaytoDate(struct tm* startDate, int days) {
    time_t second = mktime(startDate) + (days * 24 * 60 * 60);

    *startDate = *localtime(&second);
}

int main() {
    struct tm date = {0, 0, 0};

    int year = 2010;
    int month = 2;
    int day = 26;

    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    addDaytoDate(&date, 2);

    std::cout << date.tm_mday << std::endl;
    return 0;
}