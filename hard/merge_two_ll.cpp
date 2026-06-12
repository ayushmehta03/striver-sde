//merge two sorted linked list 

#include<iostream>
using namespace std;


class Node{
    public:
    int data;

    Node* next;


    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};





void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}


Node* sortTwoLinkedLists(Node*list1,Node*list2){

    // Create a dummy node to serve
    // as the head of the merged list

    Node* dummyNode=new Node(-1);

    Node*temp=dummyNode;

    //traverse both list simultaeonsly

    while(list1!=nullptr &&list2!=nullptr){

        if(list1->data<=list2->data){
            temp->next=list1;
            list1=list1->next;
        }else{
            temp->next=list2;
            list2=list2->next;
        }

        temp=temp->next;
    }

    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;

}


int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = sortTwoLinkedLists(list1, list2);

    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}