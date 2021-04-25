#include <iostream>
using namespace std;

class AccountNumbers
{
    private:
        typedef struct node
        {
            int Account_Num;
            struct node* next;
        }* nodePtr;
        nodePtr head;
        nodePtr curr;
    public:
    AccountNumbers(){head=curr=nullptr;};
    void insertAccountNum(int);
    bool ifExist(int);
};

// CheckAccountNumber functions
void AccountNumbers::insertAccountNum(int Account_numbers)
{
    nodePtr n = new node;
    n->Account_Num = Account_numbers;

    if (head != NULL)
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

bool AccountNumbers::ifExist(int Account_number)
{
    bool result = false;
    curr = head;

    while (curr != NULL)
    {
        if (curr->Account_Num == Account_number)
        {
            result = true;
            break;   
        }
        curr = curr->next;
    }
    return result;
}