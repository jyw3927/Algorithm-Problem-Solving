#include <iostream>
#include <vector>

using namespace std;

int n, m, answer;
vector< vector< pair<int, int> > > group;

int main() {
    cin >> n >> m;

    for (int in = 0; in < m; in++) {
        int x, y, g_x_i = -1, g_x_j = -1, g_y_i = -1, g_y_j = -1;

        cin >> x >> y;

        for (int i = 0; i < group.size(); i++) {
            for (int j = 0; j < group[i].size(); j++) {
                if (x == group[i][j].first) {
                    g_x_i = i;
                    g_x_j = j;
                }

                if (y == group[i][j].first) {
                    g_y_i = i;
                    g_y_j = j;
                }
            }
        }

        if (g_x_i < 0 && g_y_i < 0) {
            vector< pair<int, int> > new_group;
            new_group.push_back(make_pair(x, 1));
            new_group.push_back(make_pair(y, 2));
            group.push_back(new_group);
        } else if (g_x_i >= 0 && g_y_i < 0) {
            group[g_x_i].push_back(make_pair(y, (3-group[g_x_i][g_x_j].second)));
        } else if (g_x_i < 0 && g_y_i >= 0) {
            group[g_y_i].push_back(make_pair(x, (3-group[g_y_i][g_y_j].second)));
        } else if (g_x_i >= 0 && g_y_i >= 0) {
            if (g_x_i == g_y_i) {
                if (group[g_x_i][g_x_j].second == group[g_y_i][g_y_j].second) {
                    answer = in+1;
                    break;
                }
            } else {
                if (group[g_x_i][g_x_j].second == group[g_y_i][g_y_j].second) {
                    for (int idx = 0; idx < group[g_y_i].size(); idx++) {
                        group[g_y_i][idx].second = 3 - group[g_y_i][idx].second;
                    }
                    group[g_x_i].insert(group[g_x_i].end(), group[g_y_i].begin(), group[g_y_i].end());
                    group.erase(group.begin() + g_y_i);
                } else {
                    group[g_x_i].insert(group[g_x_i].end(), group[g_y_i].begin(), group[g_y_i].end());
                    group.erase(group.begin() + g_y_i);
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}