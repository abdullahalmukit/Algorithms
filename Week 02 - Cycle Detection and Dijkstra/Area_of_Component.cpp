#include <bits/stdc++.h>
using namespace std;

int n, m;
bool vis[105][105];
vector<pair<int, int>> p = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char grid[105][105];

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.');
}

int bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int area = 0;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        area++;

        for (int i = 0; i < 4; i++) {
            int ci = par_i + p[i].first;
            int cj = par_j + p[i].second;
            if (valid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }

    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int min_area = INT_MAX;
    bool component_found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                component_found = true;
                int area = bfs(i, j);
                min_area = min(min_area, area);
            }
        }
    }

    cout << (component_found ? min_area : -1) << endl;

    return 0;
}
