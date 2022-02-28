#include <iostream>
#include <algorithm>

using namespace std;
#define INF 1e9

int n, k, diff_sum = 0, answer = INF;
int *info, *diff;

int main() {
    cin >> n >> k;

    info = new int[n];
    diff = new int[n-1];

    for (int i = 0; i < n; i++)
        cin >> info[i];

    sort(info, info + n);

    for (int j = 1; j < n; j++) {
        diff[j-1] = info[j] - info[j-1];
        diff_sum += diff[j-1];
    }

    // print
    
    // for (int i = 0; i < n; i++) {
    //     cout << info[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n-1; i++) {
    //     cout << diff[i] << " ";
    // }
    // cout << endl << diff_sum << endl;


    int criteria = diff_sum / k;
    int sum = 0, cnt = 0;

    for (int idx = 0; idx < n-1; idx++) {
        if (cnt == k-2) {
            sum += diff[idx];
            if (idx == n-2) {
                answer = min(answer, sum);
            }
        } else {
            if (idx == n-2) {
                sum += diff[idx];
                answer = min(answer, sum);
            } else if (sum + diff[idx] - criteria < criteria - sum) {
                sum += diff[idx];
            } else {
                answer = min(answer, sum);
                cnt++;
                sum = 0;
            }
        }
    }




    cout << answer << endl;

    delete[] info;
    delete[] diff;

    return 0;
}