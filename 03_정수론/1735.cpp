#include <iostream>
using namespace std;
int gcdIter(int a, int b)	//기약분수연산
{
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
int main()
{
	int fraction[4] = { 0 }, result[2] = { 0 };	// 분자 = A, 분모 = B
	int gcd_result = 0;
	//입력
	for (int i = 0; i <= 3; i++)
	{
		cin >> fraction[i];
	}

	//연산
	if (fraction[1] == fraction[3])		//분모가 같을 경우
	{
		result[0] = fraction[0] + fraction[2];	//분자계산
		result[1] = fraction[1];				//분모계산
	}
	else								//분보가 다를 경우
	{
		result[0] = fraction[0] * fraction[3] + fraction[2] * fraction[1]; //분자계산
		result[1] = fraction[1]*fraction[3];							 //분모계산
	}

	//기약분수연산 => 최대공약수 구함
	if (result[0] <= result[1])
	{
		gcd_result = gcdIter(result[1], result[0]);
		result[0] /= gcd_result;
		result[1] /= gcd_result;
	}
	else
	{
		gcd_result = gcdIter(result[0], result[1]);
		result[0] /= gcd_result;
		result[1] /= gcd_result;
	}
	
	//출력
	for (int i = 0; i < 2; i++)
	{
		cout << result[i]<<" ";
	}
}