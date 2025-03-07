#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visite[1005];

void dfs(int src){
    cout << src << " ";
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
    dfs(0);

    return 0;
}
/*
Input:
7 7
0 2
2 4
0 1
1 5
1 3
0 3
3 6
*/