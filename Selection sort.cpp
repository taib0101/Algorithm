#include<bits/stdc++.h>
using namespace std;
// selection sort
//6,5,4,2,3,1;
int main()
{
    int n;
    while(cin >> n)
    {
        int arr[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        for(int i = 0; i < n-1; ++i)//selection_sort
        {
            for(int j = i+1; j < n; ++j)
            {
                if(arr[i] > arr[j])
                    swap(arr[i],arr[j]);
            }
        }
        for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
