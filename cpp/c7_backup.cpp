#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, answer = 100000;
// int **conflict;
int conflict[3][10001];
vector< pair <int, int> > saved_conflict;
bool is_found = false;

int main() {
    cin >> n;
    cin >> m;

    // conflict = new int*[3];
    // for (int row = 0; row < 3; row++) {
    //     conflict[row] = new int[n+1];
    //     memset(conflict[row], 0, (n+1)*sizeof(int));
    // }

    
    // cout << endl << "conflict" << endl;
    // for (int r = 1; r <= n; r++) {
    //     for (int c = 0; c < 3; c++) {
    //         cout << conflict[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    int first_num1, first_num2;
    cin >> first_num1 >> first_num2;
    conflict[0][first_num1] = conflict[1][first_num2] = 1;

    for (int x = 0; x < 3; x++) {
        for (int y = 1; y <= n; y++) {
            cout << conflict[x][y] << " ";
        }
        cout << endl;
    }

    for (int i = 2; i <= m; i++) {
        int num1, num2;

        cin >> num1 >> num2;

        if (!is_found) {
            if (conflict[0][num1] > 0 && conflict[0][num2] > 0) {
                answer = i;
                is_found = true;
            } else if (conflict[1][num1] > 0 && conflict[1][num2] > 0) {
                answer = i;
                is_found = true;
            } else if (conflict[0][num1] == 0 && conflict[1][num1] == 0) {
                if (conflict[0][num2] == 0 && conflict[1][num2] == 0) {
                    conflict[2][num1] = conflict[2][num2] = 1;
                    saved_conflict.push_back(make_pair(num1, num2));
                    // for (int j = 0; j < saved_conflict.size(); j++) {
                    //     cout << saved_conflict[j].first << " " << saved_conflict[j].second << endl;
                    // }
                } else if (conflict[0][num2] > 0) {
                    if (conflict[2][num1] > 0)
                        conflict[2][num1] = 0;
                    conflict[1][num1] = 1;
                } else if (conflict[1][num2] > 0) {
                    if (conflict[2][num1] > 0)
                        conflict[2][num1] = 0;
                    conflict[0][num1] = 1;
                }
            } else if (conflict[0][num2] == 0 && conflict[1][num2] == 0) {
                if (conflict[0][num1] == 0 && conflict[1][num1] == 0) {
                    conflict[2][num1] = conflict[2][num2] = 1;
                } else if (conflict[0][num1] > 0) {
                    if (conflict[2][num2] > 0)
                        conflict[2][num2] = 0;
                    conflict[1][num2] = 1;
                } else if (conflict[1][num1] > 0) {
                    if (conflict[2][num2] > 0)
                        conflict[2][num2] = 0;
                    conflict[0][num2] = 1;
                }
            }
            
            for (int j = 0; j < saved_conflict.size(); j++) {
                if (conflict[0][saved_conflict[j].first] > 0 && conflict[0][saved_conflict[j].second] > 0) {
                    answer = i;
                    is_found = true;
                }
            }
        }

        for (int x = 0; x < 3; x++) {
            for (int y = 1; y <= n; y++) {
                cout << conflict[x][y] << " ";
            }
            cout << endl;
        }
    }

    cout << answer << endl;

    // for (int row = 0; row <= n; row++) {
    //     delete[] conflict[row];
    // }

    return 0;
}