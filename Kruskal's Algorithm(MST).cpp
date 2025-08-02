#include<bits/stdc++.h>
using namespace std;

struct mst
{
    int u;
    int v;
    int cost;
};
vector< pair < pair < int,int > , int > > vpp;
bool cmp(struct mst x, struct mst y)
{
    return x.cost < y.cost;
}
int find(int uu,int *parent)
{
    if(parent[uu] == uu)
        return uu;
    parent[uu] = find(parent[uu],parent);
    return parent[uu];
}
void Union(int uu,int vv,int cc,int *parent,int *rank)
{
    int u1 = uu,v1 = vv;
    uu = find(uu,parent);
    vv = find(vv,parent);
    if(uu != vv)
    {
        if(rank[uu] > rank[vv])
            parent[vv] = uu;
        else if(rank[uu] < rank[vv])
            parent[uu] = vv;
        else
        {
            parent[vv] = uu;
            rank[uu]++;
        }
        vpp.push_back({{u1,v1},cc});
    }
}
int main()
{
    int vartex, edges;
    cout << "Krushkal Algorithm --->> " << endl;
    cout << "Minimum Spening Tree --->> " << endl;
    while(cin >> vartex >> edges)
    {
        vector < mst > vm;
        vpp.clear();
        int uu, vv, cc;
        int parent[100], rank[100];
        for(int i = 0;i < edges; ++i)
        {
            cin >> uu >> vv >> cc;
            vm.push_back({uu,vv,cc});
            parent[uu] = uu;
            parent[vv] = vv;
        }
        sort(vm.begin(),vm.end(),cmp);
        memset(rank,0,sizeof(rank));
        for(int i = 0; i < vm.size(); ++i)
        {
            Union(vm[i].u,vm[i].v,vm[i].cost,parent,rank);
            //printf("u = %d,v = %d,c = %d\n",vm[i].u,vm[i].v,vm[i].cost);
        }
        //cout << "rank = " << rank[5] << endl;
        int sum = 0;
        for(int i = 0;i < vpp.size(); ++i)
            printf("u = %d,v = %d,c = %d\n",vpp[i].first.first,vpp[i].first.second,vpp[i].second),sum += vpp[i].second;
        cout << "Minimum Weight = " << sum << endl;
    }
    return 0;
}
// 7 9
// 1 6 1
// 1 5 5
// 0 4 6
// 2 4 6
// 0 3 3
// 3 5 8
// 5 7 2
// 6 7 6
// 5 6 3
