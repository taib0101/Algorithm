#include<bits/stdc++.h>
using namespace std;
// Activity selection 
struct acti
{
    int ac, st, en;
};
bool cmp(struct acti x, struct acti y)
{
    return x.en < y.en;
}
int main()
{
//8
//1 0 1 4 2 5 3 4
//3 4 2 6 9 8 5 5
    int t;
    while(cin >> t)
    {
        struct acti arr[10000];
        memset(arr,0,sizeof(arr));
        for(int i = 0; i < t; ++i)
        {
            cin >> arr[i].st;
            arr[i].ac = i;
        }
        for(int i = 0; i < t; ++i)
            cin >> arr[i].en;
        sort(arr,arr+t,cmp);
        int x = arr[0].en,i = 0, j = 1;
        vector < int > vc;
        while(j < t)
        {
            if(x <= arr[j].st)
            {
                x = arr[j].en;
                vc.push_back(arr[i].ac);// jdi arr[j].ac hoy taile while loop er age push(arr[0].ac) dite hbe karon i ar j ektu age piche hoy
//                cout << "i = " << i << endl;
//                cout << "j = " << j << endl;
                i = j;
            }
            j++;
        }
        vc.push_back(arr[i].ac);
        for(int i = 0 ; i < t; ++i)
        {
            cout << "start = " << arr[i].st << ", end = " << arr[i].en << endl;
        }
        cout << "Activity --->>> " << endl;
        for(int i = 0; i < vc.size(); ++i)
            cout << vc[i] << endl;
    }
    return 0;
}
