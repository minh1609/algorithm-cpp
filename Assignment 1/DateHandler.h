using namespace std;

#include <ctime>
//Add, substract days from date
class DateHandler {
   private:
    int day;
    int month;
    int year;

   public:
    int getDay();
    int getYear();
    int getMonth();

    DateHandler(int day, int month, int year);
    //add day to date, day < 0 to substract
    void addDay(int day);

    //compare date to date
    int compare(DateHandler d2);
};