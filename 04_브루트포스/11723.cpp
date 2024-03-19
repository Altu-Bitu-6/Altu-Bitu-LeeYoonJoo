#include <iostream>
#include <cstring>

using namespace std;
int add(int a)
{
	int x;
	cin >> x;
	a |= (1 << x);
	return a;
}
int remove(int a)
{
	int x;
	cin >> x;
	a &= ~(1 << x);
	return a;
}
void check(int a)
{
	int x;
	cin >> x;
	if (a & (1 << x))
		cout << 1 << '\n';
	else
		cout << 0 << '\n';
}
int toggle(int a)
{
	int x;
	cin >> x;
	if (a & (1 << x))
		a &= ~(1 << x);
	else
		a |= (1 << x);
	return a;
}
int all(int a)
{
	int x;
}
int empty(int a)
{
	int x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a = 0;//공집합
	int x, num; 
	string calc="";

	cin >> num;

	for(int i=0;i<num;i++)
	{
		cin >> calc;
		
		if (calc == "add")
		{
			a = add(a);
		}
			
		else if (calc == "remove")
		{
			a = remove(a);
		}
		else if (calc == "check")
		{
			check(a);
		}
		else if (calc == "toggle")
		{
			a = toggle(a);
		}
			
		else if (calc == "all")
		{
			a = (1 << 21) - 1;
		}
			
		else if (calc == "empty")
		{
			a = 0;
		}
	}
	return 0;
}