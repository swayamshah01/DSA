#include<iostream>
using namespace std;

void revarray(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    swap(arr[s],arr[e]);
    revarray(arr,s+1,e-1);
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    revarray(arr,0,n-1);
}