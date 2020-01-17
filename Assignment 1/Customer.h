#include <string>
#include "DateHandler.h"
using namespace std;

class Customer {
   private:
   public:
    string customerId;
    int bedRequest;
    DateHandler checkIn;
    DateHandler checOut;
    Customer(string id, int bedRequest, DateHandler checkIn, DateHandler checkOut);
};