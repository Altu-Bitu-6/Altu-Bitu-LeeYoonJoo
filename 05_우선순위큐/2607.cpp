#include <iostream>
#include <vector>
using namespace std;

const int NUM_CAHRS = 26;

//구성을 세는 함수
void countFreq(string word,vector<int> &freq)
{
    for(int i=0;i<word.length();i++)
    {
        //abcde
        //char e-> 아스키코드에 저장 ex) 'A' -> freq[0] / ... / 'Z'-> freq[25]
        //'A'-'A' = 0 / 'B'-'A' = 1/ ...
        freq[word[i]='A']++; 
    }
}
//구성을 비교하는 함수
int countDiff(string word, vector<int> &original_freq)
{
    vector<int> comp_freq(NUM_CAHRS,0);
    int diff = 0; //원본 단어와의 구성 차이
    countFreq(word,comp_freq); //비교할 대상인 단어의 구성을 계산
    for(int i=0;i<NUM_CAHRS;i++)  // 원본 단어와 다른 알파벳 개수 구하기
    {
        diff +=abs(original_freq[i]-comp_freq[i]); 
    }
    return diff;
}

int main()
{
    //입력
    int n,ans=0;
    cin >> n;
    string original;
    cin >>original; //원본단어
    vector<int> original_freq(NUM_CAHRS,0);  //원본 단어의 구성을 저장할 벡터
    //연산
    countFreq(original,original_freq); //원본단어 구성을 셈
    for(int i=1;i<n;i++)    
    {
        string word; //비교할 단어
        cin >> word;
        int diff = countDiff(word, original_freq);
        //비슷한 단어인지 확인
        if (diff = 0 || diff ==1 || diff ==2 && original.length()==word.length())
        {
            ans++;
        }
        
    }
    //출력
    cout<<ans;
    return 0;
}