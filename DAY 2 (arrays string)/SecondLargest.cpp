#include<iostream>
using namespace std;

int main()
{
    int n=5;
    
    int arr[n]={9,6,10,5,1};
    int largest = arr[0];
    int seclar = -1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] > largest)
        {
            seclar = largest;
            largest = arr[i];
        }
        else if(arr[i] > seclar && arr[i] != largest)
        {
            seclar = arr[i];
        }

    }
    cout<<"The largest element in the array is: "<<largest;
    cout<<"The second largest element in the array is: "<<seclar;
    return 0;
}