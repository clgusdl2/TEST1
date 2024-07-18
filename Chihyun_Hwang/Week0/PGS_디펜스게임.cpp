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
        if (n >= enemy[i]) // n���� �ϴ� ���� ���� ��������� �� 
        {
            pq.push(enemy[i]);
            n -= enemy[i];
        }
        else // n�� ���ڸ��� ����� ���� �� ���� ū���� �������� ����ϰ�
        {    // �� ���� ���� �� ������ ����
            if (k > 0) // ������ 
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
                return i; // �׋� ���带 ������
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