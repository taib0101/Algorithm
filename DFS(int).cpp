#include<bits/stdc++.h>
using namespace std;
vector < int > vec[100];
bool vis[101];
void dfs(int s)// with loop like bfs
{
    stack < int > st;
    vis[s] = 1;
    st.push(s);
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        for(int i = 0; i < vec[node].size(); ++i)
        {
            int next = vec[node][i];
            if(!vis[next])
            {
                vis[next] = 1;
                st.push(next);
            }
        }
    }
}
//void dfs(int s)// with recursion
//{
//    cout << "To == " << s << endl;
//    vis[s] = 1;
//    for(int i = 0; i < vec[s].size(); ++i)
//    {
//        int next = vec[s][i];
//
//        if(!vis[next])
//        {
//            cout << "from == " << s << endl;
//            dfs(next);
//        }
//    }
//}
int main()
{
    int nodes, edges;

    while(cin >> nodes >> edges)
    {
        memset(vis,0,sizeof(vis));
        int a, b;
        for(int i = 0; i < edges; ++i)
        {
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int source;
        cin >> source;
        dfs(source);
        cout << "visited -->> " << endl;
        for(int i = 0; i <= 4; ++i)
            cout << vis[i] << endl;
        for(int i = 0; i <= nodes; ++i)
            vec[i].clear();
    }
    return 0;
}
