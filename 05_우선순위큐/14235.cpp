#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, value, x, cnt = 0, result[5000];
	priority_queue<int> pri_q;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		if (value != 0) //거점지인 아이들 만남
		{
			while (value--)
			{
				cin >> x;
				pri_q.push(x);
			}
		}
		else //거잠지 아닌 아이들 만남
		{
			if (pri_q.empty())
				result[cnt]= 0;
			else
			{
				result[cnt] = pri_q.top();
				pri_q.pop();
			}
			cnt++;
		}
	}

	//출력
	for (int i = 0; i < cnt; i++)
	{
		if (result[i] == 0)
			cout << "-1" << '\n';
		else
			cout << result[i] << '\n';
	}
		
}