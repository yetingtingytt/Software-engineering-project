#ifndef PRESCRIPTION
#define PRESCRIPTION
using namespace std;

#include "./patient.hh"
#include "./doctor.hh"
#include "./global.hh"

class prescription
{
private:
    int id;
    doctor D;
    patient P;
    string pre; //prescription
    string data;//XXXXÄêXXÔÂXXÈÕ
public:
    prescription();
    ~prescription();
    void fillMap();
    void saveMap();
    void printDetails();
    void addPrescription();
    void getDetails();
    void deletePrescription();
};
#endif // !PRESCRIPTION