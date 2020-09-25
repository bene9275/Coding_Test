/*
https://tech.kakao.com/2017/11/14/kakao-blind-recruitment-round-3/
*/

/*
단어를 통해 색인번호를 찾아야하는데,
많은 검색이 요구되므로 search 시간이 작은 "map 자료구조"를 이용
단어 = string, 색인번호 = int 자료형을 사용하여
=> map<string, int>

*/


#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    map<string, int> m;
    int index = 1;

    // 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for(char key = 'A'; key <= 'Z'; ++key) {
        string tmp;
        tmp.push_back(key);
        m[tmp] = index++;
    }

    while(true) {
        string w, c;
        int i;

        // 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다
        for(i = input.length(); i >= 1; --i) {
            w = input.substr(0, i);
            if(m.find(w) != m.end()) { // 현재 문자열이 사전에 존재하면
                // w에 해당하는 사전의 색인 번호를 출력하고
                cout << m[w] << endl;
                // 입력에서 w를 제거한다.
                input = input.substr(i, input.length() - i);
                break;
            }
        }

        if(input.length() == 0) // 입력이 모두 처리됨
            break;

        c = input.substr(0, 1); // 입력에서 처리되지 않은 다음 글자
        m[w + c] = index++;
    }

    return 0;
}
