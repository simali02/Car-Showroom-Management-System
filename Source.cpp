#include<iostream>
#include<iomanip>
#include<string>
#include<conio.h>
#include <fstream>
#include <limits>
#include <time.h>
using namespace std;
struct Employee
{
	int EmpID;
	string EmpName;
	string EmpAddress;
	int Emp_phoneNumber;
	int CNIC;
	string EmpPosition;
	int Salary;
	Employee* next, * prev;
}
*empHead = NULL, * empTail = NULL;
struct CAR
{
	int car_id;
	string CARname;
	string status;
	int price;
	int cc;
	string car_company;
	CAR* next;
	CAR* prev;
}*head = NULL, * tail = NULL;
void main_portal();
void admin_portal();
void car_details_for_admin();
void employee_function();
void employee_login();
void admin_login();
void employee_portal();
void sell_a_car_emp();
void search_for_car_details_emp();
int const maintain = 100;
void size();
void Delete_Car(int);
void Insert_Car(int car_id, string
	car_company, string CARname, string s,
	int price, int cc);
bool Search_For_Car(int car_id);
void Display_Car();
void Write_Car();
void Read_Car();
void Sold_Car_Search();
void Update_About_Car(int car_id);
void car_maintenance();
void sold_car_bill(int car_id);
void add_Employee(int ID, string Name,
	string Address, int PhoneNum, int CNIC,
	string pos, int salary);
void delete_Employee(int ID);
bool search_Employee(int ID);
int TotalEmployee();
void updateEmployee(int ID);
void Read_emp();
void Write_emp();
bool carstatus(string);
bool carname(string);
bool carcompany(string);
bool carcc(int);
bool carprice(int);
void Display_Employees();
string Password();
int main()
{
	system("COLOR D");
	Read_Car();
	Read_emp();
	main_portal();
	return 0;
}
void main_portal()
{
	int choice;
A:
	cout << "==================================================================================================================";
	cout << "\t\t\t\t\t\t\t CAR SHOWROOM MANAGEMENT SYSTEM" << endl;
	cout << "==================================================================================================================\n\n";
	cout << "\n\t\t\t\t\t\t1. Admin Login " << endl;
	cout << "\n\t\t\t\t\t\t2. Employee Login " << endl;
	cout << "\n\t\t\t\t\t\t3. Exit " << endl;
	cout << "\n\n******************************************************************************************************************" << endl;
	cout << "\t\t\t\t\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		admin_login();
		break;
	case 2:
		system("cls");
		employee_login();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "\t\t\t\t\tWRONG CHOICE!" << endl;
	}
	system("pause");
	system("cls");
	goto A;
}
/*
PORTALS
*/
void admin_portal()
{
	int choice;
B:
	system("cls");
	cout << "==================================================================================================================";
	cout << "\t\t\t\t\t\t\t\t ADMIN PORTAL" << endl;
	cout << "==================================================================================================================";
	cout << "\n\n\n";
	cout << "\t\t\t\t\t1. Employee Function " << endl;
	cout << "\n\t\t\t\t\t2. Car Function " << endl;
	cout << "\n\t\t\t\t\t3. Logout " << endl;
	cout << "\n\n************************************************************************************************************************" << endl;
	cout << "\n\t\t\t\t\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		employee_function();
		break;
	case 2:
		system("cls");
		car_details_for_admin();
		break;
	case 3:
		system("cls");
		main_portal();
		break;
	default:
		cout << "Wrong Choice!" <<
			endl;
	}
	system("pause");
	system("cls");
	goto B;
}
void employee_function()
{
	int ID, empPhone, empCNIC,
		empSalary;
	string empName, empAddress, empPos;
	int choice;
A:
	system("cls");
	cout << "==================================================================================================================";
	cout << "\t\t\t\t\t\t EMPLOYEE FUNCTION FOR ADMIN" << endl;
	cout << "==================================================================================================================\n\n";
	cout << "\n\t\t\t\t\t1. Add	Employee " << endl;
	cout << "\n\t\t\t\t\t2. Delete Employee " << endl;
	cout << "\n\t\t\t\t\t3. Update About Employee " << endl;
	cout << "\n\t\t\t\t\t4. Search For Employee " << endl;
	cout << "\n\t\t\t\t\t5. Display All Employees Detail " << endl;
	cout << "\n\t\t\t\t\t6. Total Employees Working" << endl;
	cout << "\n\t\t\t\t\t7. Back " << endl;
	cout << "\n\n************************************************************************************************************************" << endl;
	cout << "\n\t\t\t\t\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "==================================================================================================================";
		cout << "\t\t\t\t\t\tADD EMPLOYEE" << endl;
		cout << "==================================================================================================================\n\n";
		if (empHead == NULL &&
			empTail == NULL)
		{
			ID = 1;
		}
		else {
			ID = empTail->EmpID;
			ID++;
		}
		cout << "\t\tEmployee ID: "
			<< ID << endl;
		cout << "\t\tNAME: ";
		cin.ignore();
		getline(cin, empName);
		cout << "\t\tADDRESS: ";
		cin.ignore();
		getline(cin, empAddress);
		cout << "\t\tPHONE: ";
		cin >> empPhone;
		while (1) { //For Validation
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximumnumber of characters to ignore
				cout << "\t\tInvalid Entry!" << endl;
				cout << "\t\tPHONE: "; cin >> empPhone;
			}
			if (!cin.fail())
				break;
		}
		cout << "\t\tCNIC: ";
		cin >> empCNIC;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\tInvalid Entry" << endl;
				cout << "\t\tCNIC: "; cin >> empCNIC;
			}
			if (!cin.fail())
				break;
		}
		cout << "\t\tPosition in the company: ";
		cin.ignore();
		getline(cin, empPos);
		cout << "\t\tSalary: $";
		cin >> empSalary;
		while (1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\tInvalid Entry" << endl;
				cout << "\t\tSalary: $"; cin >> empSalary;
			}
			if (!cin.fail())
				break;
		}
		add_Employee(ID, empName,
			empAddress, empPhone, empCNIC, empPos,
			empSalary);
		Write_emp();
		break;
	case 2:
		system("cls");
		cout << "==================================================================================================================";
		cout << "\t\t\t\t\t\tDELETE EMPLOYEE" << endl;
		cout << "==================================================================================================================\n\n";
		cout << "\t\t\t\t\tENTER EMPLOYEE ID TO DELETE : ";
		cin >> ID;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tENTER EMPLOYEE ID TO DELETE:";
				cin >> ID;
				delete_Employee(ID);
			}
			if (!cin.fail())
				break;
		}
		delete_Employee(ID);
		Write_emp();
		break;
	case 3:
		system("cls");
		cout << "==================================================================================================================";
		cout << "\t\t\t\t\t\tUPDATE EMPLOYEE" << endl;
		cout << "==================================================================================================================\n\n";
		cout << "\t\t\t\t\tENTER EMPLOYEE ID TO UPDATE : ";
		cin >> ID;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximumnumber of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tENTER EMPLOYEE ID TO UPDATE:";
				cin >> ID;
			}
			if (!cin.fail())
				break;
		}
		updateEmployee(ID);
		Write_emp();
		break;
	case 4:
		system("cls");
		cout << "==================================================================================================================";
		cout << "\t\t\t\t\t\tSEARCH EMPLOYEE" << endl;
		cout << "==================================================================================================================\n\n";
		Read_emp();
		cout << "\t\t\t\t\tENTER EMPLOYEE ID TO SEARCH : \n";
		cin >> ID;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tID: "; cin >> ID;
			}
			if (!cin.fail())
				break;
		}
		search_Employee(ID);
		break;
	case 5:
		system("cls");
		cout << "================================================================================================================== ";
		cout << "\t\t\t\t\t\tDISPLAY EMPLOYEE" << endl;
		cout << "================================================================================================================== \n\n";
		Display_Employees();
		break;
	case 6:
		cout << "\t\t\t\t\tTotal Employees are : " << TotalEmployee() << endl;
		break;
	case 7:
		system("cls");
		main_portal();
		break;
	default:
		cout << "\t\t\t\t\tWrong Choice!\n";
	}
	system("pause");
	system("cls");
	goto A;
}
string Password() {
	string pass;
	char a;
	for (int i = 0;;)
	{
		a = _getch(); //to take input from user
		if ((a >= 'a' && a <= 'z') ||
			(a >= 'A' && a <= 'Z') || (a >= '0' && a <=
				'9'))
		{
			pass += a; ++i; cout
				<< "*";
		}
		else if (a == '\b' && i >= 1)
			// "\b" use to bakspace
		{
			cout << "\b \b"; --i;
		}
		else if (a == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}
	return pass;
}
void admin_login()
{
	string username, pass;
	cout << "==================================================================================================================";
	cout << "\t\t\t\t\t\t\t\t ADMIN	LOGIN" << endl;
	cout << "==================================================================================================================\n\n";
	cout << "\n\t\t\t\t\tUSERNAME: ";
	cin >> username;
	if (username == "simrah" || username
		== "SIMRAH" || username == "kainat" ||
		username == "KAINAT" || username ==
		"ayesha" || username == "AYESHA")
	{
		cout << "\n";
	pass:
		cout << "\t\t\t\t\tPASSWORD:";
		pass = Password();
		if (pass == "4545") {
			_getch();
			cout <<
				"\n\t\t\t\t\tLogin Successful" << endl;
			system("pause");
			system("cls");
			admin_portal();
		}
		else {
			cout <<
				"\n\t\t\t\t\tWRONG PASSWORD!!!!!!!" <<
				endl;
			pass.clear();
			goto pass;
		}
	}
	else
	{
		cout << "\n\t\t\t\t\tWRONG USERNAME!!!" << endl;
		system("pause");
		system("cls");
		admin_login();
	}
}
bool carname(string carname)
{
	bool flag = true;
	for (int i = 0; i <
		carname.length(); i++)
	{
		char a = carname[i];
		if ((a >= 65 && a >= 90) ||
			(a >= 97 && a >= 122))
		{
		}
		else
		{
			cout << "\t\t\t\t\tERROR IN CAR NAME INPUT!!!!\n";
			flag = false;
			break;
		}
	}
	return flag;
}
bool carcompany(string carcompany)
{
	bool flag = true;
	for (int i = 0; i <
		carcompany.length(); i++)
	{
		char a = carcompany[i];
		if ((a >= 65 && a >= 90) ||
			(a >= 97 && a >= 122))
		{
		}
		else
		{
			cout << "\t\t\t\t\tERROR IN CAR COMPANY INPUT!!!!\n";
			flag = false;
			break;
		}
	}
	return flag;
}
bool carstatus(string status)
{
	bool flag = true;
	if (status == "NOT" || status ==
		"not" || status == "SOLD" || status ==
		"sold")
	{
	}
	else
	{
		cout << "\t\t\t\t\tERROR IN STATUS INPUT!!!!\n";
		flag = false;
	}
	return flag;
}
bool carcc(int cc)
{
	bool flag = true;
	if (cc == 800 || cc == 1000 || cc
		== 1200 || cc == 1800 || cc == 2500)
	{
	}
	else
	{
		cout << "\t\t\t\t\tERROR INCC INPUT!!!!\n";
		flag = false;
	}
	return flag;
}
bool carprice(int price)
{
	bool flag = true;
	if (price >= 500000 || price == 0
		|| price < 5000000)
	{
	}
	else
	{
		cout << "\t\t\t\t\tERROR INCC INPUT!!!!\n";
		flag = false;
	}
	return flag;
}
void car_details_for_admin()
{
	int car_id;
	int choice;
	string CARname;
	string status;
	int price = 0;
	int cc = 0;
	string car;
	string car_company;
	system("cls");
	cout << "==================================================================================================================";
	cout << "\t\t\t\t\t\t CAR FUNCTION FOR ADMIN" << endl;
	cout << "==================================================================================================================\n\n";
	cout << "\n\t\t\t\t\t1. Add Car " << endl;
	cout << "\n\t\t\t\t\t2. Delete Car" << endl;
	cout << "\n\t\t\t\t\t3. Update About Car " << endl;
	cout << "\n\t\t\t\t\t4. Search For Car Details " << endl;
	cout << "\n\t\t\t\t\t5. Search For Sold Cars Detail " << endl;
	cout << "\n\t\t\t\t\t6. Display All Cars Detail " << endl;
	cout << "\n\t\t\t\t\t7. Total Cars" << endl;
	cout << "\n\t\t\t\t\t8. Display Reciepts for Car Maintenance" << endl;
	cout << "\n\t\t\t\t\t9. Back " << endl;
	cout << "\n\n**********************************************************************************************************************" << endl;
	cout << "\n\t\t\t\t\tEnter Your Choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "==================================================================================================================";
		cout << "\t\t\t\t\t\tADD CAR" << endl;
		cout << "==================================================================================================================\n\n";
		if (head == NULL && tail ==
			NULL) {
			car_id = 111;
		}
		else {
			car_id = tail->car_id;
			car_id++;
		}
		cout << "\t\t\t\t\tCAR ID:";
		cout << car_id << endl;
	START:
		cout << "\t\t\t\t\tEnter CAR COMPANY : ";
			cin >> car_company;
		if
			(!carcompany(car_company))
		{
			goto START;
		}
	START1:
		cout << "\t\t\t\t\tEnter CAR NAME : ";
		cin >> CARname;
		if (!carname(CARname))
		{
			goto START1;
		}
	START2:
		cout << "\t\t\t\t\tEnter SOLD OR NOT : ";
			cin >> status;
		if (!carstatus(status))
		{
			goto START2;
		}
	START3:
		cout << "\t\t\t\t\tEnter CC:";
		cin >> cc;
		if (!carcc(cc))
		{
			goto START3;
		}
	START4:
		cout << "\t\t\t\t\tEnter CAR PRICE : ";
			cin >> price;
		if (!carprice(price))
		{
			goto START4;
		}
		Insert_Car(car_id,
			car_company, CARname, status, price, cc);
		Write_Car();
		system("PAUSE");
		car_details_for_admin();
		break;
	case 2:
		system("cls");
		cout <<"==================================================================================================================";
		cout << "\t\t\t\t\t\tDELETE CAR" << endl;
		cout <<"==================================================================================================================\n\n";
		cout << "\t\t\t\t\tENTER CAR ID TO DELETE : \n";
		cin >> car_id;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout <<"\t\tInvalid Entry" << endl;
				cout <<"\t\t\t\t\tENTER CAR ID TO DELETE: \n";
				cin >> car_id;
			}
			if (!cin.fail())
				break;
		}
		Delete_Car(car_id);
		Write_Car();
		system("PAUSE");
		car_details_for_admin();
		break;
	case 3:
		system("cls");
		cout <<"==================================================================================================================";
		cout << "\t\t\t\t\t\tUPDATE CAR" << endl;
		cout <<"==================================================================================================================\n\n";
		cout << "\t\t\t\t\tENTER CAR ID TO UPDATE : \n";
			cin >> car_id;
		Update_About_Car(car_id);
		Write_Car();
		system("PAUSE");
		car_details_for_admin();
		break;
	case 4:
		system("cls");
		cout <<"==================================================================================================================";
		cout << "\t\t\t\t\t\tSEARCH CAR" << endl;
		cout <<"==================================================================================================================\n\n";
			Read_Car();
		cout << "\t\t\t\t\tENTER CAR ID TO SEARCH : \n";
			cin >> car_id;
		Search_For_Car(car_id);
		system("PAUSE");
		car_details_for_admin();
		break;
	case 5:
		system("cls");
		cout <<"==================================================================================================================";
		cout << "\t\t\t\t\t\tSOLD CAR" << endl;
		cout <<"==================================================================================================================\n\n";
			Read_Car();
		Sold_Car_Search();
		system("PAUSE");
		car_details_for_admin();
		break;
	case 6:
		system("cls");
		cout <<"==================================================================================================================";
		cout << "\t\t\t\t\t\tDISPLAY ALL CARS" << endl;
		cout <<"==================================================================================================================\n\n";
			Display_Car();
		system("PAUSE");
		car_details_for_admin();
		break;
	case 7:
		system("cls");
		cout <<"==================================================================================================================";
		cout << "\t\t\t\t\t\tTOTAL CARS" << endl;
		cout <<"==================================================================================================================\n\n";
			size();
		system("PAUSE");
		car_details_for_admin();
		break;
	case 8: {
		system("cls");
		string line;
		ifstream myfile("CAR MAINTENANCE.txt");
			if (myfile.is_open())
			{
				while
					(getline(myfile, line))
				{
					cout <<
						"\t\t\t\t\t" << line << '\n';
				}
				myfile.close();
			}
			else cout <<
				"\t\t\t\t\tUnable to open file"; }
		  break;
	case 9:
		system("cls");
		admin_portal();
		break;
	default:
		cout << "\t\t\t\t\tWrong Choice!";
}
}
void employee_login()
{
	string username, pass;
	cout <<"==================================================================================================================";
	cout << "\t\t\t\t\t\t\t\t EMPLOYEE LOGIN" << endl;
	cout <<"==================================================================================================================\n\n";
	cout << "\n\t\t\t\t\t USERNAME: ";
	cin >> username;
	if (username == "simrah" || username
		== "SIMRAH" || username == "kainat" ||
		username == "KAINAT" || username ==
		"ayesha" || username == "AYESHA")
	{
	pass:
		cout <<
			"\n\t\t\t\t\tPASSWORD: ";
		pass = Password();
		if (pass == "4545") {
			_getch();
			cout <<
				"\n\t\t\t\t\tLogin Successful" << endl;
			system("pause");
			system("cls");
			employee_portal();
		}
		else
		{
			system("pause");
			cout <<
				"\n\t\t\t\t\tWRONG PASSWORD!!!!!!!" <<
				endl;
			pass.clear();
			goto pass;
		}
	}
	else
	{
		cout << "n\t\t\t\t\tWRONG USERNAME!!!" << endl;
			system("pause");
		system("cls");
		employee_login();
	}
}
void employee_portal()
{
	int choice;
	system("cls");
	cout <<"==================================================================================================================";
	cout << "\t\t\t\t\t\t EMPLOYEE PORTAL" << endl;
	cout <<"==================================================================================================================\n\n";
	cout << "\t\t\t\t\t1. Sell Car " << endl;
	cout << "\t\t\t\t\t2. Search For Car Details " << endl;
	cout << "\t\t\t\t\t3. Search ForSold Cars Detail " << endl;
	cout << "\t\t\t\t\t4. Display All Cars Detail " << endl;
	cout << "\t\t\t\t\t5. Car Maintenance" << endl;
	cout << "\t\t\t\t\t6. Logout " <<endl;
	cout <<"\n\n************************************************************************************************************************" << endl;
	cout << "\t\t\t\t\tEnter Your Choice: ";
		cin >> choice;
A:
	switch (choice)
	{
	case 1:
		Read_Car();
		sell_a_car_emp();
		system("PAUSE");
		employee_portal();
		break;
	case 2:
		Read_Car();
		search_for_car_details_emp();
		system("PAUSE");
		employee_portal();
		break;
	case 3:
		Read_Car();
		Sold_Car_Search();
		system("PAUSE");
		employee_portal();
		break;
	case 4:
		Display_Car();
		system("PAUSE");
		employee_portal();
		break;
	case 5:
		system("cls");
		car_maintenance();
		system("PAUSE");
		system("cls");
		employee_portal();
		break;
	case 6:
		system("cls");
		main_portal();
		break;
	}
	system("pause");
	system("cls");
	goto A;
}
void sell_a_car_emp()
{
	CAR* temp = head;
	int car_id;
	cout << "\t\t\t\t\tEnter CAR ID to SOLD: ";
		cin >> car_id;
	if (Search_For_Car(car_id) == true)
	{
		while (temp) {
			if (temp->car_id ==
				car_id) {
				break;
			}
			else
				temp = temp -> next;
		}
		if (temp->status == "SOLD"
			|| temp->status == "sold")
		{
			cout <<"\t\t\t\t\tTHIS CAR IS ALREADY SOLDED!!!!";
		}
		else {
			cout <<"\t\t\t\t\tEnter SOLD to SOLD the CAR: ";
			cin >> temp->status;
			cout <<"\t\t\t\t\tSOLD!!!!!\n";
			Write_Car();
			sold_car_bill(car_id);
		}
	}
	else
	{
		cout << "\t\t\t\t\tCAR ID NOT FOUND!!!!!\n";
	}
}
void search_for_car_details_emp()
{
	int car_id;
	cout << "\t\t\t\t\tENTER CAR ID to SEARCH";
		cin >> car_id;
	Search_For_Car(car_id);
}
void sold_car_bill(int car_id)
{
	CAR* temp = head;
	while (temp != NULL)
	{
		if (temp->car_id == car_id)
		{
			cout <<"==================================================================================================================";
			cout << "\t\t\t\t\t\tADD CAR" << endl;
			cout <<"==================================================================================================================\n\n";
			cout <<"\t\t\t\t\tCAR ID: " << "\t \t " << temp -> car_id<<"\t\t\t\t\tCAR COMPANY: " << "\t \t " <<temp->car_company<<"\t\t\t\t\tCARname : " << "\t \t " <<temp->CARname<<"\t\t\t\t\tCC :" << "\t \t " << temp->cc<<"\t\t\t\t\tCAR PRICE :" << "\t \t " <<temp->price << "\n\t\tSOLD!!!!";
		}
	}
}
void car_maintenance()
{
	ofstream Mfile;
	Mfile.open("CAR MAINTENANCE.txt");
	char date[9];
	_strdate_s(date);
	int ch, others;
	char choice;
	string part;
	int total = 0;
	int housepipe = 0, airfilter = 0,
		clutchplate = 0, breakpads = 0,
		wiperblades = 0, boots = 0, fuelfilter =
		0, coolant = 0, belt = 0, mirror = 0,
		other = 0;
	int QuanHP, QuanAF, QuanCP = 1,
		QuanBP, QuanWB = 1, QuanGear = 1, QuanFF
		= 1, QuanEC = 1, QuanDB, QuanM, QuanOther
		= 1;
	cout <<"==================================================================================================================";
	cout << "\t\t\t\t\t\t SPARE PARTS" << endl;
	cout <<"==================================================================================================================\n\n";
	cout << "\t\t\t\t\tPARTS Price\n" << endl;
	cout << "\t\t\t\t\t1. Hose Pipes $10" << endl;
	cout << "\t\t\t\t\t2. Air Filter $5" << endl;
	cout << "\t\t\t\t\t3. Clutch Plate $20" << endl;
	cout << "\t\t\t\t\t4. Brake Pads $15" << endl;
	cout << "\t\t\t\t\t5. Wiper Blades $10" << endl;
	cout << "\t\t\t\t\t6. Steering Gearbox & Boots $60" << endl;
	cout << "\t\t\t\t\t7. Fuel Filter $5" << endl;
	cout << "\t\t\t\t\t8. Engine Coolant $20" << endl;
	cout << "\t\t\t\t\t9. Drive Belts $30" << endl;
	cout << "\t\t\t\t\t10.Mirrors $80" << endl;
	cout << "\t\t\t\t\t11.Other parts $30" << endl;
	A:
	cout << "\t\t\t\t\tChoose any one option for maintenance : ";
	cin >> ch;
	switch (ch) {
	case 1:
		cout << "\t\t\t\ttQuantity:";
		cin >> QuanHP;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tQuantity: "; cin >> QuanHP;
			}
			if (!cin.fail())
				break;
		}
		housepipe = 10 * QuanHP;
		total += housepipe;
		cout << "\t\t\t\t\tHose Pipes inserted!" << endl;
		break;
	case 2:
	C:
		cout << "\t\t\t\t\tQuantity:";
		cin >> QuanAF;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tQuantity: "; cin >> QuanAF;
			}
			if (!cin.fail())
				break;
		}
		if (QuanAF == 1 || QuanAF ==
			2) {
			airfilter = 5 *
				QuanAF;
			total += airfilter;
			cout << "\t\t\t\t\tAir Filter inserted:" << endl;
		}
		else {
			cout << "\t\t\t\t\tCar can only have Two AirFilters, please try again!" << endl;
			goto C;
		}
		break;
	case 3:
		clutchplate = 20 * QuanCP;
		total += clutchplate;
		cout << "\t\t\t\t\tClutch Plate inserted : " << endl;
		break;
	case 4:
	D:
		cout << "\t\t\t\t\tQuantity:";
		cin >> QuanBP;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tQuantity: "; cin >> QuanBP;
			}
			if (!cin.fail())
				break;
		}
		if (QuanBP > 0 || QuanBP <=
			8) {
			breakpads = 15 *
				QuanBP;
			total += breakpads;
			cout << "\t\t\t\t\tBrake Pads inserted" << endl;
		}
		else {
			cout << "\t\t\t\t\tPlease enter the correct amount, 1 - 8 brakepads per car!";
			goto D;
		}
		break;
	case 5:
		wiperblades = 10 * QuanWB;
		total += wiperblades;
		cout << "\t\t\t\t\tWiper Blades inserted" << endl;
		break;
	case 6:
		boots = 60 * QuanGear;
		total += boots;
		cout << "\t\t\t\t\tSteering Gearbox & Boots inserted" << endl;
		break;
	case 7:
		fuelfilter = 5 * QuanFF;
		total += fuelfilter;
		cout << "\t\t\t\t\tFuel Filter inserted" << endl;
		break;
	case 8:
		coolant = 20 * QuanEC;
		total += coolant;
		cout << "\t\t\t\t\tEngine Coolant inserted" << endl;
		break;
	case 9:
	E:
		cout << "\t\t\t\t\tQuantity:";
		cin >> QuanDB;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tQuantity: "; cin >> QuanDB;
			}
			if (!cin.fail())
				break;
		}
		if (QuanDB >= 1 || QuanDB <=
			4) {
			belt = 20 * QuanDB;
			total += belt;
			cout << "\t\t\t\t\tDrive Belts inserted" << endl;
		}
		else {
			cout << "\t\t\t\t\tWrong Quantity,1-4 belts per car only, please try again!";
			goto E;
		}
		break;
	case 10:
		cout << "\t\t\t\t\tQuantity:";
		cin >> QuanM;
		while (1)
		{ //For Validation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
				cout << "\t\t\t\t\tInvalid Entry!" << endl;
				cout << "\t\t\t\t\tQuantity: "; cin >> QuanM;
			}
			if (!cin.fail())
				break;
		}
		mirror = 30 * QuanM;
		total += mirror;
		cout << "\t\t\t\t\tMirrors inserted:" << endl;
		break;
	case 11:
		cout << "\t\t\t\t\tEnter part name which you wants to insert in car : ";
		cin >> part;
		cout << "\t\t\t\t\tEnter Other part price : $ ";
		cin >> others;
		other = 30 * QuanOther;
		cout << "\t\t\t\t\t" << part << " inserted" << endl;
		total += other;
		break;
	default:
		cout << "\t\t\t\t\tWrong Choice\n";
	}
	B:
		cout << "\t\t\t\tDo you want more Maintenance enter 'y' to continue 'n' to get the bill : ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		goto A;
		else if (choice == 'n' || choice == 'N') {
		system("cls");
		cout << "\t\t\t\t\tDATE: " << date << endl;
		cout << "==================================================================================================================";
		cout << "\t\t\t\t\t\tMAINTENANCE BILL" << endl;
		cout << "==================================================================================================================\n\n";
		cout << "\t\t\t\t\t\tPARTS BILL" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
		cout << " \t\t\t\t\tHose Pipes $" << housepipe <<endl;
		cout << " \t\t\t\t\tAir Filter $" << airfilter <<endl;
		cout << " \t\t\t\t\tClutch Plate $" << clutchplate << endl;
		cout << " \t\t\t\t\tBrake Pads $" << breakpads <<endl;
		cout << " \t\t\t\t\tWiper Blades $" << wiperblades <<endl;
		cout << " \t\t\t\t\tSteering Gearbox & Boots $" << boots << endl;
		cout << " \t\t\t\t\tFuel Filter $" << fuelfilter <<endl;
		cout << " \t\t\t\t\tEngine Coolant $" << coolant << endl;
		cout << " \t\t\t\t\tDrive Belt $" << belt << endl;
		cout << " \t\t\t\t\tMirrors $" << mirror << endl;
		cout << " \t\t\t\t\tOther parts $" << other << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\t\tTotal Bill $" << total <<"\n\n\n";
		}
		else {
			cout << "\t\t\t\t\tWrong Choice, please choose again!" << endl;
			goto B;
		}
		if (Mfile) {
			Mfile << "DATE: " << date <<endl;
			Mfile << "==================================================================================================================\n";
			Mfile << "\t\tBILL";
			Mfile << "\n==================================================================================================================\n";
			Mfile << " PARTS BILL" << endl;
			Mfile << "------------------------------------------" << endl;
			Mfile << " Hose Pipes $" << housepipe << endl;
			Mfile << " Air Filter $" << airfilter << endl;
			Mfile << " Clutch Plate $" << clutchplate << endl;
			Mfile << " Brake Pads $" << breakpads << endl;
			Mfile << " Wiper Blades $" << wiperblades << endl;
			Mfile << " Steering Gearbox & Boots $" << boots << endl;
			Mfile << " Fuel Filter $" << fuelfilter << endl;
			Mfile << " Engine Coolant $" << coolant << endl;
			Mfile << " Drive Belt $" << belt << endl;
			Mfile << " Mirrors $" << mirror << endl;
			Mfile << " Other parts $" << other << endl;
			Mfile << "--------------------------------------------" << endl;
			Mfile << "Total Bill $" << total << "\n\n\n";
		}
		Mfile.close();
}
void Insert_Car(int car_id, string
	car_company, string CARname, string
	status, int price, int cc) {
	CAR* obj = new CAR;
	obj->car_id = car_id;
	obj->CARname = CARname;
	obj->status = status;
	obj->price = price;
	obj->cc = cc;
	obj->car_company = car_company;
	obj->next = NULL;
	obj->prev = NULL;
	if (head == NULL && tail == NULL)
	{
		head = obj;
		tail = obj;
	}
	else {
		tail->next = obj;
		obj->prev = tail;
		tail = obj;
	}
}
void Delete_Car(int ID)
{
	if (head == NULL)
	{
		cout << "\t\t\t\t\tNO CAR FOUND!" << endl;
	}
	//Delete from Head
	else if (head->car_id == ID)
	{
		CAR* temp = head;
		head = head->next;
		head->prev = NULL;
		cout << "\t\t\t\t\tCAR ID: " << temp->car_id << "\n\t\t\t\t\tCAR COMPANY: " << temp->car_company <<"\n\t\t\t\t\tCAR NAME : " << temp -> CARname<< "\n\t\t\t\t\tSOLD OR NOT : " << temp->status <<"\n\t\t\t\t\tCAR PRICE :" << temp->price<< "\n\t\t\t\t\tCC : "<< temp->cc << "\n\t\t\t\t\tTHIS RECORDHAS BEEN DELETED!!!\n" << endl;delete temp;
	}
	//Delete from Tail
	else if (tail->car_id == ID)
	{
		CAR* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		cout << "\t\t\t\t\tCAR ID: "<< temp->car_id << "\n\t\t\t\t\tCAR COMPANY: " << temp->car_company <<"\n\t\t\t\t\tCAR NAME : " << temp -> CARname << "\n\t\t\t\t\tSOLD OR NOT : " << temp->status <<"\n\t\t\t\t\tCAR PRICE :" << temp->price<< "\n\t\t\t\t\tCC : "<< temp->cc << "\n\t\t\t\t\tTHIS RECORD HAS BEEN DELETED!!!\n" << endl;delete temp;
	}
	//Delete from Middle
	else {
		CAR* temp = head;
		CAR* temp2 = NULL;
		while (temp != tail) {
			temp2 = temp;
			if (temp->car_id == ID)
			{
				cout <<"\t\t\t\t\tID found! ";
				break;
			}
			else {
				temp = temp -> next;
			}
		}//end of while
		temp2 = temp->next;
		temp2->prev = temp->prev;
		temp->prev->next = temp2;
		cout << "\t\t\t\t\tCAR ID: "<< temp->car_id << "\n\t\t\t\t\tCAR COMPANY: " << temp->car_company <<"\n\t\t\t\t\tCAR NAME : " << temp -> CARname<< "\n\t\t\t\t\tSOLD OR NOT : " << temp->status <<"\n\t\t\t\t\tCAR PRICE : " << temp->price<< "\n\t\t\t\t\tCC : "<< temp->cc << "\n\t\t\t\t\tTHIS RECORD HAS BEEN DELETED!!!\n" << endl;
	}
}
void Write_Car()
{
	ofstream file;
	file.open("CAR.txt", ios::trunc);
	if (file.is_open())
	{
		CAR* temp = head;
		while (temp != NULL)
		{
			file << temp->car_id<< "\t";
			file << temp -> car_company << "\t";
			file << temp->CARname<< "\t";
			file << temp->status<< "\t";
			file << temp->price<< "\t";
			file << temp->cc <<"\t";
			file << "\n";
			temp = temp->next;
		}
		file.close();
		cout << "\t\t\t\tDONE WRITING IN FILE!!!!\n";
	}
	else
	{
		cout << "\t\t\t\tFILE IS NOT FOUND!!!\n";
	}
}
void Read_Car()
{
	ifstream file;
	file.open("CAR.txt");
	int car_id;
	string CARname;
	string status;
	int price;
	int cc;
	string car_company;
	bool flag = file.peek() == EOF;
	if (flag)
	{
		head = tail = NULL;
	}
	else if (file.is_open())
	{
		CAR* temp = head;
		while (file >> car_id >>
			car_company >> CARname >> status >> price
			>> cc)
		{
			Insert_Car(car_id,
				car_company, CARname, status, price, cc);
		}
	}
	else
	{
		cout << "\t\t\t\t\t\tFILE NOT FOUND!!!\n";
	}
	file.close();
}
bool Search_For_Car(int car_id)
{
	CAR* temp = head;
	while (temp != NULL)
	{
		if (temp->car_id == car_id)
		{
			cout <<"\t\t\t\t\tFOUND!!!!\n";
			cout << "\n\t\t\t\t\tCAR ID: " << temp->car_id << "\n\t\t\t\t\tCAR COMPANY: " << temp->car_company << "\n\t\t\t\t\tCAR NAME : " << temp->CARname << "\n\t\t\t\t\tSOLD OR NOT: " << temp->status << "\n\t\t\t\t\tCAR PRICE :" << temp->price << "\n\t\t\t\t\tCC :" << temp->cc << endl;
			return true;
			break;
		}
		else { temp = temp->next; }
	}
	return false;
}
void Display_Car()
{
	CAR* temp = head;
	while (temp != NULL)
	{
		cout << "\n\t\t\t\t\tCAR ID: " << temp->car_id << "\n\t\t\t\t\tCAR COMPANY : " << temp->car_company << "\n\t\t\t\t\tCAR NAME : " << temp->CARname << "\n\t\t\t\t\tSOLD OR NOT: " << temp->status << "\n\t\t\t\t\tCAR PRICE : " << temp->price << "\n\t\t\t\t\tCC : " << temp->cc << endl;
		temp = temp->next;
	}
}
void Sold_Car_Search()
{
	CAR* temp = head;
	string a = "SOLD";
	bool found = false;
	if (head == NULL)
	{
		cout << "/n\t\t\t\t\tFILE IS EMPTY";
	}
	else
	{
		while (a != temp->status &&
			temp->next != NULL)
		{
			temp = temp->next;
		}
		cout << "\t\t\t\t\tCAR ID: " << temp->car_id << "\n\t\t\t\t\tCAR COMPANY: " << temp->car_company << "\n\t\t\t\t\tCAR NAME : " << temp->CARname << "\n\t\t\t\t\tSOLD OR NOT : " << temp->status << "\n\t\t\t\t\tCAR PRICE :" << temp->price << "\n\t\t\t\t\tCC :" << temp->cc << endl;
	}
}
void Update_About_Car(int car_id)
{
	CAR* temp = head;
	if (Search_For_Car(car_id) == true)
	{
		cout << "\t\t\t\t\tENTER CAR PRICE TO UPDATE";
		cin >> temp->price;
		cout <<"\t\t\t\t\tUPDATE!!!\n";
	}
}
void size()
{
	int count = 0;
	string line;
	ifstream file("CAR.txt");
	while (getline(file, line))
		count++;
	cout << "\t\t\t\t\tTOTAL NUMBER OF CARS: " << count << endl;
}
/*
EMPLOYEE
*/
void add_Employee(int ID, string Name,
	string Address, int PhoneNum, int CNIC,
	string pos, int salary) {
	Employee* obj = new Employee;
	obj->EmpID = ID;
	obj->EmpName = Name;
	obj->EmpAddress = Address;
	obj->Emp_phoneNumber = PhoneNum;
	obj->CNIC = CNIC;
	obj->EmpPosition = pos;
	obj->Salary = salary;
	obj->prev = NULL;
	obj->next = NULL;
	if (empHead == NULL && empTail ==
		NULL) {
		empHead = obj;
		empTail = obj;
	}
	else {
		empTail->next = obj;
		obj->prev = empTail;
		empTail = obj;
	}
}
bool search_Employee(int ID) {
	if (empHead == NULL) {
		cout << "\t\t\t\t\tNo Employees in the List" << endl;
	}
	else {
		Employee* temp = empHead;
		while (temp != NULL) {
			if (temp->EmpID == ID) {
				cout <<"\t\t\t\t\tFOUND!" << endl;
				cout <<"\t\t\t\t\tEMPLOYEE DETAILS\n\t\t\t\t\tID: " << temp->EmpID<< "\n\t\t\t\t\tNAME: " << temp->EmpName<<"\n\t\t\t\t\tADDRESS: " << temp -> EmpAddress << "\n\t\t\t\t\tCNIC: " <<temp->CNIC<<"\n\t\t\t\t\tCONTACT NUMBER: " << temp -> Emp_phoneNumber <<"\n\t\t\t\t\tPosition: " << temp -> EmpPosition<<"\n\t\t\t\t\tSalary: $" << temp->Salary<< endl;
				return true;
			}
			temp = temp->next;
		}
	}
	cout << "\t\t\t\t\tEMPLOYEE NOT FOUND!" << endl;
	return false;
}
void delete_Employee(int ID)
{
	if (empHead == NULL) {
		cout << "\t\t\t\t\tNo record of Employees found!" << endl;
	}
	//Delete from Head
	else if (empHead->EmpID == ID)
	{
		Employee* temp = empHead;
		empHead = empHead->next;
		empHead->prev = NULL;
		cout << "\t\t\t\t\tEmployee ID: " << temp->EmpID <<"\n\t\t\t\t\tEmployee Name: " << temp -> EmpName<< "\n\t\t\t\t\tThisrecord has been Deleted!\n" << endl;delete temp;
	}
	//Delete from Tail
	else if (empTail->EmpID == ID)
	{
		Employee* temp = empTail;
		empTail = empTail->prev;
		empTail->next = NULL;
		cout << "\t\t\t\t\tEmployee ID: " << temp->EmpID <<"\n\t\t\t\t\tEmployee Name: " << temp -> EmpName<< "\n\t\t\t\t\tThisrecord has been Deleted!\n" << endl;delete temp;
	}
	//Delete from Middle
	else
	{
		Employee* temp = empHead;
		Employee* temp2 = NULL;
		while (temp != empTail)
		{
			temp2 = temp;
			if (temp->EmpID ==
				ID)
			{
				cout <<"\t\t\t\t\tID found! ";
				break;
			}
			else {
				temp = temp -> next;
			}
		}//end of while
		temp2 = temp->next;
		temp2->prev = temp->prev;
		temp->prev->next = temp2;
		cout << "\t\t\t\t\tEmployee ID: " << temp->EmpID <<"\n\t\t\t\t\tEmployee Name: " << temp -> EmpName << "\n\t\t\t\t\tThis record has been Deleted!\n" << endl;delete temp;
	}
	cout << "\t\t\t\t\tID NOT FOUND!"<< endl;
}
void Display_Employees()
{
	Employee* temp = empHead;
	cout <<"========================================================================================================================";
	cout << "\t\t\t\t\t\t EMPLOYEE DETAILS" << endl;
	cout <<"========================================================================================================================\n\n";
	while (temp != NULL)
		{
		cout << "\t\t\t\t\tID: " <<temp->EmpID << "\n\t\t\t\t\tNAME: " <<temp->EmpName<<"\n\t\t\t\t\tADDRESS: " << temp -> EmpAddress << "\n\t\t\t\t\tCNIC: " <<temp->CNIC<<"\n\t\t\t\t\tCONTACT NUMBER: " << temp -> Emp_phoneNumber <<"\n\t\t\t\t\tPosition: " << temp -> EmpPosition<<"\n\t\t\t\t\tSalary: $ " << temp->Salary<< endl;
		temp = temp->next;
		cout << endl;
	}
}
int TotalEmployee()
{
	int count = 0;
	string line;
	ifstream file("Employee.txt");
	while (getline(file, line))
		count++;
	return count;
}
void updateEmployee(int ID)
{
	Employee* temp = empHead; int choice;
	while (temp != NULL) {
		if (temp->EmpID == ID ==
			true)
		{
			break;
		}
		temp = temp->next;
	}
	cout << "\t\t\t\t\tWhat do you want to Update ? " << endl;
	cout << "\n\t\t\t\t\t1. Name\n";
	cout << "\t\t\t\t\t2. Address\n";
	cout << "\t\t\t\t\t3. Phone Number\n";
	cout << "\t\t\t\t\t4. CNIC\n";
	cout << "\t\t\t\t\t5. Postion\n";
	cout << "\t\t\t\t\t6. Salary\n";
	cout << "\n\t\t\t\t\tChoice is : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\t\t\t\t\tCurrent Name : " << temp->EmpName;
		cout << "\n\t\t\t\t\tNew Name : ";
		cin.ignore(); getline(cin,
			temp->EmpName);
		cout <<
			"\t\t\t\t\tUpdated!";
		break;
	case 2:
		cout << "\n\t\t\t\t\tCurrent Address : " << temp->EmpAddress;
		cout << "\n\t\t\t\t\tNew Address : ";
		cin.ignore(); getline(cin,	temp->EmpAddress);
		cout <<"\n\t\t\t\t\tUpdated!\n";
		break;
	case 3:
		cout << "\n\t\t\t\t\tCurrent Phone Number : " << temp->Emp_phoneNumber;
		cout << "\n\t\t\t\t\tNew Phone Number : ";
			while (1)
			{ //For Validation
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //sets the maximum number of characters to ignore
					cout <<"\t\t\t\t\tInvalid Entry!" << endl;
					cout <<"\t\t\t\t\tPHONE: "; cin >> temp -> Emp_phoneNumber;
				}
				if (!cin.fail())
					break;
			}
		cout <<
			"\t\t\t\t\tUpdated!";
		break;
	case 4:
		cout << "\t\t\t\t\tCurrent CNIC : " << temp->Emp_phoneNumber;
		cout << "\t\t\t\t\tNew CNIC:";
		cout << "\t\t\t\t\tCNIC: ";
		cin >> temp->CNIC;
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout <<"\t\t\t\t\tInvalid Entry" << endl;
				cout <<"\t\t\t\t\tCNIC: ";
				cin >> temp -> CNIC;
			}
			if (!cin.fail())
				break;
		}
		cout <<
			"\n\t\t\t\t\tUpdated!\n";
		break;
	case 5:
		cout << "\n\t\t\t\t\tCurrent Position : " << temp->EmpPosition;
		cout << "\n\t\t\t\t\tNew Position : ";
		cin.ignore(); getline(cin,temp->EmpPosition);
		cout <<"\n\t\t\t\t\tUpdated!\n";
		break;
	case 6:
		cout << "\t\t\t\t\tCurrent Salary : " << temp->Salary;
		cout << "\t\t\t\t\tNew Salary : ";
		cout << "\t\t\t\t\tSalary: "; cin >> temp->CNIC;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout <<"\t\t\t\t\tInvalid Entry" << endl;
					cout <<"\t\t\t\t\tSalary: ";
					cin >> temp -> Salary;
				}
				if (!cin.fail())
					break;
			}
			cout <<
				"\n\t\t\t\t\tUpdated!\n";
			break;
	case 7:
		main();
		break;
	default:
		cout << "\t\t\t\t\tWrong Choice\n";
	}
	cout << "\n\t\t\t\t\tID: " << temp -> EmpID << "\n\t\t\t\t\tNAME: " << temp -> EmpName<< "\n\t\t\t\t\tADDRESS: "<< temp->EmpAddress << "\n\t\t\t\t\tCNIC:" << temp->CNIC<< "\n\t\t\t\t\tCONTACT NUMBER: " << temp->Emp_phoneNumber <<endl;
}
void Write_emp()
{
	ofstream file;
	file.open("Employee.txt",ios::ate);
	if (file.is_open())
	{
		Employee* temp = empHead;
		while (temp != NULL)
		{
			file << temp -> EmpID<< "\t";
			file << temp -> EmpName<< "\t";
			file << temp -> EmpAddress << "\t";
			file << temp -> Emp_phoneNumber << "\t";
			file << temp -> CNIC <<"\t";
			file << temp -> EmpPosition << "\t";
			file << temp -> Salary<< "\t";
			file << "\n";
			temp = temp -> next;
		}
		file.close();
	}
	else
	{
		cout << "\tFILE IS NOT FOUND!!!\n";
	}
}
void Read_emp()
{
	ifstream file;
	file.open("Employee.txt");
	int EmpID;
	string EmpName;
	string EmpAddress;
	int Emp_phoneNumber;
	int CNIC;
	string Position;
	int Salary;
	bool flag = file.peek() == EOF;
	if (flag)
	{
		empHead = empTail = NULL;
	}
	else if (file.is_open())
	{
		Employee* temp = empHead;
		while (file >> EmpID >>
			EmpName >> EmpAddress >> Emp_phoneNumber
			>> CNIC >> Position >> Salary)
		{
			add_Employee(EmpID,
				EmpName, EmpAddress, Emp_phoneNumber,
				CNIC, Position, Salary);
		}
	}
	else
	{
		cout << "\t\t\t\t\tFILE NOT FOUND!!!\n";
	}
	file.close();
}