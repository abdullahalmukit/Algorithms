#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    vector<int> mat[n];
    for(int i = 0; i<e; i++){
        int a,b;
        cin >>  a >> b;
        mat[a].push_back(b);
    }
    int q;
    cin >> q;
    for(int i = 0 ; i<q ; i++){
        int x,y;
        int flag = 0;
        cin >> x >> y;
        if (x == y) { 
            cout << "YES" << endl;
            continue;
        }
        for(int p : mat[x]){
            if(p == y){
                flag = 1;
            }
        }
        if(flag==1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}