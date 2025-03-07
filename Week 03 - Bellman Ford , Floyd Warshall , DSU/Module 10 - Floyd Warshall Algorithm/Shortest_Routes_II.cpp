#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , e ,q;
    cin >> n >> e >> q;
    long long int adj_list[n+5][n+5];
    for(int i = 1; i <=n; i++){
        for(int j = 1 ; j<=n; j++){
            if(i==j){
                adj_list[i][j] = 0;
            }
            else{
                adj_list[i][j] = LLONG_MAX;
            }
        }
    }
    while(e--){
        long long int a,b,c;
        cin >> a >> b >> c;
        adj_list[a][b] = min(adj_list[a][b],c);
        adj_list[b][a] = min(adj_list[b][a],c);
    }

    for(int k = 1 ; k<=n ; k++){
        for(int i =1; i<=n; i++){
            for(int j = 1 ; j<=n; j++){
                if(adj_list[i][k]!=LLONG_MAX && adj_list[k][j]!=LLONG_MAX && adj_list[i][k] + adj_list[k][j]< adj_list[i][j]){
                    adj_list[i][j] = adj_list[i][k] + adj_list[k][j];
                }
            }
        }
    }

    while(q--){
        int m,n;
        cin >> m >> n;
        if(adj_list[m][n] == LLONG_MAX){
            cout << "-1" << endl;
        }
        else{
            cout << adj_list[m][n] << endl;
        }
    }

    return 0;
}