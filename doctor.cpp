using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "global.hh"
#include "doctor.hh"
#include "hospital.hh"

doctor::doctor()
{
    id = -1;
    type = "";
    appointmentsBooked = 0;
    cat = "doctor";
    category = 1;
}
void doctor::fillMap()
{
    fstream f;
    f.open("./data/doctors.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        doctor d;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s4, s5, s9;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, d.firstName, ',');
        getline(s, d.lastName, ',');
        getline(s, s4, ',');
        getline(s, s5, ',');
        getline(s, d.mobNumber, ',');
        getline(s, d.address, ',');
        getline(s, d.type, ',');
        getline(s, s9, ',');
        d.id = strToNum(s1);
        d.gender = s4[0];
        d.age = strToNum(s5);
        d.appointmentsBooked = strToNum(s9);
        hospital::doctorsList[d.id] = d;
    }
    f.close();
    return;
}
void doctor::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "doctorId,firstName,lastName,gender,age,mobNumber,address,type,appointmentsBooked\n";
    for (auto i : hospital::doctorsList)
        f << i.second.id << "," << i.second.firstName << "," << i.second.lastName << "," << i.second.gender
          << "," << i.second.age << "," << i.second.mobNumber << "," << i.second.address
          << "," << i.second.type << "," << i.second.appointmentsBooked << endl;
    f.close();
    remove("./data/doctors.csv");
    rename("./data/temp.csv", "./data/doctors.csv");
    return;
}
void doctor::addPerson()
{
    if (hospital::doctorsList.size() == hospital::doctorsLimit)
    {
        cout << "\n\nDoctors limit reached, can't add more!\n\n";
        return;
    }
    //18 and 65 are the age limits for registration of a new doctor;
    person::addPerson(18, 65);
    if ((age < 18) || (age > 65))
        return;
    cout << "\nEnter the type of the doctor: \n";
    getline(cin >> ws, type);
    if (hospital::doctorsList.rbegin() != hospital::doctorsList.rend())
        id = ((hospital::doctorsList.rbegin())->first) + 1;
    else
        id = 1;
    hospital::doctorsList[id] = *this;

    cout << "\n"
         << firstName << " " << lastName << " registered successfully!\n";
    cout << "Their ID is: " << id << "\n";

    return;
}
void doctor::printDetails()
{
    if (id == -1)
        return;
    person::printDetails();
    cout << "Type            : " << type << "\n";
    cout << "Appointments    : " << appointmentsBooked << "/8 (appointments booked today)\n";
    return;
}
void doctor::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n[3]: Filter by Type\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2 && opt != 3)
        cout << "option 1, 2 or 3?\n", cin >> opt;
    //1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (hospital::doctorsList.find(reqId) != hospital::doctorsList.end())
            *this = hospital::doctorsList[reqId];
        else
            cout << "\nNo matching record found!\n";
    }
    //2: Filter by name;
    else if (opt == 2)
    {
        string reqFName, reqLName;
        cout << "First Name:\n";
        getline(cin >> ws, reqFName);
        cout << "\nLast Name:\n";
        getline(cin, reqLName);
        vector<doctor> matchingRecords;
        for (auto i : hospital::doctorsList)
        {
            if (i.second.firstName == reqFName && i.second.lastName == reqLName)
                matchingRecords.push_back(i.second);
        }
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i : matchingRecords)
            i.printDetails();
        char tt = 'N';
        if (matchingRecords.size() > rec)
        {
            do
            {
                int reqId;
                cout << "\nEnter the ID of the required doctor: ";
                cin >> reqId;
                if (hospital::doctorsList.find(reqId) != hospital::doctorsList.end())
                    *this = hospital::doctorsList[reqId];
                else
                {
                    cout << "\nInvalid ID!\nTry again? (Y = Yes || N = No)\n";
                    cin >> tt;
                    while (tt != 'Y' || tt != 'N')
                        cout << "Y or N?\n", cin >> tt;
                }
            } while (tt == 'Y');
        }
    }
    //3: Filter by type;
    else if (opt == 3)
    {
        string reqType;
        cout << "Enter the type of doctor required:\n";
        getline(cin >> ws, reqType);
        vector<doctor> matchingRecords;
        for (auto i : hospital::doctorsList)
        {
            if (i.second.type == reqType)
                matchingRecords.push_back(i.second);
        }
        cout << "\n";
        cout << matchingRecords.size() << " matching record(s) found!\n";
        for (auto i : matchingRecords)
            i.printDetails();
        char tt = 'N';
        if (matchingRecords.size() > 0)
            do
            {
                int reqId;
                cout << "\nEnter the ID of the required doctor: ";
                cin >> reqId;
                if (hospital::doctorsList.find(reqId) != hospital::doctorsList.end())
                    *this = hospital::doctorsList[reqId];
                else
                {
                    cout << "\nInvalid ID!\nTry again? (Y = Yes || N = No)\n";
                    cin >> tt;
                    while (tt != 'Y' || tt != 'N')
                        cout << "Y or N?\n", cin >> tt;
                }
            } while (tt == 'Y');
    }
    return;
}
void doctor::removePerson()
{
    cout << "\nSearch for the doctor you want to remove.\n";
    getDetails();
    if (id == -1)
        return;
    if (appointmentsBooked > 0)
    {
        cout << "\nSelected doctor has appointments booked for today, can't be removed.\n\n";
        return;
    }
    hospital::doctorsList.erase(id);

    cout << firstName << " " << lastName << " removed successfully!\n";
    return;
}