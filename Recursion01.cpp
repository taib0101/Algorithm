//////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

void recur(vector < int > vc, int i,bool fg,int sum)
{
    int sz = vc.size();
    if(fg)
        sum += vc[i];
    if(i == sz-1)
    {
//        cout << "end = " << i << endl;
        cout << "end sum = " << sum << endl;
        return;
    }
    for(int j = i+1; j < sz; ++j)
    {
        cout << "main = " << i << endl;
        cout << "call = " << j << endl;
        recur(vc,j,1,sum);
        cout << "back = " << j << endl;
        cout << "sum = " << sum << endl;
    }
}

int main()
{
    int t;
    while(cin >> t)
    {
        int n;
        cin >> n;
        vector < int > vc;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            vc.push_back(x);
        }
        recur(vc,-1,0,0);
    }
    return 0;
}

