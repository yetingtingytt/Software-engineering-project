using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "global.hh"
#include "ambulance.hh"
#include "hospital.hh"

ambulance::ambulance()
{
    id = -1;
    address = "`````";
    D.id = -1;
}
void ambulance::fillMap()
{
    fstream f;
    f.open("./data/ambulances.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        ambulance a;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s3, s4, s5;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, a.carNumber, ',');
        getline(s, s3, ',');
        getline(s, s4, ',');
        getline(s, s5, ',');
        a.id = strToNum(s1);
        a.idle = (s3 == "Y");
        if (!a.idle)
        {
            a.address=s4;
            a.D = hospital::driversList[strToNum(s5)];
        }
        hospital::ambulancesList[a.id] = a;
    }
    f.close();
    return;
}
void ambulance::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    f << "ambulanceId,carNumber,idle?,address,driverID\n";
    for (auto i : hospital::ambulancesList)
    {
        f << i.second.id << "," << i.second.carNumber
          << "," << (i.second.idle ? ("Y,NA,NA\n") : ("N," + i.second.address + ","));
        if (!(i.second.idle))
        {
            f << i.second.D.id << endl;
        }
    }
    f.close();
    remove("./data/ambulances.csv");
    rename("./data/temp.csv", "./data/ambulances.csv");
    return;
}
void ambulance::addAmbulance()
{
    if (hospital::ambulancesList.size() == hospital::ambulancesLimit)
    {
        cout<<"\n\nAmbulances limit reached, can't add more!\n\n";
        return;
    }
    //getting the basic details of the ambulance from the user side;
    cout << "\nEnter Car Registration Number of the ambulance:\n";
    getline(cin >> ws, carNumber);
    if (hospital::ambulancesList.rbegin() != hospital::ambulancesList.rend())
        id = ((hospital::ambulancesList.rbegin())->first) + 1;
    else
        id = 1;
    hospital::ambulancesList[id] = *this;

    cout << "\n"
         <<  " ambulance " << " added successfully!\n";
    cout << "Its ID is: " << id << "\n";
}
void ambulance::printDetails()
{
    if (id == -1)
        return;
    cout << "Details:\n";
    cout << "ID                      : " << id << "\n";
    cout << "Car Registration Number : " << carNumber << "\n";
    cout << "Idle?                   : " << ((idle) ? "Y" : "N") << "\n";
    if (!idle)
    {
        cout << "Going to Address: " << address << "\n";
        cout << "Driver ID       : " << D.id << "\n";
    }
    return;
}
void ambulance::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2] Filter by Car Reg. Number\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2)
        cout << "option 1 or 2?\n", cin >> opt;
    //1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (hospital::ambulancesList.find(reqId) != hospital::ambulancesList.end())
            *this = hospital::ambulancesList[reqId];
        else
            cout << "\nNo matching record found!\n";
    }
    //2: Filter by vehicle reg. number;
    else if (opt == 2)
    {
        string reqN;
        cout << "Enter the Car reg. number of ambulance required:\n";
        getline(cin >> ws, reqN);
        for (auto i : hospital::ambulancesList)
        {
            if (i.second.carNumber == reqN)
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

void ambulance::send()
{

    //*************picking an idle ambulance*************;

    bool gotOne = 0;
    for (auto i : hospital::ambulancesList)
    {
        if (i.second.idle)
        {
            *this = i.second;
            gotOne = 1;
            break;
        }
    }
    if (!gotOne)
    {
        cout << "No, idle ambulance found!"
             << "\n";
        return;
    }
    //*************  picking a free driver  *************;

    gotOne = 0;
    for (auto i : hospital::driversList)
    {
        if (i.second.idle)
        {
            D = i.second;
            gotOne = 1;
            break;
        }
    }
    if (!gotOne)
    {
        cout << "No, idle driver found!"
             << "\n";
        return;
    }

    idle = 0;

    cout << "Enter destination address:\n";
    getline(cin>>ws,address);

    //updating status of ambulance;
    hospital::ambulancesList[id] = *this;

    //updating status of driver;
    hospital::driversList[D.id].idle = 0;

    cout << "ambulance with " << carNumber << " sent with driver " << D.firstName << " " << D.lastName << " (ID = " << D.id << ") successfully!\n";
    return;
}
void ambulance::reportArrival()
{
    getDetails();

    //updating status of driver;
    //note that if we first update the status of ambulance we will lose the identity of it's driver;
    //and then there will be no way to update the status of the driver;
    hospital::driversList[D.id].idle = 1;

    //updating status of ambulance;
    hospital::ambulancesList[id].idle = 1;
    hospital::ambulancesList[id].address = "`````";
    driver d;
    hospital::ambulancesList[id].D = d;

    cout << "\nStatus updated successfully!\n\n";
    return;
}
void ambulance::removeAmbulance()
{
    cout << "\nSearch for the ambulance you want to remove.\n";
    getDetails();
    if (id == -1)
        return;
    if (!idle)
    {
        cout << "\nSorry, the ambulance you selected to remove is NOT currently idle.\nOnly idlers can be removed.\n\n";
        return;
    }
    hospital::ambulancesList.erase(id);
    cout << " ambulance with " << carNumber  << "removed successfully!\n";
    return;
}