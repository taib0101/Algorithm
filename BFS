#include<bits/stdc++.h>
using namespace std;
#define mx 110
vector < int > graph[mx];
int dis[mx];
bool vis[mx] = {0};

void bfs(int source)
{
    dis[source] = 0;
    vis[source] = 1;
    queue < int > Q;
    Q.push(source);

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i = 0; i < graph[node].size(); ++i)
        {
            int next = graph[node][i];
            if(!vis[next])
            {
                vis[next] = 1;
                dis[next] = dis[node] + 1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    while(cin >> nodes >> edges)
    {
        for(int i = 1; i <= edges; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int source;
        cin >> source;
        bfs(source);
        cout <<"distance " << source << " : "<<endl;
        for(int i = 1; i <= nodes; ++i)
            cout << i <<" -->> "<<dis[i]<<endl;

        memset(dis,0,sizeof(dis));
        memset(vis,0,sizeof(vis));
//        for(int i = 1; i <= nodes; ++i)
//        {
//            cout << "from node to " << i << " -->> ";
//            for(int j = 0; j < graph[i].size(); ++j)
//                cout << graph[i][j] << " . ";
//            cout << endl;
//            graph[i].clear();
//        }
    }
    return 0;
}
//7 9
//1 2
//1 3
//1 7
//2 3
//2 4
//4 5
//5 6
//3 7
//3 6
