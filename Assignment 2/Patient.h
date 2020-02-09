#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient {
   public:
    int priority;
    string id;

    Patient(string id, int priority);
};
bool operator<(const Patient& p1, const Patient& p2) {
    return p1.priority < p2.priority;
}
ostream& operator<<(ostream& os, Patient p) {
    os << "{id:" << p.id << ", priority:" << p.priority << "}";
    return os;
}

#endif
