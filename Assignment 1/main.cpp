#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void DatePlusDays(struct tm* date, int days) {
    time_t date_seconds = mktime(date) + (days * 24 * 60 * 60);

    *date = *localtime(&date_seconds);
}

int main() {
    struct tm date = {0, 0, 0};

    int year = 2010;
    int month = 2;  // February
    int day = 26;   // 26th

    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    DatePlusDays(&date, 1);

    // Show time/date using default formatting
    std::cout << date.tm_mday << std::endl;
    return 0;
}