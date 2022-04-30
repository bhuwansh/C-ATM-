#include <iostream>
using namespace std;

void showMenu()
{
 

    cout << "####################################################" << endl;
    cout << "######         *Welcome to AIS ATM*           ######" << endl;
    cout << "##  -------------------------------------------   ##" << endl;
    cout << "##  1) Register a user / Account Open             ##" << endl;    
    cout << "##  2) Withdraw INR                               ##" << endl;
    cout << "##  3) Withdraw International Currency            ##" << endl;
    cout << "##  4) Check Balance                              ##" << endl;
    cout << "##  5) Show All Accounts List                     ##" << endl;
    cout << "####################################################" << endl;
}

// class
class Bank
{
private:
    int acno = 1111;
    char name[30];
    char Email[50];
    char Mobile[12];
    int age;
    string Gender;
    int WithdrawalFees;
    long MonthlySalary, balance = 5000, WithdrawAmount;
    string InternationalCurrency[3] = {"USD", "GBP", "AUD"};

public:
    void OpenAccount(int id)
    {
        cout << "User Registration Form  :" << endl;

        cout << " Enter Your Name  :";
        cin >> name;
        cout << endl;
        cout << " Enter Your Email  :";
        cin >> Email;
        cout << endl;
        cout << " Enter Your Mobile:";
        cin >> Mobile;
        cout << endl;
        cout << " Enter Your Age :";
        cin >> age;
        cout << endl;
        cout << " Enter Your Gender :";
        cin >> Gender;
        cout << endl;
        cout << " Enter Your Monthly Salary  :";
        cin >> MonthlySalary;
        cout << endl;
        acno += id;
        cout << " ###################################################" << endl;
        cout << " Thank Your for Registor! Your Account is open in AIS Bank  " << endl;
        cout << " Your Account Number is " << acno << " and Initial Balance is : " << balance << " Rs. " << endl;
    }
    void ShowAccount()
    {

        cout << "----------------------------------" << endl;
        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "----------------------------------" << endl;
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
        if (amt <= balance){
            balance = balance - amt;
            cout << "Withdraw Successful " << endl; 
        }
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
        case 1: // OPen Account
            C[uniq_id].OpenAccount(uniq_id);
            uniq_id++;
            break;

        case 2: // withdraw operation
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
            case 3: //Withdraw International Currency
             cout << "Withdraw International Currency : ";
            break;
        case 4: // searching the record
            cout << "Enter Account Number? ";
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
        case 5: // displating all accounts
            for (i = 0; i < uniq_id; i++)
            {
                C[i].ShowAccount();
            }
            break;

        case 11: // deposit operation
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

        case 10: // exit
            cout << "Have a nice day" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 9);
    return 0;
}
