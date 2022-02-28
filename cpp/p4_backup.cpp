#include <iostream>
#include <map>
#define INF 1e9
#define N_INF -1e9
using namespace std;

int k_f, k_g;
pair<long long, long long> *info_f, *info_g;
long long p, q, answer = 0;
long long saved_idx_f = INF, saved_idx_g = INF, max_value;

long long get_max_value(long long point, bool is_f) {
    if (is_f) {
        if (saved_idx_f == INF) {
            for (int i = 1; i <= k_f; i++) {
                if (point < info_f[i].first) {
                    saved_idx_f = i-1;
                    max_value = info_f[saved_idx_f].second;
                    break;
                }
            }
        } else {
            if (point == info_f[saved_idx_f+1].first) {
                saved_idx_f++;
                max_value = info_f[saved_idx_f].second;
            } else {
                max_value = info_f[saved_idx_f].second;
            }
        }
    } else {
        if (saved_idx_g == INF) {
            for (int j = 1; j <= k_g; j++) {
                if (point < info_g[j].first) {
                    saved_idx_g = j-1;
                    max_value = info_g[saved_idx_g].second;
                    break;
                }
            }
        } else {
            if (point == info_g[saved_idx_g+1].first) {
                saved_idx_g++;
                max_value = info_g[saved_idx_g].second;
            } else {
                max_value = info_g[saved_idx_g].second;
            }
        }
    }
    return max_value;
}

int main() {
    cin >> k_f;
    info_f = new pair<long long, long long>[k_f+1];
    info_f[0] = make_pair(N_INF, 0);
    for (int i = 1; i <= k_f; i++) {
        int point, value;
        cin >> point >> value;
        info_f[i] = make_pair(point, value);
    }

    cin >> k_g;
    info_g = new pair<long long, long long>[k_g+1];
    info_g[0] = make_pair(N_INF, 0);
    for (int j = 1; j <= k_g; j++) {
        int point, value;
        cin >> point >> value;
        info_g[j] = make_pair(point, value);
    }

    cin >> p >> q;

    cout << "\nanswer: "<< endl;
    for (long long point = p; point <= q; point++) {
        answer += max(get_max_value(point, true), get_max_value(point, false));
        cout << point << ": " << max(get_max_value(point, true), get_max_value(point, false)) << endl;
    }

    cout << answer << endl;

    return 0;
}