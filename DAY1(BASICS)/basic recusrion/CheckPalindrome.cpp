#include<iostream>
using namespace std;

bool check(string str,int s,int e){
    if(s>=e){
        return true;
    }
    if(str[s]!=str[e]){
        return false;
    }
    return check(str,s+1,e-1);
}

int main(){
    string str="naman";
    bool result = check(str,0,str.length()-1);
    cout << result << endl;
}