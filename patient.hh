#ifndef PATIENT
#define PATIENT
using namespace std;

#include "./person.hh"

class appointment;
class prescription;
class bill;
class patient : public person
{
private:
    int height; //in cms;
    int weight; //in pounds;
    bool hospitalized;
    friend class appointment;
    friend class prescription;
    friend class bill;

public:
    patient();
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void getDetails(int rec = 0);
    void hospitalize();
    void discharge();
    void removePerson();
};
#endif // !PATIENT