#include <iostream>
using namespace std;
int main()
{
    int arr[] = {3, 4, 5, 6, 7};

    int arr2[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "enter: ";
    //     cin >> arr2[i];
    // }
    cout << arr[0] << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << endl;
    }

    int test[2][3] = {{2, 4, 5}, {9, 0, 19}};
    for (int i = 0; i < 2; ++i)
    {

        // access columns of the array
        for (int j = 0; j < 3; ++j)
        {
            // cout << "test[" << i << "][" << j << "] = " << test[i][j] << endl;
        }
    }
    // Pointer
    int *ptr;
    ptr = &arr[0];
    for (int i = 0; i < 3; ++i)
    {
        cout << "&arr[" << i << "] = " << *(ptr+i) << endl;
    }
}