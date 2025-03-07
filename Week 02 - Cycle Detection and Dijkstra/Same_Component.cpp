#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
vector<pair<int, int>> p = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char grid[105][105];
int level[105][105];

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
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

        for (int i = 0; i < 4; i++) {
            int ci = par_i + p[i].first;
            int cj = par_j + p[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    
    if (grid[si][sj] == '-' || grid[di][dj] == '-') {
        cout << "NO" << endl;
        return 0;
    }
    
    bfs(si, sj);
    
    if (level[di][dj] != -1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
