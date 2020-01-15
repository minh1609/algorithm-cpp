#include <string>

using namespace std;

class Customer {
   private:
    string customerId;
    int bedRequest;

   public:
    Customer(string id, int bedRequest);
};