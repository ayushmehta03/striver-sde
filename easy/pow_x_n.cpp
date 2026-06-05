#include<iostream>
using namespace std;


double pow(double x,long n){
        if(n==0) return 1.0;

        if(n==1) return x;

        if(n%2==0){
            return pow(x*x,n/2);
        }

        return x*pow(x,n-1);
    }


    double myPow(double x,int n){

        long long num=n;

        if(num<0){
          return (1.0 / pow(x, -num));

        }

        return pow(x,num);
    }


int main(){

    double x;

    int n;

    cin>>x;
    cin>>n;



    cout<<"ans will be: "<<myPow(x,n);

    return 0;
    


}