#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9
using namespace std;

int n, k, min_val, answer = 0;
int *info;
bool *is_selected;

void choose_k(int idx, int cnt) {
    if (cnt == k) {
        int tmp = 100001;
        min_val = INF;
        for (int x = 0; x < n; x++) {
            if (is_selected[x]) {
                if (tmp > 100000) {
                    tmp = x;
                } else {
                    min_val = min(min_val, info[x] - info[tmp]);
                    if (min_val < answer)
                        return;
                    tmp = x;
                }
            }
        }
        answer = max(answer, min_val);

        return;
    }
 
    for (int i = idx; i < n; i++) {
        if (!is_selected[i]) {
            is_selected[i] = true;
            choose_k(i, cnt + 1);
            is_selected[i] = false;
        }
    }
}

int main() {
    cin >> n >> k;

    info = new int[n];
    is_selected = new bool[n];

    for (int i = 0; i < n; i++) {
        cin >> info[i];
        is_selected[i] = false;
    }
    sort(info, info + n);

    choose_k(0, 0);

    cout << answer << endl;

    delete[] info;
    delete[] is_selected;

    return 0;
}