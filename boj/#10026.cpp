#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int way[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int N;

void bfs(int x, int y, bool visited[][100], char grid[][100]) {
    queue<pair<int, int>> q;


    char curColor = grid[x][y];
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int w = 0; w < 4; w++) {
            int ni = i + way[w][0];
            int nj = j + way[w][1];

            if (ni < 0 || nj < 0 || ni >= N || nj >= N)
                continue;

            if (grid[ni][nj] == curColor && visited[ni][nj] == false) {
                q.push(make_pair(ni, nj));
                visited[ni][nj] = true;
            }
        }

    }
}

// R, G 같은색
void bfsRG(int x, int y, bool visitedRG[][100], char grid[][100]) {
    queue<pair<int, int>> q;


    char curColor = grid[x][y];
    if (curColor == 'G')
        curColor = 'R';
    q.push(make_pair(x, y));
    visitedRG[x][y] = true;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int w = 0; w < 4; w++) {
            int ni = i + way[w][0];
            int nj = j + way[w][1];

            if (ni < 0 || nj < 0 || ni >= N || nj >= N)
                continue;

            if (grid[ni][nj] == 'G')
                grid[ni][nj] = 'R';

            if (grid[ni][nj] == curColor && visitedRG[ni][nj] == false) {
                q.push(make_pair(ni, nj));
                visitedRG[ni][nj] = true;
            }
        }

    }

}

int main()
{

    bool visited[100][100] = { false };
    bool visitedRG[100][100] = { false };
    char grid[100][100];
    char color;

    cin >> N;
    
    char tmp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            grid[i][j] = tmp;
        }
    }

    int ans = 0;
    int ansRG = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == false) {
                bfs(i, j, visited, grid);
                ans++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visitedRG[i][j] == false) {
                bfsRG(i, j, visitedRG, grid);
                ansRG++;
            }
        }
    }



    cout << ans << " " << ansRG;

    return 0;
}
