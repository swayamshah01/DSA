#include<iostream>
using namespace std;

void pyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int k=0;k<=i;k++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

void oddpyramid(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
            for(int k=1;k<=2*i-1;k++){
                cout<<"*";
            }
        cout<<endl;
    }
   
}

void diamond(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
            for(int k=1;k<=2*i-1;k++){
                cout<<"*";
            }
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
            for(int k=1;k<=2*i-1;k++){
                cout<<"*";
            }
        cout<<endl;
    }
}

int main(){
    int n=5;
    pyramid(n);
    oddpyramid(n);
    diamond(n);
}