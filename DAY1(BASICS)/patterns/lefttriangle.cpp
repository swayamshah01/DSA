#include<iostream>
using namespace std;

void leftTriangle(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
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