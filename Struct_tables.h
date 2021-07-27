#pragma once

#ifndef      __Table_H__
#define      __Table_H__
#include"iostream"
#include<string>
using namespace std;

struct Salesman
{
    int id;
    string name;
    string city;
    int commission;

   Salesman()
   {
        cout << "Enter salesman info: "<<endl;

        cout << "Enter salesman ID: ";
        cin >> id;
        cin.ignore(256, '\n');

        cout << "Enter salesman name: ";
        fflush(stdin);
        getline(cin, name);

        cout << "Enter salesman city: ";
        fflush(stdin);
        getline(cin, city);

        cout << "Enter salesman commission: ";
        cin >> commission;
   }


};

struct Customers 
{
    int id;
    string name;
    string city;
    int grade;
    int salesman_ID;

    Customers()
    {
        cout << "Enter customer info: "<<endl;

        cout << "Enter customer ID: ";
        cin >> id;
        cin.ignore(256, '\n');

        cout << "Enter customer name: ";
        fflush(stdin);
        getline(cin, name);

        cout << "Enter customer city: ";
        fflush(stdin);
        getline(cin, city);

        cout << "Enter customer grade: ";
        cin >> grade;

        cout << "Enter salesman ID(customer table): ";
        cin >> salesman_ID;
    }
};

struct Orders
{
    int ord_no;
    int purch_amt;
    string ord_date;//convert in sql
    int customer_id;
    int salesman_id;

    Orders()
    {
        cout << "Enter order info: "<<endl;

        cout << "Enter order ID: ";
        cin >> ord_no;
        //cin.ignore(256, '\n');

        cout << "Enter order purch_amt: ";
        cin >> purch_amt;
        cin.ignore(256, '\n');

        cout << "Enter order date: ";
        fflush(stdin);
        getline(cin, ord_date);

        cout << "Enter customer_ID (orders table): ";
        fflush(stdin);
        cin >> customer_id;

        cout << "Enter salesman_ID (orders table): ";
        fflush(stdin);
        cin >> salesman_id;
    }

};

#endif 
//string toStringSql() 
//{
//    string sql;
//    sql = "INSERT INTO salesman(salesman_id, name, city, commission) VALUES('" + to_string(this->id) + "','" + this->name + "', 'Da Nang', 1);";
//    return sql;
//}
//void inputData() 
//{
//    cout << "Enter id of saleman" << endl;
//    cin >> this->id;
//    cin.ignore(256, '\n');
//    cout << "Enter name of saleman" << endl;
//    getline(cin, this->name);
//}
