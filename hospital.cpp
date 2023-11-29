using namespace std;
#include <iostream>
#include <sstream>
#include <fstream>

#include "doctor.hh"
#include "patient.hh"
#include "nurse.hh"
#include "driver.hh"
#include "ambulance.hh"
#include "appointment.hh"
#include "prescription.hh"
#include "bill.hh"
#include "hospital.hh"

map<int, doctor> hospital::doctorsList;
map<int, patient> hospital::patientsList;
map<int, nurse> hospital::nursesList;
map<int, driver> hospital::driversList;
map<int, ambulance> hospital::ambulancesList;
map<int, appointment> hospital::appointmentsList;
map<int, prescription> hospital::prescriptionsList;
map<int, bill> hospital::billsList;

const int hospital::doctorsLimit = 30;
const int hospital::nursesLimit = 50;
const int hospital::driversLimit = 30;
const int hospital::ambulancesLimit = 30;
const int hospital::appointmentsLimit = 240; //per day;
const int hospital::prescriptionsLimit = 1000;
const int hospital::billsLimit = 1000;

void hospital::printDoctors()
{
    for (auto i : doctorsList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printPatients()
{
    for (auto i : patientsList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printNurses()
{
    for (auto i : nursesList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printDrivers()
{
    for (auto i : driversList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printAmbulances()
{
    for (auto i : ambulancesList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printAppointments()
{
    for (auto i : appointmentsList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printPrescriptions()
{
    for (auto i : prescriptionsList)
        i.second.printDetails(), cout << "\n";
    return;
}
void hospital::printBills()
{
    for (auto i : billsList)
        i.second.printDetails(), cout << "\n";
    return;
}