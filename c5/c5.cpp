#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
#define MAX_ROW 9

int n, block_count = 0, row;
pair<int, int> h_w_info[6];
int info[6][5][5] = {0, };
int answer[MAX_ROW][MAX_ROW] = {0, };
int tmp[MAX_ROW][MAX_ROW] = {0, };
bool is_possible = false;

bool is_square(int num) {
  int root = (int)(sqrt((double)num)+0.5);
  return num == root * root;
}

bool insert_poly(int x, int y, int idx) {
    int height = h_w_info[idx].first;
    int width = h_w_info[idx].second;
    bool result = true;

    for (int col = 0; col <= row; col++)
        memset(tmp[col], 0, sizeof(int)*(row+1));

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (answer[x+i-1][y+j-1] != 0 && info[idx][i][j] != 0) {
                result = false;
                break;
            } else {
                tmp[x+i-1][y+j-1] = info[idx][i][j];
            }
        }
    }
    return result;
}

void polyomino(int block_idx) {
    int height = h_w_info[block_idx].first;
    int width = h_w_info[block_idx].second;
    int pos_row_idx = row + 1 - height;
    int pos_col_idx = row + 1 - width;

    for (int x = 1; x <= pos_row_idx; x++) {
        for (int y = 1; y <= pos_col_idx; y++) {
            for (int i = 1; i <= row; i++) {
                for (int j = 1; j <= row; j++) {
                    if (answer[i][j] >= block_idx) {
                        answer[i][j] = 0;
                    }
                }
            }
            if (insert_poly(x, y, block_idx)) {
                for (int a = 1; a <= row; a++) {
                    for (int b = 1; b <= row; b++) {
                        answer[a][b] += tmp[a][b];
                    }
                }
                if (block_idx == n)
                    is_possible = true;
                else
                    polyomino(block_idx+1);
            }
            if (is_possible)
            break;
        }
        if (is_possible)
            break;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int block, h, w;
        cin >> h >> w;

        h_w_info[i] = make_pair(h, w);

        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= w; k++) {
                cin >> block;
                
                if (block == 1) {
                    info[i][j][k] = block * i;
                    block_count++;
                }
            }
        }
    }

    if (is_square(block_count)) {
        row = sqrt(block_count);

        polyomino(1);

        if (is_possible) {
            for (int i = 1; i <= row; i++) {
                for (int j = 1; j <= row; j++) {
                    cout << answer[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "No solution possible" << endl;
        }
    } else {
        cout << "No solution possible" << endl;
    }
    
    return 0;
}