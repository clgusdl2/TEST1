#include <iostream>

using namespace std;

int N, S, cnt;
int A[20];

void so(int a, int c) {
    if (c == N) {
        if (a == S) {
            cnt++;
        }
        return;
    }
    so(a, c + 1);
    so(a + A[c], c + 1);
}

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cnt = 0;

    so(0, 0);

    if (S == 0) {
        cnt--;
    }

    cout << cnt;

    return 0;
}