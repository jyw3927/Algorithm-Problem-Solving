#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, last_card, card_cnt = 0, answer = 0;
int info[50000][3];
vector<int> tmp;

void print_buf() {
    for (int i = 0; i < tmp.size(); i++) {
        cout << "   " << tmp[i] << " ";
    }
    cout << endl;
}

void ascend_search() {
    int left, right, mid, idx_to_change;
    for (int i = 0; i < n; i++) {
        left = 0;
        right = tmp.size() - 1;
        
        if (right < 0) {
            tmp.push_back(info[i][0]);
            idx_to_change = 0;
        } else {
            while (left <= right) {
                if (info[i][0] > tmp.back()) {
                    idx_to_change = right + 1;
                    break;
                } else if (info[i][0] < tmp.front()) {
                    idx_to_change = left;
                    break;
                }

                mid = (left + right) / 2;

                if (info[i][0] == tmp[mid]) {
                    idx_to_change = mid;
                    break;
                } else if (info[i][0] < tmp[mid]) {
                    if (info[i][0] > tmp[mid-1]) {
                        idx_to_change = mid;
                        break;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (info[i][0] < tmp[mid+1]) {
                        idx_to_change = mid + 1;
                        break;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            if (idx_to_change >= tmp.size())
                tmp.push_back(info[i][0]);
            else
                tmp[idx_to_change] = info[i][0];
        }
        // print_buf();
        info[i][1] += idx_to_change;
    }
}

void descend_search() {
    int left, right, mid, idx_to_change;
    for (int i = n-1; i >= 0; i--) {
        left = 0;
        right = tmp.size() - 1;
        
        if (right < 0) {
            tmp.push_back(info[i][0]);
            idx_to_change = 0;
        } else {
            while (left <= right) {
                if (info[i][0] > tmp.back()) {
                    idx_to_change = right + 1;
                    break;
                } else if (info[i][0] < tmp.front()) {
                    idx_to_change = left;
                    break;
                }

                mid = (left + right) / 2;

                if (info[i][0] == tmp[mid]) {
                    idx_to_change = mid;
                    break;
                } else if (info[i][0] < tmp[mid]) {
                    if (info[i][0] > tmp[mid-1]) {
                        idx_to_change = mid;
                        break;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (info[i][0] < tmp[mid+1]) {
                        idx_to_change = mid + 1;
                        break;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            if (idx_to_change >= tmp.size())
                {tmp.push_back(info[i][0]);
                cout << "added " << info[i][0] << endl;}
            else
                {tmp.insert(tmp.begin() + idx_to_change, info[i][0]);
                cout << "inserted " << info[i][0] << endl;}
        }
        print_buf();
        info[i][2] += idx_to_change;
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
    tmp.clear();
    descend_search();

    print();

    get_answer();

    cout << answer << endl;

    return 0;
}