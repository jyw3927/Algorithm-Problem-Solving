#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n;
vector< vector< pair<int, string> > > graph(26);
int in_degree[26] = {0, };
int out_degree[26] = {0, };
stack <string> shiritori;

int get_Eulerian_start() {
    bool is_Eulerian_circuit = true;
    bool is_Eulerian_trail = true;

    for (int i = 0; i < 26; i++) {
        if (in_degree[i] != out_degree[i])
            is_Eulerian_circuit = false;
            break;
    }

    if (is_Eulerian_circuit) {
        return 1;
    } else {
        int trail_start = -1;
        int trail_end = -1;

        for (int j = 0; j < 26; j++) {
            if (in_degree[j] != out_degree[j]) {
                if (trail_start < 0 && (in_degree[j] + 1) == out_degree[j]) {
                    trail_start = j;
                } else if (trail_end < 0 && in_degree[j] == (out_degree[j] + 1)) {
                    trail_end = j;
                } else {
                    is_Eulerian_trail = false;
                    break;
                }
            }
        }
        
        if (is_Eulerian_trail) return trail_start;
        else return -1;
    }
}

void dfs(int idx) {
    for (int i = graph[idx].size()-1; i >= 0; i--) {
        if (in_degree[graph[idx][i].first] != 0) {
            in_degree[graph[idx][i].first]--;
            graph[idx].pop_back();
            // 이 밑에 두개 바꾸면 제대로, 안바꾸면 거꾸로.
            shiritori.push(graph[idx][i].second);
            dfs(graph[idx][i].first);
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

        first_c = new_word[0];
        last_c = new_word[new_word.length()-1];

        in_degree[last_c - 97]++;
        out_degree[first_c - 97]++;
        
        graph[first_c - 97].push_back(make_pair(last_c - 97, new_word));
    }

    int start_point = get_Eulerian_start();

    if (start_point < 0) {
        cout << 0 << endl;
    } else {
        for (int j = 0; j < 26; j++)
            sort(graph[j].begin(), graph[j].end(), str_comp);

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