#include <iostream>
using namespace std;

int n, group_cnt;
long long t, min_pos, *final_position;

int main() {
    cin >> n >> t;

    final_position = new long long[n];

    for (int i = 0; i < n; i++) {
        long long start_position, speed;

        cin >> start_position >> speed;

        final_position[i] = start_position + (t * speed);
    }

    min_pos = final_position[n-1];
    group_cnt = n;

    for (int prev = n-2; prev >= 0; prev--) {
        long long prev_pos = final_position[prev];

        if (min_pos <= prev_pos)
            group_cnt--;
        else
            min_pos = prev_pos;
    }

    cout << group_cnt << endl;

    delete[] final_position;
    return 0;
}