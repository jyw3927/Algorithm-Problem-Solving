#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9

int n, tmp = 0, answer;
int *part_sum, **cable_table;
int cnt = 0;

int cable(int start, int end) {
    if (cable_table[start][end] == INF) {
        int new_val, min_val = INF;
        
        if (end - start < 1) {
            min_val = 0;
        } else if (end - start == 1) {
            min_val = part_sum[end] - part_sum[start-1];
        } else {
            for (int i = 0; i <= end-start-1; i++) {
                cnt++;
                new_val = cable(start, start+i) + cable(start+i+1, end);
                if (new_val < min_val)
                    min_val = new_val;
            }
            min_val += (part_sum[end] - part_sum[start-1]);
        }
        cable_table[start][end] = min_val;
    }

    return cable_table[start][end];
}

int main() {
    cin >> n;

    part_sum = new int[n+1];
    part_sum[0] = 0;

    cable_table = new int*[n+1];
    for (int row = 0; row <= n; row++) {
        cable_table[row] = new int[n+1];
    }

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;

        tmp += input;
        part_sum[i] = tmp;
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            cable_table[a][b] = INF;
        }
    }

    answer = cable(1, n);

    cout << answer << endl;
    cout << cnt << endl;

    delete[] part_sum;
    for (int row = 0; row <= n; row++) {
        delete[] cable_table[row];
    }

    return 0;
}

