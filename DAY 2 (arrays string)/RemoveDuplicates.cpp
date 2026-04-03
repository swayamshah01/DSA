#include<iostream>
using namespace std;

int main(){
    //remove duplicates from an array
    int arr[]={1,1,2,2,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=0;
    for(int i=1;i<n;i++){
        if(arr[i] != arr[res-1]){
            arr[res] = arr[i];
            res++;
        }
    }
    cout<<"The array after removing duplicates is: ";
    for(int i=0;i<res;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
}