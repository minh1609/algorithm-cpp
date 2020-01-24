#include "Customer.h"

using namespace std;

Customer::Customer(DateHandler checkIn, string customerId, int bed, DateHandler checkOut) {
    this->customerId = customerId;
    this->bedRequest = bed;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
}

void Customer::print() {
    checkIn.print();
    cerr << "|" << customerId << "|" << bedRequest << "|";
    checkOut.print();
    cerr << endl;
}