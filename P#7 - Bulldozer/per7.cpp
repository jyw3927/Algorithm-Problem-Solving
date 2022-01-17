#include <iostream>
#include <algorithm>
using namespace std;

int n, d, m, day_cnt, target, bulldozer_cnt = 0, answer;
int asdf;
int *early_due;
bool is_finished = false;

int main() {
    cin >> n >> d >> m;

    early_due = new int[m];

    for (int x = 0; x < m; x++) {
        cin >> early_due[x];
    }
    sort(early_due, early_due + m);
    int start = early_due[0];

    while(!is_finished) {
        bulldozer_cnt++;
        target = 0;

        for (int day_cnt = start; day_cnt <= n; day_cnt++) {
            for (int i = 0; i < bulldozer_cnt; i++) {
                if (day_cnt < early_due[target]) {
                    continue;
                } else if (day_cnt > (early_due[target] + d)) {
                    break;
                } else {
                    target++;

                    if (target > m-1) {
                        answer = bulldozer_cnt;
                        is_finished = true;
                        break;
                    }
                }
            }
        }
    }
    cout << answer << endl;

    delete[] early_due;

    return 0;
}