// #include<bits/stdc++.h>
// using namespace std;

// vector<int> adj_list[1005];
// bool check[1005];
// int level[1005];
// int par[1005];

// void bfs(int sourc){
//     queue<int> q;
//     q.push(sourc);
//     check[sourc]=true;
//     level[sourc]=0;
//     par[sourc] = -1;
//     while(!q.empty()){
//         int parent = q.front();
//         q.pop();
//         for(auto child : adj_list[parent]){
//             if(check[child]== false){
//                 q.push(child);
//                 check[child]=true;
//                 level[child]=level[parent]+1;
//                 par[child] = parent;
//             }         
//         }
//     }
// }
// int main()
// {
//     int v,e;
//     cin >> v >> e;
//     while(e--){
//         int a ,b;
//         cin >> a >> b;
//         adj_list[a].push_back(b);
//         adj_list[b].push_back(a);
//     }
//     memset(check,false,sizeof(check));
//     memset(level,-1,sizeof(level));
//     memset(par,-1,sizeof(par));
//     int src,dest;
//     cin >> src >> dest ;

//     bfs(src); 

//     vector<int> path;
//     int node = dest;
//     while(node != -1){
//         path.push_back(node);
//         node = par[node];
//     }
//     reverse(path.begin(),path.end());
//     for(auto x : path){
//         cout << x << " ";
//     }
    

//     return 0;
// }
// /*Input:
// 7 8
// 0 1
// 1 3
// 3 2
// 1 4
// 3 5
// 2 5
// 5 6
// 4 6
// 0
// 6
// */


#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool check[1005];
int level[1005];
int parent[1005];

void bfs(int sourc){
    queue<int> q;
    q.push(sourc);
    check[sourc]=true;
    level[sourc]= 0;
    parent [sourc] = -1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto child : adj_list[par]){
            if(check[child]==false){
                q.push(child);
                check[child]=true;
                level[child]= level[par] + 1;
                parent[child] = par;
            }
        }
    }
    
}
int main()
{
    int v,e;
    cin >> v >> e ;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(check,false,sizeof(check));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));

    int src,dest;
    cin >> src >> dest;

    bfs(src);
    vector<int> path;
    int node = dest;
    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(),path.end());
    for(auto x : path){
        cout << x << " ";
    }

    return 0;
}
/*Input:
7 8
0 1
1 3
3 2
1 4
3 5
2 5
5 6
4 6
0
6
*/