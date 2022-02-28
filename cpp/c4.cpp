#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, k, answer = 0;
vector<int> info[4];

int get_rod(int disk) {
    int rod_idx;

    for (int idx = 1; idx <= 3; idx++) {
        if (find(info[idx].begin(), info[idx].end(), disk) != info[idx].end()) {
            rod_idx = idx;
            break;
        }
    }
    return rod_idx;
}

void hanoi(int n, int from, int to) {
    if (n == 1) {
        answer++;
    } else if (from == to) {
        hanoi(n-1, get_rod(n-1), to);
    } else {
        answer++;
        answer += (pow(2, n-1) - 1);
        hanoi(n-1, get_rod(n-1), (6-from-to));
    }
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= 3; i++) {
        int disk_count = 0;
        cin >> disk_count;
        for (int j = 0; j < disk_count; j++) {
            int disk;
            cin >> disk;
            info[i].push_back(disk);
        }
    }
    hanoi(n, get_rod(n), k);

    cout << answer << endl;

    return 0;
}