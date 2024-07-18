#include <iostream>
using namespace std;

int main(){
        int T;
        cin >> T;
        for(int test_case = 1; test_case <= T; test_case++)
        {
            int N,M;
            cin >> N >> M;
            int board[N][N];
            int answer = 0;
            for (int i=0;i<N;i++){
                for (int j=0;j<N;j++){
                    cin >> board[i][j];
                }      
            }
           for (int i=0;i<N;i++){
                for (int j=0;j<N;j++){
                    int sum = board[i][j];
                    for (int k=1;k<M;k++){
                        int dx[4] = {1,0,-1,0};
                        int dy[4] = {0,1,0,-1};
                        for(int dir=0;dir<4;dir++){
                            int nx = i+k*dx[dir];
                            int ny = j+k*dy[dir];
                            if (nx>=0 && nx<N && ny>=0 && ny<N){
                                sum += board[nx][ny];
                            }
                        }
                    }
                    if (sum>answer){
                        answer = sum;
                    }
                    sum = board[i][j];
                    for (int k=1;k<M;k++){
                        int dx[4] = {1,1,-1,-1};
                        int dy[4] = {1,-1,1,-1};
                        for(int dir=0;dir<4;dir++){
                            int nx = i+k*dx[dir];
                            int ny = j+k*dy[dir];
                            if (nx>=0 && nx<N && ny>=0 && ny<N){
                                sum += board[nx][ny];
                            }
                        }
                    }
                    if (sum>answer){
                        answer = sum;
                    }
                }      
            }
            cout << "#"<<test_case<<" "<<answer<<endl;
    }
    return 0;
}