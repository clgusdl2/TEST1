
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, s;


int dfsv[1001];
int bfsv[1001];

vector<vector<int>>edges;
vector<int>r1;
vector<int>r2;



void dfs(int x)
{
	dfsv[x] = 1;
	r1.push_back(x);

	for (int i = 0; i < edges[x].size(); i++)
	{
		if (!dfsv[edges[x][i]])
		{
			dfs(edges[x][i]);		
		}
	}
}

void bfs(int x)
{
	queue<int>q;
	q.push({ x });
	bfsv[x] = 1;


	while (!q.empty())
	{
		int cr = q.front();
		q.pop();
		r2.push_back(cr);

		for (int i = 0; i < edges[cr].size(); i++)
		{
			int nx = edges[cr][i];

			if (!bfsv[nx])
			{
				bfsv[nx] = 1;
				q.push({ nx });

			}

		}
	}
}

int main()
{
	cin >> n >> m >> s;
	edges.resize(1001);

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		edges[from].push_back(to);
		edges[to].push_back(from);
	}
	
	for (int i = 0; i < m; i++)
	{
		sort(edges[i].begin(), edges[i].end());
	}


	dfs(s);

	for (int i = 0; i < r1.size(); i++)
	{
		cout << r1[i] << " ";
	}

	bfs(s);

	cout << endl;
	for (int i = 0; i < r2.size(); i++)
	{
		cout << r2[i] << " ";
	}
}