#include<iostream>
using namespace std;

void _0and1triangle(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if((i+j)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n=5;
    _0and1triangle(n);
}