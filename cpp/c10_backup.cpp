#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int n, answer = 0;
pair<int, int> *info;

struct Disjoint_Set {
    vector<int> parent, rank;
    Disjoint_Set (int n) : parent(n), rank(n,1) {
        for (int i=0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int u) {
        if (u == parent[u]) return u;

        return parent[u] = find(parent[u]);
    }
    
    void merge (int u, int v) {
        u = find(u); v = find(v);
        
        if (u == v) return;
        
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) ++rank[v];
    }
};

void print_info() {
    cout << endl << "info::::" << endl;
    for (int i = 0; i < n; i++) {
        cout << info[i].first << ", " << info[i].second << endl;
    }
}

int main() {
    cin >> n;

    info = new pair<int, int>[n];
    Disjoint_Set disj_set(n);

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        info[i] = make_pair(x, y);
    }

    sort(info, info + n);

    // print_info();
    
    for (int curr = 1; curr < n; curr++) {
        for (int comp = curr - 1; comp >= 0; comp--) {
            long long x_dist = info[curr].first - info[comp].first;
            long long y_dist = info[curr].second - info[comp].second;
            if (x_dist <= 5) {
                if (pow(x_dist, 2) + pow(y_dist, 2) <= 25) {
                    disj_set.merge(curr, comp);
                    
                }
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << disj_set.parent[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << disj_set.rank[i] << " ";
    }
    cout << endl;
    
    // int last_rank = 0;

    // for (int j = 0; j < n; j++) {
    //     int curr_rank = disj_set.rank[j];
    //     if (curr_rank > last_rank) {
    //         answer += (curr_rank / 2);
    //     }
    //     last_rank = curr_rank;
    // }


    cout << answer << endl;

    delete[] info;
    return 0;
}