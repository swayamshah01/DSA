#include<iostream>
using namespace std;

void leftTriangle(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the left triangle: ";
    cin>>n;
    leftTriangle(n);
}