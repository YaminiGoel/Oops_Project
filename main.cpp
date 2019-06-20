#include <iostream>
#include <windows.h>
#include <string>
#include "login.h"
#include "feed.h"
using namespace std;

/*
Count.txt has the count of users, ques and ans currently registered or authored respectively.
Users has the details of registered users.
Ques has question details.
Users and Ques are binary files.
*/

void chooseFeed(User obj)
{
    int choice;
    while(1)
    {
        cout << "\n\n\tMENU!\n";
        cout << "PRESS 1: Visit News Feed.\n";
        cout << "PRESS 2: Ask question.\n";
        cout << "PRESS 3: Answer question.\n";
        cout << "PRESS 4: View Profile.\n";
        cout << "PRESS 5: Logout.\n";
        cout << "Your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                Feed s;
                s.displayFeed();
                Sleep(2000);
                break;
            }
        case 2:
            {
                string quesStatement;
                cout << "\nYour question statement: ";
                cin.ignore();
                getline(std::cin, quesStatement);

                Ques quesObj(quesStatement, obj.getID());
                quesObj.putQues(obj);
                displayAllQues();
                Sleep(2000);
                break;
            }
        case 3:
            {
                int quesNo;
                if(displayAllQues())
                {
                    cout << "Question No. you wish to answer: ";
                    cin >> quesNo;
                    if(quesNo >= findQuesCount() || quesNo < 1)
                    {
                        cout << "\nNo question with such Question ID.";
                        break;
                    }
                    string ansStatement;
                    cout << "\nYour answer: ";
                    cin.ignore();
                    getline(std::cin, ansStatement);

                    Ans ansObj(quesNo, ansStatement, obj.getID());
                    ansObj.putAns(obj);
                    Sleep(2000);
                }
                break;
            }
        case 4:
            {
                cout << "\nQuestions asked or answers authored will be updated after you logout.\n";
                obj.display();
                Sleep(2000);
                break;
            }
        case 5:
            {
                return;
            }
        default:
            {
                cout << "\nNot a valid choice.";
                Sleep(1000);
            }
        }
    }


}

int main()
{
    int choice;

    while(1)
    {
        cout << "\n\tMENU!\n";
        cout << "PRESS 1: To register.\n";
        cout << "PRESS 2: To login.\n";
        cout << "PRESS 3: To exit.\n";
        cout << "Your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                registerUsr();
                cout << "\nKindly login or register as new user to proceed further.\n";
                Sleep(2000);
                break;
            }
        case 2:
            {
                User currentUser = login();
                User tmp;
                if(currentUser == tmp)
                {
                    cout << "\n\tERROR!\nKindly check the username or password.";
                    Sleep(2000);
                }
                else
                {
                    cout << "\nYou are successfully login.";
                    Sleep(2000);
                    currentUser.display();
                    chooseFeed(currentUser);
                }
                break;
            }
        default:
            {
                cout << "Have a nice day!";
                return 0;
            }
        }
    }
    return 0;
}
