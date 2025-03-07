#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[105][105];
vector<pair<int,int>> p = {{-1,0},{1,0},{0,-1},{0,1}};
char grid[105][105];
bool valid(int i,int j){
    if(i<0 || i >= n || j <0 || j >= m){
        return false;
    }
    return true;
}

void dfs(int si , int sj){
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for(int i = 0 ; i<4; i++){
        int ci = si + p[i].first;
        int cj = sj + p[i].second;
        if(!vis[ci][cj] && valid(ci,cj)){
            dfs(ci,cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j <m ; j++){
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int si , sj;
    cin >> si >> sj;
    dfs(si,sj);

    return 0;
}
