from itertools import combinations
T=int(input())
for tc in range(1,T+1):
    N,B = map(int,input().split())
    keys = list(map(int,input().split()))
  
    answer = float('inf')
    for i in range(1,N+1):
        for lst in combinations(keys,i):
            if answer>sum(lst)>=B:
                answer = sum(lst)
  
    print('#'+str(tc),answer-B)