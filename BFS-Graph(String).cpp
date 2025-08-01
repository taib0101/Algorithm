#include<bits/stdc++.h>
using namespace std;
map < string , vector < string > > mapp;
map < string , vector < string > > :: iterator it;
map < string , bool > vis;
map < string , int  > dis;

void bfs(string source)
{
    vis[source] = 1;
    dis[source] = 0;
    queue < string > que;
    que.push(source);
    while(!que.empty())
    {
        string node = que.front();
        que.pop();
        it = mapp.find(node);
        for(int i = 0; i < it->second.size(); ++i)
        {
            string next = it->second[i];
            if(!vis[next])
            {
                vis[next] = 1;
                dis[next] = dis[node] + 1;
                que.push(next);
            }
        }
    }
}


int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for(int i = 1; i <= edges; ++i)
    {
        string u, v;
        cin>>u>>v;
        mapp[u].push_back(v);
        mapp[v].push_back(u);
    }
    string source;
    while(cin>>source)
    {
        for(it = mapp.begin(); it != mapp.end(); ++it)
            vis[it->first] = 0;
        bfs(source);
        cout <<"Source = " << source <<endl;
        for(it = mapp.begin(); it != mapp.end(); ++it)
            cout << it->first <<" : distance = " << dis[it->first]<<endl;
    }
//    for(it = mapp.begin(); it != mapp.end(); ++it)
//    {
//        cout << it->first << " ";
//        for(int i = 0;i < it->second.size(); ++i)
//            cout <<it->second[i]<<" ";
//        cout<<endl;
//    }
    return 0;
}
