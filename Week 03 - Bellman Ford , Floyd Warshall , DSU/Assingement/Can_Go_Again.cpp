// // #include <bits/stdc++.h>
// // using namespace std;

// // class Edge {
// //     public:
// //     int a, b, c;
// //     Edge(int a, int b, int c) {
// //         this->a = a;
// //         this->b = b;
// //         this->c = c;
// //     }
// // };

// // const int INF = 1e9;
// // int dis[1005];

// // int main() {
// //     int n, e;
// //     cin >> n >> e;
    
// //     vector<Edge> edge_list;
// //     for (int i = 0; i < e; i++) {
// //         int a, b, c;
// //         cin >> a >> b >> c;
// //         edge_list.push_back(Edge(a, b, c));
// //     }
    
// //     int S;
// //     cin >> S;

// //     fill(dis, dis + n + 1, INF);
// //     dis[S] = 0;

// //     for (int i = 0; i < n - 1; i++) {
// //         for (auto ed : edge_list) {
// //             int a = ed.a, b = ed.b, c = ed.c;
// //             if (dis[a] != INF && dis[b] > dis[a] + c) {
// //                 dis[b] = dis[a] + c;
// //             }
// //         }
// //     }

// //     for (auto ed : edge_list) {
// //         int a = ed.a, b = ed.b, c = ed.c;
// //         if (dis[a] != INF && dis[b] > dis[a] + c) {
// //             cout << "Negative Cycle Detected" << endl;
// //             return 0;
// //         }
// //     }

// //     int T;
// //     cin >> T;
// //     while (T--) {
// //         int D;
// //         cin >> D;
// //         if (dis[D] == INF) {
// //             cout << "Not Possible" << endl;
// //         } else {
// //             cout << dis[D] << endl;
// //         }
// //     }

// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// class Edge {
//     public:
//     int a, b, c;
//     Edge(int a, int b, int c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }
// };

// int dis[1005];

// int main() {
//     int n, e;
//     cin >> n >> e;
    
//     vector<Edge> edge_list;
//     for (int i = 0; i < e; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         edge_list.push_back(Edge(a, b, c));
//     }
    
//     int s;
//     cin >> s;

//     for (int i = 0; i <= n; i++) {
//         dis[i] = INT_MAX;
//     }
//     dis[s] = 0;

//     for (int i = 0; i < n - 1; i++) {
//         for (auto ed : edge_list) {
//             int a = ed.a;
//             int b = ed.b;
//             int c = ed.c;
//             if (dis[a] != INT_MAX && dis[b] > dis[a] + c) {
//                 dis[b] = dis[a] + c;
//             }
//         }
//     }

//     for (auto ed : edge_list) {
//         int a = ed.a, b = ed.b, c = ed.c;
//         if (dis[a] != INT_MAX && dis[b] > dis[a] + c) {
//             cout << "Negative Cycle Detected" << endl;
//             return 0;
//         }
//     }

//     int t;
//     cin >> t;
//     while (t--) {
//         int d;
//         cin >>d;
//         if (dis[d] == INT_MAX) {
//             cout << "Not Possible" << endl;
//         } else {
//             cout << dis[d] << endl;
//         }
//     }

//     return 0;
// }











#include <bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int a, b;
    long long c;
    Edge(int a, int b, long long c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
long long dis[1005];
int main(){
    int n, e;
    cin >> n >> e;
    
    vector<Edge> edge_list;
    for(int i = 0; i < e; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    
    int s;
    cin >> s;

    for(int i = 0; i <= n; i++){
        dis[i] = LLONG_MAX;
    }
    dis[s] = 0;

    for(int i = 0; i < n - 1; i++){
        for(auto ed : edge_list){
            int a = ed.a;
            int b = ed.b;
            long long c = ed.c;
            if(dis[a] != LLONG_MAX && dis[b] > dis[a] + c){
                dis[b] = dis[a] + c;
            }
        }
    }

    for(auto ed : edge_list){
        int a = ed.a, b = ed.b;
        long long c = ed.c;
        if(dis[a] != LLONG_MAX && dis[b] > dis[a] + c){
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        if(dis[d] == LLONG_MAX){
            cout << "Not Possible" << endl;
        } 
        else{
            cout << dis[d] << endl;
        }
    }

    return 0;
}
