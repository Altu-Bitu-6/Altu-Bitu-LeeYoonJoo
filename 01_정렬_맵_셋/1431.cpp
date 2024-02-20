#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

//문자열에서 숫자추출해서 더하기
int ExtractNumSum(string& S)
{
	int sum=0,num;
	for(char c : S){
		if(isdigit(c)){
			num = c - 48;
			sum += num;
		}
	}
    return sum;
}

//시리얼 번호 길이 순서 정렬하기
bool SizeSort(string& S1,string& S2){
	cout<<"S1:"<<S1<<" S2:"<<S2<<'\n';
	if(S1.size()!=S2.size())							//문자열의 길이가 다른 경우
    {
        cout<<"길이가 다름"<<'\n';
		return S1.size() < S2.size();						//길이가 짧은 게 앞에 온다.
    }
    if(S1.size()==S2.size())							//문자열의 길이가 같은 경우
	{
		cout<<"길이가 같음"<<'\n';
		if(ExtractNumSum(S1)==0&&ExtractNumSum(S2)==0){ 			//숫자가 없는경우
			cout<<"숫자가 없음"<<'\n';
			return S1 < S2;										//알파벳순 
		}
		
		else{  												//숫자가 있는경우
			if(ExtractNumSum(S1)==ExtractNumSum(S2)){			//더한값이 같은 경우
				cout<<"더한값이 같음"<<'\n';
				return S1 < S2;
			}  				
			else{												//더한값이 다른 경우
				cout<<"더한값이 다름"<<'\n';
				return ExtractNumSum(S1)<ExtractNumSum(S2);		        	
			}											    
		}
	}
	
}

int main(){
    int N,i;
    cin>>N;
	vector<string> vserial(N);
    if(N<=50)
    {
        //입력
        for(i=0;i<N;i++)
        {
            cin >> vserial[i];
			
        }
		
		if(vserial.begin()!=vserial.end()){
			//정렬
			sort(vserial.begin(),vserial.end(),SizeSort);
		}
        //출력
		for(int i=0;i<N;i++){
			cout<<vserial[i]<<'\n';
		}
	}
    return 0;
}