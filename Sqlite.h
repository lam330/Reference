#pragma once
#ifndef      __Sqlite_H__
#define      __Sqlite_H__
#include"Struct_tables.h"
#include<sqlite3.h>
#include<iomanip>

static int Callback(void* NotUsed, int argc, char** argv, char** azColName)
{
    static int j=0;
  
    if (j == 0)
    {
        for (int i = 0; i < argc; i++)
        {
            cout << setw(20) << azColName[i];
        }
        j++;
    }
 
    cout << endl;

    for (int i = 0; i < argc; i++)
    {
        cout << setw(20)<<argv[i];
    }
    
    printf("\n");
    return 0;
}

class Sqlite3 
{
private:
    sqlite3* db;
    char* zErrMsg;
    int rc;
    string sql;
    string announClosed;
    const char* data = "Callback function called";
public:
    Sqlite3(const string& ipFile)//tao file database
    {
        rc = sqlite3_open(ipFile.c_str(), &db);

        if (rc)
        {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        }
        else
        {
            cout << ipFile << ": ";
            fprintf(stdout, "Opened database successfully\n");
        }
    }
    ~Sqlite3()//no para for destructor
    {
        if (zErrMsg != nullptr)
        {
            cout << "err" << endl;
            delete zErrMsg;
            zErrMsg = nullptr;
        }
        sqlite3_close(db);
        cout << endl;
        cout << announClosed << " is closed" << endl;
    }

    void SetAnnounClosed(const string& ipFile)
    {
        announClosed = ipFile;
    }

    //method
    void CreateTable()
    {
        cout << endl;
        sql = "CREATE TABLE Salesman("  \
            "SALESMAN_ID    NUMERIC(5)        NOT NULL    PRIMARY KEY," \
            "NAME           VARCHAR(30)       NOT NULL," \
            "CITY           VARCHAR(15)       NOT NULL," \
            "COMMISSION     DECIMAL(5,2)      NOT NULL);";

        rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else
        {
            fprintf(stdout, "Salemans Table created successfully\n");
        }


        sql = "CREATE TABLE Customers("  \
            "CUSTOMER_ID    NUMERIC(5)          NOT NULL    PRIMARY KEY," \
            "CUST_NAME      VARCHAR(30)         NOT NULL," \
            "CITY       	  VARCHAR(15)       NOT NULL," \
            "GRADE    	  NUMERIC(3)            NOT NULL," \
            "SALESMAN_ID    NUMERIC(5)          NOT NULL," \
            "FOREIGN KEY(SALESMAN_ID) REFERENCES Salesman(SALESMAN_ID) );";


        rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Customers Table created successfully\n");
        }

        
        sql = "CREATE TABLE Orders("  \
            "ORD_NO         NUMERIC(5)      NOT NULL    PRIMARY KEY," \
            "PURCH_AMT      DECIMAL(8,2)    NOT NULL," \
            "ORD_DATE       DATE            NOT NULL," \
            "CUSTOMER_ID    NUMERIC(5)      NOT NULL," \
            "SALESMAN_ID    NUMERIC(5)      NOT NULL,"\

            "FOREIGN KEY(CUSTOMER_ID) REFERENCES Customers(CUSTOMER_ID),"\
            "FOREIGN KEY(SALESMAN_ID) REFERENCES Salesman(SALESMAN_ID) );";

        rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
        else {
            fprintf(stdout, "Orders Table created successfully\n");
        }

    }
    void InsertSalesman(int& ipID, const string& ipName, const string& ipCity, int& ipCommission);
    void InsertCustomer(int& ipID, const string& ipName, const string& ipCity, int& ipGrade, int& ipSalesmanID);
    void InsertOrder(int& ipOrd_No, int& ipPurch_amt, const string& ipOrd_date, int& ipCustomer_ID, int& ipSalesman_ID);

    void Select(const string& ipCol, const int& ipTable, const string& ipCondition);
    //void Update();
    void Delete(const int& ipTable, const string& ipCondition);
    void Sort(const int& ipTable, const string& ipCols, const int& ipOrder);
    void BackUp( const string& ipPath);

    void ShowTables()
    {
        cout << "List of table: "<<endl;
        cout << "1. Salesman" << endl;
        cout << "2. Customers" << endl;
        cout << "3. Orders" << endl;
    }

    void ShowOrder()
    {
        cout << "1. ASCENDING" << endl;
        cout << "2. DESCENDING" << endl;
    }
    
 
};

#endif 