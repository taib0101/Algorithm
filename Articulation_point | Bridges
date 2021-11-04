#include<bits/stdc++.h>
using namespace std;
int timee;
void articulation_point(vector < int > gh[],int u,bool *vs,int *lw,int *di,int *pr)
{
    vs[u] = 1;
    di[u] = lw[u] = ++timee;

    for(int i = 0; i < gh[u].size(); ++i)
    {
        int v = gh[u][i];
        if(!vs[v])
        {
            pr[v] = u;
            articulation_point(gh,v,vs,lw,di,pr);
            lw[u] = min(lw[u] , lw[v]);

            if(lw[v] >= di[u])
                cout << u << "  is articulation point" << endl;
        }
        else if(v != pr[u])
            lw[u] = min(lw[u] ,di[v]);
    }
}

int main()
{
    int n, e;
    while(cin >> n >> e)
    {
        vector < int > gh[210];
        for(int i = 0; i < e; ++i)
        {
            int u, v;
            cin >> u >> v;
            gh[u].push_back(v);
            gh[v].push_back(u);
        }
        bool vs[210];
        int low[210], discovery[210],parent[210];
        memset(vs,0,sizeof(vs));
        memset(low,0,sizeof(low));
        memset(discovery,0,sizeof(discovery));
        memset(parent,-1,sizeof(parent));
        timee = 0;

        articulation_point(gh,0,vs,low,discovery,parent);

        for(int i = 0; i <= 5; ++i)
            printf("low[%d] = %d, discover[%d] = %d\n",i,low[i],i,discovery[i]);
    }
    return 0;
}
/////////////////////////////////// Uva 10199///////////////////////
//In the name of Allah , the Entirely Merciful , the Specially Merciful
//Alhamdulillah
/*
Inputs ----
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado

5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
*/
#include<bits/stdc++.h>
using namespace std;
map < string , bool > vs;//visit
map < string , int > lw;//low
map < string , int > ds;//discover
map < string , string > pr;//parent
map < string , bool > ans;
vector < string > totall;
map < string , int > child;
int timee;
string root;
void articulation_point(map < string , vector < string > > mv, string u)
{
    vs[u] = 1;
    ds[u] = lw[u] = ++timee;
    for(int i = 0; i < mv[u].size(); ++i)
    {
        string v = mv[u][i];
        if(!vs[v])
        {
            if(u == root)
                child[u]++;
            pr[v] = u;
            articulation_point(mv,v);

            lw[u] = min(lw[u],lw[v]);
            if(lw[v] >= ds[u] && root != u && !ans[u])
            {
                totall.push_back(u);
                ans[u] = 1;
            }

        }
        else if(v != pr[u])
            lw[u] = min(lw[u],ds[v]);
    }
}

bool cmp(string x, string y)
{
    return x < y;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t, co = 1;
    while(cin >> t && t)
    {
        if(co != 1)
            cout << endl;
        map < string , vector < string > > mv;
        vs.clear();
        lw.clear();
        ds.clear();
        pr.clear();
        ans.clear();
        totall.clear();

        string str;
        for(int i = 1; i <= t; ++i)
        {
            cin >> str;
            vs[str] = 0;
        }
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            string u, v;
            cin >> u >> v;
            mv[u].push_back(v);
            mv[v].push_back(u);
        }
        timee = 0;

        for(auto it = mv.begin(); it != mv.end(); ++it)
        {
            string u = it -> first;
            if(!vs[u])
            {
                child.clear();
                root = u;
                articulation_point(mv,u);

                if(child[u] > 1)
                    totall.push_back(u);
            }

        }

        printf("City map #%d: %d camera(s) found\n",co,totall.size());
        sort(totall.begin(),totall.end(),cmp);

        for(int i = 0; i < totall.size(); ++i)
            cout << totall[i] << endl;
        co++;
    }
    return 0;
}

