// greddy approach
#include<iostream>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comp(Item a ,Item b){


    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;

    return r1>r2;
}


double fractionKs(int W, Item arr[],int n){

    //sort the array based on val/weight ratio

    sort(arr,arr+n,comp);


    int currW=0; //current weight of knapsack
    double finalVal=0.0;  //final value we can acheive

    for(int i=0;i<n;i++){
        if(currW+arr[i].weight<=W){
            currW+=arr[i].weight;
            finalVal+=arr[i].value;

        }

        else{
            int rem=W-currW;
            finalVal+=(arr[i].value/(double)arr[i].weight)*(double)rem;
            break;
        }
    }

    return finalVal;

}






//driver code

int main(){

    int n=3,weight=50;
    Item arr[n] ={{100,20},{60,10},{120,30}};

    cout<<"max value is: "<<fractionKs(weight,arr,n);
}

