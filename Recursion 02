#include<bits/stdc++.h>
using namespace std;
vector < int > ans[100];
vector < int > temp;
int a = 0;
void recur(vector < int > vc,int i, int lvl)
{
    int sz = vc.size();
    if(lvl == 3)
    {
        ans[a++] = temp;
//        cout << "return  = " << vc[i] << endl;
        return;
    }
    for(int j = i+1; j < sz; ++j)
    {
        temp.push_back(vc[j]);
//        cout << "main = " << i << endl;
//        cout << "call = " << vc[j] << endl;
        recur(vc,j,lvl+1);
        temp.pop_back();
//        cout << "back = " << vc[j] << endl;
    }
    return;
}
// input : 5
// 1 2 3 4 5
int main()
{
    int n;
    while(cin >> n)
    {
        vector < int > vc;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            vc.push_back(x);
        }
        a = 0;
        recur(vc,-1,0);
        for(int i = 0; i < a; ++i)
        {
            for(int j = 0; j < ans[i].size(); ++j)
                cout << ans[i][j] << " ";
            cout << endl;
            ans[i].clear();
        }
    }
    return 0;
}
