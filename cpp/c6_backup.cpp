#include <iostream>
#include <algorithm>
using namespace std;

int n, last_card, card_cnt = 0, answer = 0;
int info[50000][3];

void ascend_search() {
    int new_val = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (info[i][0] == info[j][0]) {
                info[i][1] = info[j][1];
            } else if (info[i][0] > info[j][0]) {
                new_val = info[j][1] + 1;

                if (new_val > info[i][1])
                    info[i][1] = new_val;
            }
        }
    }
}

void descend_search() {
    int new_val = 0;

    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if (info[i][0] > info[j][0]) {
                new_val = info[j][2] + 1;

                if (new_val > info[i][2])
                    info[i][2] = new_val;
            }
        }
    }
}

void get_answer() {
    for (int i = 0; i < n; i++)
        answer = max(answer, (info[i][1] + info[i][2]));
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << info[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n;

    for (int j = 0; j < n; j++) {
        cin >> info[j][0];
        info[j][1] = 1;
        info[j][2] = 0;
    }

    ascend_search();
    descend_search();

    // print();

    get_answer();

    cout << answer << endl;

    return 0;
}