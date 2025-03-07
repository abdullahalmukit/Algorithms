#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat,0,sizeof(mat));  // er maddhome sob gulo value 0 kore dite pari
    // for(int i = 0 ; i<n; i++){
    //     for(int j = 0 ; j <n; j++ ){
    //         // mat[i][j] = 0;
    //         cout << mat [i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<n; j++){
            if(i==j){
                mat[i][j]= 1;
            }
        }
    }
    while(e--){
        int a , b;
        cin >> a >> b;
        mat[a][b] = 1;
    }

    for(int i = 0 ; i<n; i++){
        for(int j = 0 ; j <n; j++ ){
            // mat[i][j] = 0;
            cout << mat [i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Input:
5 5
0 1
0 2
3 0
1 3
3 4

*/