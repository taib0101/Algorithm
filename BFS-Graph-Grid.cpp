#include<bits/stdc++.h>
using namespace std;
bool vis[100][100] = {0};
int dis[100][100] = {0};
int row, colmn;
void bfs_grid(int x, int y)
{
    queue < pair < int , int > > qp;
    qp.push({x,y});
    int dx[] = {-1,1,0,0,-1,-1,1,1};
    int dy[] = {0,0,-1,1,-1,1,-1,1};
    vis[x][y] = 1;
    dis[x][y] = 0;

    while(!qp.empty())
    {
        x = qp.front().first;
        y = qp.front().second;
        qp.pop();
        for(int i = 0; i < 8; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(!vis[xx][yy] && xx >= 0 && xx < row && yy >= 0 && yy < colmn)
            {
                vis[xx][yy] = 1;
                dis[xx][yy] = dis[x][y] + 1;
                qp.push({xx,yy});
            }
        }
    }
}

int main()
{
    cin >> row >> colmn;
    int u,v;
    bfs_grid(2,2);
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 6; ++j)
            cout << dis[i][j] <<" ";
        cout << endl;
    }

    return 0;
}
