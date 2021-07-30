#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visited[10000] = { false, };

int changeNum(char order, int num) {
    int tmp;

    switch (order) {
    case 'D':
        return (num * 2) % 10000;
    case 'S':
        if (num == 0)
            return 9999;
        return num - 1;
    case 'L':
        tmp = num / 1000;
        num = (num * 10) % 10000;
        return num + tmp;
    case 'R':
        tmp = num % 10;
        num = num / 10;
        return num + (tmp * 1000);
    }
}

string bfs(int orig, int dest) {
    
    visited[orig] = true;

    int nD, nS, nL, nR;
    string curOrder;
    //vector<char> curOrder;
    int curNum;

    queue<pair<string, int>> q;
    nD = changeNum('D', orig);
    nS = changeNum('S', orig);
    nL = changeNum('L', orig);
    nR = changeNum('R', orig);

    q.push(make_pair("D", nD));
    q.push(make_pair("S", nS));
    q.push(make_pair("L", nL));
    q.push(make_pair("R", nR));
    
    while (!q.empty()) {
        curOrder = q.front().first;
        curNum = q.front().second;
        q.pop();

        if (curNum == dest)
            return curOrder;

        nD = changeNum('D' ,curNum);

        if (!visited[nD]) {
            visited[nD] = true;
            q.push(make_pair(curOrder + 'D', nD));
        }

        nS = changeNum('S', curNum);
        if (!visited[nS]) {
            visited[nS] = true;
            q.push(make_pair(curOrder + 'S', nS));
        }

        nL = changeNum('L', curNum);
        if (!visited[nL]) {
            visited[nL] = true;
            q.push(make_pair(curOrder + 'L', nL));
        }

        nR = changeNum('R', curNum);
        if (!visited[nR]) {
            visited[nR] = true;
            q.push(make_pair(curOrder + 'R', nR));
        }

    }
    return "";
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, orig, dest;

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> orig >> dest;
        fill_n(visited, 10000, false);
        cout << bfs(orig, dest) << "\n";
    }

    return 0;
}