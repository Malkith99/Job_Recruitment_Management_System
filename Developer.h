#pragma once
#include<iostream>
#include<istream>
#include<string.h>
#include<vector>
#include<fstream> // use for file handling
#include<sstream>
#include<cstdio>
using namespace std;

void addCompany(string, int, int);
int hashFunction(string);
void displayCompanyDetails();
void displayJobDetails();
bool findduplicates(int);
void writeToCompany(string);
const int  N = 10;                // Size of ComPany HashArray;
int k = 0;                      // variable that used to detect the Job Titles
struct Company* HashArray[N];   // Initializing of the Hash Array        // # USING OF HASHTABLE DATA STRUCTURE
int sortArray[5];               // Array that store distinct job titles  // # USING OF ARRAYS DATA STRUCTURE
int isAvailableCompanyCSV = 0;

void displayJobDetails() {
	cout << "-----------------------JoB Titles with Reference Number----------------------------" << endl;

	cout << "Software Engineering            =>   100" << endl;
	cout << "Electronic Engineering          =>   101" << endl;
	cout << "Electircal Engineering          =>   102" << endl;
	cout << "Telecommuincation Engineering   =>   103" << endl;
	cout << "Power Engineering               =>   104" << endl;
	cout << endl;
}
void findJob(int jobIndex) {                                        // Display the available jobs for user
	switch (jobIndex)
	{
	case 100:
		cout << "100-> Software Engineering  " << endl;
		break;
	case 101:
		cout << "101->Electronic Engineering " << endl;
		break;
	case 102:
		cout << "102-> Electrical Engineering" << endl;
		break;
	case 103:
		cout << "103-> Telecomunication Engineering" << endl;
		break;
	case 104:
		cout << "104-> Power Enginnering" << endl;
		break;
	default:
		cout << "104-> Power Enginnering" << endl;
		break;
	}
}

struct Company
{
	string comName;                        // key value of the HashArray
	int refNumber = 0;
	//string jobTitle;
	int noOfVacancies = 0;

};
void inputCompanyDetails() {
	string Name;
	int jobRefNo, vacancies;
	cout << "--------------------------Enter the Company Details-------------------------------" << endl << endl;
	cout << "Enter the Company Name: ";
	cin >> Name;
	cout << endl;
	displayJobDetails();
	cout << "Enter the Job Referance Number: ";
	cin >> jobRefNo;
	cout << endl;
	cout << "Enter the Number of Vacancies: ";
	cin >> vacancies;
	cout << endl;
	addCompany(Name, jobRefNo, vacancies);
}
void addCompany(string Name, int refNo, int vacancies) {   // adding elements for the HashArray
	struct Company* company = new struct Company;

	company->comName = Name;
	company->refNumber = refNo;
	company->noOfVacancies = vacancies;
	int index = hashFunction(Name);
	while (HashArray[index] != NULL) {                                // Collision method  is linear probing algorithm
		index++;
		index = index % N;
	}
	HashArray[index] = company;

}
int hashFunction(string key) {                                  // hashfunction
	int sum = 0;
	for (int i = 0; i < key.length(); i++) {
		sum += key[i];
	}
	return (sum % N);

}
void displayCompanyDetails() {                                   // Dispaly full details about the companies
	for (int i = 0; i < N; i++) {
		if (HashArray[i] != NULL) {
			cout << "Company Name : " << HashArray[i]->comName << "==> Index Number : " << i << endl;
			cout << "Job details" << endl;
			cout << "Job Title :- ";
			findJob(HashArray[i]->refNumber);
			cout << " No of Vaccancies :- " << HashArray[i]->noOfVacancies << endl;
			cout << endl;
		}

	}
}


void sortJobs() {                                    //function that insert disctint Job titles  into an array 

	for (int i = 0; i < N; i++) {
		if (HashArray[i] != NULL) {
			if (findduplicates(HashArray[i]->refNumber)) {
				sortArray[k] = (HashArray[i]->refNumber);
				k++;
			}
		}

	}
}
bool findduplicates(int number) {               // remove duplicats to create above array
	for (int i = 0; i < k; i++) {
		if (sortArray[i] == number) {
			return false;
		}
	}
	return true;
}
void displayAvailableJobs() {               // Display the available jobs for user
	cout << "---------------Available Jobs Oppotunities----------------------" << endl;
	for (int i = 0; i < k; i++) {
		switch (sortArray[i])
		{
		case 100:
			cout << "100-> Software Engineering  " << endl;
			break;
		case 101:
			cout << "101->Electronic Engineering " << endl;
			break;
		case 102:
			cout << "102-> Electrical Engineering" << endl;
			break;
		case 103:
			cout << "103-> Telecomunication Engineering" << endl;
			break;
		case 104:
			cout << "104-> Power Enginnering" << endl;
			break;
		default:
			cout << "104-> Power Enginnering" << endl;
			break;
		}
	}
}
void update(int comIndex) {
	int jobrefNo, noOfVacancies;
	cout << "Exist Details:- " << endl;
	cout << "Company Name : " << HashArray[comIndex]->comName << endl;
	cout << "Job Title : ";
	findJob(HashArray[comIndex]->refNumber);
	cout << endl;
	cout << "No of Vacancies : " << HashArray[comIndex]->noOfVacancies << endl;
	cout << "Let's start updating purposes" << endl;
	displayJobDetails();
	cout << "Enter the Job Referance Number : ";
	cin >> jobrefNo;
	cout << "Enter the Number of Vacancies : ";
	cin >> noOfVacancies;
	HashArray[comIndex]->refNumber = jobrefNo;
	HashArray[comIndex]->noOfVacancies = noOfVacancies;
	cout << " Succesfully updated " << endl;
}
/*                                                   functions used to write, read, update and resotre CSV file
void readToCompany(string fileName) {                         //read the data from CSV file
	fstream file(fileName, ios::in);
	string line;
	string Comref;
	string Comname;
	string refNumber;
	string jobTitle;
	string noOfVacancies;
	while (getline(file, line)) {
		stringstream ss(line);                  //using stringtream seperate the row into words
		getline(ss, Comref, ',');
		getline(ss, Comname, ',');
		getline(ss, refNumber, ',');
		getline(ss, jobTitle, ',');
		getline(ss, noOfVacancies, '\n');
		addCompany(Comname, stoi(refNumber), jobTitle, stoi(noOfVacancies));
	}
	file.close();
}
void writeToCompany(string fileName) {                             //write the data into CSV file
	isAvailableCompanyCSV = 1;
	fstream file;
	file.open(fileName, ios:: out| ios::app);// open an existing file or creates a new file
	for (int i = 0; i < N; i++) {
		if (HashArray[i] != NULL) {
			file << i<<","<<HashArray[i]->comName << "," << HashArray[i]->refNumber <<"," << HashArray[i]->jobTitle << "," << HashArray[i]->noOfVacancies <<endl;
		}
	}
	file.close();
}
void update_recode()
{

	// File pointer
	fstream fin, fout;

	// Open an existing record
	fin.open("Company.csv", ios::in);

	// Create a new file to store updated data
	fout.open("Companynew.csv", ios::out | ios::app);

	int comRefNumber, roll1, count = 0, i;
	int refNumber, noOfVacancies;
	//int index, new_marks;
	string line, word,jobTitle;
	vector<string> row;

	// Get the roll number from the user
	cout << "Enter the Company Referance number of the record to be updated : ";
	cin >> comRefNumber;

	// Get the data to be updated
	displayJobDetails();
	cout << "Enter the New/Existing Job referenace Number : ";
	cin >> refNumber;
	cout << endl;
	cout << "Enter the New/Existing Job Title : ";
	cin >> jobTitle;
	cout << endl; cout << "Enter the Number of Vacancies : ";
	cin >> noOfVacancies;
	cout << endl;


	// Traverse the file
	while (!fin.eof()) {

		row.clear();

		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ',')) {
			row.push_back(word);
		}
		roll1 = stoi(row[0]);
		int row_size = row.size();

		if (roll1 == comRefNumber) {
			count = 1;
			stringstream newJobRefNumber;
			stringstream newJobTitle;
			stringstream newNoOfVacancies;

			// sending a number as a stream into output string
			newJobRefNumber << refNumber;
			newJobTitle << jobTitle;
			newNoOfVacancies << noOfVacancies;

			// the str() converts number into string
			row[2] = newJobRefNumber.str();
			row[3] = newJobTitle.str();
			row[4] = newNoOfVacancies.str();

			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

					// write the updated data
					// into a new file 'reportcardnew.csv'
					// using fout
					fout << row[i] << ",";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else {
			if (!fin.eof()) {
				for (i = 0; i < row_size - 1; i++) {

					// writing other existing records
					// into the new file using fout.
					fout << row[i] << ", ";
				}

				// the last column data ends with a '\n'
				fout << row[row_size - 1] << "\n";
			}
		}
		if (fin.eof())
			break;
	}
	if (count == 0)
		cout << "Record not found\n";

	fin.close();
	fout.close();

	// removing the existing file
	remove("Company.csv");

	// renaming the updated file with the existing file name
	rename("Companynew.csv", "Company.csv");

	/*if (rename("Companynew.csv", "Company.csv") == 0) {
		cout << "Updated Successfully" << endl;
	}
}
void restoreCompanyData() {
	fstream fin, fout;
	fin.open("Company.csv", ios::in);
	fout.open("Companynew.csv", ios::out | ios::app);
	for (int i = 0; i < N; i++) {
		if (HashArray[i] != NULL) {
			fout << i << "," << HashArray[i]->comName << "," << HashArray[i]->refNumber << "," << HashArray[i]->jobTitle << "," << HashArray[i]->noOfVacancies << endl;
		}
		fout.close();
	}
	fin.close();
	remove("Company.csv");
	// renaming the restored file with the existing file name

	if (rename("Companynew.csv", "Company.csv") == 0) {
		cout << "Resotred Successfully" << endl;
	}


}*/
