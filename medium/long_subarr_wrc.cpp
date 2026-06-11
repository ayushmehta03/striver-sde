//longest subarray without repeating character

#include<iostream>
#include<algorithm>
using namespace std;


//tc =O(N) sc=O(1)

int lenghtsubA(string s){


    //two pointers
    int left=0,right=0;


    //store the freq of all the char 
    int hashLen=256;

    int hash[hashLen];

    //intialize with -1 at all position

    for(int i=0;i<hashLen;i++)hash[i]=-1;

    int len=0,maxLen=0;

    int n=s.size();

    //running a single loop to count and check occurance 

    while(right<n){

        // if the char index has been visited before and left is before right
        if(hash[s[right]]!=-1 && hash[s[right]]>=left){
            //move left ahead of the repeating window
            left=hash[s[right]]+1;

        }

        //mark the index of char
        hash[s[right]]=right;

        //calculate the length
        len=right-left+1;

        //keep track of max length
        maxLen=max(maxLen,len);


        //move right pointer
        right++;
    }


    return maxLen;


}


int main(){

    string s="cadbzabcd";

    cout<<"max length is :"<<lenghtsubA(s);



}