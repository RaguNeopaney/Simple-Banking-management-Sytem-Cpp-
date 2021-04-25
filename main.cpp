#include <iostream>
#include "Account.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include "CheckAccountNumber.h"
using namespace std;
// Simple Banking Project
int RandomNumbers();





// Main function
int main() 
{                
    AccountNumbers acc_num;
    Account test;
	// Variables
	int option = 0;
	string FirstName = "";
	string LastName = "";
	double InitialBalance = 0.00;

	int account_number = 0;

	int ask_account_num;
	int amount_to_deposite_or_withdrawl;

	cout << "\n WELCOME TO BANKING SYSTEM" << endl;

	while (option != 7)
	{
		cout << "\nSelect one option below: "
			<< "\n1. Open an Account"
			<< "\n2. Balance Enquiry"
			<< "\n3. Deposit"
			<< "\n4. Withdrawal"
			<< "\n5. Close an Account"
			<< "\n6. Show All Accounts"
			<< "\n7. Quit" << endl;
		cin >> option;
		switch (option)
		{
			case 1:
				cout << "Enter customer first name: ";
				cin >> FirstName;
				cout << "Enter customer last name: ";
				cin >> LastName;
				cout << "Enter initial balance deposite for this account: ";
				cin >> InitialBalance;	

                // Generating random number and checking for duplicate for Account number
                do
                {
                    account_number = RandomNumbers();
                    acc_num.insertAccountNum(account_number);
                } while (!acc_num.ifExist(account_number));
                
                // Done with Account number		
                test.Open_Account(FirstName,LastName,account_number,InitialBalance);
				break;
			case 2:
				cout << "Enter the account number: ";
                cin >> ask_account_num;
                if (acc_num.ifExist(ask_account_num))
                {
                    cout << "The balance on this account is : $" << test.Get_Acc_balance(ask_account_num)<<endl;
                    break;
                }
                else
                {
                    cout << "Account doesnt exist" <<endl;
                    break;
                }
                
				
			case 3: 
				cout << "Please enter account number you would like to make a deposite to: " ;
				cin >> ask_account_num;
				cout << "Please Enter the amount you would like to deposite: ";
				cin >> amount_to_deposite_or_withdrawl;

				if (acc_num.ifExist(ask_account_num))
				{
					test.Deposite_balance(ask_account_num,amount_to_deposite_or_withdrawl);
				}
				else
				{
					cout<< "The accound number provided is not on our database" << endl;
				}
				
				break;
			case 4: 
				cout << "Please enter account number you would like to make a withdrawal to: " ;
				cin >> ask_account_num;
				cout << "Please Enter the amount you would like to deposite: ";
				cin >> amount_to_deposite_or_withdrawl;
				break;
			case 5:
				cout << "Please enter account number you would like to close: " ;
				cin >> ask_account_num;
				if (acc_num.ifExist(ask_account_num))
				{
					test.delete_Account(ask_account_num);
				}
				else
				{
					cout<< "The accound number provided is not on our database" << endl;
				}
				
				break;
			case 6:
				test.Show_Account();
				break;
			default:
				cout << "Please Enter a valid option(1-6) " << endl;
				break;
		}
	}
	return 0;
}

/*
RandomNumbers function takes no argument and return int. it will create 7 digit random number to be used
for account number.
*/
int RandomNumbers()
{
        // Random seed
    srand(time(NULL));

    // Two variable used in this function
    int RandNum = 0;
    string conversion ="";
    string AccountNumber = "";

    while (AccountNumber.length() < 7)
    {
        RandNum = rand() % 9 + 1;
        conversion = to_string(RandNum);
        AccountNumber = AccountNumber.append(conversion);
    }
    int ConversionToInt = stoi(AccountNumber);

    return ConversionToInt;
}