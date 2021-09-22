#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

#define MAX 100001
#define INF 987654321

int N, mid = INF;
priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

int insert(int tmp) {
    if (mid == INF) {
        mid = tmp;
        return mid;
    }

    if (mid > tmp) { // 중앙값 보다 작은 수가 왔을 때
        if (maxHeap.size() == minHeap.size()) { // 총 홀수개
            maxHeap.push(tmp);
            tmp = maxHeap.top();
            maxHeap.pop();

            minHeap.push(mid);
            mid = tmp;
        }
        else if (maxHeap.size() < minHeap.size()) { // 총 짝수개
            maxHeap.push(mid);
            maxHeap.push(tmp);
            mid = maxHeap.top();
            maxHeap.pop();
        }
    }
    else { // 중앙값 보다 큰 수가 왔을 때
        if (maxHeap.size() == minHeap.size()) { // 총 홀수개
            minHeap.push(tmp);
            minHeap.push(mid);
            mid = minHeap.top();
            minHeap.pop();
        }
        else if (maxHeap.size() < minHeap.size()) { // 총 짝수개
            minHeap.push(tmp);
            tmp = minHeap.top();
            minHeap.pop();

            maxHeap.push(mid);
            mid = tmp;
        }
    }

    return mid;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    int tmp;

    for (int i = 0; i < N; i++) {
        cin >> tmp;

        cout << insert(tmp) << "\n";
    }

    return 0;
}
