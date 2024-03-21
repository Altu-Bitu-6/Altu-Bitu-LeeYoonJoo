#include <iostream>
#include <queue>

using namespace std;
struct cmp {
	bool operator()(const int& x1, const int& x2) {
		return x1 > x2; //오름차순 정렬 ex) 첫번째 줄 12 7 9 15 5-> 5 7 9 12 15
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, x; 
	priority_queue<int,vector<int>,cmp> pri_q;
	cin >> n;
	int max = n * n;
	for (int i = 0; i < max; i++)
	{
		cin >> x;
		pri_q.push(x);
		
		if (n<pri_q.size()) //5개씩 큐에 삽입
		{
			pri_q.pop(); // 정렬된 마지막 원소 삭제
		}
		//pri_q.pop();
		
	}
	cout << pri_q.top();
	return 0;
}