#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, d, answer;
int **well;
pair<double, double> *info;
vector< vector< pair<double, double> > > overlapped_range(n);

void range_cmp(int idx1, int idx2) {
    for (int i = 0; i < overlapped_range[idx1].size(); i++) {
        for (int j = 0; j < overlapped_range[idx2].size(); j++) {
            if (overlapped_range[idx1][i].first < overlapped_range[idx2][j].first && overlapped_range[idx1][i].second > overlapped_range[idx2][j].first) {
                
            } else {
                
            }
        }
    }
}

int get_well_cnt() {
    while(overlapped_range.size() != 1) {
        for (int i = 0; i < overlapped_range.size()-1; i++) {
            range_cmp(i, i+1);
        }
        overlapped_range.pop_back();
    }

    return overlapped_range[0].size();
}

int main() {
    cin >> n >> d;

    info = new pair<double, double>[n];
    well = new int*[n];
    for (int row = 0; row < n; row++) {
        well[row] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        double x, y, dist, start, end;
        cin >> x >> y;

        if (y == d) {
            start = end = x;
        } else {
            dist = sqrt(pow(d, 2) - pow(y, 2));
            start = x - dist;
            end = x + dist;
        }

        info[i] = make_pair(start, end);
    }

    sort(info, info + n);

    for (int j = 0; j < n; j++) {
        overlapped_range[j].push_back(info[j]);
    }

    answer = get_well_cnt();

    // for (int a = 0; a < n; a++) {
    //     for (int b = 0; b < overlapped_range[a].size(); b++) {
    //         cout << overlapped_range[a][b].first << " " << overlapped_range[a][b].second << endl;
    //         // cout << well[a][b] << " ";
    //     }
    //     // cout << endl;
    // }


    cout << answer << endl;

    return 0;
}