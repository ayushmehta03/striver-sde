#include<iostream>
using namespace std;


class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


class Solution {
public:
    // Function to detect a loop in the linked list
    bool detectLoop(Node* head) {
        // Initialize two pointer at head
        Node* slow = head;
        Node*fast=head;


        // Traverse the linked list with tortise and hare algo approahc
        while (fast != nullptr&&fast->next!=nullptr) {
           
            //move slow by one point and fast by two point

            slow=slow->next;
            fast=fast->next;
 
            //if they met at some point it means loop exists 
            if(slow==fast) return true;

            
        }

        // If traversal completes, no loop detected
        return false;
    }
};




// Driver function
int main() {
    // Create sample linked list nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    // Create a Solution object
    Solution obj;

    // Check if loop exists
    if (obj.detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}