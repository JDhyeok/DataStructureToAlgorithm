#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int WAY[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
int visited[21][21] = { 0 , }, N;

int bfs(int sea[][21], int i, int j) {
    
    bool edible = true;

    int ans = 0, dist = 0;
    int curi, curj;
    int sharkSize = 2, eatenFish = 0;

    queue<pair<int, int>> fishQ;
    queue<pair<int, int>> q;

    q.push(make_pair(i,j));
    visited[i][j] = 1;

    while (edible) {
        edible = false;
        while (!q.empty()) {
            curi = q.front().first;
            curj = q.front().second;
            q.pop();

            for (int w = 0; w < 4; w++) {
                int ni = curi + WAY[w][0];
                int nj = curj + WAY[w][1];

                if (ni < 0 || nj < 0 || ni >= N || nj >= N)
                    continue;

                if (sea[ni][nj] > sharkSize || visited[ni][nj])
                    continue;

                if (sea[ni][nj] < sharkSize && sea[ni][nj] != 0) {
                    fishQ.push(make_pair(ni, nj));
                    visited[ni][nj] = visited[curi][curj] + 1;
                    edible = true;

                    /*while (!q.empty()) q.pop();
                    q.push(make_pair(ni, nj));

                    sea[ni][nj] = 0;

                    ans += visited[curi][curj];
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                            visited[i][j] = 0;

                    visited[ni][nj] = 1;
                    eatenFish++;
                    if (eatenFish == sharkSize) {
                        sharkSize++;
                        eatenFish = 0;
                    }
                    break;*/
                }

                visited[ni][nj] = visited[curi][curj] + 1;
                q.push(make_pair(ni, nj));
            }
        }
        if (edible) {
            int fishI = fishQ.front().first;
            int fishJ = fishQ.front().second;
            fishQ.pop();

            while (!fishQ.empty()) {
                int nextI = fishQ.front().first;
                int nextJ = fishQ.front().second;
                fishQ.pop();

                if (visited[fishI][fishJ] == visited[nextI][nextJ]) {
                    if (nextI < fishI) {
                        fishI = nextI;
                        fishJ = nextJ;
                    }
                    else if (nextI == fishI && nextJ < fishJ) {
                        fishI = nextI;
                        fishJ = nextJ;
                    }

                }
                else {
                    while (!fishQ.empty()) fishQ.pop();
                }
            }
            
            q.push(make_pair(fishI, fishJ));
            sea[fishI][fishJ] = 0;
            ans += (visited[fishI][fishJ] - 1);

            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    visited[i][j] = 0;
            visited[fishI][fishJ] = 1;
            eatenFish++;
            if (eatenFish == sharkSize) {
                sharkSize++;
                eatenFish = 0;
            }
        }
    }

    return ans;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int sea[21][21] = { 0 , }, tmp;
    int start_x, start_y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            sea[i][j] = tmp;
            if (tmp == 9) {
                start_x = i;
                start_y = j;
                sea[i][j] = 0;
            }
        }
    }
    
    cout << bfs(sea, start_x, start_y);

    return 0;
}