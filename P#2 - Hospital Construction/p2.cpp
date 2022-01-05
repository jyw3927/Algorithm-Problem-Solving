#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, answer = 0, max_val = 0, last_idx = 0;
vector<pair<long long, int> > input;
long long **info;

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        long long point;
        int people;

        cin >> people >> point;

        input.push_back(make_pair(point, people));
    }
    sort(input.begin(), input.end());

    info = new long long*[n];
    for(long long i = 0; i < n; ++i) {
        info[i] = new long long[2];
    }

    for (int a = 0; a < n; a++) {
        info[a][0] = input[a].first;
        info[a][1] = input[a].second;
    }

    for (int x = 0; x < n; x++) {
        if (info[x][0] - info[0][0] <= 2*k) {
            max_val += info[x][1];
            last_idx = x;
        } else {
            break;
        }
    }
    answer = max_val;

    for (int y = 1; y < n; y++) {
        if (last_idx == n-1)
            break;

        max_val -= info[y-1][1];
        
        while((info[last_idx+1][0] - info[y][0]) <= 2*k) {
            max_val += info[last_idx+1][1];
            last_idx++;
            if (last_idx == n-1)
                break;
        }

        if (max_val > answer)
            answer = max_val;
    }

    cout << answer << endl;
    
    return 0;
}