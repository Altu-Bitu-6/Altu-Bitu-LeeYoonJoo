#include <iostream>
#include <string>
using namespace std;

int main()
{
	int loop = 0, cnt=0,input_cnt;
	string num = "666";
	cin >> input_cnt;
	while (true)
	{
		string s = to_string(loop);
		if (s.find(num) != string::npos)
			cnt++;

		if (cnt == input_cnt)
			break;
		loop++;
	}
	cout << loop;
	return 0;
}