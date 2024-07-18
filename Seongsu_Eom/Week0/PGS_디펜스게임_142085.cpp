#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    if(k == enemy.size()) {
        return k;
    }
    if(k > enemy.size()) {
        return enemy.size();
    }
    int a = 0;
    int cnt = k;
    priority_queue<int, vector<int>, greater<int>> e;
    for(int i=0;i<k;i++) {
        e.push(enemy[i]);
    }
    
    while(1){
        e.push(enemy[cnt]);
        a += e.top();
        e.pop();
        
        
        if(n < a) {
            break;
        }
        if(enemy.size() == cnt) {
            break;
        }
        cnt++;
    }   
    
    
    int answer = cnt;
    return answer;
}