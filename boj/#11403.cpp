#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N;

bool bfs(bool graph[][101], int start, int end ) {
    if (graph[start][end])
        return true;

    bool visited[101] = { false, };
    queue<int> q;

    q.push(start);
    //visited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        

        if (cur == end && start != end)
            return true;
        else if (start == end) {
            if (visited[start]) {
                return true;
            }
        }

        for (int next = 0; next < N; next++) {

            if (graph[cur][next] && !visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int tmp;
    bool graph[101][101] = { false, };

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bfs(graph, i, j) << " ";
        }
        cout << "\n";
    }

    return 0;
}