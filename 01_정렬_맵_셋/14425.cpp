#include <iostream>
#include <string>
#include <vector>
#include <set>
//#include <map>
using namespace std;

int count=0;
int CountNum(set<string>& SetUnit,string& check) //중복된 문자열 개수세는 함수
{
	set<string>::iterator iter;
	iter = SetUnit.find(check);
	if (iter != SetUnit.end()) {
		count++;
	}
	return count;
}

int main()
{
	
    int N,M,result;
    
    cin >> N;
    cin >> M;
	
	string input;										// 입력받는 문자열(집합S)
	set<string> set_stringunit;							//집합S에 포함된 문자열
	vector<string> check_inputstring(M); 				//검사해야할 문자열
	
	for(int i=0;i<N;i++)
	{
		cin >> input;
		set_stringunit.insert(input);
	}
	for(int j=0;j<M;j++)
	{
		cin >> check_inputstring[j];
		result = CountNum(set_stringunit,check_inputstring[j]);
	}
	
	//출력
    cout<<result<<'\n';
	return 0;
}
