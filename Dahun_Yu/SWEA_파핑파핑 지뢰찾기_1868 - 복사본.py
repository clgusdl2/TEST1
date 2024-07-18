from collections import deque
T = int(input())
#900*8 = 7200
for tc in range(1,T+1):
    N = int(input())
    board = []
    for _ in range(N):
        board.append(list(input()))
  
    dx = [1,0,-1,0,1,1,-1,-1]
    dy = [0,-1,0,1,1,-1,1,-1]
  
    zero_point = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == '.':
                count = 0
                for k in range(8):
                    nx = i+dx[k]
                    ny = j+dy[k]
                    if 0<=nx<N and 0<=ny<N and board[nx][ny] == '*':
                        count +=1
                board[i][j] = count
                if count == 0:
                    zero_point.append((i,j))
  
    visited = [[False]*N for _ in range(N)]
  
    answer = 0
  
    for i,j in zero_point:
        if not visited[i][j]:
            visited[i][j] = True
            que = deque()
            que.append((i,j))
            while que:
                x,y = que.popleft()
                for k in range(8):
                    nx = x + dx[k]
                    ny = y + dy[k]
                    if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                        if board[nx][ny] == 0:
                            visited[nx][ny] = True
                            que.append((nx,ny))
                        elif board[nx][ny] != '*':
                            visited[nx][ny] = True
                        else:
                            pass
            answer +=1
  
    for i in range(N):
        for j in range(N):
            if not visited[i][j] and board[i][j] != '*':
                answer +=1
  
    print('#'+str(tc),answer)