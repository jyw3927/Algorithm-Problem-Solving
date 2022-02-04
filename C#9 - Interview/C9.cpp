#include <iostream>
#include <vector>
using namespace std;

int n;
vector< vector< pair<int, int> > > group_list;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        vector<int> group_to_combine;

        cin >> x >> y;

        if (group_list.size() == 0) {
            group_list.push_back(vector< pair<int, int> >());
            group_list[0].push_back(make_pair(x, y));
        } else {
            group_to_combine.clear();

            for (int group = 0; group < group_list.size(); group++) {
                for (int applicant = 0; applicant < group_list[group].size(); applicant++) {
                    if (x > group_list[group][applicant].first && y < group_list[group][applicant].second) {
                        group_to_combine.push_back(group);
                        break;
                    } else if (x < group_list[group][applicant].first && y > group_list[group][applicant].second) {
                        group_to_combine.push_back(group);
                        break;
                    }
                }
            }

            int size = group_to_combine.size();

            if (size == 0) {
                group_list.push_back(vector< pair<int, int> >());
                group_list.back().push_back(make_pair(x, y));
            } else if (size == 1) {
                group_list[group_to_combine[0]].push_back(make_pair(x, y));
            } else if (size > 1) {
                for (int b = size-1; b >= 1; b--) {
                    group_list[group_to_combine[0]].insert(group_list[group_to_combine[0]].end(), group_list[group_to_combine[b]].begin(), group_list[group_to_combine[b]].end());
                    group_list.erase(group_list.begin() + group_to_combine[b]);
                }
                group_list[group_to_combine[0]].push_back(make_pair(x, y));
            }
        }
    }
    cout << group_list.size() << endl;

    return 0;
}