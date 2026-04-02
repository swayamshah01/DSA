#include<iostream>
using namespace std;

int printfibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return printfibo(n-1)+printfibo(n-2);
    

}

int main(){
    int n=10;
     for(int i = 0; i < n; i++){
        cout << printfibo(i) << " ";
    }
}