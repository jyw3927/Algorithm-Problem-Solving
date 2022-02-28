#include <iostream>
#include <algorithm>

using namespace std;
#define INF 1e9

int n, k, min_val, answer = 0;
int *info, *selected;

void choose_k(int idx, int curr) {
	if (idx == k - 1) {
        min_val = INF;
        for (int x = 1; x < k; x++) {
            min_val = min(min_val, selected[x] - selected[x-1]);
            if (min_val < answer)
                break;
        }
        answer = max(answer, min_val);

		return;
	}
 
	for (int i = curr; i < n - 1; ++i) {
		selected[idx] = info[i];
		choose_k(idx + 1, i + 1);
	}
}

int main() {
    cin >> n >> k;

    info = new int[n];
    selected = new int[k];

    for (int i = 0; i < n; i++)
        cin >> info[i];

    sort(info, info + n);

    selected[0] = info[0];
    selected[k-1] = info[n-1];
    choose_k(1, 1);

    cout << answer << endl;

    delete[] info;
    delete[] selected;

    return 0;
}