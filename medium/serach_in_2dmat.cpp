#include<iostream>
#include<vector>
using namespace std;


// two diff wasy to implement 

//1. instead of traversing the whole matrix traverse row wise with the help of range


bool bs(vector<int>&nums,int t){
    int low=0,high=nums.size()-1;

    while(low<=high){

        int mid=(low+high)/2;

        if(nums[mid]==t) return true;

        else if(nums[mid]<t) low=mid+1;

        else high=mid-1;
    }
    return false;
}

bool way1(vector<vector<int>>&matrix,int target){


    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){

        // range between starting and end position of a row
     if(matrix[i][0]<=target && target<=matrix[i][m-1]){
        return bs(matrix[i],target);
     }
    }
            return false;


}







int main(){

    vector<vector<int>>matrix={{1,3,5,7},{10,13,17,22},{23,28,32,40}};


    int t=5;
    if(way1(matrix,t)){
        cout<<"yes target exists";
    }

    else{
        cout<<"no target found";
    }

    return 0;

}