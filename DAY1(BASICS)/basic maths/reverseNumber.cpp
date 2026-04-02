#include<iostream>
using namespace std;

int main(){
    int n=234;
    int rev=0;
    for(int i=0;n>0;i++){
        int lastdigit=n%10;
        rev=rev*10+lastdigit;
        n=n/10;
    }
    cout<<rev;

}