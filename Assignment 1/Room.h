#include <ctime>
#include <string>

using namespace std;

class Room {
   private:
    string customer;
    string checkIn;
    string checkOut;
    int numberOfBed;

   public:
    Room();
    Room(string customer, string checkIn, string checkOut, int numberOfBed);
    int addDate();
};