#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void reverseArr(vector<int>&arr){

    int left=0;
    int right=arr.size()-1;

    while(left<=right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }

}

int main(){
    vector<int>arr={1,2,3,4,5};


    reverseArr(arr);


    cout<<"reversed array: ";
    for(auto it:arr)cout<<" "<<it;

    return 0;

}