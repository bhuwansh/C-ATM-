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
    cout << "####################################################" << endl;
}

void userRegistration()
{
}

int main()
{
#pragma region - requirments
    // Design a money withdrawal console application that will
    //  create a bank account by registering a user.
    // As the program starts these show 4 options
    // 1) Register a user
    // 2) Withdraw INR
    // 3) Withdraw international currency
    // 4) Check balance

#pragma endregion

#pragma region - varible declare
    int option;

    // 1  user registration
    string Name;
    string Email;
    string Mobile;
    int Age;
    string Gender;
    double MonthlySalary;
    double Balance = 5000.00;
    string AccountNumber = "1111111111";
    // 2 Inr withdrawal
    double WithdrawAmount;
    int WithdrawalFees;

    // 3 International currency withdrawal
    string InternationalCurrency[3] = {"USD", "GBP", "AUD"};

    // 4  Check balance
    double finalBalance;
#pragma endregion

    do
    {
        showMenu();

        cout << "Choose Option :";
        cin >> option;

        system("cls");
        switch (option)
        {
        case 1:
            /* code */
            cout << "User Register  :" << endl;

            cout << " Enter Your Name (string) :";
            cin >> Name;
            cout << endl;
            cout << " Enter Your Email (string) :";
            cin >> Email;
            cout << endl;
            cout << " Enter Your Mobile (string):";
            cin >> Mobile;
            cout << endl;
            cout << " Enter Your Age (int):";
            cin >> Age;
            cout << endl;
            cout << " Enter Your Gender (string):";
            cin >> Gender;
            cout << endl;
            cout << " Enter Your Monthly Salary (double/Int) :";
            cin >> MonthlySalary;
            cout << endl;
            cout << " ###################################################" << endl;
            cout << " Thank Your for Registor! Your Account is open in AIS Bank  " << endl;
            cout << " Your Account Number is " << AccountNumber << " and Initial Balance is : " << Balance << " Rs. " << endl;

            break;
        case 2:
            /* code */
            cout << " Withdraw INR:" << endl;
            cout << " Enter Withdrawal Amount (Rs.) :";
            cin >> WithdrawAmount;
            if (WithdrawAmount <= Balance)
            {
                Balance -= WithdrawAmount;
                cout << " Your have Withdraw " << WithdrawAmount << " Rs. " << endl;
                cout << " Your current balance is :" << Balance << " Rs. " << endl;
                // cout << " Thank You for banking with us ! Visit Again." << endl;
            }
            else
            {
                cout << "  *Not Enough Money in your Account !" << endl;
            }
            cout << endl;
            break;
        case 3:
            /* code */
            cout << "Withdraw International Currency : ";
            break;
        case 4:
            /* code */
            cout << "Your Balance is : " << Balance << " Rs. " << endl;
            break;
        }
    } while (option != 0);

    system("pause>0");
}