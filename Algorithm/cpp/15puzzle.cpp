#include<bits/stdc++.h>
using namespace std;

int position(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                return n - i;
            }
        }
    }
    return -1;
}


int count_inv(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<int> res;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res.push_back(arr[i][j]);
        }
    }

    int count = 0;
    for(int i = 0; i < res.size(); i++) {
        if(res[i] == 0) continue;
        for(int j = i + 1; j < res.size(); j++) {
            if(res[i] > res[j] && res[j] != 0) count++;
        }
    }
    
    return count;
}

int main() {
	int n;
    cin >> n;
    vector<vector<int>> arr(n , vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }


    if(n % 2 == 1) {
        if(count_inv(arr) % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else {
        if(position(arr) % 2 == 1 && count_inv(arr) % 2 == 0) {
            cout << "YES" << endl;

        }
        else if(position(arr) % 2 == 0 && count_inv(arr) % 2 == 1) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }  
    return 0;
}
