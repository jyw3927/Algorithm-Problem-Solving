#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, answer = 100000;
int *conflict_cnt, **conflict;

int main() {
    cin >> n;
    cin >> m;

    conflict_cnt = new int[n+1];
    memset(conflict_cnt, 0, (n+1)*sizeof(int));
    conflict = new int*[n+1];
    for (int row = 0; row <= n; row++) {
        conflict[row] = new int[n+1];
        memset(conflict[row], 0, (n+1)*sizeof(int));
    }

    
    // cout << endl << "conflict" << endl;
    // for (int r = 1; r <= n; r++) {
    //     for (int c = 1; c <= n; c++) {
    //         cout << conflict[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    int max1 = 0, max2 = 0;
    bool is_found = false;

    for (int i = 1; i <= m; i++) {
        int first, second;

        cin >> first >> second;

        if (!is_found) {
            if (conflict[first][second] == 0) {
                conflict[first][second]++;
                conflict_cnt[first]++;
            }
            if (conflict[second][first] == 0) {
                conflict[second][first]++;
                conflict_cnt[second]++;
            }

            // if (conflict_cnt[first] > conflict_cnt[max1]) {
            //     max2 = max1;
            //     max1 = first;
            // } else if (conflict_cnt[first] < conflict_cnt[max1] && conflict_cnt[first] > conflict_cnt[max2]) {
            //     max2 = first;
            // }

            // if (conflict_cnt[second] > conflict_cnt[max1]) {
            //     max2 = max1;
            //     max1 = second;
            // } else if (conflict_cnt[second] < conflict_cnt[max1] && conflict_cnt[second] > conflict_cnt[max2]) {
            //     max2 = second;
            // }
            
            // if (conflict_cnt[max1] == n-1 && conflict_cnt[max2] > 1) {
            //     answer = i;
            //     is_found = true;
            // }
            for (int r = 1; r <= n; r++) {
                vector<int> conflicting_idx;
                for (int c = 1; c <= n; c++) {
                    if (conflict[r][c] == 1) {
                        conflicting_idx.push_back(c);
                    }
                }
                
            }
        }
    }
    // cout << "conflict_cnt" << endl;
    // for (int x = 0; x <= n; x++) {
    //     cout << conflict_cnt[x] << " ";
    // }
    // cout << endl;

    cout << answer << endl;

    delete[] conflict_cnt;
    for (int row = 0; row <= n; row++) {
        delete[] conflict[row];
    }

    return 0;
}