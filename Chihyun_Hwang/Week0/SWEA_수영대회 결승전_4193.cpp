#include<iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 15
int n; // 맵크기
int map[MAXN][MAXN]; //맵
int visited[MAXN][MAXN];

int sx, sy; //시작위치
int ex, ey; //도착위치

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int result = 0;

void init()
{
	result = 0;
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));

	/*
		fill(&map[0][0], &map[MAXN-1][MAXN], 0);
	*/
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy;
	cin >> ex >> ey;


}

void bfs(int sx, int sy)
{
	queue<pair<int, pair<int, int>>>q;
	q.push({ -1,{ sx,sy } });
	visited[sx][sy] = 1;


	while (!q.empty())
	{

		int size = q.size();
		pair<int, pair<int, int>> temp = q.front();
		int timep = temp.first;
		int cx = temp.second.first;
		int cy = temp.second.second;
		timep++;
		q.pop();

		//cout << "cxcy: " << " 시간 " << timep << " " << cx << " " << cy << endl;

		if (cx == ex && cy == ey)
		{
			result = timep;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			//좌표 범위 확인
			if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;

			if (map[nx][ny] == 1) continue; //벽무시

			if (visited[nx][ny]) continue;

			if (map[nx][ny] == 2)
			{
				if (timep % 3 == 2) // 토네이도 지나갈 수 있는 시간
				{
					q.push({ timep,{ nx,ny } });
					visited[nx][ny] = 1;
				}
				else
				{
					q.push({ timep,{ cx,cy } });
				}
			}

			if (!visited[nx][ny] && map[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				q.push({ timep,{ nx,ny } });
			}

		}

	}
	result = -1; // 도착할 수 없다면
	return;

}

int solve()
{
	// 0은 지나갈 수 있는 거리
	// 지나갈 수 없는 장애물, 사라지는 장애물
	//소용돌이는 0초 1초 / 2초 지나감 / 3,4초 생성 / 5초 지나감

	// 즉 0일때만 지나가게함 1초는 고정벽
	// 벽을 bfs돌릴때 --하면 될듯

	bfs(sx, sy);
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		solve();
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}