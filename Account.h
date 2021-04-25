#include <iostream>
#include <iomanip>

using namespace std;

class Account
{
    private:
        typedef struct node
        {
            string first_name;
            string last_name ;
            int account_number;
            double Account_balance;

            struct node* next;
        }* nodePtr;
        nodePtr  head;
        nodePtr curr;
        nodePtr temp;

    public:
        Account(){head=curr=temp=nullptr;};
        //~Account(){delete head; delete curr; delete temp;};
        void Open_Account(string,string,int,double);
        double Get_Acc_balance(int);
        void Deposite_balance(int,int);
        void Show_Account();
        void delete_Account(int);
};

// Functions Defination
void Account::Open_Account(string FirstName, string LastName, int AccountNumber, double AccountBalance)
{
    nodePtr n = new node;
    n->first_name = FirstName;
    n->last_name = LastName;
    n->account_number = AccountNumber;
    n->Account_balance = AccountBalance;

    if(head != NULL)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        
        curr->next = n;
        
    }
    else
    {
        head = n;
    }
}
double Account::Get_Acc_balance(int AcountNumber)
{
    curr = head;
    while (curr != NULL)
    {
        if (curr->account_number == AcountNumber)
        {
            return curr->Account_balance;
        }
        curr = curr->next;
    }
    return 0.00;
    
}
void Account::Deposite_balance(int AccountNumber,int Balance_to_deposite)
{
    curr = head;
    while (curr != NULL)
    {
        if (curr->account_number == AccountNumber)
        {
            curr->Account_balance += Balance_to_deposite;
            break;
        }
        curr = curr->next;
        
    }
    
}
void Account::delete_Account(int AccountNumber){
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;
    while (curr != NULL && curr->account_number != AccountNumber)
    {
        temp = curr;
        curr = curr->next;
    }
    if(curr == NULL){
        cout << AccountNumber << " was not in our database\n";
        delete delPtr;
    }
    else
    {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        delete delPtr;
        cout << "The account "<< AccountNumber << " is now deleted\n";

    }
    
    
    
    
}
void Account::Show_Account()
{ 
    curr = head;        
    cout << "-- Customer data Begins --\n";
    cout << "---------------------------\n\n";
    while (curr != NULL)
    {

        cout << "First Name: " << curr->first_name<<endl;
        cout << "Last Name: "<<curr->last_name <<endl;
        cout << "Account Number: " << curr->account_number << endl;
        cout << "Account Balance: " << curr->Account_balance << endl;
        cout << "---------------------------\n";
        curr = curr->next;
    }
        cout << "-- Customer data Ends   --\n\n";
}