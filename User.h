#pragma once
#include<iostream>
#include <vector>
#include<string>
#include<fstream>
#include "Developer.h"

using namespace std;

string name;
void display_company(int job_ref) {
   
}
void display_job() {
    for (int i = 0; i < 5; i++) {
        cout << sortArray[i] << endl;
    }
}
void viewComapnies(int refNumber) {
    cout << "Companied under your prefered job catogoty\n";
    for (int i = 0; i < N; i++) {
        if (HashArray[i] != NULL) {
            if (HashArray[i]->refNumber == refNumber && HashArray[i]->noOfVacancies > 0) {
                cout <<i<<"=>" << HashArray[i]->comName << endl;
            }
        }
    }
}

string usn;
int tm;
void valid(string str)
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if (tm == 3)
        {
            cout << "\nThis username already exists\nPlease try Again.";
            return;
        }
        cout << "\nThis username already exists!\nCreate a username:";
        cin >> usn;
        valid(usn);
    }
}


bool writeRecordtofile(string file_name, string name, int job_index, int company_index) {
    fstream file;
    file.open(file_name, ios_base::app);
    file << name << " , " << job_index << " , " << company_index << " , " << endl;
    file.close();
    cout << "All data have saved.Thank you!!! we will email you futher notices" << endl;
    return 0;
}
void printUser() {
    cout << "Nimna" << endl;
}
void login() {
    int choice, exit = 0;
    string ans, psd, age, Degree, fname, bio, usern, pw, line, line2;
    ofstream fileo;
    ifstream filei;
    cout << "--------------------------------------Welcome to our system!-----------------------------\n";
    while (exit == 0)
    {
        cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter your username:";
            cin >> usn;
            cout << "\nEnter your password:";
            cin >> psd;
            fname = usn + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail())
            {
                cout << "\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei, usern);
            getline(filei, line);
            getline(filei, pw);
            if (usn == usern && psd == pw)
            {
                cout << "\nYou are successfully logged in:)\nYOUR PROFILE SAYS:\n";
                cout << "Username:" << usern << endl;
                cout << "Name:" << line << endl;
                // getline(filei, age);
                   //fileo << age << endl;
                 //  cout << "Age:" << age << endl;
                   //getline(filei, line);

                break;
                filei.close();
            }
            else {
                cout << "\nWrong username or password!\nPlease try Again.\n";
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "\nEnter your name:";
            cin.ignore();
            getline(cin, name);
            cout << "\Enter your age: ";
            cin.ignore();
            cin >> age;
            getline(cin, age);
            cout << "\nCreate a username:";
            cin >> usn;
            tm = 0;
            valid(usn);
            if (tm >= 3)
            {
                continue;
            }
            cout << "\nCreate a password:";
            cin >> psd;
            fname = usn + ".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo << usn << endl << name << endl << psd << endl;
            cout << "\nYou are successfully registered:)\n";
            //  cout << "\nAdd to your  and press enter when you are done:";
            //  cin.ignore();
             //getline(cin, bio);
             // fileo << bio << endl;
              //cout << "\nYour bio is saved as: " << bio;
            fileo.close();
            break;
        }
        else
        {
            cout << "You entered wrong!!!.Please try again\n";
        }

    }
}
void select_job() {
    cout << "------------------------Select the job you are looking for:-------------------\n";
    //display_job();
    cout << "Select the index of prefered job :";
    int job_index;
    cin >> job_index;
    cout << "Are you going to apply?( 1 OR 0 )" << endl;
    int preference;
    cin >> preference;

    if (preference == 1) {
      //  viewComapnies(job_index);
        int company_index;
        cout << "Select the companies you prefered : ";
        while (1) {
            cin >> company_index;
            writeRecordtofile("user.csv", name, job_index, company_index);

            break;
            // OUTPUT_COMPANY.push_back(company_index);
          //   if (company_index == (int)'Q') {
          //       break;
          //   }
        }

    }
    else {
        cout << "\n-----------------Thank you!!! for visiting us------------------\n" << endl;
    }
}
    
  