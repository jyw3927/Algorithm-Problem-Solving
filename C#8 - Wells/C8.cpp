#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, d, idx = 0, well_cnt = 0;
int *overlapped_cnt;
pair<double, double> *info;
bool is_decreased;

int main() {
    cin >> n >> d;

    overlapped_cnt = new int[n];
    for (int a = 0; a < n; a++)
        overlapped_cnt[a] = 1;
    
    info = new pair<double, double>[n];

    for (int i = 0; i < n; i++) {
        double x, y, dist, start, end;
        cin >> x >> y;

        if (y == d) {
            start = end = x;
        } else {
            dist = sqrt(pow(d, 2) - pow(y, 2));
            start = x - dist;
            end = x + dist;
        }
        info[i] = make_pair(start, end);
    }

    sort(info, info + n);

    for (int j = 0; j < n-1; j++) {
        for (int k = j+1; k < n; k++) {
            if (info[k].first < info[j].second)
                overlapped_cnt[j]++;
            else
                break;
        }
    }

    while (idx < n) {
        is_decreased = false;

        for (int a = idx; a < idx + overlapped_cnt[idx]-1; a++) {
            if (overlapped_cnt[a+1] - overlapped_cnt[a] < 0) {
                idx = a+1;
                is_decreased = true;
                break;
            }
        }

        if (!is_decreased) {
            idx += overlapped_cnt[idx];
            well_cnt++;
        } 
    }

    cout << well_cnt << endl;

    delete[] overlapped_cnt;
    delete[] info;

    return 0;
}