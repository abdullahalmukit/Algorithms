#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        int max1 = INT_MIN, max2 = INT_MIN;
        int maxInd1 = -1, maxInd2 = -1;
        
        for(int i = 0; i < n; i++){
            if(arr[i] > max1){
                max2 = max1;
                maxInd2 = maxInd1;
                max1 = arr[i];
                maxInd1 = i;
            }
            else if(arr[i] > max2 && arr[i] != max1){
                max2 = arr[i];
                maxInd2 = i;
            }
        }
        if (maxInd1 > maxInd2){
            swap(maxInd1, maxInd2);
        }
        cout << maxInd1 << " " << maxInd2 << endl;
    } 
    return 0;
}
