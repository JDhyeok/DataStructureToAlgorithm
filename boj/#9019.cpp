#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
memory : 2288 KB
time : 3960 ms
*/

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

/*********************** 다른 풀이 ***********************/
/*
memory : 2456 KB
time : 2832 ms
*/

int visited[10000] = { false, };
int q[100000] = { 0, };
int i = 0, j = 0;
int origin, dest;

int change(char order, int n) {
	int tmp = 0;
	switch (order) {
	case 'D':
		return (n * 2) % 10000;
	case 'S':
		if (n == 0)
			return 9999;
		return n - 1;
	case 'L':
		tmp = n / 1000;
		n = (n % 1000) * 10;
		return (n + tmp);
	case 'R':
		tmp = n % 10;
		n = n / 10;
		return (n + (tmp * 1000));
	}
}

string bfs() {
	queue<string> qOrder;

	qOrder.push("");
	q[j++] = origin;

	while (i < j) {
		int cur = q[i++];
		string curOrder = qOrder.front();
		qOrder.pop();
		int Dn = change('D', cur);
		if (Dn == dest)
			return curOrder + 'D';
		if (!visited[Dn]) {
			visited[Dn] = true;
			q[j++] = Dn;
			qOrder.push(curOrder + 'D');
		}

		int Sn = change('S', cur);
		if (Sn == dest)
			return curOrder + 'S';
		if (!visited[Sn]) {
			visited[Sn] = true;
			q[j++] = Sn;
			qOrder.push(curOrder + 'S');
		}

		int Ln = change('L', cur);
		if (Ln == dest)
			return curOrder + 'L';
		if (!visited[Ln]) {
			visited[Ln] = true;
			q[j++] = Ln;
			qOrder.push(curOrder + 'L');
		}

		int Rn = change('R', cur);
		if (Rn == dest)
			return curOrder + 'R';
		if (!visited[Rn]) {
			visited[Rn] = true;
			q[j++] = Rn;
			qOrder.push(curOrder + 'R');
		}
	}
	return "";
}

int main() {

	int T;

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> origin >> dest;
		i = 0; j = 0;
		fill_n(visited, 10000, false);
		fill_n(q, 100000, 0);
		cout << bfs() << "\n";
	}

	return 0;
}