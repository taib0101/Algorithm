// This Algorithm Is Implemented by kosarajus Algorithm with DFS
//Complexity O(V+E) FOR G, and GT;
/*
8 10
3 0
0 1
1 2
2 3
2 4
4 5
5 6
6 4
7 6
7 8
*/
// UVA - 247 Calling Circles,11709 Trust groups,  11504 - Dominos
/////////////////////////////////////
// kosaraju updated
#include<bits/stdc++.h>
using namespace std;
vector < int > g[300];
vector < int > gt[300];
stack < int > st1;
vector < int > st2;
bool vs[300];
void reversee_graph(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        int u = i;
        for(int j = 0; j < g[u].size(); ++j)
        {
            int v = g[u][j];
            gt[v].push_back(u);
        }
    }
}
void dfs1(int u)
{
    vs[u] = 1;
    for(int v: g[u])
    {
        if(!vs[v])
            dfs1(v);
    }
    st1.push(u);
    st2.push_back(u);
}
int root;
void dfs2(int u)
{
    vs[u] = 1;
    cout << u << " ";
    for(int v: gt[u])
    {
        if(!vs[v])
            dfs2(v);
    }
    if(root == u)
        cout << endl;
}

void clearr(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        g[i].clear();
        gt[i].clear();
    }
}


void kosaraju(int n)
{
    memset(vs,0,sizeof(vs));
    for(int i = 0; i <= n; ++i)
    {
        if(!vs[i])
            dfs1(i);
    }
    reversee_graph(n);

    memset(vs,0,sizeof(vs));
    while(!st1.empty())
    {
        int u = st1.top();
        if(!vs[u])
        {
            root = u;
            dfs2(u);
        }
        st1.pop();
    }
//    for(int i = st2.size()-1; i >= 0; --i)
//    {
//        int u = st2[i];
//        if(!vs[u])
//        {
//            root = u;
//            dfs2(u);
//        }
//
//    }
    clearr(n);
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        for(int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            //gt[v].push_back(u);
        }
        kosaraju(n);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

stack < int > st1;//stacks by stack
vector < int > st2;//stacks by vector
int timee;
void dfs1_scc(int *ds1,int *fn1,vector < int > g[],int u,bool *vs1)
{
    ds1[u] = ++timee;//discovery time;
    vs1[u] = 1;
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(!vs1[v])
            dfs1_scc(ds1,fn1,g,v,vs1);
    }
    fn1[u] = ++timee;//finish time
    st2.push_back(u);
    st1.push(u);
}

int root;

void dfs2_scc(int *ds2,int *fn2,vector < int > gt[],int u,bool *vs2)
{
    vs2[u] = 1;
    ds2[u]= ++timee;
    cout << u << " ";
    for(int i = 0; i < gt[u].size(); ++i)
    {
        int v = gt[u][i];
        if(!vs2[v])
            dfs2_scc(ds2,fn2,gt,v,vs2);
    }
    if(root == u)
        cout << endl;
    fn2[u] = ++timee;
}

void stongly_component_connected(vector < int > g[],vector < int > gt[],int n,int *ds1,int *fn1,int *ds2,int *fn2)
{
    bool vs1[n+10], vs2[n+10];
    memset(vs1,0,sizeof(vs1));
    memset(vs2,0,sizeof(vs2));
    timee = 0;
    for(int i = 0; i <= n; ++i)
    {
        if(!vs1[i])
            dfs1_scc(ds1,fn1,g,i,vs1);
    }
    cout << "Discover And Finish time for DIRECT Graph" << endl;
    for(int i = 0; i <= n; ++i)
        printf("Discover[%d] = %d, Finish[%d] = %d\n",i,ds1[i],i,fn1[i]);
    cout << endl;

    cout << "Strongly Component Connected" << endl;
    vector < int > x;
    while(!st1.empty())
    {
        int u = st1.top();
        x.push_back(u);
        if(!vs2[u])
        {
            root = u;
            dfs2_scc(ds2,fn2,gt,u,vs2);
        }
        st1.pop();
    }
    cout << endl;
    timee = 0;

    cout << "stack of connected component" << endl;
    for(int i = st2.size()-1,j = 0; i >= 0; --i, ++j)
    {
        int u1 = x[j], u2 = st2[i];
        cout << "stack = " << u1 << " , vector = " << u2 << endl;
        st1.pop();
    }

    st2.clear();
    cout << endl;
    cout << "Discover And Finish time for REVERSE Graph" << endl;
    for(int i = 0 ; i <= n; ++i)
        printf("Discover2[%d] = %d, Finish2[%d] = %d\n",i,ds2[i],i,fn2[i]);
    cout << endl;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        vector < int > graph[n+10];
        vector < int > graph_reverse[n+10];

        for(int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph_reverse[v].push_back(u);
        }
        //we can reverse by that
//        for(auto i = 0; i <= n; ++i)
//        {
//            int u = i;
//            for(int j = 0; j < graph[u].size(); ++j)
//            {
//                int v = graph[u][j];
//                graph_reverse[v].push_back(u);
//            }
//        }
        int ds1[n+10], fn1[n+10];//direct graph
        int ds2[n+10], fn2[n+10];//reverse graph;
        memset(ds1,0,sizeof(ds1));
        memset(fn1,0,sizeof(fn1));
        memset(ds2,0,sizeof(ds2));
        memset(fn2,0,sizeof(fn2));

        stongly_component_connected(graph,graph_reverse,n,ds1,fn1,ds2,fn2);

    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

//Strongly Component Connected
//This is implemented by tarzan algorithm
#include<bits/stdc++.h>
using namespace std;
stack < int > st;
int timee;
void tarjan_scc(int *ds,int *lw,bool *stm,vector < int > gh[],int u)//stm means stack_member
{
    ds[u] = lw[u] = ++timee;
    st.push(u);
    stm[u] = 1;

    for(int i = 0; i < gh[u].size(); ++i)
    {
        int v = gh[u][i];
        if(ds[v] == 0)
        {
            tarjan_scc(ds,lw,stm,gh,v);

            lw[u] = min(lw[u], lw[v]);
        }
        else if(stm[v] == 1)
            lw[u] = min(lw[u], ds[v]);
    }

    if(lw[u] == ds[u])
    {
        while(1)
        {
            int uu = st.top();
            cout << uu << " ";
            st.pop();
            stm[uu] = 0;
            if(u == uu)
                break;
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        vector < int > gh[n+10];
        for(int i = 1; i <= m; ++i)
        {
            int u, v;
            cin >> u >> v;
            gh[u].push_back(v);
        }

        int lw[n+10], ds[n+10];
        bool stack_member[n+10];

        memset(lw,0,sizeof(lw));
        memset(ds,0,sizeof(ds));
        memset(stack_member,0,sizeof(stack_member));

        timee = 0;
        for(int i = 0; i <= n; ++i)
        {
            if(!ds[i])
                tarjan_scc(ds,lw,stack_member,gh,i);
        }
    }
    return 0;
}
