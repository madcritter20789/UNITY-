#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t_______________________________________________\n\n\n";
    cout << "\t\t\t                     Welcome                   \n\n\n";
    cout << "\t| Press 1 for LOGIN              |" << endl;
    cout << "\t| Press 2 for REGISTER             |" << endl;
    cout << "\t| Press 3 for if you FORGOR your PASSWORD           |" << endl;
    cout << "\t| Press 4 to EXIT              |" << endl;
    cout << "\n\t\t\t| PLEASE ENTER YOUR CHOICE              |" << endl;
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t\t Thank you! \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Please select from the option given above \n"
             << endl;
        main();
    }
    return 0;
}
void login()
{
    int count;
    string userid, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userid;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userid && pass == password)
        {
            count = 1;
            system("cls");
        }
        input.close();

        if (count = 1)
        {
            cout << userid << " \n\t YOUR LOGIN IS SUCCESSFUL \n THANKS FOR LOGGING IN !";
            main();
        }
        else
        {
            cout << "\n\t LOGIN ERROR \n PLEASE CHECK YOUR USERNAME AND PASSWROD ";
            main();
        }
    }
}
void registration()
{
    string ruserid, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> ruserid;
    cout << "|t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserid << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t  REGISTRATION IS SUcCESSFUL! \n";
}
void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t YOU FORGOT THE PASSWORD? NO WOORRIES \n";
    cout << "Press 1 to serach you r id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass;
        cout << "\n\t\t\t Enter the username which you remembered : ";
        cin >> suserid;
        ifstream f2("records.txt");
        while (f2 >> sid >> spass)
        {
            if (sid == suserid)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your password is : " << spass;
            main();
        }
        else
        {
            cout << "\n\t Sorry ! your acoount  is not found! \n";
            main();
        }
    }
    case 2:
    {main();

    }
    default:
    cout<<"\t\t\t Wrong choice ! Please try again "<<endl;
    forgot();
    }
}
