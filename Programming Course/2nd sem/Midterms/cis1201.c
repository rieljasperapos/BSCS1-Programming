#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {false, true} Boolean;
typedef char String[30];

typedef struct {
	int hour;
	int minute;
	Boolean meridian;				// true => AM; false => PM
} MyTime, *MyTimePtr;

typedef struct {
	MyTime in;
	MyTime out;
} Attendance, *AttendancePtr;

typedef struct {
	String firstname;
	String middlename;
	String lastname;
} Name, *NamePtr;

typedef struct {
	int houseNumber;
	String barangay;
	String city;
	int zip;
} Address, *AddressPtr;

typedef struct {
	int empID;
	Name empName;
	Address empHomeAddress;
	Attendance empDTR[5];			// contains each attendance from Monday to Friday
} Employee, *EmployeePtr;

MyTime time24(int hour, int minute, Boolean meridian);
MyTime newTime(int hour, int minute, Boolean meridian);
Attendance newAttendance(MyTime in, MyTime out);
Name newName(String firstname, String middlename, String lastname);
Address newAddress(int houseNumber, String barangay, String city, int zip);
Employee newEmployee(int empID, Name empName, Address empAddress, Attendance attMon, Attendance attTue, Attendance attWed, Attendance attThu, Attendance attFri);
EmployeePtr populateEmployeeList();
void displayTime24(MyTime t);
void displayTime12(MyTime t);
void displayAddress(Address a);
void displayName(Name n);
void displayEmployees(EmployeePtr list);

/**
 *	Create your own prototypes here for the other features needed.
 *
 *  For No.2 -> For convert time. Allows to convert a given time from
 *		12-hour format and returns the 24-hour format (12:00 AM is equal to
 *		00:00 and 12:00 PM is equal to 12:00. Use the hour numbers from
 *		0-23 for 24-hour format).
 *	
 *	For No.3 -> Create a function that will display the information 
 *		of a single employee based on the output format provided including 
 *		the daily attendance from Monday to Friday. (Single employee only)
 *
 *	For No.4 -> Create a function that will get the late employees in the 
 *		list/collection in the morning of a specified week day.
 *		Ex: Late employees on a Monday morning.
 *  
 *	Write all the function definition in the "cis1201.c".
 */

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	printf("[1.0 ] Empoyee List (ID & Name): \n\n");
	// start of no.1
	// make the code below work by updating the populateEmployeeList() in cis1201.c
	EmployeePtr employees = populateEmployeeList();
	displayEmployees(employees);
	// end of no.1
	
	printf("\n\n\n");
	system("pause");
	system("cls");
	
	printf("[2.0 ] Convert 12-hour time format to 24-hour time format:\n");
	// start of no.2
	/* make your declaration and function calls here for no.2
	 * utilize the newly created function and usable functions in cis1201 files
	 */
    MyTime time = time24(time.hour, time.minute, time.meridian);
    displayTime24(time);



	//end of no.2
	
	printf("\n\n\n");
	system("pause");
	system("cls");
	
	printf("[3.0 ] Employee Information (DISPLAY):\n\n");
	// start of no.3
	/* using the employee list in no.1 display all there information
	 * utilizing the display employee info (single employee) function
	 * create necessary decleration here for no.3
	 */
    for (int i = 0; i < 6; i++) {

    }

	
	
	
	
	// 	end of no.3
	
	printf("\n\n\n");
	system("pause");
	system("cls");
	
	printf("[4.0 ] Employees that are late on a specified day in the morning(DISPLAY NAMES):\n\n");
	// start of no.4
	// display all the late employees and make you necessary declaration here
	
	
	

	//end of no.4
	
	printf("\n\n\n");
	system("pause");
	return 0;
}

MyTime newTime(int hour, int minute, Boolean meridian) {
	MyTime t;
	
	t.hour = hour;
	t.minute = minute;
	t.meridian = meridian;
	
	return t;	
}

Attendance newAttendance(MyTime in, MyTime out) {
	Attendance a;
	
	a.in = in;
	a.out = out;
	
	return a;	
}

Name newName(String firstname, String middlename, String lastname) {
	Name n;
	
	strcpy(n.firstname, firstname);
	strcpy(n.middlename, middlename);
	strcpy(n.lastname, lastname);
	
	return n;	
}

Address newAddress(int houseNumber, String barangay, String city, int zip) {
	Address a;
	
	a.houseNumber = houseNumber;
	strcpy(a.barangay, barangay);
	strcpy(a.city, city);
	a.zip = zip;
	
	return a;	
}

Employee newEmployee(int empID, Name empName, Address empAddress, Attendance attMon, Attendance attTue, Attendance attWed, Attendance attThu, Attendance attFri) {
	Employee e;
	
	e.empID = empID;
	e.empName = empName;
	e.empHomeAddress = empAddress;
	e.empDTR[0] = attMon;
	e.empDTR[1] = attTue;
	e.empDTR[2] = attWed;
	e.empDTR[3] = attThu;
	e.empDTR[4] = attFri;
	
	return e;
}

EmployeePtr populateEmployeeList() {
	// create your declaration for the list of employees here...
	EmployeePtr list;
    list = malloc(sizeof(Employee));
	
	
	list[0] = newEmployee(1000, newName("Khent", "Yu", "dela Paz"), newAddress(12, "Talamban", "Cebu", 6000), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)));	
	list[1] = newEmployee(1001, newName("Christian", "Felix", "Maderazo"), newAddress(17, "Talamban", "Cebu", 6000), newAttendance(newTime(7, 45, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 15, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(4, 30, false)), newAttendance(newTime(8, 0, true), newTime(5, 10, false)));
	list[2] = newEmployee(1002, newName("Peter", "Fuerzas", "Fillo"), newAddress(20, "Talamban", "Cebu", 6000), newAttendance(newTime(8, 0, true), newTime(4, 0, false)), newAttendance(newTime(12, 30, false), newTime(5, 0, false)), newAttendance(newTime(8, 20, true), newTime(5, 0, false)), newAttendance(newTime(8, 5, true), newTime(5, 0, false)), newAttendance(newTime(9, 0, true), newTime(5, 0, false)));
	list[3] = newEmployee(1003, newName("Christine", "Arellano", "Pena"), newAddress(15, "Basak", "Mandaue", 6032), newAttendance(newTime(7, 0, true), newTime(7, 15, false)), newAttendance(newTime(7, 45, true), newTime(8, 0, false)), newAttendance(newTime(7, 50, true), newTime(9, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 15, false)), newAttendance(newTime(8, 0, true), newTime(5, 45, false)));
	list[4] = newEmployee(1004, newName("Patrick Troy", "Ceniza", "Elalto"), newAddress(12, "Yati", "Mandaue", 6032), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)), newAttendance(newTime(8, 0, true), newTime(5, 0, false)));
	list[5] = newEmployee(0, newName("", "", ""), newAddress(0, "", "", 0), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)), newAttendance(newTime(12, 0, true), newTime(12, 0, true)));
	
	// create a return statement for the list of employees here...
	return list;
	
}

MyTime time24(int hour, int minute, Boolean meridian) {
    MyTime time;

    if (time.meridian == false) {
        hour + 12;
    }
    time.hour = hour;
    time.minute = minute;

    return time;
}

void displayTime24(MyTime t) {
	printf("%02d:%02d", t.hour, t.minute);
}

void displayTime12(MyTime t) {
	if(t.meridian == true) {
		printf("%02d:%02d AM", t.hour, t.minute);
	} else {
		printf("%02d:%02d PM", t.hour, t.minute);
	}	
}

void displayAddress(Address a) {
	printf("%d Brgy. %s, %s City, %d", a.houseNumber, a.barangay, a.city, a.zip);
}

void displayName(Name n) {
	printf("%s, %s", n.lastname, n.firstname);
	if(strcmp(n.middlename,"") != 0) {
		printf(" %c.", n.middlename[0]);
	}
}

void displayEmployees(EmployeePtr list) {
	int i = 0;
	printf("%10s | %s\n", "ID", "NAME");
	
	while(list[i].empID != 0) {
		printf("%10d | ", list[i].empID);
		displayName(list[i].empName);
		printf("\n");
		i++;
	}
}

//Add your function definitions for the prototypes created in cis1201.h
