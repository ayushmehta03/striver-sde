#include<iostream>
#include<vector>
using namespace std;




string permSeq(int n,int k){

    int fact=1;
    vector<int>numbers;


    for(int i=1;i<n;i++){
        fact*=i;
        numbers.push_back(i);
    }

    numbers.push_back(n); // add last element

    string ans="";


    k=k-1; //convert k to 0 based idx

    while(true){
        ans=ans+to_string(numbers[k/fact]); //add digit at that position
        numbers.erase(numbers.begin()+k/fact); // remove the number from the list


        if(numbers.size()==0) break; //exit when all numbers are used

         k = k % fact;  // Reduce k to fit within the remaining sub-permutation
     fact = fact / numbers.size();  // Update factorial for the remaining numbers

    }

    return ans;  // Return the Kth permutation sequence



}



int main(){

    int n=4;
    int k=17;

    cout<<permSeq(n,k);



}