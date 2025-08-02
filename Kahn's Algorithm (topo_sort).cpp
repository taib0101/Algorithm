//Kahn's Algorithm with Topological implemented by queue which is learnt from bfs
/*
5
c a
d a
b d
e b
e c
*/
#include<bits/stdc++.h>
using namespace std;
vector < int > kahns_algo(vector < int > vs[],int in_degree[],map < int , int > mp)
{
    vector < int > ans;
    queue < int > que;
    for(auto it = mp.begin(); it != mp.end(); ++it)
    {
        if(in_degree[it->first] == 0)
            que.push(it->first);
    }
    while(!que.empty())
    {
        int x = que.front();
        ans.push_back(x);
        que.pop();

        for(int i = 0; i < vs[x].size(); ++i)
        {
            int next = vs[x][i];
            //cout << "next = " << next << endl;
            in_degree[next]--;
            if(in_degree[next] == 0)
                que.push(next);
        }
    }
    return ans;
}
int main()
{
    int t;
    while(cin >> t)
    {
        vector < int > vs[30];
        int in_degree[30];
        memset(in_degree,0,sizeof(in_degree));
        map < int , int > mp;
        for(int i = 0; i < t; ++i)
        {
            char x, y;
            cin >> x >> y;
            vs[x - 'a' + 1].push_back(y - 'a' + 1);
            in_degree[y - 'a' + 1]++;//in coming edge collecting
            mp[x-'a'+1] = mp[y-'a'+1] = 0;
        }
        vector < int > ans = kahns_algo(vs,in_degree,mp);//topo_sort by bfs with indegree method
        cout << "Topological sort with Kahn's Algorithm " << endl;
        for(int i = 0; i < ans.size(); ++i)
        {
            char c = ans[i] + 'a' - 1;
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
