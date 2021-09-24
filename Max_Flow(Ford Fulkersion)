//In the name of Allah , the entirely merciful, the specially merciful
// Alhamdulillah
/*
6 7
1 2 2
2 5 1
5 6 4
1 3 5
3 4 3
4 6 4
2 4 3
1 6
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int capacity[N][N];
int dfs(vector < int > g[], int n,int s,int t)
{
    int parent[n+10];
    int final_mix = 0;// this is means minimum tube with maximum flow to the shink
    for(int i = 1; i <= n; ++i)
        parent[i] = 0;
    stack < int > node;
    stack < int > min_capacity;
    node.push(s);
    int INF = 1000000;
    min_capacity.push(INF);

    while(!node.empty())
    {
        int u = node.top();
        int mincap = min_capacity.top();
        node.pop();
        min_capacity.pop();

        if(u == t)
        {
            final_mix = mincap;
            break;
        }

        for(int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if(capacity[u][v] > 0 && parent[v] == 0)
            {
                parent[v] = u;
                node.push(v);
                min_capacity.push(min(mincap,capacity[u][v]));
            }
        }
    }
    if(final_mix > 0)
    {
        int v = t;
        while(v != s)
        {
            capacity[parent[v]][v] = capacity[parent[v]][v] - final_mix;
            capacity[v][parent[v]] = capacity[v][parent[v]] + final_mix;
            v = parent[v];
        }
    }
    return final_mix;
}
int ford_fulkarsion(vector < int > g[],int node,int s,int t)
{
    int max_flow = 0;
    while(1)
    {
        int get = dfs(g,node,s,t);
        if(get == 0)
            break;
        max_flow = max_flow + get;
    }
    return max_flow;
}
int main()
{
    int node, vertex;
    while(cin >> node >> vertex)
    {
        vector < int > graph[node+10];
        memset(capacity,0,sizeof(capacity));
        for(int i = 0; i < vertex; ++i)
        {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u].push_back(v);
            capacity[u][v] = c;
        }
        int source, shink;
        cin >> source >> shink;
        cout << ford_fulkarsion(graph,node,source,shink) << endl;
    }
    return 0;
}
