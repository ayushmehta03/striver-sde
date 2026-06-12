#include<iostream>
using namespace std;


class ListNode{

    public:
        int val;
        ListNode* next;


    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};


class Solution{

    public:
        ListNode* reverseList(ListNode*head){

            //initialize previous pinter to null
            ListNode*prev=NULL;

            //start from head of list

            ListNode*temp=head;

            //traverse the list
            while(temp!=NULL){
                //save the next node

                ListNode*front=temp->next;


                //reverse the current node's pointer

                temp->next=prev;


                //move prev to the current node

                prev=temp;

                // move to the next node

                temp=front;
            }

            // return new head(last node becomes the first one)
            return prev;


        }

};



int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    // Reversing the list
    ListNode* newHead = sol.reverseList(head);

    // Printing the reversed list
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}