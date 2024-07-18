#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

unordered_map<char, int>moums;
string s;


bool checkmoum(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			return true;
		}
	}
	return false;
}

bool counts(string s)
{
	int mcnt = 0;
	int scnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		

		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			mcnt++;
			scnt = 0;
		}
		
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
		{
			scnt++;
			mcnt = 0;
		}
		if (mcnt >= 3 || scnt >= 3)
		{
			return false;
		}

	}
	return true;
}

bool chains(string s)
{
	//3. ���� ���ڰ� ���������� �ι����� �ȵȴ�.
	//3-1 ee�� oo�� ���
	stack<char>st;
	for (int i = 0; i < s.size(); i++)
	{

		if (i > 0 && ((st.top() != 'o' && st.top() != 'e')&& st.top() == s[i]))
		{
			return false;
		}

		st.push(s[i]);
	}
	return true;

} 

bool simul()
{

	while (true)
	{
		bool flag = true;
		moums.clear(); // �ؽ����̺� ����2 clear;
		cin >> s;

		if (s == "end")
		{
			return false;
		}

		//1 a,e,i,o,u �ϳ��� �ݵ�� �����ؾ��Ѵ�.
		if (!checkmoum(s))
		{
			flag = false;
		}
		//2. ������ 3�� Ȥ�� ������ 3�� �������� ���� �ȵȴ�
		if (flag && !counts(s))
		{
			flag = false;
		}
		//3. ���� ���ڰ� ���������� �ι����� �ȵȴ�.
		//3-1 ee�� oo�� ���
		if (flag && !chains(s))
		{
			flag = false;
		}
		if (flag)
		{
			cout<< "<" << s << ">" << " is acceptable." << endl;
		}
		else
		{
			cout << "<" << s << ">" << " is not acceptable." << endl;
		}
	}



}


int main()
{
	simul();
	return 0;
}
