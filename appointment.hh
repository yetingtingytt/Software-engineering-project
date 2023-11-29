#ifndef APPOINTMENT
#define APPOINTMENT
using namespace std;

#include "./patient.hh"
#include "./doctor.hh"

class appointment
{
private:
    int id;
    doctor D;
    patient P;
    int hh; //���￪ʼʱ��
public:
    appointment();
    ~appointment();
    void fillMap();
    void saveMap();
    void printDetails();
    void book();
    void getDetails();
};
#endif // !APPOINTMENT