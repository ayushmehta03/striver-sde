#include <iostream>
#include <vector>

using namespace std;

int main() {
    

    int r, c;
    if (!(cin >> r >> c)) return 0;

    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    bool first = true; 

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            if (!first) cout << " ";
            cout << matrix[top][i];
            first = false;
        }
        top++;

        for (int i = top; i <= bottom; ++i) {
            if (!first) cout << " ";
            cout << matrix[i][right];
            first = false;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                if (!first) cout << " ";
                cout << matrix[bottom][i];
                first = false;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                if (!first) cout << " ";
                cout << matrix[i][left];
                first = false;
            }
            left++;
        }
    }

    cout << "\n";
    return 0;
}