#include<bits/stdc++.h>
using namespace std;
// Bubble sort
//6,5,4,2,3,1;
int main()
{
    int n;
    while(cin >> n)
    {
        int arr[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        for(int i = 0; i < n; ++i)//bubble_sort
        {
            for(int j = 0; j < n-i; ++j)
            {
                if(arr[j] > arr[j+1])
                {
                    co++;
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
