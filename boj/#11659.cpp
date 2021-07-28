#include<iostream>

using namespace std;

int main() {
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, tmp;

    int cum[100002];
    
    cin >> N >> M;

    cum[0] = 0;
    for (int i = 0; i < N; i++) {

        cin >> tmp;

        cum[i + 1] = cum[i] + tmp;
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << cum[b] - cum[a - 1] << "\n";
    }

    return 0;
}