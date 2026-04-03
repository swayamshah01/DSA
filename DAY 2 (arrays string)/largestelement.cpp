#include<iostream>
using namespace std;

int main()
{
    int n=5;
    
    int arr[n]={1,2,3,4,5};
    int largest = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    cout<<"The largest element in the array is: "<<largest;
    return 0;
}