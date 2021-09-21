#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

int clocks[4];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++)
        cin >> clocks[i];

    int minClock = 10000;

    for (int i = 0; i < 4; i++) {
        int tmp = clocks[i] * 1000 + clocks[(i + 1) % 4] * 100 + clocks[(i + 2) % 4] * 10 + clocks[(i + 3) % 4];
        minClock = min(minClock, tmp);
    }
    
    int cnt = 0;
    for (int i = 1111; i <= minClock; i++) {
        int tmp = 0, num = 10000;
        clocks[0] = i / 1000;
        clocks[1] = i / 100 % 10;
        clocks[2] = i / 10 % 10;
        clocks[3] = i % 10;

 

        for (int j = 0; j < 4; j++) {
            tmp = clocks[j] * 1000 + clocks[(j + 1) % 4] * 100 + clocks[(j + 2) % 4] * 10 + clocks[(j + 3) % 4];
            num = min(num, tmp);
        }
        
        if (i == num)
            cnt++;
    }


    cout << cnt << "\n";

    return 0;
}
