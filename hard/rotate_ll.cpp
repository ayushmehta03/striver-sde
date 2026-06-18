//rotate linked list to the right with k steps


#include<iostream>
using namespace std;



class Node{
    public:
        int val;
        Node*next;

      Node(int val){
        this->val=val;
      }
};



Node*rotateLinkedList(Node*head,int k){

if(!head ||!head->next||k==0) return head;
// Initialize length and tail pointer
        int length = 1;
        Node* tail = head;

        // Traverse to find the tail and length
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Make it a circular linked list
        tail->next = head;

        // Effective rotations needed
        k = k % length;

        // Traverse to the new tail (length - k - 1 steps from head)
        int stepsToNewTail = length - k;
        Node* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Set the new head
        Node* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;





}


//driver code

int main(){

    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
     head->next->next->next = new Node(5);


     int k=2;

    Node*result=rotateLinkedList(head,k);






}