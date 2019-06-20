#include <iostream>
#include "register.h"
using namespace std;

User getObj(string name, string psswrd)
{
    User obj; //these kind of objects don't increment count value
    ifstream file;
    file.open("Users", ios::in);
    file.read((char*)&obj, sizeof(obj));

    while(file.tellg() > -1)
    {
        if(obj.getUserName() == name && obj.getPassword() == psswrd)
           {
              // obj.display();
               return obj;
           }
        else
           {
               file.read((char*)&obj, sizeof(obj));
           }
    }
    file.close();
    User tmp;
    return tmp;
}

User login()
{
    string name, pass = "";
	cout << "User Name: ";
	cin >> name;
	cout << "\nPassword: ";
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
            return login();
          }
        }
    }
     return getObj(name, pass);
}



