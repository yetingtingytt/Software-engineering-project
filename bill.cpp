using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "global.hh"
#include "bill.hh"
#include "hospital.hh"

bill::bill()
{
    id = -1;
    D.id = -1;
    P.id = -1;
    price = 0;
    data = "";
}
bill::~bill()
{
    id = -1;
    D.id = -1;
    P.id = -1;
    price = 0;
    data = "";
    return;
}
void bill::fillMap()
{
    fstream f;
    f.open("./data/bills.csv", ios::in);
    string temp;
    getline(f >> ws, temp);
    while (getline(f >> ws, temp))
    {
        bill b;
        stringstream s(temp);
        string s1, s2, s3, s4;
        getline(s, s1, ',');
        getline(s, s2, ',');
        getline(s, s3, ',');
        getline(s, s4, ',');
        getline(s, b.data, ',');
        b.id = strToNum(s1);
        b.D = hospital::doctorsList[strToNum(s2)];
        b.P = hospital::patientsList[strToNum(s3)];
        b.price= strToNum(s4);

        hospital::billsList[b.id] = b;
    }
    f.close();
    return;
}
void bill::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    f << "billId,doctorId,patientId,price,data,\n";
    for (auto i : hospital::billsList)
        f << i.second.id << "," << i.second.D.id << "," << i.second.P.id
        << "," << i.second.price << "," << i.second.data << endl;
    f.close();
    remove("./data/bills.csv");
    rename("./data/temp.csv", "./data/bills.csv");
    return;
}
void bill::printDetails()
{
    if (id == -1)
        return;
    cout << "\n\n\nBill Details:\nID                 : " << id << "\n"
        << "Patient's Name     : " + P.firstName + " " + P.lastName + "(ID = " << P.id << ")\n"
        << "Doctor's Name      : " + D.firstName + " " + D.lastName + "(ID = " << D.id << ")\n"
        << "Price              : " << price << "(元)\n"
        << "Data               : " << data << "\n\n";
    return;
}
void bill::addBill()
{
    if (hospital::billsList.size() == hospital::billsLimit)
    {
        cout << "\n\nBills limit reached, can't add more!\n\n";
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
    cout << "\nEnter the price of the bill(Using integers): \n";
    cin >> price;

    std::stringstream ss;
    ss << yyyymmdd;
    // 获取年、月、日部分
    std::string YYYY_str = ss.str().substr(0, 4);
    std::string MM_str = ss.str().substr(4, 2);
    std::string DD_str = ss.str().substr(6, 2);
    data = YYYY_str + "年" + MM_str + "月" + DD_str + "日";

    if (hospital::billsList.rbegin() != hospital::billsList.rend())
        id = ((hospital::billsList.rbegin())->first) + 1;
    else
        id = 1;

    hospital::billsList[id] = *this;

    cout << "\nBill of patient " + P.firstName + " " + P.lastName + " with doctor "
        << D.firstName << " " << D.lastName << " added successfully!\n";
    printDetails();
    return;
}
void bill::getDetails()
{
    cout << "\nEnter bill ID:\n";
    cin >> id;
    if (hospital::billsList.find(id) == hospital::billsList.end())
    {
        cout << "\nInvalidbill ID!\n";
        id = -1;
        return;
    }
    *this = hospital::billsList[id];
    return;
}
void bill::deleteBill()
{
    cout << "\nSearch for the Bill you want to delete.\n";
    getDetails();
    if (id == -1)
        return;
    hospital::billsList.erase(id);

    cout << " bill " << id << " deleted successfully!\n";
    return;
}