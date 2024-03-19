#include <iostream>
#include <vector>
#define Limit 10^101
using namespace std;

int main()
{
    vector<int> num1(Limit);
    //vector<int> num2(Limit);
    int a,b; // 입력받은 수
    for(int i=0;i<Limit;i++)
    {
        cin >> num1[i];
    }
    for(int i=0;i<Limit;i++)
    {
        if(num1[i]==1)
        {
            break;
        }
        cout<<num1[i];
    }

}