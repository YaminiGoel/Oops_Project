#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include<fstream>
#define MAX 10
using namespace std;

//The file with all find and increment functions

int findUserCount()
{
    ifstream file;
    file.open("Count.txt", ios::in);

    string tmp;
    getline(file,tmp);
    file.close();

    int to = tmp.find(",");
    string sub = tmp.substr(0,to);
    int count = atoi(sub.c_str());

    return count;
}

int findQuesCount()
{
    ifstream file;
    file.open("Count.txt", ios::in);

    string tmp;
    getline(file,tmp);
    file.close();

    int from = tmp.find(",");
    int to = tmp.find(",", from+1);
    string sub = tmp.substr(from+1,to);
    int count = atoi(sub.c_str());

    return count;
}

int findAnsCount()
{
    ifstream file;
    file.open("Count.txt", ios::in);

    string str;
    getline(file,str);
    file.close();

    int tmp = str.find(",");
    int from = str.find(",", tmp+1);
    int to = str.find(",", from+1);
    string sub = str.substr(from+1,to);
    int count = atoi(sub.c_str());

    return count;
}


void incUserCount()
{
    int countUser = findUserCount();
    int countQues = findQuesCount();
    int countAns = findAnsCount();
    countUser++;

    // string str = to_string(countUser);
    stringstream tmp;
    tmp << countUser;
    string str = tmp.str();
    str += ",";
    tmp.str("");
    tmp << countQues;
    str += tmp.str();
    str += ",";
    tmp.str("");
    tmp << countAns;
    str += tmp.str();

    ofstream file;
    file.open("Count.txt",ios::out);
    file << str;
    file.close();
}

void incQuesCount()
{
    int countUser = findUserCount();
    int countQues = findQuesCount();
    int countAns = findAnsCount();
    countQues++;

    std::stringstream tmp;
    tmp << countUser;
    string str = tmp.str();
    str += ",";
    tmp.str("");
    tmp << countQues;
    str += tmp.str();
    str += ",";
    tmp.str("");
    tmp << countAns;
    str += tmp.str();

    ofstream file;
    file.open("Count.txt",ios::out);
    file << str;
    file.close();
}

void incAnsCount()
{
    int countUser = findUserCount();
    int countQues = findQuesCount();
    int countAns = findAnsCount();
    countAns++;

    std::stringstream tmp;
    tmp << countUser;
    string str = tmp.str();
    str += ",";
    tmp.str("");
    tmp << countQues;
    str += tmp.str();
    str += ",";
    tmp.str("");
    tmp << countAns;
    str += tmp.str();

    ofstream file;
    file.open("Count.txt",ios::out);
    file << str;
    file.close();
}





