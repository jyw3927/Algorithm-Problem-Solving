#include <iostream>
#include <map>
#include <algorithm>

#define INF 1e9
#define N_INF -1e9
using namespace std;

int k_f, k_g;
pair<long long, long long> *info = new pair<long long, long long>[2000000];
long long p, q, answer = 0;
long long saved_idx = INF, max_value;

long long get_first_max_value(long long point) {
    for (int i = 1; i <= k_f+k_g; i++) {
        if (point < info[i].first) {
            saved_idx = i-1;
            max_value = info[saved_idx].second;
            break;
        }
    }
    return max_value;
}

long long get_max_value(long long point) {
    if (point == info[saved_idx+1].first) {
        if (point == info[saved_idx+2].first) {
            saved_idx += 2;
            max_value = max(max_value, info[saved_idx].second);
        } else {
            saved_idx++;
            max_value = max(max_value, info[saved_idx].second);
        }
    }
    return max_value;
}

int main() {
    cin >> k_f;
    info[0] = make_pair(N_INF, 0);
    for (int i = 1; i <= k_f; i++) {
        int point, value;
        cin >> point >> value;
        info[i] = make_pair(point, value);
    }

    cin >> k_g;
    for (int j = k_f+1; j <= k_f+k_g; j++) {
        int point, value;
        cin >> point >> value;
        info[j] = make_pair(point, value);
    }

    sort(info, info+k_f+k_g+1);

    cin >> p >> q;

    // cout << "\ninfo:" << endl;
    // for (int i = 0; i <= k_f+k_g; i++) {
    //     cout << info[i].first << " " << info[i].second << endl;
    // }

    // cout << "\nanswer: "<< endl;
    answer += get_first_max_value(p);
    
    for (long long point = p+1; point <= q; point++) {
        answer += get_max_value(point);
        // cout << point << ": " << get_max_value(point) << endl;
    }

    cout << answer%10007 << endl;

    return 0;
}