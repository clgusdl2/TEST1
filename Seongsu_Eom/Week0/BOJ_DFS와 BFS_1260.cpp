#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> A;
int vit[1000];
queue<int> q;
vector<int> v;

void dfs(int s) {
    if (vit[s - 1] == 1) {
        return;
    }
    cout << s << " ";
    vit[s - 1] = 1;
    vector<int> v1;
    for (int i = 0; i < M; i++) {
        if (A[i][0] == s && vit[A[i][1] - 1] == 0) {
            v1.push_back(A[i][1]);
        }
        if (A[i][1] == s && vit[A[i][0] - 1] == 0) {
            v1.push_back(A[i][0]);
        }
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        dfs(v1[i]);
    }

    return;
}

void bfs() {
    int cnt = 0;
    while (!q.empty()) {
        v.clear();
        int s = q.front();
        q.pop();

        if (vit[s - 1] == 1) {
            continue;
        }
        cout << s << " ";
        vit[s - 1] = 1;
        cnt++;
        if (cnt == N) {
            break;
        }
        for (int i = 0; i < M; i++) {
            if (A[i][0] == s) {
                v.push_back(A[i][1]);
            }
            if (A[i][1] == s) {
                v.push_back(A[i][0]);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            q.push(v[i]);
        }
    }
}

int main()
{
    cin >> N >> M >> V;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        A.push_back({ a,b });
    }
    memset(vit, 0, sizeof(vit));
    v.clear();

    sort(A.begin(), A.end());
    dfs(V);
    cout << endl;

    v.clear();
    memset(vit, 0, sizeof(vit));
    q.push(V);
    bfs();

    return 0; 
}