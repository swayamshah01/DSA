#include<iostream>
using namespace std;

void printname(int n,string name){
    if(n==0){
        return;
    }
    if(n==1){
        cout<<name;
    }else{
        cout<<name<<" ";
        printname(n-1,name);
    }
}

int main(){
    int n=5;
    string name="hello";
    printname(n,name);
}