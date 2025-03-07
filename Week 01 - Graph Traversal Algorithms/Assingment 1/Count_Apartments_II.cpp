#include <bits/stdc++.h>
using namespace std;

char graph[1001][1001];
bool vis[1001][1001];

vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int row, col;

bool valid(int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return false;
    } 
    else 
    {
        return true;
    }
}

int dfs(int sr, int sc) {
    vis[sr][sc] = true;
    int room_count = 1; 
    
    for (int i = 0; i < 4; i++) {
        int child_row = sr + direction[i].first;
        int child_col = sc + direction[i].second;

        if (valid(child_row, child_col) && !vis[child_row][child_col] && graph[child_row][child_col] == '.') {
            room_count += dfs(child_row, child_col);
        }
    }
    return room_count;
}

int main() {
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> graph[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    vector<int> apartment_sizes;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (graph[i][j] == '.') {
                if (!vis[i][j]) {
                    int apartment_size = dfs(i, j);
                    apartment_sizes.push_back(apartment_size);
                }
            }
        }
    }

    sort(apartment_sizes.begin(), apartment_sizes.end());

    if (apartment_sizes.empty()) {
        cout << 0 << endl;
    } 
    else {
        for (int size : apartment_sizes) {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
