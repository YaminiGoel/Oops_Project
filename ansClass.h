#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#define MAX 500
using namespace std;

class Ans
{
    int quesID, ansID, authorID;
    char ans[MAX];

 public:
     Ans()
     {
         quesID = -1;
         ansID = -1;
         ans[0] = '\0';
         authorID = -1;
     }
     Ans(int ques, string statement, int author)
     {
         quesID = ques;
         ansID = findAnsCount();
         transform(statement.begin(), statement.end(), statement.begin(), ::tolower);
         strcpy(ans, statement.c_str());
         authorID = author;
    }
    int getQuesID()
    {
        return quesID;
    }
    void putAns(User);
    string getAnsStat()
    {
        string tmp(ans);
        return ans;
    }
    Ans getAns(int);
    //void display();
};

void Ans::putAns(User author)
{
    author.linkAns(ansID);

    ofstream file;
    file.open("Ans",ios::app | ios::ate);
    file.write((char *)&(*this), sizeof(*this));
    file.close();

    incAnsCount();
}

Ans Ans::getAns(int id)
{
    Ans obj; //these kind of objects don't increment count value
    ifstream file;
    file.open("Ans", ios::in);
    file.read((char*)&obj, sizeof(obj));

    while(file.tellg() > -1)
    {
        if(obj.ansID == id)
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
    Ans tmp;
    return tmp;
}
/*
void Ans::display()
{
    cout << "\n\tAns Details";
    cout << "\nAns ID: " << ansID;
    cout << "\nAnswer: " << ans;
    cout << "\nAuthor ID: " << authorID;
}*/
