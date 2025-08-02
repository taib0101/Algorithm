#include<bits/stdc++.h>
using namespace std;
const int N = 11;
bool cboard[N][N];
bool safe(vector < pair < int , int > > pv,int row, int col)
{
    if(pv.size() == 0)
        return 1;
    int rrow, ccol;
    for(int i = 0; i < pv.size(); ++i)
    {

        rrow = pv[i].first;
        ccol = pv[i].second;

        if(rrow == row)
            return 0;
        else if(ccol == col)
            return 0;
        else if(abs(rrow - row) == abs(ccol - col))
            return 0;
    }
//    cout << "rrow = " << rrow << ", ccol = " << ccol << endl;
    return 1;
}
int a = 0;
bool nqueen(vector < pair < int , int > > pv,int col,int board[N][N], int n)
{
    if(col == n)
    {
//        cout << "return" << endl;
//        cout << "column = " << col << endl;
        return 1;
    }

    for(int i = 0; i < n; ++i)
    {
        if(safe(pv,i,col))
        {
            pv.push_back({i,col});
            cboard[i][col] = 1;
            if(nqueen(pv,col+1,board,n))
                return 1;
            pv.pop_back();
            cboard[i][col] = 0;
        }
    }
    return 0;
}
int main()
{
    int n;
    while(cin >> n)
    {
        int board[N][N];
        memset(board,0,sizeof(board));
        memset(cboard,0,sizeof(cboard));
        vector < pair < int , int > > pv;
        if(nqueen(pv,0,board,n))
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                    cout << cboard[i][j] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
//////////////////////////////
10 queen possibility solution
#include<bits/stdc++.h>
using namespace std;
const int N = 11;
bool cboard[726][N][N];
int a;
bool safe(vector < pair < int,int > > pv,int r1, int c1)
{
    if(pv.size() == 0)
        return 1;
    for(int i = 0; i < pv.size(); ++i)
    {
        int r2 = pv[i].first;
        int c2 = pv[i].second;
        if(r1 == r2)
            return 0;
        if(c1 == c2)
            return 0;
        if(abs(r1-r2) == abs(c1-c2))
            return 0;
    }

    return 1;
}
void nqueen(int n, int col, bool board[N][N], vector < pair < int,int > > pv)
{
    if(col == n)
    {
//        cout << "a = " << a << endl;
        for(int i = 0; i < pv.size(); ++i)
        {
            int r = pv[i].first;
            int c = pv[i].second;
//            cout << "row = " << r << " , ";
//            cout << "column = " << c << endl;
            cboard[a][r][c] = 1;
        }
        a++;
        return;
    }
    for(int i = 0; i < n; ++i)
    {
        if(safe(pv,i,col))
        {
//            cout << "col = " << col << endl;
            pv.push_back({i,col});
            nqueen(n,col+1,board,pv);
            pv.pop_back();
        }
    }
}
int main()
{
    int n;
    while(cin >> n)
    {
        bool board[N][N];
        memset(board,0,sizeof(board));
        memset(cboard,0,sizeof(cboard));
        a = 0;
        vector < pair < int, int > > pv;
        nqueen(n,0,board,pv);
        cout << "Total possible :: " << a << endl << endl;
        for(int i = 0; i < a; ++i)
        {
            cout << "Solution ---> " << i+1 << endl;
            for(int j = 0; j < n; ++j)
            {
                for(int k = 0; k < n; ++k)
                    cout << cboard[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
