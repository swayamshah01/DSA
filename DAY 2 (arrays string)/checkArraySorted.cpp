#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {4,5,7,10,8};
    bool issorted=false;
    for(int i=0;i<v.size()-1;i++){
        if(v[i] > v[i+1]){
            issorted = false;
            break;
        }
        issorted = true;
    }
    if(issorted){
        cout<<"The array is sorted."<<endl;
    }
    else{
        cout<<"The array is not sorted."<<endl;
    }
}
