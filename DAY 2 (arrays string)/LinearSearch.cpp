//linear search
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=3;
    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            found = true;
            cout<<"Element found at index: "<<i<<endl;
            break;
        }
    }
    if(!found){
        cout<<"Element not found in the array."<<endl;
    }
}