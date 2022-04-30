#include <iostream>
using namespace std;

// class
class Bank
{
private:
    // 1  user registration
    char name[30];
    char Email[50];
    char Mobile[12];
    int Age, WithdrawalFees;
    char Gender[1];
    double MonthlySalary, balance = 5000.00, WithdrawAmount;
    int acno;
    // 3 International currency withdrawal
    string InternationalCurrency[3] = {"USD", "GBP", "AUD"};
    // 4  Check balance
   

public:

void GenerateAccNo(){
    acno =  rand();
}

    void OpenAccount()
    {
     cout << "User Registration / Account Opening Form  :" << endl;

            cout << " Enter Your Name  :";
            cin >> name;
            cout << endl;
            cout << " Enter Your Email  :";
            cin >> Email;
            cout << endl;
            cout << " Enter Your Mobile:";
            cin >> Mobile;
            cout << endl;
            cout << " Enter Your Age:";
            cin >> Age;
            cout << endl;
            cout << " Enter Your Gender:";
            cin >> Gender;
            cout << endl;
            cout << " Enter Your Monthly Salary :";
            cin >> MonthlySalary;
            cout << endl;
            cout << " ###################################################" << endl;
            cout << " Thank Your for Registor! Your Account is open in AIS Bank  " << endl;
            cout << " Your Account Number is " << acno << " and Initial Balance is : " << balance << " Rs. " << endl;

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

void showMenu()
{
    cout << "####################################################" << endl;
    cout << "######         *Welcome to AIS ATM*           ######" << endl;
    cout << "##  -------------------------------------------   ##" << endl;
    cout << "##  1) Register a user / Account Open             ##" << endl;
    cout << "##  2) Withdraw INR                               ##" << endl;
    cout << "##  3) Withdraw International Currency            ##" << endl;
    cout << "##  4) Check Balance                              ##" << endl;
    cout << "####################################################" << endl;
}

// main code
int main()
{
    Bank C[10];

    int found = 0, a, ch, i;
    // for (i = 0; i <= 2; i++) {
    //     C[i].OpenAccount();
    // }

    do
    {
        // display options
        // cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" << endl;
        showMenu();

        // user input
        cout << "Please input your choice: ";
        cin >> ch;
        system("cls");
        
        switch (ch)
        {
        case 1: // account open
            // for (i = 0; i <= 2; i++)
            // {
            //     C[i].ShowAccount();
            // }
            C->OpenAccount();
            break;
        case 5: // account info
            // for (i = 0; i <= 2; i++)
            // {
            //     C[i].ShowAccount();
            // }
            C->ShowAccount();
            break;
        case 2: // searching the record
            cout << "Account Number? ";
            cin >> a;
            for (i = 0; i <= 2; i++)
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
            for (i = 0; i <= 2; i++)
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
            cout << "Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i <= 2; i++)
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
        case 6: // exit
            cout << "Have a nice day" << endl;
            break;
        }
    } while (ch != 10);
    return 0;
}
