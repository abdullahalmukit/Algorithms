#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool check[1005];

int bfs_node_sum(int sorch){
    int sum = 0;
    queue<int> q;
    q.push(sorch);
    check[sorch] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        sum = sum + parent;
        for(auto child : adj_list[parent]){
            if(check[child]==false){
                q.push(child);
                check[child] = true;
            }
        }
    }
    return sum;
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
    memset(check,false,sizeof(check));
    cout << bfs_node_sum(0) << endl;

    return 0;
}