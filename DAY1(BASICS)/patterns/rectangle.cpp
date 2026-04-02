#include<iostream>
using namespace std;

void rectangle(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the rectangle: ";
    cin>>n;
    rectangle(n);
}