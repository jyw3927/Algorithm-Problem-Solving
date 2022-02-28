#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, answer = 0;
int **conflict;

int main() {
    cin >> n;
    cin >> m;

    conflict = new int*[n+1];
    for (int row = 0; row <= n; row++) {
        conflict[row] = new int[n+1];
        memset(conflict[row], 0, (n+1)*sizeof(int));
    }

    
    
    int max1 = 0, max2 = 0;
    bool is_found = false;

    for (int i = 1; i <= m; i++) {
        int first, second;

        cin >> first >> second;

        if (!is_found) {
            for (int j = 1; j <= n; j++) {
                if (conflict[first][j] == 1) {
                    if (conflict[second][j] != 0) {
                        answer = i;
                        is_found = true;
                        break;
                    }
                }

                if (conflict[second][j] > 1) {
                    if (conflict[first][j] != 0) {
                        answer = i;
                        is_found = true;
                        break;
                    }
                }
            }
        
            conflict[first][second]++;
            conflict[second][first]++;
            

            cout << "conflict" << endl;
            for (int r = 1; r <= n; r++) {
                for (int c = 1; c <= n; c++) {
                    cout << conflict[r][c] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    cout << answer << endl;

    for (int row = 0; row <= n; row++) {
        delete[] conflict[row];
    }

    return 0;
}