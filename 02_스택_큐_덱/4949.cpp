#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool nobalance(string str) {
    stack<char> s;
    int i = 0;
    
    while (str[i]!='.') {
        
        if (str[i] == '(' || str[i] == '[') {
            
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']') {
            if (s.empty()) {
                
                return false;  // 닫는 괄호가 나왔는데 스택에 여는 괄호가 없는 경우
            }

            else if ((s.top() == '(' && str[i] == ')') ||(s.top() == '[' && str[i] == ']')) 
            {
                
                s.pop();
                
            }
            else
            {
                return false;  // 괄호의 짝이 맞지 않는 경우
            }
        }

        i++;
        
    }
    if (0 < i && !s.empty())
    {
        return false;
    }
        
    return s.empty();
    
}

int main() {
    int i = 0;
    string str_i;
    vector<string> result;
    while (str_i != ".")
    {
        getline(cin, str_i);
        if (nobalance(str_i) == false)
            result.push_back("no");
        else
            result.push_back("yes");
        i++;
    }
   
    for (int j = 0; j < i-1; j++)
    {
        cout << result[j] << '\n';
    }
    return 0;
}
