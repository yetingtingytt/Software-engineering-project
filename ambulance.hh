#ifndef AMBULANCE
#define AMBULANCE
using namespace std;
#include <string>

#include "./driver.hh"

class ambulance
{
private:
    int id;
    string carNumber; //vehicle registration number;
    bool idle;
    string address;
    driver D;

public:
    ambulance();
    void fillMap();
    void saveMap();
    void addAmbulance();
    void printDetails();
    void getDetails(int rec = 0);
    void send();
    void reportArrival();
    void removeAmbulance();
};
#endif // !AMBULANCE