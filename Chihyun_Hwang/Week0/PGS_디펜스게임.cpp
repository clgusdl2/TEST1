#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int play(int n, int k, vector<int> enemy)
{
    priority_queue<int, vector<int>, less<int>>pq;

    for (int i = 0; i < enemy.size(); i++)
    {
        if (n >= enemy[i]) // n으로 일단 적을 막고 저장공간에 둠 
        {
            pq.push(enemy[i]);
            n -= enemy[i];
        }
        else // n이 모자르면 저장된 적군 중 가장 큰놈을 무적권을 사용하고
        {    // 그 수를 더한 후 적군을 뺴줌
            if (k > 0) // 무적권 
            {

                if (!pq.empty())
                {
                    k--;
                    int prev = pq.top();
                    pq.pop();
                    n += prev - enemy[i];
                    pq.push(enemy[i]);
                }
            }
            else
            {
                return i; // 그떄 라운드를 돌려줌
            }
        }
    }
}


int solution(int n, int k, vector<int> enemy) {
    int answer = 0;


    if (enemy.size() <= k)
    {
        return enemy.size();
    }
    answer = play(n, k, enemy);

    return answer;
}

int main()
{
        int n = 7, k = 3;
        vector<int>enemy = { 4,2,4,5,3,3,1 };
        solution(n, k, enemy);
}