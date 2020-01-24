#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Customer.cpp"
#include "DateHandler.cpp"
#include "Room.cpp"
#include "RoomLinkedList.cpp"
using namespace std;

//process data from txt file, store in vector
void readFile(vector<Customer>& list) {
    ifstream fin;
    fin.open("Customers.txt");
    string line;

    getline(fin, line);

    // Process Each line
    while (!fin.eof()) {
        getline(fin, line);
        vector<string> customerData;

        //split by ,
        stringstream ss(line);

        while (ss.good()) {
            string tmp;
            getline(ss, tmp, ',');
            tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

            customerData.push_back(tmp);
        }

        //Create new Customer Object from vector string
        DateHandler checkIn = DateHandler(customerData[0]);
        string Id = customerData[1];
        int bed = stoi(customerData[2]);
        DateHandler checkOut = DateHandler(customerData[0]);
        checkOut.addDay(stoi(customerData[3]));
        Customer newCustomer = Customer(checkIn, Id, bed, checkOut);

        list.push_back(newCustomer);
    }
}

int main() {
    vector<Customer> customers;
    readFile(customers);

    RoomLinkedList oneBed = RoomLinkedList(100);
    RoomLinkedList twoBeds = RoomLinkedList(50);
    RoomLinkedList threeBeds = RoomLinkedList(30);

    for (int i = 0; i < customers.size(); i++) {
        Customer cust = customers[i];
        if (cust.bedRequest == 1 && oneBed.available() > 0) {
            Room r = Room(cust.customerId, cust.checkIn, cust.checkOut, cust.bedRequest);
            oneBed.addRoom(r);
        } else if (cust.bedRequest == 2 && twoBeds.available() > 0) {
            Room r = Room(cust.customerId, cust.checkIn, cust.checkOut, cust.bedRequest);
            twoBeds.addRoom(r);
        } else if (cust.bedRequest == 3 && threeBeds.available() > 0) {
            Room r = Room(cust.customerId, cust.checkIn, cust.checkOut, cust.bedRequest);
            threeBeds.addRoom(r);
        } else {
            cerr << "no room available for";
            cust.print();
        }
    }

    return 0;
}