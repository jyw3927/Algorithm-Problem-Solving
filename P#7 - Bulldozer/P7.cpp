#include <iostream>
#include <algorithm>
using namespace std;

int n, d, m, day_cnt, target, bulldozer_cnt = 0, answer = 0;
int asdf;
int *early_due;
bool is_finished = false, is_break;

int main() {
    cin >> n >> d >> m;

    early_due = new int[m];

    for (int x = 0; x < m; x++)
        cin >> early_due[x];

    sort(early_due, early_due + m);

    while(!is_finished) {
        bulldozer_cnt++;
        target = 0;
        is_break = false;

        for (int day_cnt = 1; day_cnt <= n; day_cnt++) {
            for (int repeat = 1; repeat <= bulldozer_cnt; repeat++) {
                if (day_cnt < early_due[target]) {
                    continue;
                } else if (day_cnt > (early_due[target] + d)) {
                    is_break = true;
                    break;
                } else {
                    target++;

                    if (target == m) {
                        answer = bulldozer_cnt;
                        is_finished = true;
                        break;
                    }
                }
            }
            if (is_finished || is_break)
                break;
        }
    }

    cout << answer << endl;

    delete[] early_due;

    return 0;
}