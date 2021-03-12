#include<bits/stdc++.h>
using namespace std;
//insertion_sort
int main()
{
    int n;
    while(cin >> n)
    {
        int arr[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        for(int i = 0; i < n; ++i)
        {
            int x = arr[i];
            int j = i - 1;
            for( ; j >= 0 && arr[j] > x; --j)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = x;
        }
        for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
