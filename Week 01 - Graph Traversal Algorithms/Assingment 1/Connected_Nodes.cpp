#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<int> mat[n];
    
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        
        if (mat[x].empty()) {
            cout << "-1" << endl;
            continue;
        }

        vector<int> v = mat[x];
        sort(v.rbegin(), v.rend()); 

        for (int y : v) {
            cout << y << " ";
        }
        cout << endl;
    }
    
    return 0;
}
