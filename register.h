#include <iostream>
#include "userClass.h"
using namespace std;

void registerUsr()
{
	string name, pass = "";
	cout << "User Name: ";
	cin >> name;
	cout << "\nPassword(Max 6 characters): ";
    char ch;
    ch = _getch();
    for(int i=0; ; i++)
    {
       if(ch == '\r' || ch == ' ') //checking enter or space
          break;

       else
        {
          pass += ch;
          cout << '*';

          if(i == 5) //preventing extra user input, under normal circumstances this acts as the termination pt of the loop
            break;

          ch = _getch();
          if(ch == '\b')
          {
            cout << "\n\tERROR!\nBackspaces are not expected. Kindly re-enter the informations.\n\n";
            registerUsr();
            return;
          }
        }
    }
	User obj(name, pass);
	if(!obj.isPresent())
    {
        obj.putObj();
        cout << "\nYou are successfully registered!\n";
        obj.display();
    }
    else
    {
        cout << "\nUserName already taken.\n";
        return;
    }
}





