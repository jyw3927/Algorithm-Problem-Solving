#include <iostream>
#include <algorithm>
using namespace std;

int n, d, m, bulldozer, bulldozer_to_add = 0, bulldozer_cnt = 1;
int *early_due;

int main() {
    cin >> n >> d >> m;

    early_due = new int[m+1];

    for (int x = 1; x <= m; x++) {
        cin >> early_due[x];
        // if (early_due[x] + d <= n) {
        //     early_due[x] += d;
        // } else {
        //     early_due[x] = n;
        // }
    }

    sort(early_due + 1, early_due + m + 1);

    // for (int x = 1; x <= m; x++) {
    //     cout << early_due[x] << " ";
    // }
    // cout << endl;

    bulldozer_cnt = (m / n);
    if ((m % n) > 0)
        bulldozer_cnt ++;

    for (int i = 1; i <= m; i++) {
        while (true) {
            int last_due = early_due[i] + d;
            if (last_due > n) {
                last_due = n;
            }

            bulldozer = i / bulldozer_cnt;
            if (i % bulldozer_cnt > 0)
                bulldozer++;
            
            while(early_due[i] > bulldozer + bulldozer_to_add) {
                bulldozer_to_add++;
            }
            bulldozer += bulldozer_to_add;
            

            if (last_due < bulldozer) {
                bulldozer_cnt++;
            // } else if (i != m && bulldozer == n) { // added
            } else if (bulldozer > n) {
                bulldozer_cnt++;
            // } else if (early_due[i] > bulldozer) { // added
            //     bulldozer_to_add++;
            } else {
                // cout << bulldozer << " " << bulldozer_to_add << " " << bulldozer_cnt << endl;
                break;
            }
        }
    }
    // cout << endl;
    // cout << bulldozer_to_add << " ";
    cout << bulldozer_cnt << endl;

    delete[] early_due;

    return 0;
}