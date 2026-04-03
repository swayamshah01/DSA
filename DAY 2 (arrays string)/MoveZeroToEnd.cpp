#include<iostream>
using namespace std;

int main(){
    int arr[]={0,1,0,3,12};
    int n=sizeof(arr)/sizeof(arr[0]);

    int j = -1;

    
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }


    if(j == -1){
        cout << "No zero found in the array." << endl;
    
    }

    int i = j + 1;
    while(i < n){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
        i++;
    }

    for(int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }

    return 0;
}