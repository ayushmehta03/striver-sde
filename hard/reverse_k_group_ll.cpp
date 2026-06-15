#include<iostream>
using namespace std;

// reverse linkedlist with k groups

// this problem combines various problem knowledge 

//1. reverse a linked list 
//2. pointers and traversal in ll



// time complexity =O(2N)

//space complexity = O(1)

//creating node class

class ListNode{

   
  public:
   int val;
    ListNode *next;

    ListNode(int x){
        val=x;
        next=NULL;
    }


    ~ListNode(){
        cout<<"clean up";
    }

    

};


// helper function to reverse linkedlist

//explaination-> easy-> reverse_ll.cpp

ListNode*reverseLinkedList(ListNode*head){

    ListNode*temp=head;
    ListNode*prev=NULL;

    while(temp!=NULL){
        ListNode*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }

    return prev;
}




ListNode*getKthNode(ListNode*curr,int k){

    //for the entry node count
    k-=1;

    // till curr is not null and k value is greater than 0
    while(curr && k>0){
     
        //move the curr pointer and decrease the k

        curr=curr->next;
        k--;

    }


    //return the kthnode
    return curr;
}

ListNode* reverseKgroup(ListNode*head,int k){

    //start from the head
    ListNode*temp=head;

    //previous will be null at starting
    ListNode*prev=NULL;


    while(temp!=NULL){

        //get the kthNode 
        ListNode*kthNode=getKthNode(temp,k);

        //if the kth node value is null it means no k groups can be formed further

        if(kthNode==NULL){

            //if previously any group created it means previous exists and is not null

            //make sure to point prev next to the temp which returned null from getkthnode helper func
            if(prev){
                prev->next=temp;
            }

            //end point so break
            break;
        }


        // always store the next element to the kthNode for future linking

        ListNode*nextNode=kthNode->next;

        // break the link cause we only want to reverse k group at one time
        kthNode->next=NULL;

        //reverse function call

        // now the linked list be from temp to kthNode only because we have disconnected the link before
        reverseLinkedList(temp);


        //for the first time if temp is head 

        // we have to change the head for the first reversal 

        // new head will be kthNode cause we are reversing in k groups

        //eg 1->2->3, 3 is the kthNode after reversal 3->2->1 kthNode is the newhead

        if(temp==head){
            head=kthNode;
        }

        // point the previous to the kthnode cause kthnode will come front due to reversal
        else{
            prev->next=kthNode;
        }

        // make previous point to temp to remember the linking point
        prev=temp;

        //move temp to nextNode for further reversal and kthnode ops
        temp=nextNode;

    }

    return head;


}







//driver code

int main(){


    // linkedlist creation and init of value of k
ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k=2;



    // print the linkedlist

    ListNode *result=reverseKgroup(head,k);

    while(result!=NULL){
        cout<<result->val<<" ";
        result=result->next;
    }

    return 0;


}