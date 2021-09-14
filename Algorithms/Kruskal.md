# 크루스칼 알고리즘 (Kruskal's Algorithm)
## 개념
### 최소 스패닝 트리 (Minimum Spanning Tree - MST)
스패닝 트리란 그래프의 모든 정점을 포함하는 **트리 형태의 서브 그래프**를 말한다. 여기서 서브 그래프 중에 간선의 가중치의 합이 최소인 경우를 **최소 스패닝 트리**라고 부른다.

해당 알고리즘인 **크루스칼 알고리즘은** 한 그래프에서 **최소 스패닝 트리를** 찾는 알고리즘이다.

### 크루스칼 알고리즘
**그리디**한 방법을 사용해 최소 스패닝 트리를 구한다. 다음 순서를 거치면 그래프의 최소 스패닝 트리를 구할 수 있다.

1. 간선을 가중치 오름차순으로 정렬한다. (모든 vertex들은 간선 없이 독립적으로 존재한다.)

2. 정렬된 간선 순서대로 선택한다.

3. 선택한 간선에 연결된 두 노드가 연결되어 있지 않은지 확인, Cycle이 있는지 확인하고 없으면 두 정점을 연결시킨다. (있다면 skip)

4. 위 step 2,3 을 반복하며 모든 간선을 순회한다. 최종적으로 만들어진 트리가 **최소 스패닝 트리**이다.

## 소스코드
### Cpp
```cpp
// union-find 알고리즘으로 cycle 찾음
//int find(int x){
//   x의 parent를 찾아주는 find 함수
//}

//void merge(int v1, int v2) {
//   v1, v2를 연결해주는 union함수
//}

struct Edge {
    int v1, v2;
    int cost;
};

vector<Edge> edges;

bool cmp(Edge a, Edge b){
    return a.cost < b.cost;
}

int kruskal(){
    // 가중치 오름차순 정렬
    sort(edges.begin(), edges.end(), cmp);

    for(auto e : edges) {
        // 두 vertex 합치면서 사이클 확인
        bool isCycle = false;
        if(find(e.v1) == find(e.v2))
            isCycle = true;

        // 사이클이 없다면 두 vertex 합치기
        if(!isCycle){
            merge(e.v1, e.v2);
        }
    }
}
```

### Kruskal의 정당성
귀류법으로 증명이 가능하다. 다음 가정이 부정인것을 증명하면 된다.
<br/>
<br/>
#### **(가정)** **크루스칼의 결과가 MST가 아니다**
<br/>
<br/>
크루스칼로 선택된 간선들의 그래프 = T

이 때 크루스칼 알고리즘 시작은 T에 간선이 없다. 알고리즘 진행에 따라 간선이 한 개씩 증가.
크루스칼이 끝났을 때 T는 스패닝 트리 이면서 MST가 아니다.

이제 크루스칼의 시작 시점의 T를 T-init이라 하고 끝났을 시점의 T를 T-last라고 하면 다음과 같은 명제는 참이다.

$$T_{init} \subset MST \quad AND \quad (T_{last}) \nsubseteq MST$$

T-init은 공집합이기 때문에 MST의 부분집합이 될 수 있었지만, T-last는 MST가 아닌 그냥 스패닝 트리이기 때문에 MST의 부분 그래프가 아니다.

따라서 알고리즘에서 선택되는 간선 중에 T가 MST의 부분 그래프를 못만들게 하는 어떤 간선 (u,v)가 존재해야 한다.

이제 위와 같은 간선 (u,v)가 존재함을 증명하면 가정을 입증할 수 있다.

정리하면, 크루스칼 진행과정에 T에 추가되는 간선 중에 MST를 불가능하게 하는 간선 (u,v)가 존재한다. 식으로

$$T_{init} \subset MST \quad AND \quad (T \cup (u,v)) \nsubseteq MST$$

이제 (u,v)를 선택하기 직전 부분 그래프로 가지는 MST 중 하나를 생각해 본다. 이 MST에서는 (u,v)가 직접 연결되어 있지 않고 간접적으로 연결되어 있다.

여기서 **(u,v)가 선택되었다? 는 이전의 간선을 모두 연결해도 u,v는 연결되지 않았다**는 뜻이다.

이 때, MST에 포함된 정렬된 간선 배열에서 (u,v)보다 뒤에 있던 간선을 삭제하고 (u,v)를 추가하면 스패닝 트리가 유지되고 현 MST보다 작은 MST인 트리가 완성된다.

즉, (u,v)를 추가해도 MST를 만족한다. 해당 **가정이 모순이다**를 증명이 됐다.



# Ref
https://www.weeklyps.com/entry/%ED%81%AC%EB%A3%A8%EC%8A%A4%EC%B9%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Kruskals-algorithm