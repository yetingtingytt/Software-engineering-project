using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "global.hh"
#include "driver.hh"
#include "hospital.hh"

driver::driver()
{
    id = -1;
    licenseNumber = "";
    idle = 0;
    cat = "driver";
    category = 4;
}
void driver::fillMap()
{
    fstream f;
    f.open("./data/drivers.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        driver d;
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
        getline(s, d.licenseNumber, ',');
        getline(s, s9, ',');
        d.id = strToNum(s1);
        d.gender = s4[0];
        d.age = strToNum(s5);
        d.idle = (s9 == "Y");
        hospital::driversList[d.id] = d;
    }
    f.close();
    return;
}
void driver::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "driverId,firstName,lastName,gender,age,mobNumber,address,licenseNumber,idle?\n";
    for (auto i : hospital::driversList)
        f << i.second.id << "," << i.second.firstName << "," << i.second.lastName << "," << i.second.gender
          << "," << i.second.age << "," << i.second.mobNumber << "," << i.second.address
          << "," << i.second.licenseNumber << "," << (i.second.idle ? 'Y' : 'N') << endl;
    f.close();
    remove("./data/drivers.csv");
    rename("./data/temp.csv", "./data/drivers.csv");
    return;
}
void driver::addPerson()
{
    if (hospital::driversList.size() == hospital::driversLimit)
    {
        cout << "\n\nDrivers limit reached, can't add more!\n\n";
        return;
    }
    //18 and 65 are the age limits for registration of a new driver;
    person::addPerson(18, 65);
    if ((age < 18) || (age > 65))
        return;
    cout << "\nEnter the license number of the driver: \n";
    getline(cin >> ws, licenseNumber);
    idle = 1;
    if (hospital::driversList.rbegin() != hospital::driversList.rend())
        id = ((hospital::driversList.rbegin())->first) + 1;
    else
        id = 1;
    hospital::driversList[id] = *this;

    cout << "\n"
         << firstName << " " << lastName << " registered successfully!\n";
    cout << "Their ID is: " << id << "\n";

    return;
}
void driver::printDetails()
{
    if (id == -1)
        return;
    person::printDetails();
    cout << "License Number  : " << licenseNumber << "\n";
    cout << "Idle?           : " << (idle ? "Y\n" : "N\n");
    return;
}
void driver::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n[3]: Filter by License Number\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2 && opt != 3)
        cout << "option 1, 2 or 3?\n", cin >> opt;
    //1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (hospital::driversList.find(reqId) != hospital::driversList.end())
            *this = hospital::driversList[reqId];
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
        vector<driver> matchingRecords;
        for (auto i : hospital::driversList)
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
                cout << "\nEnter the ID of the required driver: ";
                cin >> reqId;
                if (hospital::driversList.find(reqId) != hospital::driversList.end())
                    *this = hospital::driversList[reqId];
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
    //3: Filter by licenseNumber;
    else if (opt == 3)
    {
        string reqlicenseNumber;
        cout << "Enter the license number of driver required:\n";
        getline(cin >> ws, reqlicenseNumber);
        for (auto i : hospital::driversList)
        {
            if (i.second.licenseNumber == reqlicenseNumber)
            {
                *this = i.second;
                return;
            }
        }
        //if a record is found, it's details will be stored in the driver class object that called this function,
        //and the control is returned;
        //else:
        cout << "\nNo matching record found!\n";
    }
    return;
}
void driver::removePerson()
{
    cout << "\nSearch for the driver you want to remove.\n";
    getDetails();
    if (id == -1)
        return;
    if (!idle)
    {
        cout << "\nSorry, the driver you selected to remove is NOT currently idle.\nOnly idlers can be removed.\n\n";
        return;
    }
    hospital::driversList.erase(id);

    cout << firstName << " " << lastName << " removed successfully!\n";
    return;
}