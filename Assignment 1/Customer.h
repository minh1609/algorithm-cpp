#include <string>
#include "DateHandler.h"
using namespace std;

class Customer {
   private:
   public:
    string customerId;
    int bedRequest;
    DateHandler checkIn;
    DateHandler checkOut;
    Customer(DateHandler checkIn, string customerId, int bed, DateHandler checkOut);
    void print();
};