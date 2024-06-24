#include<iostream>
using namespace std;
int main()
{
    int arr[]={3,4,5,6,7};

    int arr2[5];
    for(int i=0;i<5;i++){
        cout<<"enter: ";
        cin>>arr2[i];
    }
    cout<<arr[0]<<endl;


    for(int i=0;i<5;i++){
        cout<<arr2[i]<<endl;
    }
}