#include<iostream>
using namespace std;

void pyramid(int n){
    for(int i=0;i<n;i++){
        for(int k=0;k<=i;k++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        for(int k=0;k<i;k++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n=5;
    pyramid(n);
}