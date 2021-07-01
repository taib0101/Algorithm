/// In the name of Allah , the entriy mercifull, the specialy mercifull
/////////////////////
with priority_queue solution
#include<bits/stdc++.h>
using namespace std;
const int r = 100000;
int edge_cost[1000][1000];
int dis[r+10];
bool vis[r+10];
int inf = 1000000000;
struct node
{
    int vertex;
    int cost_dis;
};
class cmp
{
    public:
    bool operator() (node &a,node &b)
    {
        return a.cost_dis > b.cost_dis;// 
    }
};
void show(priority_queue < node,vector < node >, cmp > q)
{
    while(!q.empty())
    {
        cout << "cost = " << q.top().cost_dis<< endl;
        q.pop();
    }
}
void dijkstra(int s,vector < int > vc[],vector < int > arr)
{
    priority_queue < node ,vector < node > ,cmp > q;
    q.push({s,0});
    dis[s] = 0;

    while(!q.empty())
    {
        int u = q.top().vertex;
        if(!vis[u])
            show(q);
        q.pop();
        for(int i = 0; i < vc[u].size() && !vis[u]; ++i)
        {
            int v = vc[u][i];
            // if(!vis[v])
            // {
                if(dis[u] + edge_cost[u][v] < dis[v])
                    dis[v] = dis[u] + edge_cost[u][v],q.push({v,dis[v]});
                //cout << "dis = " << dis[v] << endl;
            // }
        }
        vis[u] = 1;
        //sort(q.begin(),q.end(),cmp);
    }
    sort(arr.begin(),arr.end());
    cout << "Distance of per vertex : \n";
    for(int i = 0; i < arr.size(); ++i)
        printf("i = %d, distance = %d\n",arr[i],dis[arr[i]]);
}
// 9
// 1 2
// 14
// 2 3
// 2
// 1 3
// 9
// 1 6
// 7
// 3 5
// 11
// 6 5
// 15
// 2 4
// 8
// 4 5
// 6
// 3 6
// 10
// 1

int main()
{
    int edge;
    while(cin >> edge)
    {
        vector < int > vc[10000];
        memset(vis,0,sizeof(vis));
        fill(dis,dis+r+10,inf);
        memset(edge_cost,0,sizeof(edge_cost));
        vector < int > arr;
        bool b[r+10];
        memset(b,0,sizeof(b));
        for(int i = 0;i < edge; ++i)
        {
            int u,v;
            cin >> u >> v;
            cin >> edge_cost[u][v];
            if(!b[u])
                b[u] = 1,arr.push_back(u);
            if(!b[v])
                b[v] = 1,arr.push_back(v);
            vc[u].push_back(v);
            //vc[v].push_back(u);
            //edge_cost[v][u] = edge_cost[u][v];
        }
        int source;
        cin >> source;
        dijkstra(source,vc,arr);
    }
    return 0;
}
//////////////////*************************///////////////////////
with vector solution
#include<bits/stdc++.h>
using namespace std;
const int r = 100000;
int edge_cost[1000][1000];
int dis[r+10];
bool vis[r+10];
int inf = 1000000000;
struct node
{
    int vertex;
    int cost_dis;
};
bool cmp(struct node x,struct node y)
{
    return x.cost_dis < y.cost_dis;
}
void dijkstra(int s,vector < int > vc[],vector < int > arr)
{
    vector < node > q;
    q.push_back({s,0});
    dis[s] = 0;
    
    while(q.size() != 0)
    {
        int u = q[0].vertex;
        vis[u] = 1;
        q.erase(q.begin(),q.begin()+1);
        for(int i = 0; i < vc[u].size(); ++i)
        {
            int v = vc[u][i];
            if(!vis[v])
            {
                if(dis[u] + edge_cost[u][v] < dis[v])
                dis[v] = dis[u] + edge_cost[u][v];
                q.push_back({v,dis[v]});
            }
        }
        sort(q.begin(),q.end(),cmp);
    }
    sort(arr.begin(),arr.end());
    cout << "Distance of per vertex : \n";
    for(int i = 0; i < arr.size(); ++i)
        printf("i = %d, distance = %d\n",arr[i],dis[arr[i]]);
}
// 9
// 1 2
// 14
// 2 3
// 2
// 1 3
// 9
// 1 6
// 7
// 3 5
// 11
// 6 5
// 15
// 2 4
// 8
// 4 5
// 6
// 3 6
// 10
// 1

int main()
{
    int edge;
    while(cin >> edge)
    {
        vector < int > vc[10000];
        memset(vis,0,sizeof(vis));
        fill(dis,dis+r+10,inf);
        memset(edge_cost,0,sizeof(edge_cost));
        vector < int > arr;
        bool b[r+10];
        memset(b,0,sizeof(b));
        for(int i = 0;i < edge; ++i)
        {
            int u,v;
            cin >> u >> v;
            cin >> edge_cost[u][v];
            if(!b[u])
                b[u] = 1,arr.push_back(u);
            if(!b[v])
                b[v] = 1,arr.push_back(v);
            vc[u].push_back(v);
            //vc[v].push_back(u);
            //edge_cost[v][u] = edge_cost[u][v];
        }
        int source;
        cin >> source;
        dijkstra(source,vc,arr);
    }
    return 0;
}
///////////////////////////////////////////////////////////
Iftekhar solution
///////////////////

#include<bits/stdc++.h>
using namespace std;
const int r = 100000;
int edge_cost[1000][1000];
int dis[r+10];
bool vis[r+10];
int inf = 1000000000;
struct node
{
    int vertex;
    int cost_dis;
};
int find_min(vector < node > &q)
{
    int min = inf;
    int min_in = 0;
    for(int i = 0; i < q.size(); ++i)
    {
        int u = q[i].cost_dis;
        if(u < min && !vis[q[i].vertex])
            min = u,min_in = i;
    }
    //cout << "minnn = " << min << endl;
    return min_in;
}
void dijkstra(int s,vector < int > vc[],vector < int > arr)
{
    vector < node > q;
    q.push_back({s,0});
    dis[s] = 0;
    int sz = arr.size();
    sz--;
    while(sz != -1)
    {

        int min = find_min(q);
        int u = q[min].vertex;
        vis[u] = 1;
        for(int i = 0; i < vc[u].size(); ++i)
        {
            int v = vc[u][i];
            if(!vis[v])
            {
                if(dis[u] + edge_cost[u][v] < dis[v])
                    dis[v] = dis[u] + edge_cost[u][v];
                q.push_back({v,dis[v]});
            }
        }
        sz--;
        //cout << "size = " << q[u].cost_dis << endl;
    }
    sort(arr.begin(),arr.end());
    cout << "Distance of per vertex : \n";
    for(int i = 0; i < arr.size(); ++i)
        printf("i = %d, distance = %d\n",arr[i],dis[arr[i]]);
}
// 9
// 1 2
// 14
// 2 3
// 2
// 1 3
// 9
// 1 6
// 7
// 3 5
// 11
// 6 5
// 15
// 2 4
// 8
// 4 5
// 6
// 3 6
// 10
// 1

int main()
{
    int edge;
    while(cin >> edge)
    {
        vector < int > vc[10000];
        memset(vis,0,sizeof(vis));
        fill(dis,dis+r+10,inf);
        memset(edge_cost,0,sizeof(edge_cost));
        vector < int > arr;
        bool b[r+10];
        memset(b,0,sizeof(b));
        for(int i = 0;i < edge; ++i)
        {
            int u,v;
            cin >> u >> v;
            cin >> edge_cost[u][v];
            if(!b[u])
                b[u] = 1,arr.push_back(u);
            if(!b[v])
                b[v] = 1,arr.push_back(v);
            vc[u].push_back(v);
            //vc[v].push_back(u);
            //edge_cost[v][u] = edge_cost[u][v];
        }
        int source;
        cin >> source;
        dijkstra(source,vc,arr);
    }
    return 0;
}
