// #include<bits/stdc++.h>
// using namespace std;

// vector<int> adj_list[1005];
// bool vis[1005];

// void bfs(int src){
//     queue<int> q;
//     q.push(src);
//     vis[src] = true;

//     while(!q.empty()){
//         int parent = q.front();
//         q.pop();

//         cout << parent << " ";

//         for(int child : adj_list[parent]){
//             if(vis[child] == false){
//                 q.push(child);
//                 vis[child] = true;
//             }
//         }
//     }
// }
// int main()
// {
//     int n,e;
//     cin >> n>>e;
    
//     while(e--){
//         int a,b;
//         cin >> a>>b;
//         adj_list[a].push_back(b);
//         adj_list[b].push_back(a);
//     }
//     memset(vis,false,sizeof(vis));
//     bfs(0);

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool check[1005];

void bfs(int sorce){
    queue<int> q;
    q.push(sorce);
    check[sorce] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        
        cout << parent << " ";
        for(int child : adj_list[parent]){
            if(check[child] == false){
                q.push(child);
                check[child] = true;
            }
        }
    }

}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(check,false,sizeof(check));
    bfs(0);

    return 0;
}

/*
Input:
7 7
0 1
1 3
1 4
3 2
4 6
3 5
4 5
*/