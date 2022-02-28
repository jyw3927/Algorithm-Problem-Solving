#include <iostream>
#include <algorithm>
#define MAX_SIZE 100000
using namespace std;

int m;
int info_count = 0, carrier_count = 0;
int next_idx;
int* info;

int main() {
    cin >> m;

    info = new int[MAX_SIZE];

    while (1) {
        cin >> info[info_count];
        info_count++;
        carrier_count++;

        if (cin.eof()) {
            cin.clear();
            info_count--;
            carrier_count--;
            break;
        }
    }
    sort(info, info+info_count);

    next_idx = info_count - 1;

    for (int i = 0; i < info_count; i++) {
        for (int j = next_idx; j > i; j--) {
            if (info[i] + info[j] <= m) {
                next_idx = j-1;
                carrier_count--;
                break;
            }
        }
    }
    cout << carrier_count << endl;

    return 0;
}
