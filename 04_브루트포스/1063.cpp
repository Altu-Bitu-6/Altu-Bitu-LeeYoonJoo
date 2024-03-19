#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<char, char> cc;//다른 자료형의 별명을 만들기 위해 사용됨

/**
 * input에 따라 이동한다.
*/
cc move(string input, char x, char y) {   //입력된 문자열에 따라 위치 이동을 수행하는 함수
    for (char how : input) {              //이별괸 문자열을 하나씩 확인
        if (how == 'R') {                 //이동 방향이 오른쪽이면
            x++;                          //x좌표 증가
        } else if (how == 'L') {          //이동 방향이 왼쪽이면
            x--;                          //x좌표 감소
        } else if (how == 'B') {          //이동 방향이 아래쪽이면
            y--;                          //y좌표 감소
        } else {  // (how == 'T')         //이동 방향이 위쪽이면
            y++;                          //y좌표 증가
        }
    }
    return {x, y};
}

/**
 * 두 좌표의 위치가 일치하는지 확인한다.
*/
bool isSame(cc k, cc s) {
    return (k.first == s.first && k.second == s.second);//두 위치가 같음ㄴ true 반환
}

/**
 * 체스판 범위를 넘어서는지 확인한다.
*/
bool checkRange (cc pos) {
    if (pos.first < 'A' || pos.first > 'H' || pos.second < '1' || pos.second > '8') { //보드 범위를 벗어나면
        return false; //false 반환
    }
    return true; // 범위 내에 있으면 true 반환
}

int main() {
    cc k, s;  // king, stone 위치
    int n;    // 이동 횟수를 나타내는 변수 선언
    string input;   //이동 방향을 나타내는 문자열을 저장할 변수 선언

    // 입력->초기 위치와 이동 횟수를 입력받음
    cin >> k.first >> k.second >> s.first >> s.second >> n;

    // 연산
    while (n--) {
        cin >> input;

        cc next_k, next_s;

        // king 이동
        next_k = move(input, k.first, k.second);

        // stone 이동
        if (isSame(next_k, s)) {  // 이동한 king과 stone 위치가 일치하면
            // king이 움직인 방향과 같은 방향으로 이동
            next_s = move(input, s.first, s.second);
        }
        else {
            next_s = s;
        }

        // 체스판 밖으로 나가지 않을 경우만 이동
        if (checkRange(next_k) && checkRange(next_s)) {
            k = next_k; //킹의 다음위치
            s = next_s; //stone의 다음위치
        }
    }

    // 출력
    cout << k.first << k.second << '\n' << s.first << s.second;

    return 0;
}