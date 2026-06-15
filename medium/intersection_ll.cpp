//find the first intersection point in a linked list

#include<iostream>
using namespace std;



class node {
public:
    int num;
    node* next;
    node(int val) {
        num = val;
        next = NULL;
    }
};


void insertNode(node* &head, int val) {
    node* newNode = new node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
}


node* intersectionPresent(node* head1, node* head2) {


    // take two pointer for traversing
    node*temp1=head1;
    node*temp2=head2;

    // Traverse both lists, when one reaches the end, redirect it to the head of the other list
    while (temp1 != temp2) {
        temp1 = temp1 == NULL ? head2 : temp1->next;
        temp2 = temp2 == NULL ? head1 : temp2->next;
    }
    
    return temp1;  // If they meet, return the intersection node, otherwise NULL

}







// Utility function to print linked list
void printList(node* head) {
    while (head->next != NULL) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main() {
    node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    node* head1 = head;
    head = head->next->next->next;  // Intersection point
    node* headSec = NULL;
    insertNode(headSec, 3);
    node* head2 = headSec;
    headSec->next = head;  // Creating intersection
    
    // Printing the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);
    
    // Checking if intersection is present
    node* answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL) 
        cout << "No intersection\n";
    else 
        cout << "The intersection point is " << answerNode->num << endl;
    
    return 0;
}