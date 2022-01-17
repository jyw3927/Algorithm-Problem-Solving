#include <iostream>
#include <algorithm>
using namespace std;

int n, d, m, day_cnt = 1, day_to_add = 0, bulldozer_cnt = 1;
int *early_due, *day;
bool is_finished = false;

int main() {
    cin >> n >> d >> m;

    early_due = new int[m+1];
    day = new int[m+1];

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

    while (!is_finished) {
        for (int i = 1; i <= m; i++) {
            // for (int j = 0;)
        }   
    }

    cout << bulldozer_cnt << endl;

    delete[] early_due;

    return 0;
}