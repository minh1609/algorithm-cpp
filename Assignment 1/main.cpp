#include <ctime>
#include <iostream>
#include <string>

#include "DateHandler.cpp"

using namespace std;

int main() {
    DateHandler t1 = DateHandler(1, 1, 2014);
    t1.addDay(5);
    cerr << t1.getDay() << " " << t1.getMonth() << " " << t1.getYear();
    return 0;
}