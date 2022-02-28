#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, k, answer;
long *info, min_dist = 1e9, max_dist;

int dist_check(long dist) {
    int pole_cnt = 1, last_idx = 0, idx = 0;
    int is_possible = 1;

    while (idx < n-1) {
        idx++;
        if (info[last_idx] + dist <= info[idx]) {
            last_idx = idx;
            pole_cnt++;
            if (pole_cnt == k)
                break;
        }
    }

    if (pole_cnt < k)
        is_possible = 0;

    return is_possible;
}

void binary_search(long min_dist, long max_dist) {
    if (min_dist > max_dist) return;

    long mid = (min_dist + max_dist) / 2;
 
    if (dist_check(mid) == 0) {
        return binary_search(min_dist, mid - 1);
    } else {
        answer = mid;
        return binary_search(mid + 1, max_dist);
    }
}

int main() {
    cin >> n >> k;

    info = new long[n];

    for (int i = 0; i < n; i++) {
        cin >> info[i];

        if (i > 0)
            min_dist = min(min_dist, abs(info[i] - info[i-1]));
    }

    sort(info, info + n);

    max_dist = (info[n-1] - info[0]) / (k - 1);

    binary_search(min_dist, max_dist);

    cout << answer << endl;

    delete[] info;
    return 0;
}