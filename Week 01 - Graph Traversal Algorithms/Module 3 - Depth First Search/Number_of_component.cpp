#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visite[1005];

void dfs(int src){
    // cout << src << " ";
    visite[src] = true;
    for(auto child : adj_list[src]){
        if(visite[child]==false){
            dfs(child);
        }
    }
}
int main()
{
    int v,e;
    cin >> v >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visite,false,sizeof(visite));
    int cnt = 0;
    for(int i = 0 ; i<v; i++){
        if(visite[i]==false){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

/*
Input:
8 6
1 2
0 5
2 3
6 7
4 5
1 3
*/