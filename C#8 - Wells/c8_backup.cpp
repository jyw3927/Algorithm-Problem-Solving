#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, d, answer;
int **well;
pair<double, double> *info;
vector< pair<double, double> > overlapped_range;
vector< pair<double, double> > last_overlapped_range;
bool repeat = true;

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
        overlapped_range.push_back(info[j]);
    }

    while (true) {
        for (int x = 0; x < overlapped_range.size()-1; x++) {
            if (overlapped_range[x].second > overlapped_range[x+1].first) {
                overlapped_range[x].first = overlapped_range[x+1].first;
                repeat = true; 
            } 
        }
    }
    
    // last_overlapped_range.push_back(info[0]);

    // while (repeat) {
    //     repeat = false;

    //     for (int j = 1; j < n; j++) {
    //         if (info[j].first < last_overlapped_range.back().second) {
    //             last_overlapped_range.back().first = info[j].first;
    //             answer--;
    //             repeat = true;
    //             break;
    //         } else {
    //             last_overlapped_range.push_back(info[j]);
    //         }
    //     }
    // }

    cout << answer << endl;

    return 0;
}
    