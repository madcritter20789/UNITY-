#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{m:

    int choice;
    string email;
    string password;

    cout << "\t\t\t___________________________________________________\n";
    cout << "\t\t\t                                                   \n";
    cout << "\t\t\t               SUPER MARKET MAIN MENU              \n";
    cout << "\t\t\t___________________________________________________\n";
    cout << "\t\t\t                                                   \n";
    cout << "\t\t\t  |  1) Administrator    | \n";
    cout << "\t\t\t  |                      | \n";
    cout << "\t\t\t  |  2) Buyer            | \n";
    cout << "\t\t\t  |                      | \n";
    cout << "\t\t\t  |  3) Exit             | \n";
    cout << "\t\t\t  |                      | \n";
    cout << "\n\t\t  Please select ! ";
    cin>>choice;

    switch (choice)
    {
    case 1:
    {
        cout << "\n\t\t Please Login  ";
        cout << "\n\t\t Enter your e-mail : ";
        cin >> email;
        cout << "\t\t\t Password  \n";
        cin >> password;

        if (email == "chitranshnishad@email.com" && password== "chitransh")
        {
            administrator();
        }
        else
        {
            cout << "INVALID EMAIL/PASSWORD ";
        }
        break;
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select from the given options";
        goto m;

    }

    }

}

void shopping ::administrator()
{m:
    int choice;
    cout << "\n\n\n\t\t\t ADMINISTATROR MENU ";
    cout << "\n\t\t\t  ";
    cout << "\n\t\t\t|____1) Add the product_______|";
    cout << "\n\t\t\t|_____________________________|";
    cout << "\n\t\t\t|____2) Modify the products___|";
    cout << "\n\t\t\t|_____________________________|";
    cout << "\n\t\t\t|____3) Delete the product____|";
    cout << "\n\t\t\t|_____________________________|";
    cout << "\n\t\t\t|____4) Back to the menu______|";

    cout << "\n\n\t Please enter your choice ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        edit();
        break;
    }
    case 3:
    {
        rem();
        break;
    }
    case 4:
    {
        menu();
        break;
    }
    default:
    {
        cout << "\n\t INVALID CHOICE ";
    }
    }
    goto m;
}

void shopping::buyer()
{   m:
    int choice;
    cout << "\t\t\t        Buyer         \n";
    cout << "\t\t\t______________________\n";
    cout << "\t\t\t                      \n";
    cout << "\t\t\t 1) Buy the product   \n";
    cout << "\t\t\t                      \n";
    cout << "\t\t\t 2) Go back           \n";
    cout << "\t\t\t Enter your choice : \n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "\t\t Invalid choice ";
    }
    goto m;
}

void shopping ::add()
{
    fstream data;
    int c ;
    int token = 0;
    float p;
    float d;
    string n;
m:
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product : ";
    cin >> pcode;
    cout << "\n\n\t Name of the product ";
    cin >> pname;
    cout << "\n\n\t Price of the product ";
    cin >> price;
    cout << "\n\n\t Discount on the product ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
        cout << "\n\n\t\t Record inserted !";
    }
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record ";
    cout << "\n\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\tFile doesn't exist ! ";
    }
    else
    {
        data1.open("datbase1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product of new code : ";
                cin >> c;
                cout << "\n\t\t Enter of the product : ";
                cin >> n;
                cout << "\n\t Enter the discount : ";
                cin >> d;
                data1 << " " << c << " " << p << " " << d << "\n";
                cout << "\n\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("databaase.txt");
        rename("database1.txt", "database.txt");

        if (token = 0)
        {
            cout << "\n\t\t Record not found sorry ! ";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t\t Delete product ";
    cout << "\n\t Product code :  ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist  ";
    }
    else
    {
        data1.open ("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode ==  pkey)
            {
                cout << "\n\n\t Product deleted successfully ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " "<< price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

            if (token == 0)
        {
            cout << "\n\t Record not found";
        }
    }
}
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|____________________________________________|";
    cout << "ProNo.\t\tName\t\tPrice\n";
    cout << "\n\n|____________________________________________|";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping ::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;


    cout<<"\n\n\t\t |________RECEIPT________|";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\t Empty list  ";

    }
    else
    {   m:
        data.close();
        list();
        cout<<"\n_________________________________________________";
        cout<<"\n                                                 ";
        cout<<"\n          Please  place the order                ";
        cout<<"\n                                                 ";
        do
        {
            cout<<"\n\n\t Enter the product code : ";
            cin>>arrc[c];
            cout<<"\n\n\t Enter the quantity : ";
            cin>>arrq[c];
            for (int  i = 0; i < c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\t Duplicate product code ";
                    cout<<"\t Please try again ! ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product ? if yes then press y else n";
            cin>>choice;
        } while (choice == 'y');

        cout<<"\n\n\t\t_______________RECEIPT________________";
        cout<<"\n Product No.\t Product Quantity\tPrice\tAmount\tAmount with discount\n ";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
}

cout<<"\n\n___________________________________________________";
cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();
}
