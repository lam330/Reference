#include"Sqlite.h"

void Sqlite3::InsertSalesman(int& ipID, const string& ipName, const string& ipCity, int& ipCommission)
{
	cout << endl;
	sql = "INSERT INTO Salesman (SALESMAN_ID, NAME, CITY, COMMISSION) "  \
		"VALUES('" + to_string(ipID) + "', '" + ipName + "', '" + ipCity + "','" + to_string(ipCommission) + "'); ";
	rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records for Salesman table inserted successfully\n");
	}
}

void Sqlite3::InsertCustomer(int& ipID, const string& ipName, const string& ipCity, int& ipGrade, int& ipSalesmanID)
{
	cout << endl;
	sql = "INSERT INTO Customers (CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID) "  \
		"VALUES('" + to_string(ipID) + "', '" + ipName + "', '" + ipCity + "','" + to_string(ipGrade) + "','" + to_string(ipSalesmanID) + "'); ";
	rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records for Customers table inserted successfully\n");
	}
}

void Sqlite3::InsertOrder(int& ipOrd_No, int& ipPurch_amt, const string& ipOrd_date, int& ipCustomer_ID, int& ipSalesman_ID)
{
	cout << endl;
	sql = "INSERT INTO Orders (ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID) "  \
		"VALUES('" + to_string(ipOrd_No) + "', '" + to_string(ipPurch_amt) + " ', '" + ipOrd_date + "','" + to_string(ipCustomer_ID) + "','" + to_string(ipSalesman_ID) + "'); ";
	rc = sqlite3_exec(db, sql.c_str(), Callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Records for Orders table inserted successfully\n");
	}
}

void Sqlite3::Select(const string& ipCols, const int& ipTable, const string& ipCondition)
{
	string table[] = { "Salesman","Customers","Orders" };
	sql = "SELECT " + ipCols + " FROM " + table[ipTable - 1];
	if (!ipCondition.empty())
	{
		sql = "SELECT " + ipCols + " FROM " + table[ipTable - 1] + " WHERE " + ipCondition;
	}
	cout << sql<<endl;
	rc = sqlite3_exec(db, sql.c_str(), Callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Operation done successfully\n");
	}
}

void Sqlite3::Delete(const int& ipTable, const string& ipCondition)//DELETE FROM Customers WHERE CustomerName='Alfreds Futterkiste';
{
	string table[] = { "Salesman","Customers","Orders" };
	sql = "DELETE FROM "  + table[ipTable - 1];

	if (!ipCondition.empty())
	{
		sql = "DELETE FROM " + table[ipTable - 1] + " WHERE " + ipCondition;
	}
	cout << sql << endl;
	rc = sqlite3_exec(db, sql.c_str(), Callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Operation done successfully\n");
	}
}

void Sqlite3::Sort(const int& ipTable, const string& ipCols, const int& ipOrder)//SELECT * FROM Customers ORDER BY Country DESC;
{
	string table[] = { "Salesman","Customers","Orders" };
	string order[] = { "ASC","DESC" };
	sql = "SELECT * FROM " + table[ipTable - 1] + " ORDER BY " + ipCols +" "+order[ipOrder-1];
	
	cout << sql << endl;
	rc = sqlite3_exec(db, sql.c_str(), Callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Operation done successfully\n");
	}
}

void Sqlite3::BackUp( const string& ipPath)//BACKUP DATABASE testDB TO DISK = 'D:\backups\testDB.bak' WITH DIFFERENTIAL;
{
	/*"INSERT INTO Customers (CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID) "  \
		"VALUES('" + to_string(ipID) + "', '" + ipName + "', '" + ipCity + "','" + to_string(ipGrade) + "','" + to_string(ipSalesmanID) + "'); ";*/

	//sql = "BACKUP DATABASE " + ipDataFile.substr(0, ipDataFile.size() - 3) +" TO DISK = " + ipPath;

	//VACUUM INTO 'E:\Navicat\SQlite Databases\myOtherDBName';

	sql = "VACUUM INTO '"  + ipPath + "\'";
	cout << sql << endl;
	rc = sqlite3_exec(db, sql.c_str(), Callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Operation done successfully\n");
	}
}