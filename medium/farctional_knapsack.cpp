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

     // Iterate through the sorted items
    for(int i=0;i<n;i++){

   // If the current item can be fully added to the knapsack       
    if(currW+arr[i].weight<=W){
            currW+=arr[i].weight;
            finalVal+=arr[i].value; // Add the full value of the item

        }

        // If the current item can't be fully added, take the fractional part

        else{
            int rem=W-currW;
            finalVal+=(arr[i].value/(double)arr[i].weight)*(double)rem;
            break;  // Break as we have filled the knapsack
        }
    }

    return finalVal; // Return the maximum value that can be carried

}






//driver code

int main(){

    const int n=3;
    int weight=50;
    Item arr[n] ={{100,20},{60,10},{120,30}};

    cout<<"max value is: "<<fractionKs(weight,arr,n);
}

