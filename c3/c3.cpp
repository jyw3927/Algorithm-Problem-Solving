#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9

int p, q, r, n, m;
int dist[40001];
int dist_sum[40001];
vector<pair<int, int> > adj_list[40001];
priority_queue<pair<int,int> >pq;

void dijkstra(int start, int fuel, bool is_united) {
    if (!is_united) {
        pq.push(make_pair(0, start));
        dist[start] = 0;
    } else {
        pq.push(make_pair(-dist_sum[start], start));
        pq.push(make_pair(-dist_sum[start+1], start+1));
        dist[start] = dist_sum[start];
        dist[start+1] = dist_sum[start+1];
    }
    
    while(!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();
        
        if (dist[cur_pos] < cur_dist)
            continue;

        for(int i = 0; i < adj_list[cur_pos].size(); i++) {
            int new_dist = cur_dist + (adj_list[cur_pos][i].second * fuel);

            if (new_dist < dist[adj_list[cur_pos][i].first]) {
                if (is_united) {
                    if (new_dist < dist_sum[adj_list[cur_pos][i].first]) {
                        dist[adj_list[cur_pos][i].first] = new_dist;
                        pq.push(make_pair(-new_dist, adj_list[cur_pos][i].first));
                    } else {
                        dist[adj_list[cur_pos][i].first] = dist_sum[adj_list[cur_pos][i].first];
                        pq.push(make_pair(-dist_sum[adj_list[cur_pos][i].first], adj_list[cur_pos][i].first));
                    }
                } else {
                    dist[adj_list[cur_pos][i].first] = new_dist;
                    pq.push(make_pair(-new_dist, adj_list[cur_pos][i].first));
                }
            }
        }
    }
}

int main() {
    cin >> p >> q >> r >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(make_pair(b, 1));
        adj_list[b].push_back(make_pair(a, 1));
    }
    
    fill(dist, dist + 40001, INF);
    dijkstra(1, p, false);
    for (int i = 1; i <= n; i++)
        dist_sum[i] += dist[i];

    fill(dist, dist + 40001, INF);
    dijkstra(2, q, false);
    for (int i = 1; i <= n; i++) {
        dist_sum[i] += dist[i];
        dist[i] = dist_sum[i];
    }

    fill(dist, dist + 40001, INF);
    dijkstra(1, r, true);
    
    cout << dist[n] << endl;
}