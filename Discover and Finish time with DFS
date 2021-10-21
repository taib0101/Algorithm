//In the name of Allah , the entirelly mercifull , the spacially mercifull
#include<bits/stdc++.h>
using namespace std;
int timee;
struct ele
{
    int xx;
    int yy;
    int zz;
};
vector < ele > vs;
bool cmp(struct ele aa,struct ele bb)
{
    return aa.yy < bb.yy;
}
void dfs(vector < int > vc[],int *d,int *f,bool *v,int x)
{
    
    if(v[x])
        return;
    v[x] = 1;
    
    for(int i = 0; i < vc[x].size(); ++i)
    {
        int next = vc[x][i];
        if(!v[next])
        {
            timee++;
            d[next] = timee;
            //cout << "from = " << next << " , timee = " << timee << endl;
        }
        dfs(vc,d,f,v,next);
        //cout << "back = " << next << endl;
    }
    timee++;
    f[x] = timee;
    vs.push_back({x,d[x],f[x]});
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        vs.clear();
        int discover[n+10], finish[n+10];
        memset(discover,0,sizeof(discover));
        memset(finish,0,sizeof(finish));
        vector < int > vc[n+10];
        for(int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            vc[u].push_back(v);
        }
        bool visit[n+10];
        memset(visit,0,sizeof(visit));
        timee = 1;
        int x;
        cin >> x;
        discover[x] = timee;
        dfs(vc,discover,finish,visit,x);
        finish[x] = timee;
        sort(vs.begin(),vs.end(),cmp);
        for(int i = 0; i < vs.size(); ++i)
        {
            printf("discover[%d] = %d\n",vs[i].xx,vs[i].yy);
             printf("finish[%d] = %d\n",vs[i].xx,vs[i].zz);
        }
        // for(int i = 1; i <= n; ++i)
        // {
        //     printf("discover[%d] = %d\n",i,discover[i]);
        //     printf("finish[%d] = %d\n",i,finish[i]);
        // }
    }
    return 0;
}
// Input section
/* 5 7
1 2
3 1
1 4
4 2
2 5
4 5
3 4
3
*/
////////////////////////////////////////////////////////////
Another Implement
//////////////////////////////


#include<bits/stdc++.h>
using namespace std;
int co;
void dfs(vector < int > gh[],bool *vs,int u,int *dis,int *fin)
{
    vs[u] = 1;
    dis[u] = co;
    co++;
    for(int i = 0; i < gh[u].size(); ++i)
    {
        int v = gh[u][i];
        if(!vs[v])
            dfs(gh,vs,v,dis,fin);
    }
    fin[u] = co;
    co++;
}
int main()
{
    int n, e;
    while(cin >> n >> e)
    {
        vector < int > gh[100];
        for(int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            gh[u].push_back(v);
        }
        bool vs[110];
        memset(vs,0,sizeof(vs));

        int dis[110], fin[110];
        co = 1;
        dfs(gh,vs,1,dis,fin);
        for(int i = 1; i <= n; ++i)
            printf("discovery[%d] = %d, finish[%d] = %d\n",i,dis[i],i,fin[i]);
    }
    return 0;
}
