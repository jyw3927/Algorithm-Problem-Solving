#include <iostream>
#include <algorithm>
using namespace std;

int n, d, m, day_cnt, day_to_add = 0, bulldozer_cnt = 1;
int *early_due;

int main() {
    cin >> n >> d >> m;

    early_due = new int[m+1];

    for (int x = 1; x <= m; x++) {
        cin >> early_due[x];
    }

    sort(early_due + 1, early_due + m + 1);

    // for (int x = 1; x <= m; x++) {
    //     cout << early_due[x] << " ";
    // }
    // cout << endl;

    bulldozer_cnt = (m / n);
    if ((m % n) > 0)
        bulldozer_cnt++;

    for (int i = 1; i <= m; i++) {
        while (true) {
            int last_due = early_due[i] + d;
            if (last_due > n) {
                last_due = n;
            }

            day_cnt = i / bulldozer_cnt;
            if ((i % bulldozer_cnt) > 0)
                day_cnt++;
            
            // while(early_due[i] > day_cnt + day_to_add) {
            //     day_to_add++;
            // }
            day_cnt += day_to_add;
            

            if (last_due < day_cnt) {
                bulldozer_cnt++;
            // } else if (i != m && day_cnt == n) { // added
            } else if (day_cnt > n) {
                bulldozer_cnt++;
            } else if (early_due[i] > day_cnt) { // added
                day_to_add++;
            } else {
                cout << day_cnt << " ";
                break;
            }
        }
    }
    // cout << endl;
    // cout << day_to_add << " ";
    cout << bulldozer_cnt << endl;

    delete[] early_due;

    return 0;
}