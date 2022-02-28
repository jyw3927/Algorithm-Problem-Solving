#include <iostream>
#include <algorithm>
using namespace std;

int n, d, m, bulldozer, bulldozer_cnt = 1;
int *info;

int main() {
    cin >> n >> d >> m;

    info = new int[m+1];

    for (int x = 1; x <= m; x++) {
        cin >> info[x];
        if (info[x] + d <= n) {
            info[x] += d;
        } else {
            info[x] = n;
        }
    }

    sort(info + 1, info + m + 1);

    // for (int x = 1; x <= m; x++) {
    //     cout << info[x] << " ";
    // }
    // cout << endl;

    bulldozer_cnt = (m / n);
    if ((m % n) > 0)
        bulldozer_cnt ++;

    for (int i = 1; i <= m; i++) {
        while (true) {
            bulldozer = i / bulldozer_cnt;
            if (i % bulldozer_cnt > 0)
                bulldozer++;

            if (info[i] < bulldozer) {
                bulldozer_cnt++;
            } else if (bulldozer > n) {
                bulldozer_cnt++;
            } else {
                break;
            }
        }
    }
    cout << bulldozer_cnt << endl;

    delete[] info;

    return 0;
}