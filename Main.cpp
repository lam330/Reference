#include"Sqlite.h"
#include<Windows.h>

void Menu()
{
	cout << setw(65) << "***************** SQL MANAGEMENT APPLICATION  ******************" << endl;
	cout << setw(65) << "*                1. LIST object's infomation                   *" << endl;
	cout << setw(65) << "*                2. ADD object	to database                     *" << endl;
	cout << setw(65) << "*                3. DELETE data                                *" << endl;
	cout << setw(65) << "*                4. SORT data                                  *" << endl;
	cout << setw(65) << "*                5. BACK UP database                           *" << endl;
	cout << setw(65) << "*                6. Exit                                       *" << endl;
	cout << setw(65) << "****************************************************************" << endl;
}

bool CheckSelection(const int& ipNumber)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cerr << "LETTER is not allowed" << endl;
		return false;
	}
	return true;
}


int main()
{
	//Open file
	string dataFile;
	cout << "Enter your data file: ";
	fflush(stdin);
	getline(cin, dataFile);

	Sqlite3 data(dataFile);

	////Create 3 tables
	//data.CreateTable();

	////Insert tables
	//int numberOfElements = 0;
	//cout << "Enter number of salesman: ";
	//cin >> numberOfElements;

	////Insert Salesman
	//for (int i = 0; i < numberOfElements; i++)
	//{
	//	Salesman person;
	//	data.InsertSalesman(person.id, person.name, person.city, person.commission);
	//}
	////Insert Customers
	//cout << "Enter number of customers: ";
	//cin >> numberOfElements;
	//for (int i = 0; i < numberOfElements; i++)
	//{
	//	Customers person;
	//	data.InsertCustomer(person.id, person.name, person.city, person.grade,person.salesman_ID);
	//}
	////Insert Orders
	//cout << "Enter number of orders: ";
	//cin >> numberOfElements;
	//for (int i = 0; i < numberOfElements; i++)
	//{
	//	Orders item;
	//	data.InsertOrder(item.ord_no, item.purch_amt, item.ord_date, item.customer_id, item.salesman_id);
	//}




	Sleep(2000);
	//handle app
	int selection = 0;
	while (true)
	{
		system("cls");
		Menu();
		cout << "Enter your selection: ";
		cin >> selection;
		cin.ignore(256, '\n');
		while (!(CheckSelection(selection)))
		{
			cout << "Enter selection again: ";
			cin >> selection;
			cin.ignore(256, '\n');
		}

		switch (selection)
		{
		case 1:
		{
			system("cls");

			int table = 0;
			cout << "Which table do you want to select from ?";
			data.ShowTables();
			cin >> table;
			cin.ignore(256, '\n');

			if (table == 1)
			{
				cout << "List of Collums: SALESMAN_ID, NAME, CITY, COMMISSION" << endl;
			}
			else if (table == 2)
			{
				cout << "List of Collums: CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID" << endl;
			}
			else
			{
				cout << "List of Collums: ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID" << endl;
			}

			cout << "Which cols do you want to select (* for ALL): " << endl;
			string ipCols;
			fflush(stdin);
			getline(cin, ipCols);

			string condition;
			cout << "Enter condition: ";
			fflush(stdin);
			getline(cin, condition);

			data.Select(ipCols, table, condition);
			Sleep(5000);
			break;
		}
		case 2:
		{
			system("cls");
			data.ShowTables();
			cout << "Which table do u want to insert into: "<<endl;
			int table;
			cin >> table;
			if (table == 1)
			{
				Salesman person;
				data.InsertSalesman(person.id, person.name, person.city, person.commission);
			}
			else if (table == 2)
			{
				Customers person;
				data.InsertCustomer(person.id, person.name, person.city, person.grade, person.salesman_ID);
			}
			else
			{
				Orders item;
				data.InsertOrder(item.ord_no, item.purch_amt, item.ord_date, item.customer_id, item.salesman_id);
			}
			Sleep(3000);
			break;
		}
		case 3:
		{
			system("cls");
			int table = 0;
			cout << "Which table do you want to delete from ?";
			data.ShowTables();
			cin >> table;
			cin.ignore(256, '\n');

			if (table == 1)
			{
				cout << "List of Collums: SALESMAN_ID, NAME, CITY, COMMISSION" << endl;
			}
			else if (table == 2)
			{
				cout << "List of Collums: CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID" << endl;
			}
			else
			{
				cout << "List of Collums: ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID" << endl;
			}

			string ipCondition;
			cout << "Enter condition: ";
			fflush(stdin);
			getline(cin, ipCondition);
			data.Delete(table, ipCondition);
			Sleep(3000);
			break;
		}
		case 4:
		{
			system("cls");
			int table = 0;
			
			data.ShowTables();
			cout << "Which table do u want to select from: ";
			cin >> table;
			cin.ignore(256, '\n');

			if (table == 1)
			{
				cout << "List of Collums: SALESMAN_ID, NAME, CITY, COMMISSION" << endl;
			}
			else if (table == 2)
			{
				cout << "List of Collums: CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID" << endl;
			}
			else
			{
				cout << "List of Collums: ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID" << endl;
			}

			cout << "Enter col u want to sort: ";
			string ipCol;
			fflush(stdin);
			getline(cin, ipCol);

			cout << "Which order?" << endl;
			data.ShowOrder();
			int ipOrder = 0;

			cin >> ipOrder;
			cin.ignore(256, '\n');

			data.Sort(table, ipCol, ipOrder);
			Sleep(5000);
			break;
		}
		case 5:
		{
			string ipPath;
			cout << "Enter your path u want to back up database: ";
			fflush(stdin);
			getline(cin, ipPath);// "E:\backupFiles"
			data.BackUp(ipPath);//C:\Users\ADMIN\Desktop\SQLite\backupFiles
			Sleep(5000);
			break;
		}
		case 6:
		{
			cout << "Leaving.............";
			Sleep(2000);
			system("cls");
			data.SetAnnounClosed(dataFile);
			return 0;
			break;
		}

		default:
		{
			cout << "Retry! Range of selection [1;5]";
			Sleep(2000);
			break;
		}

		}

	}

	/*int table = 0;
	cout << "Which table do you want to select from ?";
	data.ShowTables();
	cin >> table;
	cin.ignore(256, '\n');



	if (table == 1)
	{
		cout << "List of Collums: SALESMAN_ID, NAME, CITY, COMMISSION"<<endl;
	}
	else if (table == 2)
	{
		cout << "List of Collums: CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID"<<endl;
	}
	else
	{
		cout << "List of Collums: ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID"<<endl;
	}

	cout << "Which cols do you want to select (* for ALL): " << endl;
	string ipCols;
	fflush(stdin);
	getline(cin, ipCols);

	string condition;
	cout << "Enter condition: ";
	fflush(stdin);
	getline(cin, condition);

	data.Select(ipCols, table, condition);*/



	//delete
	/*int table = 0;
	cout << "Which table do you want to delete from ?";
	data.ShowTables();
	cin >> table;
	cin.ignore(256, '\n');

	if (table == 1)
	{
		cout << "List of Collums: SALESMAN_ID, NAME, CITY, COMMISSION" << endl;
	}
	else if (table == 2)
	{
		cout << "List of Collums: CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID" << endl;
	}
	else
	{
		cout << "List of Collums: ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID" << endl;
	}

	string ipCondition;
	cout << "Enter condition: ";
	fflush(stdin);
	getline(cin, ipCondition);
	data.Delete(table, ipCondition);*/

	//Sorting
	/*int table = 0;
	cout << "Which table do u want to select from: ";
	data.ShowTables();
	cin >> table;
	cin.ignore(256, '\n');

	if (table == 1)
	{
		cout << "List of Collums: SALESMAN_ID, NAME, CITY, COMMISSION" << endl;
	}
	else if (table == 2)
	{
		cout << "List of Collums: CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID" << endl;
	}
	else
	{
		cout << "List of Collums: ORD_NO, PURCH_AMT, ORD_DATE, CUSTOMER_ID, SALESMAN_ID" << endl;
	}

	cout << "Enter col u want to sort: ";
	string ipCol;
	fflush(stdin);
	getline(cin, ipCol);

	cout << "Which order?" << endl;
	data.ShowOrder();
	int ipOrder = 0;

	cin >> ipOrder;
	cin.ignore(256, '\n');

	data.Sort(table, ipCol, ipOrder);*/
}