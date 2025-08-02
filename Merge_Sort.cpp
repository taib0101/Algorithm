#include<bits/stdc++.h>
using namespace std;
int arr[10000];
//merge_sort
void merge_sort(int l, int h)
{
    int mid = (l + h) / 2;
    if(l == h)
        return;
    merge_sort(l,mid);
    merge_sort(mid+1,h);
//    cout << "l = " << l << ", mid = " << mid << ", h = " << h << endl;
    int temp[10000];
    for(int i = l, j = mid + 1, k = l; k <= h; ++k)
    {
        if(i == mid+1)
            temp[k] = arr[j++];
        else if(j == h+1)
            temp[k] = arr[i++];
        else if(arr[i] > arr[j])
            temp[k] = arr[j++];
        else
            temp[k] = arr[i++];
    }
    for(int i = l; i <= h; ++i)
        arr[i] = temp[i];
    return;
}
int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        merge_sort(0,n-1);
        for(int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
