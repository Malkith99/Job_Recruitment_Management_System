#include<iostream>
#include<string>

using namespace std;

/*struct job
{

	string jobTitle;
	int noOfVacancies;

};

struct Company
{
	string comName; // key
	struct job* jobArray;

};
void addCompany(string Name, int noOfJobs) {
	struct Company* company = new struct Company;

	company->comName = Name;
	company->jobArray = new struct job[noOfJobs];
	insertjob(company->jobArray,noOfJobs);

 }
void insertjob(struct job* array,int N)
{
	for (int i = 0; i < N; i++) {
		cout << "Enter the job title:";
		cin>>array[i].jobTitle;
		cout << endl;
		cout << "Enter the number of Vaccancies:";
		cin >> array[i].noOfVacancies;
	}
}
void insertJob(struct job* array, int n)
{
	for (int i = 0; i < n; i++) {
		displayJobDetails();
		cout << "Enter the job title:";
		cin >> array[i].jobTitle;
		cout << endl;
		cout << "Enter the Job Reference Number: ";
		cin >> array[i].refNumber;
		cout << endl;
		cout << "Enter the number of Vaccancies: ";
		cin >> array[i].noOfVacancies;
		cout << endl;
	}
}*/
/*void writeToJob(string fileName) {
	fstream file;
	file.open(fileName, ios::app);
	for (int i = 0; i < N; i++) {
		if (HashArray[i] != NULL) {
			for (int j = 0; j < HashArray[i]->noOfJobs; j++) {
				file << (HashArray[i]->jobArray[j]).refNumber <<" " << (HashArray[i]->jobArray[j]).jobTitle <<" " << (HashArray[i]->jobArray[j]).noOfVacancies<<",";
			}
			file << endl;
		}
	}
	file.close();
}
void readCompany(string Name) {
	struct Company* company = new struct Company;

	company->comName = Name;
	company->noOfJobs = noOfJobs;

	//readJobs(company->jobArray, noOfJobs);
	int index = hashFunction(Name);
	while (HashArray[index] != NULL) {      //linear probing algorithm
		index++;
		index = index % N;
	}
	HashArray[index] = company;

}
string comName;
	int noOfJobs;
	for (int i = 0; i < 1; i++) {
		cout << "Enter The Company Name :";
		cin >> comName;
		cout << endl;
		cout << "Enter the no of jobs : ";
		cin >> noOfJobs;
		//addCompany(comName, noOfJobs);
	}
	//sortJobs();
	//displayDetails();
	//displaysortArray();
	writeToCompany("Company.csv");
	writeToJob("CompanyJob.csv");*/