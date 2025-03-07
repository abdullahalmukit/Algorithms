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
    for(int i = 0 ; i<n ; i++){
        cout << i << " -> ";
        for(int x : mat[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}