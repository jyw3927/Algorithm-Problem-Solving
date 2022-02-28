#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n;
vector< vector< pair<int, string> > > adj_list(26);
int in_degree[26] = {0, };
int out_degree[26] = {0, };
stack<string> shiritori;

int get_Eulerian_start() {
    bool is_Eulerian_circuit = true;
    int circuit_start_point;

    for (int i = 0; i < 26; i++) {
        if (in_degree[i] != out_degree[i]) {
            is_Eulerian_circuit = false;
            break;
        } else {
            circuit_start_point = 0;
        }
    }

    if (is_Eulerian_circuit) {
        return circuit_start_point;
    } else {
        int trail_start_point = -1;
        int trail_end_point = -1;
        int start_cnt = 0, end_cnt = 0;

        for (int j = 0; j < 26; j++) {
            if (in_degree[j] != out_degree[j]) {
                if ((in_degree[j] + 1) == out_degree[j]) {
                    trail_start_point = j;
                    start_cnt++;
                } else if (in_degree[j] == (out_degree[j] + 1)) {
                    trail_end_point = j;
                    end_cnt++;
                } else {
                    trail_start_point = -1;
                    break;
                }
            }
        }

        if (start_cnt != 1 || end_cnt != 1)
            trail_start_point = -1;

        return trail_start_point;
    }
}

void dfs(int idx) {
    for (int i = adj_list[idx].size()-1; i >= 0; i--) {
        pair<int, string> curr = adj_list[idx][i];
        if (in_degree[curr.first] > 0) {
            in_degree[curr.first]--;
            adj_list[idx].pop_back();
            dfs(curr.first);
            shiritori.push(curr.second);
        }
    }
}

bool str_comp(pair<int, string> &first_pair, pair<int, string> &second_pair) {
    return first_pair.second > second_pair.second;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string new_word;
        int first_c, last_c;

        cin >> new_word;

        first_c = new_word[0] - 97;
        last_c = new_word[new_word.length()-1] - 97;

        in_degree[last_c]++;
        out_degree[first_c]++;
        
        adj_list[first_c].push_back(make_pair(last_c, new_word));
    }

    for (int j = 0; j < 26; j++)
        sort(adj_list[j].begin(), adj_list[j].end(), str_comp);

    int start_point = get_Eulerian_start();

    if (start_point < 0) {
        cout << 0 << endl;
    } else {
        dfs(start_point);

        if (shiritori.size() != n) {
            cout << 0 << endl;
        } else {
            while(!shiritori.empty()) {
                cout << shiritori.top() << endl;
                shiritori.pop();
            }
        }
    }

    return 0;
}