#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool check[1005];
int level[1005];

void bfs(int sourc){
    queue<int> q;
    q.push(sourc);
    check[sourc] = true;
    level[sourc] = 0;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(auto child : adj_list[parent]){
            if(check[child]==false){
                q.push(child);
                check[child]= true;
                level[child] = level[parent]+1;
            }
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
    memset(check,false,sizeof(check));
    memset(level,-1,sizeof(level));
    int src,dest;
    cin >> src >> dest;
    bfs(src);

    cout << level[dest] << endl;

    return 0;
}
/*
input:
9 7
0 1
1 3
3 2
1 4
2 5
5 6
7 8
0
3
*/


// #include<bits/stdc++.h>
// using namespace std;

// vector<int> adj_list[1005];
// bool check [1005];
// int level[1005];

// void bfs(int source){
//     queue<int> q;
//     q.push(source);
//     check[source] = true;
//     level[source] = 0;
//     while(!q.empty()){
//         int parent = q.front();
//         q.pop();
//         // cout << parent << " ";
//         for(auto child : adj_list[parent]){
//             if(check[child]==false){
//                 q.push(child);
//                 check[child]= true;
//                 level[child] = level[parent] + 1;
//             }
//         }
//     }
// }
// int main()
// {
//     int v,e;
//     cin >> v >> e;
//     while(e--){
//         int a,b;
//         cin >> a >> b;
//         adj_list[a].push_back(b);
//         adj_list[b].push_back(a);
//     }
//     memset(check,false,sizeof(check));
//     memset(level,-1,sizeof(level));
//     int src,des;
//     cin >> src >> des;
//     bfs(src);    
    
//     cout << level[des] << endl;

//     return 0;
// }

