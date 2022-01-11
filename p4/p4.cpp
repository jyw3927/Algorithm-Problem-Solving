#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define N_INF -2e9

int k_f, k_g;
pair<long long, long long> *buffer = new pair<long long, long long>[2000000];
vector< pair<long long, long long> > info;
long long p, q, answer = 0;

int main() {
    cin >> k_f;
    buffer[0] = make_pair(N_INF, 0);
    info.push_back(buffer[0]);
    for (int i = 1; i <= k_f; i++) {
        int point, value;
        cin >> point >> value;
        buffer[i] = make_pair(point, value);
    }

    cin >> k_g;
    for (int j = k_f+1; j <= k_f+k_g; j++) {
        int point, value;
        cin >> point >> value;
        buffer[j] = make_pair(point, value);
    }
    
    sort(buffer, buffer + k_f + k_g + 1);

    for (int i = 0; i <= k_f+k_g; i++) {
        if (buffer[i].second > info.back().second) {
            if (buffer[i].first == info.back().first) {
                info.pop_back();
                info.push_back(buffer[i]);
            } else {
                info.push_back(buffer[i]);
            }
        }
    }

    cin >> p >> q;

    long long matched_point = p;
    for (int i = 1; i < info.size(); i++) {
        long long point = info[i].first;
        long long prev_value = info[i-1].second;
        if (point >= p && point <= q) {
            answer += prev_value * (point - matched_point);
            matched_point = point;
        } else if (point > q) {
            answer += prev_value * (q - matched_point + 1);
            matched_point = q + 1;
            break;
        }
    }

    if (matched_point <= q)
        answer += info.back().second * (q - matched_point + 1);

    cout << answer%10007 << endl;

    return 0;
}