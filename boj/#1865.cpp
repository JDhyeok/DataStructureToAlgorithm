#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

#define N_MAX 501
#define INF 987654321

struct Edge {
    int start, dest;
    int cost;
    Edge(int a, int b, int c) :start(a), dest(b), cost(c) {}
};

int TC, N, M, W;
int dist[N_MAX];
vector<Edge> edges;

bool bellmanFord() {
    dist[1] = 0;

    for (int i = 1; i <= N - 1; i++) {
        // dist 업데이트를 N-1 번 반복하기
        for (int j = 0; j < edges.size(); j++) {
            int start = edges[j].start;
            int dest = edges[j].dest;
            int cost = edges[j].cost;

            dist[dest] = min(dist[dest], dist[start] + cost);
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        int start = edges[i].start;
        int dest = edges[i].dest;
        int cost = edges[i].cost;

        // 음의 사이클이 생긴다
        if (dist[start] + cost < dist[dest])
            return true;
    }

    // 음의 사이클이 없다
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;

        fill_n(dist, N_MAX, INF);
        edges.clear();

        int s, e, t;
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            edges.push_back(Edge(s,e,t));
            edges.push_back(Edge(e, s, t));
        }

        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;
            edges.push_back(Edge(s, e, -t));
        }

        if (bellmanFord()) // 음의 사이클이 생긴다 = 시간 줄어들 수 있다
            cout << "YES\n";
        else // 음의 사이클이 없다 = 시간 줄어들면서 돌아오기 불가능하다.
            cout << "NO\n";

    }

    return 0;
}
