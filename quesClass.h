#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class Ques
{
    int quesID, authorID;
    char ques[MAX];

 public:
     Ques()
     {
         quesID = -1;
         ques[0] = '\0';
         authorID = -1;
     }
     Ques(string statement, int author)
     {
         quesID = findQuesCount();
         transform(statement.begin(), statement.end(), statement.begin(), ::tolower);
         strcpy(ques, statement.c_str());
         authorID = author;
     }
     void putQues(User); //puts Ques to the file and links author, the one which calls linkQues function
     Ques getQues(int);  //returns ques obj with id passed in parameter
     string getQuesStat()
     {
         string tmp(ques);
         return tmp;
     }
     void display();
     int alreadyPresent(); //checks if the ques is previously asked
     friend int displayAllQues();
};

void Ques::putQues(User author)
{
    int id = alreadyPresent();
    if(id)
    {
        cout << "\nThis question is previously asked with Ques ID " << id;
        return;
    }

    author.linkQues(quesID);

    ofstream file;
    file.open("Ques",ios::app | ios::ate);
    file.write((char *)&(*this), sizeof(*this));
    file.close();

    incQuesCount();
}

Ques Ques::getQues(int id)
{
    Ques obj; //these kind of objects don't increment count value
    ifstream file;
    file.open("Ques", ios::in);
    file.read((char*)&obj, sizeof(obj));

    while(file.tellg() > -1)
    {
        if(obj.quesID == id)
        {
         //   obj.display();
            return obj;
        }
        else
        {
            file.read((char*)&obj, sizeof(obj));
        }
    }
    file.close();
    Ques tmp;
    return tmp;
}

void Ques::display()
{
    cout << "\n\tQues Details";
    cout << "\nQues ID: " << quesID;
    cout << "\nQuestion: " << ques;
    cout << "\nAuthor ID: " << authorID;
}

int displayAllQues()
{
    int count = 0;
    Ques obj; //these kind of objects don't increment count value
    ifstream file;
    file.open("Ques", ios::in);
    file.read((char*)&obj, sizeof(obj));

    if(file.tellg() > -1)
        cout << "\nAll Questions asked till date:\n";
    else
        cout << "\nNo questions.\n";
    while(file.tellg() > -1)
    {
        count ++;
        //obj.display();
        cout << obj.quesID << ": " << obj.ques << "\n";
        file.read((char*)&obj, sizeof(obj));
    }
    file.close();
    return count;
}

int Ques::alreadyPresent()
{
    Ques obj; //these kind of objects don't increment count value
    ifstream file;
    file.open("Ques", ios::in);
    file.read((char*)&obj, sizeof(obj));

    while(file.tellg() > -1)
    {
        if(!strcmp(obj.ques, ques))
        {
         //   obj.display();
            return obj.quesID;
        }
        else
        {
            file.read((char*)&obj, sizeof(obj));
        }
    }
    file.close();
    return 0;
}

