#include<bits/stdc++.h>
using namespace std;
// O(nlogn)
//tusher roy example : 3 4 -1 5 8 2 3 12 7 9 10
//10 9 2 5 3 7 101 18
int lower_boundd(int l,int h,vector < int > lis ,int a)
{
    int mid, i;
    while(l <= h)
    {
        mid = (l + h) / 2;
        if(lis[mid] >= a)
            i = mid,h = mid - 1;
        else
            l = mid + 1;
    }
    return i;
}

int main()
{
    vector < int > num;
    int n;
    while(cin >> n)
        num.push_back(n);
    vector < int > lis;
    lis.push_back(num[0]);
    for(int i = 1; i < num.size(); ++i)
    {
        if(lis.back() < num[i])
            lis.push_back(num[i]);
        else
        {
            int j = lower_boundd(0,lis.size()-1,lis,num[i]);
            lis[j] = num[i];
        }
    }
    for(int i = 0; i < lis.size(); ++i)
        cout << "lis = " << lis[i] << endl;
    cout << lis.size() << endl;
    return 0;
}
