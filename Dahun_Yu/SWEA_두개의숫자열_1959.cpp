#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++){
        int ans = 0;
        int arr1[20];
        int arr2[20];

        int N, M;
        cin >> N >> M;
 
        //cout << N << M << endl;
        for (int i = 0; i < N; i++) cin >> arr1[i];
        for (int i = 0; i < M; i++) cin >> arr2[i];
 
        //for (int i = 0; i < N; i++) cout << arr1[i];
        //for (int i = 0; i < M; i++) cout << arr2[i];

        if (N < M) for (int i = 0; i <= M - N; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) sum += arr1[j] * arr2[j + i];
            if (ans < sum) ans = sum;
        }
        else for (int i = 0; i <= N - M; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) sum += arr1[j+i] * arr2[j];
            if (ans < sum) ans = sum;
        }
         
        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}