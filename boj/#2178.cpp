#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;


int N, M, ans = 987654321;
int visited[101][101] = { 0, };
int WAY[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void bfs(vector<string>& map) {
    int curi, curj, ni, nj;
    queue<pair<int, int>> q;

    q.push(make_pair(0,0));
    visited[0][0] = 1;

    while (!q.empty()) {
        curi = q.front().first;
        curj = q.front().second;
        q.pop();

        for (int w = 0; w < 4; w++) {
            ni = curi + WAY[w][0];
            nj = curj + WAY[w][1];

            if (ni < 0 || nj < 0 || ni >= N || nj >= M || map[ni][nj] == '0')
                continue;

            if (visited[ni][nj] != 0)
                continue;

            if (ni == N - 1 && nj == M - 1) {
                ans = visited[curi][curj] + 1;
                return;
            }

            visited[ni][nj] = visited[curi][curj] + 1;
            q.push(make_pair(ni, nj));
        }
    }

    return;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string numStr;
    vector<string> map;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> numStr;
        map.push_back(numStr);
    }

    bfs(map);

    cout << ans;
    
    return 0;
}