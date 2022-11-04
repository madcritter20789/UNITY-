#include <iostream>
using namespace std;

int main()
{
    int quant;
    int choice;
    // quantity
    int qrooms = 0, qpasta = 0, qburger = 0, qnoodles = 0, qshake = 0, qfries = 0;
    // sold
    int srooms = 0, spasta = 0, sburger = 0, snoodles = 0, sshake = 0, sfries = 0;
    // total
    int trooms = 0, tpasta = 0, tburger = 0, tnoodles = 0, tshake = 0, tfries = 0;

    cout << "\n\t Quantity of items we have ";
    cout << "\n Rooms available:";
    cin >> qrooms;
    cout << "\n Quantity of Pasta : ";
    cin >> qpasta;
    cout << "\n Quantity of Burger : ";
    cin >> qburger;
    cout << "\n Quantity of Noodles : ";
    cin >> qnoodles;
    cout << "\n Quantity of Shakes: ";
    cin >> qshake;
    cout << "\n Quantity of Fries : ";
    cin >> qfries;

    m:
    cout << "\n\t\t\t please select from the menu options ";
    cout << "\n\n 1) Rooms";
    cout << "\n 2) Pasta";
    cout << "\n 3) Burger";
    cout << "\n 4) Noodles";
    cout << "\n 5) Shakes";
    cout << "\n 6) Fries";
    cout << "\n 7) Information regarding sales";
    cout << "\n 8) Exit";

    cout << "\n\n Please enter your choice! ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\n Enter the number of rooms you want: ";
        cin >> quant;
        if (qrooms - srooms >= quant)
        {
            srooms = srooms + quant;
            trooms = trooms + quant * 1200;
            cout << "\n\n\t\t" << quant << "Rooms has been alloted to you";
        }
        else
            cout << "\n\tOnly" << qrooms - srooms << "Rooms remaining in hotel ";
        break;
    case 2:
        cout << "\n\n Enter the number of Pasta you want: ";
        cin >> quant;
        if (qpasta - spasta >= quant)
        {
            spasta = spasta + quant;
            tpasta = tpasta + quant * 125;
            cout << "\n\n\t\t" << quant << "Pasta has been ordered! ";
        }
        else
            cout << "\n\tOnly" << qpasta - spasta << "Pasta remaining in  Restaurant ";
        break;
    case 3:
        cout << "\n\n Enter the number of Burger you want: ";
        cin >> quant;
        if (qburger - sburger >= quant)
        {
            sburger = sburger + quant;
            tburger = tburger + quant * 50;
            cout << "\n\n\t\t" << quant << "Burger has been ordered! ";
        }
        else
            cout << "\n\tOnly" << qburger - sburger << "Burger remaining in  Restaurant ";
        break;

    case 4:
        cout << "\n\n Enter the number of Noodles you want: ";
        cin >> quant;
        if (qnoodles - snoodles >= quant)
        {
            snoodles = snoodles + quant;
            tnoodles = tnoodles + quant * 120;
            cout << "\n\n\t\t" << quant << "Noodles has been ordered! ";
        }
        else
            cout << "\n\tOnly" << qnoodles - snoodles << "Noodles remaining in  Restaurant ";
        break;

    case 5:
        cout << "\n\n Enter the number of Shakes you want: ";
        cin >> quant;
        if (qshake - sshake >= quant)
        {
            sshake = sshake + quant;
            tshake = tshake + quant * 45;
            cout << "\n\n\t\t" << quant << "Shakes has been ordered! ";
        }
        else
            cout << "\n\tOnly" << qshake - sshake << "Shakes remaining in Restaurant ";
        break;

    case 6:
        cout << "\n\n Enter the number of Fries you want: ";
        cin >> quant;
        if (qfries - sfries >= quant)
        {
            sfries = sfries + quant;
            tfries = tfries + quant * 60;
            cout << "\n\n\t\t" << quant << "Fries has been ordered! ";
        }
        else
            cout << "\n\tOnly" << qburger - sburger << "Burger remaining in Restaurant ";
        break;

    case 7:
        cout << "\n\n\t\t Details of sales and collection ";
        cout << "\n\t Number of rooms we had : " << qrooms;
        cout << "\n\t Number of rooms booked : " << srooms;
        cout << "\n\t Number of remaining rooms : " << qrooms - srooms;
        cout << "\n\t Total rooms collection for the day : " << trooms;

        cout << "\n\t Number of pasta we had : " << qpasta;
        cout << "\n\t Number of pasta sold : " << spasta;
        cout << "\n\t Number of remaining pasta : " << qpasta - spasta;
        cout << "\n\t Total pasta collection for the day : " << tpasta;

        cout << "\n\t Number of burger we had : " << qburger;
        cout << "\n\t Number of burger sold : " << sburger;
        cout << "\n\t Number of remaining burger : " << qburger - sburger;
        cout << "\n\t Total burger collection for the day : " << tburger;

        cout << "\n\t Number of noodles we had : " << qnoodles;
        cout << "\n\t Number of noodles sold : " << snoodles;
        cout << "\n\t Number of remaining noodles : " << qnoodles - snoodles;
        cout << "\n\t Total noodles collection for the day : " << tnoodles;

        cout << "\n\t Number of shakes we had : " << qshake;
        cout << "\n\t Number of shakes sold : " << sshake;
        cout << "\n\t Number of remaining shakes : " << qshake - sshake;
        cout << "\n\t Total shakes collection for the day : " << tshake;

        cout << "\n\t Number of fries we had : " << qfries;
        cout << "\n\t Number of fries sold : " << sfries;
        cout << "\n\t Number of remaining fries : " << qfries - sfries;
        cout << "\n\t Total fries collection for the day : " << tfries;

        cout<<"\n\n\t\t Total collection for the day :"<<trooms+tpasta+tburger+tnoodles+tshake+tfries;

    case 8:
            exit(0);

    default:
            cout<<"\n\t Please select the number above mentioned";
    }

    goto m;

        return 0;
    }
