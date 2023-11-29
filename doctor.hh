#ifndef DOCTOR
#define DOCTOR
using namespace std;
#include <string>

#include "./person.hh"

class appointment;
class prescription;
class bill;
class doctor : public person
{
private:
    string type;
    int appointmentsBooked;
    friend class appointment;
    friend class prescription;
    friend class bill;

public:
    doctor();
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void getDetails(int rec = 0);
    void removePerson();
};
#endif // !DOCTOR