#include <iostream>
#include <queue>

#include <string>

#include "ER.cpp"
#include "Patient.cpp"

using namespace std;

int main() {
    ER<Patient> er = ER<Patient>();
    er.insert(Patient("1", 3));
    er.insert(Patient("2", 4));
    er.insert(Patient("3", 1));
    er.insert(Patient("4", 2));
    er.print();

    er.remove();
    er.print();

    er.remove();
    er.print();

    er.insert(Patient("5", 2));
    er.print();

    er.remove();
    er.print();

    return 0;
}