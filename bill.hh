#ifndef BILL
#define BILL
using namespace std;

#include "./patient.hh"
#include "./doctor.hh"
#include "./global.hh"

class bill
{
private:
    int id;
    doctor D;
    patient P;
    int price; //prescription
    string data;//XXXXÄêXXÔÂXXÈÕ
public:
    bill();
    ~bill();
    void fillMap();
    void saveMap();
    void printDetails();
    void addBill();
    void getDetails();
    void deleteBill();
};
#endif // !BILL