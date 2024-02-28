#include "llrec.h"

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    // check if empty
    if (head == nullptr)
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    Node *temp = head;
    head = temp->next;
    if (temp->val <= pivot)
    {
        temp->next = smaller;
        smaller = temp;
        llpivot(head, smaller->next, larger, pivot);
    }
    else
    {
        temp->next = larger;
        larger = temp;
        llpivot(head, smaller, larger->next, pivot);
    }
    temp = nullptr;
}