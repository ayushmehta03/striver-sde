#include <iostream>
#include <vector>
using namespace std;

bool isIdentityMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    
    for (int i = 0; i < n; i++) {
        if (mat[i].size() != n) return false; 
        
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (mat[i][j] != 1) return false; 
            } else {
                if (mat[i][j] != 0) return false; 
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> mat = {{1, 0, 0}, 
                               {0, 1, 0}, 
                               {0, 0, 1}};

    if (isIdentityMatrix(mat)) cout << "yes";
    else cout << "no";

    return 0;
}