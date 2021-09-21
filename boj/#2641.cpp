#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

int N, M;
int shape[51];
int maker1[102], maker2[102];

bool isSame(vector<int> tmp) {

    bool same = false;

    for (int i = 0; i < N; i++) {
        if (maker1[i] != tmp[0])
            continue;

        for (int j = 0; j < N; j++) {
            if (tmp[j] == maker1[i + j])
                same = true;
            else {
                same = false;
                break;
            }
        }
        if (same)
            break;
    }

    if (same)
        return same;

    for (int i = 0; i < N; i++) {
        if (maker2[i] != tmp[0])
            continue;

        for (int j = 0; j < N; j++) {
            if (tmp[j] == maker2[i + j])
                same = true;
            else {
                same = false;
                break;
            }
        }
        if (same)
            break;
    }

    return same;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> shape[i];


    for (int i = 0; i < N * 2; i++) {
        maker1[i] = shape[i % N];
    }

    int reverseIndex = N * 2 - 1;
    for (int i = 0; i < N * 2; i++) {
        switch (maker1[i]) {
        case 1:
            maker2[reverseIndex] = 3;
            break;
        case 2:
            maker2[reverseIndex] = 4;
            break;
        case 3:
            maker2[reverseIndex] = 1;
            break;
        case 4:
            maker2[reverseIndex] = 2;
            break;

        }
        reverseIndex--;
    }

    cin >> M;

    vector<vector<int>> ans;
    vector<int> tmp;

    for (int i = 0; i < M; i++) {
        tmp.clear();
        int num;
        for (int j = 0; j < N; j++) {
            cin >> num;
            tmp.push_back(num);
        }

        if (isSame(tmp))
            ans.push_back(tmp);

    }

    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
