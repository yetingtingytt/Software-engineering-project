using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "global.hh"
#include "prescription.hh"
#include "hospital.hh"

prescription::prescription()
{
    id = -1;
    D.id = -1;
    P.id = -1;
    pre = "";
    data = "";
}
prescription::~prescription()
{
    id = -1;
    D.id = -1;
    P.id = -1;
    pre = "";
    data = "";
    return;
}
void prescription::fillMap()
{
    fstream f;
    f.open("./data/prescriptions.csv", ios::in);
    string temp;
    getline(f >> ws, temp);
    while (getline(f >> ws, temp))
    {
        prescription p;
        stringstream s(temp);
        string s1, s2, s3;
        getline(s, s1, ',');
        getline(s, s2, ','); 
        getline(s, s3, ',');
        getline(s, p.pre, ',');
        getline(s, p.data, ',');
        p.id = strToNum(s1);
        p.D = hospital::doctorsList[strToNum(s2)];
        p.P = hospital::patientsList[strToNum(s3)];

        hospital::prescriptionsList[p.id] = p;
    }
    f.close();
    return;
}
void prescription::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    f << "prescriptionId,doctorId,patientId,prescription,data,\n";
    for (auto i : hospital::prescriptionsList)
        f << i.second.id << "," << i.second.D.id << "," << i.second.P.id
        << "," << i.second.pre << ","<<i.second.data << endl;
    f.close();
    remove("./data/prescriptions.csv");
    rename("./data/temp.csv", "./data/prescriptions.csv");
    return;
}
void prescription::printDetails()
{
    if (id == -1)
        return;
    cout << "\n\n\nPrescription Details:\nID                 : " << id << "\n"
        << "Patient's Name     : " + P.firstName + " " + P.lastName + "(ID = " << P.id << ")\n"
        << "Doctor's Name      : " + D.firstName + " " + D.lastName + "(ID = " << D.id << ")\n"
        << "Prescription       : " << pre << "\n"
        << "Data               : " << data << "\n\n";
    return;
}
void prescription::addPrescription()
{
    if (hospital::prescriptionsList.size() == hospital::prescriptionsLimit)
    {
        cout << "\n\nPrescriptions limit reached, can't add more!\n\n";
        return;
    }
    cout << "\n\nIs the patient already registered (Y : Yes || N : No)?\n";
    char ans;
    cin >> ans;
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Y or N?\n";
        cin >> ans;
    }
    if (ans == 'N')
    {
        cout << "Register the patient:\n";
        P.addPerson();
    }
    else
    {
        cout << "Search for the required patient:\n\n";
        ans = 'Y';
        while (ans == 'Y')
        {
            P.getDetails();
            ans = 'K';
            if (P.id == -1)
            {
                cout << "Try again (Y : Yes || N : No)?\n";
                cin >> ans;
                while (ans != 'Y' && ans != 'N')
                {
                    cout << "Y or N?\n";
                    cin >> ans;
                }
            }
        }
        if (ans == 'N')
        {
            return;
        }
    }
    cout << "\n\nNow, search for the required doctor:\n";
    ans = 'Y';
    while (ans == 'Y')
    {
        D.getDetails();
        ans = 'K';
        if (D.id == -1)
        {
            cout << "Try again (Y : Yes || N : No)?\n";
            cin >> ans;
            while (ans != 'Y' && ans != 'N')
            {
                cout << "Y or N?\n";
                cin >> ans;
            }
        }
    }
    if (ans == 'N')
    {
        return;
    }
    cout << "\nFill out prescription: \n";
    getline(cin >> ws, pre);

    std::stringstream ss;
    ss << yyyymmdd;
    // 获取年、月、日部分
    std::string YYYY_str = ss.str().substr(0, 4);
    std::string MM_str = ss.str().substr(4, 2);
    std::string DD_str = ss.str().substr(6, 2);
    data= YYYY_str + "年" + MM_str + "月" + DD_str + "日";

    if (hospital::prescriptionsList.rbegin() != hospital::prescriptionsList.rend())
        id = ((hospital::prescriptionsList.rbegin())->first) + 1;
    else
        id = 1;
  
    hospital::prescriptionsList[id] = *this;

    cout << "\nPrescription of patient " + P.firstName + " " + P.lastName + " with doctor "
        << D.firstName << " " << D.lastName << " added successfully!\n";
    printDetails();
    return;
}
void prescription::getDetails()
{
    cout << "\nEnter prescription ID:\n";
    cin >> id;
    if (hospital::prescriptionsList.find(id) == hospital::prescriptionsList.end())
    {
        cout << "\nInvalidprescription ID!\n";
        id = -1;
        return;
    }
    *this = hospital::prescriptionsList[id];
    return;
}
void prescription::deletePrescription()
{
    cout << "\nSearch for the Prescription you want to delete.\n";
    getDetails();
    if (id == -1)
        return;
    hospital::prescriptionsList.erase(id);

    cout << " prescription " << id << " deleted successfully!\n";
    return;
}