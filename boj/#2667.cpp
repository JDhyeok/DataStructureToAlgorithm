#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;

int WAY[4][2] = { {1, 0},{0, 1},{-1, 0},{0,-1} };

int bfs(vector<string>& map, int i, int j) {
    int num = 1, ni, nj;
    queue<pair<int, int>> q;

    q.push(make_pair(i,j));
    map[i][j] = '0';

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int w = 0; w < 4; w++) {
            ni = cur.first + WAY[w][0];
            nj = cur.second + WAY[w][1];

            if (ni < 0 || nj < 0 || ni >= N || nj >= N || map[ni][nj] == '0')
                continue;
            if (map[ni][nj] == '1') {
                q.push(make_pair(ni, nj));
                map[ni][nj] = '0';
                num++;
            }

        }
    }

    return num;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cnt = 0;
    string tmp;
    vector<string> map;
    vector<int> ans;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        map.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1') {
                ans.push_back(bfs(map, i, j));
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    sort(ans.begin(), ans.end());
    
    for (auto n : ans)
        cout << n << "\n";

    return 0;
}