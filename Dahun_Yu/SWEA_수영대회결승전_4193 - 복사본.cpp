#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        int ans = -1;
        cin >> N;
        int pool[15][15] = {};
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> pool[i][j];
        int A, B, C, D;
        cin >> A >> B;
        cin >> C >> D;
         
        int dx[4] = { 1,0,-1,0};
        int dy[4] = { 0,1,0,-1 };
 
        int flag = 0;
        int visited[15][15] = {};
        queue <tuple<int,int,int>> que;
        que.push({A, B, 0});
        while (!que.empty()) {
            tuple<int, int, int> tmp = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = get<0>(tmp) + dx[i];
                int ny = get<1>(tmp) + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < N && ((dx[i] == 0 && dy[i] == 0) || !visited[nx][ny]) && (pool[nx][ny] == 0 || pool[nx][ny] == 2 )) {
                    if (pool[nx][ny] == 0 || (pool[nx][ny] == 2 && get<2>(tmp) % 3 == 2)) {
                        if (nx == C && ny == D) {
                            ans = get<2>(tmp) + 1;
                            flag = 1;
                            break;
                        }
                        que.push({ nx,ny,get<2>(tmp) + 1 });
                        visited[nx][ny] = 1;
                    }
                    else {
                        que.push({ get<0>(tmp),get<1>(tmp),get<2>(tmp) + 1 });
                    }
                }
            }
            if (flag) break;
        }
        cout << "#" << tc << " " << ans <<endl;
    }
    return 0;
}