#include<iostream>
using namespace std;

void leftTriangle(int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void leftTriangleNumber(int n){
    for(int i=n;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n=5;
    leftTriangle(n);
    leftTriangleNumber(n);
}