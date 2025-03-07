#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool chack[1005];
void bfs(int sorch){
    queue<int> q;
    q.push(sorch);
    chack[sorch]= true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        cout << parent << " ";
        for(auto child : adj_list[parent]){
            if(chack[child] == false){
                q.push(child);
                chack[child] = true;
            }
        }
    }
    cout << endl;
}
int main()
{
    int v,e;
    cin >> v >> e;
    while(e--){
        int a,b;
        cin >> a>> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(chack,false,sizeof(chack));
    int src,des;
    cin >> src >> des;
    bfs(src);

    if(chack[des] == false){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }

    return 0;
}