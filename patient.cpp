using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "global.hh"
#include "patient.hh"
#include "hospital.hh"

patient::patient()
{
    id = -1;
    hospitalized = 0;
    cat = "patient";
    category = 2;
}
void patient::fillMap()
{
    fstream f;
    f.open("./data/patients.csv", ios::in);
    string temp;
    getline(f >> ws, temp);
    while (getline(f >> ws, temp))
    {
        patient p;
        stringstream s(temp);
        string s1, s4, s5, s8, s9, s10;
        getline(s, s1, ',');
        getline(s, p.firstName, ',');
        getline(s, p.lastName, ',');
        getline(s, s4, ',');
        getline(s, s5, ',');
        getline(s, p.mobNumber, ',');
        getline(s, p.address, ',');
        getline(s, s8, ',');
        getline(s, s9, ',');
        getline(s, s10, ',');
        p.id = strToNum(s1);
        p.gender = s4[0];
        p.age = strToNum(s5);
        p.height = strToNum(s8);
        p.weight = strToNum(s9);
        p.hospitalized = (s10 == "Y");
        hospital::patientsList[p.id] = p;
    }
    f.close();
    return;
}
void patient::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    f << "patientId,firstName,lastName,gender,age,mobNumber,address,height,weight,wasHospitalized?\n";
    for (auto i : hospital::patientsList)
        f << i.second.id << "," << i.second.firstName << "," << i.second.lastName << "," << i.second.gender
          << "," << i.second.age << "," << i.second.mobNumber << "," << i.second.address
          << "," << i.second.height << "," << i.second.weight << ","
          << (i.second.hospitalized ? 'Y' : 'N') << endl;
    f.close();
    remove("./data/patients.csv");
    rename("./data/temp.csv", "./data/patients.csv");
    return;
}
void patient::addPerson()
{
    person::addPerson();
    cout << "\nEnter the height of the patient (in cms):\n";
    cin >> height;
    cout << "\nEnter the weight of the patient (in pounds):\n";
    cin >> weight;
    char tt;
    cout << "\nIs the patient being hospitalized? (Y = Yes || N = No)\n";
    cin >> tt;
    while (tt != 'Y' && tt != 'N')
        cout << "Y or N?\n", cin >> tt;
    hospitalized = (tt == 'Y');
    if (hospital::patientsList.rbegin() != hospital::patientsList.rend())
        id = ((hospital::patientsList.rbegin())->first) + 1;
    else
        id = 1;
    hospital::patientsList[id] = *this;

    cout << "\n"
         << firstName << " " << lastName << " registered successfully!\n";
    cout << "Their ID is: " << id << "\n";

    return;
}
void patient::printDetails()
{
    if (id == -1)
        return;
    person::printDetails();
    cout << "Height (cms)    : " << height << "\n";
    cout << "Weight (pounds) : " << weight << "\n";
    cout << "Was Hospitalized? " << ((hospitalized) ? "Y" : "N") << "\n";
    return;
}
void patient::getDetails(int rec)
{
    int opt = 0;
    cout << "\nOPTIONS:\n[1]: Filter by ID\n[2]: Filter by Name\n\n";
    cin >> opt;
    while (opt != 1 && opt != 2)
        cout << "option 1 or 2?\n", cin >> opt;
    //1: Filter by ID;
    if (opt == 1)
    {
        int reqId;
        cout << "\nEnter ID:\n";
        cin >> reqId;
        if (hospital::patientsList.find(reqId) != hospital::patientsList.end())
            *this = hospital::patientsList[reqId];
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
        vector<patient> matchingRecords;
        for (auto i : hospital::patientsList)
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
                cout << "\nEnter the ID of the required patient: ";
                cin >> reqId;
                if (hospital::patientsList.find(reqId) != hospital::patientsList.end())
                    *this = hospital::patientsList[reqId];
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
    return;
}
void patient::hospitalize()
{
    cout << "\nSearch for the patient.\n";
    getDetails();
    if (id == -1)
        return;
    hospital::patientsList[id].hospitalized = 1;
    
    cout << firstName << " " << lastName << " hospitalized successfully!\n";
    return;
}
void patient::discharge()
{
    cout << "\nSearch for the patient.\n";
    getDetails();
    if (id == -1)
        return;
    hospital::patientsList[id].hospitalized = false;
    
    cout << firstName << " " << lastName << " discharged successfully!\n";
    return;
}
void patient::removePerson()
{
    cout << "\nSearch for the patient you want to remove.\n";
    getDetails();
    if (id == -1)
        return;
    if (hospitalized)
    {
        cout << "\nPatient is hospitalizd, can't be remove!\n\n";
        return;
    }
    hospital::patientsList.erase(id);
    
    cout << firstName << " " << lastName << " removed successfully!\n";
    return;
}
