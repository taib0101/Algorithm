#include<bits/stdc++.h>
using namespace std;
// fractional knapsack(greedy approch)
struct pw
{
    float p;
    int w, pww;
};
bool cmp(struct pw x,struct pw y)
{
    return x.pww > y.pww;
}
int main()
{
    int t, m;
//7 15
//10 5 15 7 6 18 3
//2 3 5 7 1 4 1
    while(cin >> t >> m)
    {
        struct pw arr[1000];
        memset(arr,0,sizeof(arr));
        for(int i = 0; i < t; ++i)
            cin >> arr[i].p;
        for(int i = 0; i < t; ++i)
            cin >> arr[i].w;
        for(int i = 0; i < t; ++i)
            arr[i].pww = arr[i].p / arr[i].w;
        sort(arr,arr+t,cmp);
        float profit = 0;
        int bag = 0;
        for(int i = 0; i < t && m != 0; ++i)
        {
            if(m >= arr[i].w)
            {
                m -= arr[i].w;
                bag += arr[i].w;
                profit += arr[i].p;
            }
            else
            {
                profit += float ((arr[i].p * m) / arr[i].w);// bager baki weigght er sthe thke given weight boro hoy
                bag += m;
                m = m - m;

            }
            cout << "pro = " << arr[i].p << ", weight = " << arr[i].w << ", p/w =  " << arr[i].pww << endl;
        }
        cout << "profit = " << profit << endl;
        cout << "bag = " << bag << endl;
    }
    return 0;
}
