#include<iostream>

using namespace std;


int maxiO(vector<int>&arr){


    int n=arr.size();

    int cnt=0,mi=0;

    for(int i=0;i<n;i++){

     if(arr[i]==1){
        cnt++;
        mi=max(mi,cnt);

     }

     else{
        cnt=0;
     }

    }

    return mi;

}


int main(){

    vector<int>arr={1,0,1,0,1,1,1,1,0,1,0,1,1,1,0};

    cout<<"maxi ones are: "<<maxiO(arr);

}