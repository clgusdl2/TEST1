#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int tc=1;tc<=T;tc++){
        int N;
        cin >> N;
        int arr[N][N];
        for(int i=0;i<N;i++)for(int j=0;j<N;j++) cin >> arr[i][j];

        int arr90[N][N],arr180[N][N],arr270[N][N];
        //90도회전 (0,0)->(0,2) / (0,2)->(2,0)
        for(int i=0;i<N;i++)for(int j=0;j<N;j++) arr90[j][(N-1)-i] = arr[i][j];
        for(int i=0;i<N;i++)for(int j=0;j<N;j++) arr180[j][(N-1)-i] = arr90[i][j];
        for(int i=0;i<N;i++)for(int j=0;j<N;j++) arr270[j][(N-1)-i] = arr180[i][j];

        cout << '#'<<tc << endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) cout<<arr90[i][j];
            cout << " ";
            for(int j=0;j<N;j++) cout<<arr180[i][j];
            cout << " ";
            for(int j=0;j<N;j++) cout<<arr270[i][j];
            cout << endl;
        }
    }
    return 0;
}