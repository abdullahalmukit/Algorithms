#include <bits/stdc++.h>
using namespace std;

char grid[8][8];          
bool vis[8][8];        
int level[8][8];         
vector<pair<int, int>> d = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}}; 
int n, m;              

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 8; i++) {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(ki, kj);

        if (ki == qi && kj == qj) {
            cout << 0 << endl;
        } else {
            cout << level[qi][qj] << endl;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> d = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {2, 1}, {1, 2}, {-1, 2}};

// bool valid(int i, int j, int n, int m) {
//     return i >= 0 && i < n && j >= 0 && j < m;
// }

// int bfs(int si, int sj, int di, int dj, int n, int m) {
//     vector<vector<bool>> vis(n, vector<bool>(m, false)); 
//     vector<vector<int>> level(n, vector<int>(m, -1));    
//     queue<pair<int, int>> q;

//     q.push({si, sj});
//     vis[si][sj] = true;
//     level[si][sj] = 0;

//     while (!q.empty()) {
//         pair<int, int> par = q.front();
//         q.pop();
//         int par_i = par.first;
//         int par_j = par.second;

//         for (int i = 0; i < 8; i++) {
//             int ci = par_i + d[i].first;
//             int cj = par_j + d[i].second;

//             if (valid(ci, cj, n, m) && !vis[ci][cj]) {
//                 q.push({ci, cj});
//                 vis[ci][cj] = true;
//                 level[ci][cj] = level[par_i][par_j] + 1;

//                 if (ci == di && cj == dj) {
//                     return level[ci][cj];
//                 }
//             }
//         }
//     }

//     return -1;
// }

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n, m;
//         cin >> n >> m;

//         int ki, kj, qi, qj;
//         cin >> ki >> kj >> qi >> qj;

//         if (ki == qi && kj == qj) {
//             cout << 0 << endl;
//             continue;
//         }

//         bool canAttack = false;
//         for (auto move : d) {
//             int ci = ki + move.first;
//             int cj = kj + move.second;
//             if (ci == qi && cj == qj) {
//                 canAttack = true;
//                 break;
//             }
//         }

//         if (canAttack) {
//             cout << 1 << endl;
//         } else {
//             int steps = bfs(ki, kj, qi, qj, n, m);
//             cout << steps << endl;
//         }
//     }

//     return 0;
// }