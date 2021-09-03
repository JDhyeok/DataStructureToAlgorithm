# 이분탐색 알고리즘
## 개념
기존 선형탐색 O(N)에서 시간복잡도를 O(logN)까지 줄여주는 탐색 알고리즘

분할정복 기법(divided-conquer)을 사용해서 탐색한다. 단 해당 방법을 사용할 때 사전조건으로 배열은 항상 **sort 되어 있어야한다**.

## 소스코드
### CPP
```cpp
// Recursion를 사용한 Binary Search
int key; // 찾을 값
int arr[]; // 오름차순으로 정렬 되어있는 배열

void binarySearch(int l, int r)) {
    if(l < r) {
        // pivot값 으로 중앙값을 사용
        int mid = (l + r) / 2;

        if(arr[mid] == n) {
            cout << "검색 완료. key의 인덱스 : " << mid;
            return;
        }
        // 중앙값보다 key가 작으면 중앙값 왼쪽의 수에서 탐색하도록 한다.
        else if(arr[mid] > key) {
            binarySearch(l, mid);
        }
        // 중앙값보다 key가 크면 중앙값 오른쪽의 수에서 탐색하도록 한다.
        else if(){
            binarySearch(mid + 1, r);
        }
    }
}
```

```cpp
// Iteration을 사용한 Binary Search
int key; // 찾을 값
int arr[]; // 정렬 되어있는 배열

int main() {
    int l = 0, r = sizeof(arr);
    while(l <= r) {
        int mid = (l + r) / 2;

        if(arr[mid] == key){
            cout << "검색 완료. key의 인덱스 : " << mid;
            break;
        }
        // 중앙값보다 key가 작으면 중앙값 왼쪽의 수에서 탐색하도록 한다.
        else if(arr[mid] > key) {
            // 오른쪽 끝 인덱스를 mid - 1로 설정
            r = mid - 1;
        }
        // 중앙값보다 key가 크면 중앙값 오른쪽의 수에서 탐색하도록 한다.
        else if(arr[mid] < key) {
            // 왼쪽 끝 인덱스를 mid - 1로 설정
            l = mid + 1;
        }
    }
}

```