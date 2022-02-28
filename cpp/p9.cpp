#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Cluster3 {
    int cell_1, cell_2, cell_3;
};

struct Cluster4 {
    int cell_1, cell_2, cell_3, cell_4;
};

int n, b, *weight, max_cluster_weight = 0;

int main() {
    vector<Cluster3> c3_vec;
    vector<Cluster4> c4_vec;
    Cluster3 c3;
    Cluster4 c4;

    cin >> n >> b;

    vector<int> adj_list[n+1];
    weight = new int[n+1];

    for (int i = 1; i <= n; i++) {
        int w;

        cin >> w;
        
        weight[i] = w;
    }

    for (int j = 0; j < b; j++) {
        int first, second;

        cin >> first >> second;
        adj_list[first].push_back(second);
        adj_list[second].push_back(first);
        max_cluster_weight = max(max_cluster_weight, (weight[first] + weight[second]));
    }

    for (int from = 1; from <= n; from++) {
        for (auto to : adj_list[from]) {
            if (from < to) {
                for (auto x : adj_list[from]) {
                    for (auto y : adj_list[to]) {
                        if (x == y) {
                            bool is_c4 = false;
                            int p;

                            for (auto c31 : adj_list[from]) {
                                for (auto c32: adj_list[to]) {
                                    for (auto c33: adj_list[x]) {
                                        if (c31 == c32 && c32 == c33) {
                                            p = c31;
                                            is_c4 = true;
                                        }
                                    }
                                }
                            }

                            if (is_c4) { 
                                c4.cell_1 = from;
                                c4.cell_2 = to;
                                c4.cell_3 = x;
                                c4.cell_4 = p;

                                c4_vec.push_back(c4);
                            } else {
                                c3.cell_1 = from;
                                c3.cell_2 = to;
                                c3.cell_3 = x;

                                c3_vec.push_back(c3);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int id = 0; id < c3_vec.size(); id++) 
        max_cluster_weight = max(max_cluster_weight, (weight[c3_vec[id].cell_1] + weight[c3_vec[id].cell_2] + weight[c3_vec[id].cell_3]));

    for (int id = 0; id < c4_vec.size(); id++)
        max_cluster_weight = max(max_cluster_weight, (weight[c4_vec[id].cell_1] + weight[c4_vec[id].cell_2] + weight[c4_vec[id].cell_3] + weight[c4_vec[id].cell_4]));

    cout << max_cluster_weight << endl;

    delete[] weight;
    return 0;
}