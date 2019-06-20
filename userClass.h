#include <iostream>
#include "findIncFunc.h"
#include <sstream>
#include<fstream>
#define MAX 10
using namespace std;

class User
{
	int userID;
	char userName[MAX], password[MAX];
	int noQues, noAns, ques[MAX], ans[MAX];

  public:
    User()
    {
        userID = -1;
		userName[0] = '\0';
		password[0] = '\0';
		noQues = 0;
		noAns = 0;
		for(int i=0; i<MAX; i++)
        {
            ques[i] = 0;
            ans[i] = 0;
        }
    }
	User(string name, string psswrd)
	{
		userID = findUserCount();
		strcpy(userName, name.c_str());
		strcpy(password, psswrd.c_str());
		noQues = 0;
		noAns = 0;
		for(int i=0; i<MAX; i++)
        {
            ques[i] = 0;
            ans[i] = 0;
        }
    }
	void putObj(); //stores User object in file
	int getID()
	{
	    return userID;
	}
	string  getUserName()
	{
	    return userName;
	}
	string getPassword()
	{
	    return password;
	}
    void linkQues(int quesID) //links Ques ID with Author and updates no of questions ansked
    {
        ques[noQues] = quesID;
        noQues++;
        updateFile();
    }
    void linkAns(int ansID) //links Ques ID with Author and updates no of questions ansked
    {
        ans[noAns] = ansID;
        noAns++;
        updateFile();
    }
    void updateFile();
	void display();
	bool operator ==(User);
	int isPresent();
};

void User::putObj()
{
    ofstream file;

    file.open("Users",ios::app | ios::ate);
    file.write((char *)&(*this), sizeof(*this));
    file.close();

    incUserCount();
}

void User::updateFile()
{
    User obj;
    fstream file;

    file.open("Users");
    file.read((char*)&obj, sizeof(obj));

   while(!file.eof())
   {
       if(userID != obj.userID)
       {
           //cout << "\nIn update file(When not equal):";
           //obj.display();
           file.read((char*)&obj, sizeof(obj));
       }
       else
       {
           //cout << "\nIn update file(When equal):";
           //obj.display();
           file.seekp(file.tellg() - sizeof(obj));
           file.write((char *)&(*this), sizeof(*this));
           file.read((char*)&obj, sizeof(obj));
       }
   }
   file.close();
}

void User::display()
{
    cout << "\n\tUser Profile\n";
    cout << "\nUser ID: " << userID;
    cout << "\nUserName: " << userName;
    cout << "\nPassword: " << password;
    cout << "\nNo of ques asked: " << noQues;
    cout << "\nNo of answers authored: " << noAns;

    if(noQues)
    {
        cout << "\nQues ID of the asked ques: ";
        for(int i=0; i<noQues; i++)
            cout << ques[i] << " ";
    }
    if(noAns)
    {
        cout << "\nAnswer ID of the authored answers: ";
        for(int i=0; i<noAns; i++)
            cout << ans[i] << " ";
    }
}

bool User::operator == (User obj)
{
    if(userID == obj.userID)
         return 1;
    return 0;
}

int User::isPresent()
{
    User obj; //these kind of objects don't increment count value
    ifstream file;
    file.open("Users", ios::in);
    file.read((char*)&obj, sizeof(obj));

    while(file.tellg() > -1)
    {
        if(!strcmp(obj.userName, userName))
        {
         //   obj.display();
            return obj.userID;
        }
        else
        {
            file.read((char*)&obj, sizeof(obj));
        }
    }
    file.close();
    return 0;
}




