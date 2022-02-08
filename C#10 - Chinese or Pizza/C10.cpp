#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n, answer = 0;
pair<int, int> info[50000];
vector<int> adj_list[50000];
int brand[50000];

void bfs(int start) {
    int brand_num, chinese_cnt = 0, pizza_cnt = 0;
    queue<int> q;
    q.push(start);
    brand[start] = 1;
    chinese_cnt++;
    
    while (!q.empty()) {
        int curr = q.front();
        brand_num = 3 - brand[curr];
        q.pop();

        for (int i = 0; i < adj_list[curr].size(); i++) {
            int curr_adj = adj_list[curr][i];
            if (brand[curr_adj] == 0) {
                q.push(curr_adj);
                brand[curr_adj] = brand_num;
                if (brand_num == 1) chinese_cnt++;
                else pizza_cnt++;
            }
        }
    }
    answer += min(chinese_cnt, pizza_cnt);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;
        info[i] = make_pair(x, y);
    }
    sort(info, info + n);

    for (int curr = 1; curr < n; curr++) {
        for (int comp = curr - 1; comp >= 0; comp--) {
            int x_dist = info[curr].first - info[comp].first;
            int y_dist = info[curr].second - info[comp].second;
            if (x_dist <= 5) {
                if (pow(x_dist, 2) + pow(y_dist, 2) <= 25) {
                    adj_list[curr].push_back(comp);
                    adj_list[comp].push_back(curr);
                }
            } else {
                break;
            }
        }
    }

    for (int idx = 0; idx < n; idx++) {
        if (brand[idx] == 0)
            bfs(idx);
    }

    cout << answer << endl;

    return 0;
}