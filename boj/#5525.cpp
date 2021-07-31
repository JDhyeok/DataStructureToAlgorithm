#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string Pn = "I", S = "";
    char tmp;
    int N, M, ans = 0;
    bool isEqual = false;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        Pn += "OI";

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        S += tmp;
    }
    
    if (N > 499999)
    {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {

        if (S[i] == 'I') {
            cnt = 0;

            while (S[i + 1] == 'O' && S[i + 2] == 'I') {
                i += 2;
                cnt++;
                if (cnt == N) {
                    cnt--;
                    ans++;
                }

            }
        }
    }

    cout << ans;

    return 0;
}