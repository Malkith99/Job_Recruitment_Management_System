#include<iostream>
#include<string.h>
#include<vector>
#include<fstream> // use for file handling
#include<sstream>
#include<filesystem>
#include "Developer.h"
#include "User.h"
using namespace std;

void registration() {

	int input1;
	cout << "----------------------Welcome to the Job Recruitment System----------------------" << endl << endl;
	cout << "		# If you want to post a job       => Press 0 " << endl;
	cout << "		# If you want to apply for a job  => Press 1" << endl;
	cout << "\nYour Preference :";
	cin >> input1;

	if (input1 == 0) {
		int input2;
		cout << "     # Are you going to post a job?	                => Press 0 " << endl;
		cout << "     # Are you want to update or view your profile	    => Press 1" << endl;
		cout << "\nYour Preference :";
		cin >> input2;
		if (input2 == 0) {
			inputCompanyDetails();
		}
		else if (input2 == 1) {
			int input3, input4;
			displayCompanyDetails();
			cout << "Enter your Company Index : ";
			cin >> input3;
			userQueue.searchCompany(input3);
			cout << "If you want to update your details  =>Press 0 if it is not =>Press 1" << endl;
			cin >> input4;
			if (input4 == 0) {
				update(input3);
			}
		}
		else {
			cout << "Your input is wrong!!! Try again.\n" << endl;
		}
	}
	else if (input1 == 1)
	{
		login();
	}
	else {
		cout << "Your input is wrong!!! Try again.\n" << endl;
	}
}
int main() {

	addCompany("Dialog", 100, 1);
	addCompany("SLT", 103, 2);
	/*addCompany("MAS", 100, 3);
	addCompany("Toyota", 101, 5);
	addCompany("Nissan", 104, 1);
	sortJobs();
	*/

	cout << "----------------------Welcome to the Job Recruitment System----------------------" << endl << endl << endl;
	cout << " - _ - _ - Adding Company Data for the System - _ - _ - " << endl << endl;
	cout << "#Adding 3 Companies to HashTable for test trial" << endl;
	inputCompanyDetails();
	displayCompanyDetails();
	sortJobs();
	displayAvailableJobs();
	int com;
	cout << endl << endl << " - _ - _ - Adding User Data for the System - _ - _ - " << endl << endl;
	cout << endl << endl << "#Adding 2 Users to Queue for test trial" << endl;
	for (int i = 0; i < 2; i++) {
		login();
	}
	displayCompanyDetails();
	cout << "Insert a Comapany Index to check the applicants : ";
	int index;
	cin >> index;
	userQueue.searchCompany(index);
	cout << "Display the all Applicants" << endl;
	userQueue.printAllAplicants();
	cout << endl;
	int input5;
	cout << "If you want to update a Company Detail press=>0 or if you want try any kind of Registraiton press=>1  or to quit press=>2" << endl;
	cin >> input5;
	if (input5 == 0) {
		cout << "For any kind of Registration" << endl;
		registration();
	}
	else if (input5 == 1) {
		int input6;
		displayCompanyDetails;
		cout << "Enter the Company Index : ";
		cin >> input6;
		update(input6);
		cout << "----Updated Comapany Details---" << endl;
		displayCompanyDetails();
	}
	else if (input5 == 2) {
		cout << "-----------------Thank you!!! for visiting us------------------" << endl;
		return 0;
	}


	return 0;
}
