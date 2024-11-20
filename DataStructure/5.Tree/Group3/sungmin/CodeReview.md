# 1991번
- 책 보면서 풀었다.
- 연결 트리를 만드는 과정이 어색했지만 익히면 할만 할 것 같았다.

# 9934번 
- 위의 문제랑 비슷했다. 
- 이진 트리라는 것을 알고 트리를 만들면 어렵지 않았다.

# 14244번 
- n개의 노드로 이루어지고, m개의 리프로 이루어진 트리를 만들기 위해서  

```
0 - 1 - 2 - 3   -4
                -5
                -6
                -7
                -8
```
이런 구조로 트리를 만들면 쉽게 할 수 있다.
- 코딩적인 센스가 좀 필요했다. 코드 자체는 되게 짧음.

# 1068번 
- 이진 트리가 아닐 때 노드를 다루는 방법에 대해 공부했음
- 리스트로 저장하다 보니 조금 헷갈리는 부분이 있었지만 금방 익숙해졌다.
- 그리고 지우는 과정을 귀납적으로 했는데 이 부분이 너무 어려워서 시간이 조금 걸렸다.
- 연결 구조를 확실하게 알아야 할 듯 하다.

# 1240번
- DFS 를 확실하게 공부 했어야 했다.
- DFS 를 실전에서 사용해보긴 처음이라 시간이 조금 걸리긴 했지만 코드 자체가 틀이 정해져 있어서 쓰는건 어렵지 않았다.
  
  ``` python
  def bfs(start, target): # 거리탐색을 위한 함수
    queue = [(start, 0)]
    visited = [False] * (n + 1) # 방문 체크
    visited[start] = True # 시작 노드 

    while queue:
        current, distance = queue.pop(0)
        if current == target:
            return distance # 결과 값

        for neighbor, weight in graph[current]: 
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append((neighbor, distance + weight))

- 이 부분을 외우면 좋을 것 같았다. queue 로 구현했으면 더 쉬웠을 것 같다.
