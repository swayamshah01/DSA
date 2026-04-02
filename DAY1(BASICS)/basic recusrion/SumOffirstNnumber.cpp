#include<iostream>
using namespace std;

int sumofN(int n){
    int sum=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    sum=n+sumofN(n-1);
    return sum;
}

int main(){
    int n=10;
    int x=sumofN(n);
    cout<<x<<endl;
}