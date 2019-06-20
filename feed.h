#include <iostream>
#include <cstdlib>
#include <time.h>
#include "quesClass.h"
#include "ANSCLASS.H"
using namespace std;

struct Feed
{
    bool canDisplay()
    {
        return (findQuesCount()-1)&&(findAnsCount()-1);
    }
    void displayFeed()
    {
        if(canDisplay())
        {
                Ans objA;
                srand (time(NULL));
                objA = objA.getAns(rand()%(findAnsCount()-1)+1);

                Ques objQ;
                objQ = objQ.getQues(objA.getQuesID());

                cout << "\n***********************************************************\n";
                cout << objQ.getQuesStat() << "\n";
                cout << objA.getAnsStat();
                cout << "\n***********************************************************\n";
        }
        else
        {
            cout << "\n***********************************************************\n";
            cout << "Nothing in feed to display atm.";
            cout << "\n***********************************************************\n";
        }

    }
};
