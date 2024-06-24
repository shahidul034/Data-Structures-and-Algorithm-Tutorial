# Data-Structures-and-Algorithm
## Array
> Basic array example
> Header files declartion 
```
#include<iostream>
using namespace std;
```
> Main function
```
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
```
