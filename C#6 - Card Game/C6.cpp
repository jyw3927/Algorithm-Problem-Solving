#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, answer = 0;
int info[50000][3];
vector<int> temp;

void ascend_search() {
    int left, right, mid, idx_to_change = 0;
    for (int i = 0; i < n; i++) {
        left = 0;
        right = temp.size() - 1;
        
        if (right < 0) {
            temp.push_back(info[i][0]);
            idx_to_change = 0;
        } else {
            while (left <= right) {
                if (info[i][0] > temp.back()) {
                    idx_to_change = right + 1;
                    break;
                } else if (info[i][0] < temp.front()) {
                    idx_to_change = left;
                    break;
                }

                mid = (left + right) / 2;

                if (info[i][0] == temp[mid]) {
                    idx_to_change = mid;
                    break;
                } else if (info[i][0] < temp[mid]) {
                    if (info[i][0] > temp[mid-1]) {
                        idx_to_change = mid;
                        break;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (info[i][0] < temp[mid+1]) {
                        idx_to_change = mid + 1;
                        break;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            if (idx_to_change >= static_cast<int>(temp.size()))
                temp.push_back(info[i][0]);
            else
                temp[idx_to_change] = info[i][0];
        }
        info[i][1] += idx_to_change;
    }
}

void descend_search() {
    int left, right, mid, idx_to_change = 0;
    for (int i = n-1; i >= 0; i--) {
        left = 0;
        right = temp.size() - 1;
        
        if (right < 0) {
            temp.push_back(info[i][0]);
            idx_to_change = 0;
        } else {
            while (left <= right) {
                if (info[i][0] > temp.back()) {
                    idx_to_change = right + 1;
                    break;
                } else if (info[i][0] < temp.front()) {
                    idx_to_change = left;
                    break;
                }

                mid = (left + right) / 2;

                if (info[i][0] == temp[mid]) {
                    idx_to_change = mid;
                    break;
                } else if (info[i][0] < temp[mid]) {
                    if (info[i][0] > temp[mid-1]) {
                        idx_to_change = mid;
                        break;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (info[i][0] < temp[mid+1]) {
                        idx_to_change = mid + 1;
                        break;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            if (idx_to_change >= static_cast<int>(temp.size()))
                temp.push_back(info[i][0]);
            else
                temp[idx_to_change] = info[i][0];
        }
        info[i][2] += idx_to_change;
    }
}

void get_answer() {
    for (int i = 0; i < n; i++)
        answer = max(answer, (info[i][1] + info[i][2]));
}

int main() {
    cin >> n;

    for (int j = 0; j < n; j++) {
        cin >> info[j][0];
        info[j][1] = 1;
        info[j][2] = 0;
    }

    ascend_search();
    temp.clear();
    descend_search();

    get_answer();

    cout << answer << endl;

    return 0;
}