#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
using namespace std;
#include "global.hh"
#include "hospital.hh"
#include "person.hh"
#include "appointment.hh"
#include "patient.hh"
#include "doctor.hh"
#include "nurse.hh"
#include "driver.hh"
#include "ambulance.hh"
#include "prescription.hh"
#include "bill.hh"

void appointmentsMenu();
void patientsMenu();
void doctorsMenu();
void nursesMenu();
void driversMenu();
void ambulancesMenu();
void prescriptionsMenu();
void billsMenu();

void appointmentsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/APPOINTMENTS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Book an appointment\n";
        cout << "[02] : Get appointment details\n";
        cout << "[03] : Show all appointments\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            appointment a;
            a.book();
        }
        else if (purpose == 2)
        {
            appointment a;
            a.getDetails();
            a.printDetails();
        }
        else if (purpose == 3)
        {
            hospital::printAppointments();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}
void prescriptionsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/PRESCRIPTIONS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Add a prescription\n";
        cout << "[02] : Get prescription details\n";
        cout << "[03] : Show all prescriptions\n";
        cout << "[04] : Delete a prescription\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            prescription p;
            p.addPrescription();
        }
        else if (purpose == 2)
        {
            prescription p;
            p.getDetails();
            p.printDetails();
        }
        else if (purpose == 3)
        {
            hospital::printPrescriptions();
        }
        else if (purpose == 4)
        {
            prescription p;
            p.deletePrescription();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}
void billsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/BILLS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Add a bill\n";
        cout << "[02] : Get bill details\n";
        cout << "[03] : Show all bills\n";
        cout << "[04] : Delete a bill\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            bill b;
            b.addBill();
        }
        else if (purpose == 2)
        {
            bill b;
            b.getDetails();
            b.printDetails();
        }
        else if (purpose == 3)
        {
            hospital::printBills();
        }
        else if (purpose == 4)
        {
            bill b;
            b.deleteBill();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}
void patientsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/PATIENTS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new patient\n";
        cout << "[02] : Get patient details\n";
        cout << "[03] : Hospitalize a registered patient\n";
        cout << "[04] : Discharge a patient\n";
        cout << "[05] : Remove a patient \n";
        cout << "[06] : Get details of all registered patients\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            patient p;
            p.addPerson();
        }
        else if (purpose == 2)
        {
            patient p;
            p.getDetails(1);
            p.printDetails();
        }
        else if (purpose == 3)
        {
            patient p;
            p.hospitalize();
        }
        else if (purpose == 4)
        {
            patient p;
            p.discharge();
        }
        else if (purpose == 5)
        {
            patient p;
            p.removePerson();
        }
        else if (purpose == 6)
        {
            hospital::printPatients();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void doctorsMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/DOCTORS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new doctor\n";
        cout << "[02] : Get doctor details\n";
        cout << "[03] : Remove a doctor\n";
        cout << "[04] : Get details of all registered doctors\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            doctor d;
            d.addPerson();
        }
        else if (purpose == 2)
        {
            doctor d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            doctor d;
            d.removePerson();
        }
        else if (purpose == 4)
        {
            hospital::printDoctors();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void nursesMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/NURSES\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new nurse\n";
        cout << "[02] : Get nurse details\n";
        cout << "[03] : Remove a nurse\n";
        cout << "[04] : Get details of all registered nurses\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            nurse n;
            n.addPerson();
        }
        else if (purpose == 2)
        {
            nurse n;
            n.getDetails(1);
            n.printDetails();
        }
        else if (purpose == 3)
        {
            nurse n;
            n.removePerson();
        }
        else if (purpose == 4)
        {
            hospital::printNurses();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void driversMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/DRIVERS\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Register a new driver\n";
        cout << "[02] : Get driver details\n";
        cout << "[03] : Remove a driver\n";
        cout << "[04] : Get details of all registered drivers\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            driver d;
            d.addPerson();
        }
        else if (purpose == 2)
        {
            driver d;
            d.getDetails(1);
            d.printDetails();
        }
        else if (purpose == 3)
        {
            driver d;
            d.removePerson();
        }
        else if (purpose == 4)
        {
            hospital::printDrivers();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

void ambulancesMenu()
{
    bool exit = false;
    while (!exit)
    {
        int purpose = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect an option:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME/AMBULANCES\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Add an ambulance\n";
        cout << "[02] : Send an ambulance\n";
        cout << "[03] : Get ambulance details\n";
        cout << "[04] : Report ambulance arrival\n";
        cout << "[05] : Remove an ambulance\n";
        cout << "[06] : Get details of all registered ambulances\n\n";
        cout << "[-1] : Back\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> purpose;

        if (purpose == 1)
        {
            ambulance a;
            a.addAmbulance();
        }
        else if (purpose == 2)
        {
            ambulance a;
            a.send();
        }
        else if (purpose == 3)
        {
            ambulance a;
            a.getDetails(1);
            a.printDetails();
        }
        else if (purpose == 4)
        {
            ambulance a;
            a.reportArrival();
        }
        else if (purpose == 5)
        {
            ambulance a;
            a.removeAmbulance();
        }
        else if (purpose == 6)
        {
            hospital::printAmbulances();
        }
        else if (purpose == -1)
        {
            exit = true;
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clearing cin buffer;

        cout << endl;
        cout << "\nPress ENTER to continue...\n";
        cout << endl;

        getchar();
    }
    return;
}

int main()
{
    fstream f;
    f.open("./data/appointments.csv", ios::in);
    string temp, s, header;
    getline(f, header);
    getline(f, temp);
    f.close();
    stringstream str(temp);
    getline(str, s, ',');
    getline(str, s, ',');
    int dd, mm, yyyy;
    if (s != "")
        cout << "\n\n\nLast usage date (DD-MM-YYYY) : " << s.substr(6, 2) + "-" + s.substr(4, 2) + "-" + s.substr(0, 4) + "\n";
    cout << "\nPlease Enter Today's Date (DD-MM-YYYY) :\n\nEnter Day: ";
    cin >> dd;
    while (dd < 1 || dd > 31)
    {
        cout << "Invalid Day! Please enter a valid day: ";
        cin >> dd;
    }
    cout << "Enter Month: ";
    cin >> mm;
    while (mm < 1 || mm > 12)
    {
        cout << "Invalid Month! Please enter a valid month: ";
        cin >> mm;
    }
    cout << "Enter Year (YYYY): ";
    cin >> yyyy;
    yyyymmdd = yyyy * 10000 + mm * 100 + dd;
    if (stoi(((s == "") ? ("0") : (s))) < yyyymmdd)
    {
        f.open("./data/temp.csv", ios::out);
        f << header << "\n";
        f.close();
        remove("./data/appointments.csv");
        rename("./data/temp.csv", "./data/appointments.csv");
        fstream fout("./data/temp.csv", ios::out);
        f.open("./data/doctors.csv", ios::in);
        getline(f, temp);
        fout << temp << endl;
        while (getline(f, temp))
        {
            if (temp.size())
                temp[temp.size() - 1] = '0';
            fout << temp << endl;
        }
        f.close();
        fout.close();
        remove("./data/doctors.csv");
        rename("./data/temp.csv", "./data/doctors.csv");
    }
    else if (stoi(s) > yyyymmdd && s != "")
    {
        cout << "\nEntered date detected wrong!\nToday's date can't be older than the last usage date, which is : "
             << s.substr(6, 2) + "-" + s.substr(4, 2) + "-" + s.substr(0, 4) + "\n";
        return 0;
    }
    // filling maps with data from csv files;
    {
        doctor d1;
        patient p1;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        prescription p2;
        bill b;
        d1.fillMap();
        p1.fillMap();
        n.fillMap();
        d2.fillMap();
        a1.fillMap();
        a2.fillMap();
        p2.fillMap();
        b.fillMap();
    }
    while (1)
    {
        int category = 0;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\nSelect a category:\n\n";

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "./HOME\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : APPOINTMENTS\n";
        cout << "[02] : PATIENTS\n";
        cout << "[03] : DOCTORS\n";
        cout << "[04] : NURSES\n";
        cout << "[05] : DRIVERS\n";
        cout << "[06] : AMBULANCES\n";
        cout << "[07] : PRESCRIPTIONS\n";
        cout << "[08] : BILLS\n\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
        cout << "Enter your choice: ";
        cin >> category;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "\n";
        if (category == -1)
        {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "\nShutting Down System...\n";
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if (category == 1)
        {
            appointmentsMenu();
        }
        else if (category == 2)
        {
            patientsMenu();
        }
        else if (category == 3)
        {
            doctorsMenu();
        }
        else if (category == 4)
        {
            nursesMenu();
        }
        else if (category == 5)
        {
            driversMenu();
        }
        else if (category == 6)
        {
            ambulancesMenu();
        }
        else if (category == 7)
        {
            prescriptionsMenu();
        }
        else if (category == 8)
        {
            billsMenu();
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }

        cout << endl;
    }
   
    {
        doctor d1;
        patient p1;
        nurse n;
        driver d2;
        ambulance a1;
        appointment a2;
        prescription p2;
        bill b;
        d1.saveMap();
        p1.saveMap();
        n.saveMap();
        d2.saveMap();
        a1.saveMap();
        a2.saveMap();
        p2.saveMap();
        b.saveMap();
    }

    return 0;
}