#include<iostream>
using namespace std;

//check palindrome in a linkedlist

class Node{
    public:
    int val;
    Node*next;

    Node(int val){
        this->val=val;
        next=NULL;
    }


};


//reverse the linked list

Node*reverseLinkedList(Node *head){
    if(head==NULL || head->next==NULL) return head;

    Node*temp=head;
    Node*prev=NULL;


    while(temp!=NULL){
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }

    return prev;

}


//function to check plaindrome 

bool isPalindrome(Node*head){

    // there is only element or null palindrome will always be same to the orignal

    if(head==NULL || head->next==NULL) return true;


    //calculate the middle node to divide them into two equal half for comprasion

    Node*slow=head;
    Node*fast=head;

    while(fast->next!=NULL &&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }


    //reverse the second half as the second half starts after slow so will pass slow->next as argument
    Node*newHead=reverseLinkedList(slow->next);

    // two pinters for traversal and comprasion of values 
    Node*am=head;
    Node*ad=newHead;


    while(ad!=NULL){

        //in case of mismatch of values
        if(ad->val!=am->val){
            //get the orignal linked list
            reverseLinkedList(newHead);

            //return false as response
            return false;
        }
    }

    // all checks done get the orignal list and retun true

    reverseLinkedList(newHead);
    return true;

}







// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";  // Print the current node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}





//driver code

int main(){

    Node*head=new Node(1);
 head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    cout<<"Orignal linked list: ";
    printLinkedList(head);


 if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;


}