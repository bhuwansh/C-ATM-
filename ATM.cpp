#include <iostream>
using namespace std;

void showMenu()
{
    // cout << "\n\n0:Account Open
    //   n1:Display All
    //   n2:By Account No
    //   n3:Deposit
    //   n4:Withdraw
    //   n5:Exit" << endl;

    cout << "####################################################" << endl;
    cout << "######         *Welcome to AIS ATM*           ######" << endl;
    cout << "##  -------------------------------------------   ##" << endl;
    cout << "##  0) Register a user / Account Open             ##" << endl;
    cout << "##  1) Withdraw INR                               ##" << endl;
    cout << "##  2) Withdraw INR                               ##" << endl;
    cout << "##  3) Withdraw International Currency            ##" << endl;
    cout << "##  4) Check Balance                              ##" << endl;
    // cout << "##  5) Check Balance                              ##" << endl;
    cout << "####################################################" << endl;
}

// class
class Bank
{
private:
    int acno;
    char name[30];
    char Email[50];
    char Mobile[12];
    int age;
    string Gender;
    int WithdrawalFees;
    long MonthlySalary, balance, WithdrawAmount;
    string InternationalCurrency[3] = {"USD", "GBP", "AUD"};

public:
    void OpenAccount()
    {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter  Balance: ";
        cin >> balance;
    }
    void ShowAccount()
    {
        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
    {
        long amt;
        cout << "Enter Amount U want to withdraw? ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "Less Balance..." << endl;
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (acno == a)
    {
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main()
{
    Bank C[10];

    int uniq_id = 0, found = 0, a, ch, i;

    do
    {
        // display options
        showMenu();

        // user input
        cout << "Please input your choice: ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 0: // OPen Account
            C[uniq_id].OpenAccount();
            uniq_id++;
            break;
        case 1: // displating account info
            for (i = 0; i < uniq_id; i++)
            {
                C[i].ShowAccount();
            }
            break;
        case 2: // searching the record
            cout << "Account Number? ";
            cin >> a;
            for (i = 0; i < uniq_id; i++)
            {
                found = C[i].Search(a);
                if (found)
                    break;
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 3: // deposit operation
            cout << "Account Number To Deposit Amount? ";
            cin >> a;
            for (i = 0; i < uniq_id; i++)
            {
                found = C[i].Search(a);
                if (found)
                {
                    C[i].Deposit();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 4: // withdraw operation
            cout << "Enter Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i < uniq_id; i++)
            {
                found = C[i].Search(a);
                if (found)
                {
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 5: // exit
            cout << "Have a nice day" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    return 0;
}
