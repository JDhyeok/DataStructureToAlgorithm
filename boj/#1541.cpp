#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

/*** 메모리 비효율적인 코드 ***/
int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    queue<string> q;
    queue<int> numsQ;
    string exp;
    string numStr;

    cin >> exp;

    for (int i = 0; i < exp.size(); i++) {
        numStr.clear();
        while ('0' <= exp[i] && exp[i] <= '9') {
            numStr += exp[i];
            i++;
        }
        q.push(numStr);
        if (exp[i] == '+')
            q.push("+");
        else if(exp[i] == '-')
            q.push("-");
    }
    int num = 0;

    while (!q.empty()) {
        if (q.front() == "+") {

        }
        else if (q.front() == "-") {
            numsQ.push(num);
            num = 0;
        }
        else {
            num += stoi(q.front());
        }
        if (q.size() == 1)
            numsQ.push(num);
        q.pop();
    }


    int ans = numsQ.front();
    numsQ.pop();

    while (!numsQ.empty()) {
        ans -= numsQ.front();
        numsQ.pop();
    }

    cout << ans;

    return 0;
}