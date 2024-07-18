#include <iostream>

using namespace std;

int m[21];
int n, s;
int cnt = 0;
void dt(int level,int total, int sum)
{
	if (level == n)
	{
		if (total == sum) cnt++;
	}


	dt(level + 1, total + m[level], sum);
	dt(level + 1, total, sum);


}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin>>m[i];
	}
	dt(0,0, s);
	cout << cnt;
}