/*
https://programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(auto iter1 = completion.begin(), iter2 = participant.begin(); iter1 != completion.end(); ++iter1, ++iter2) {
        if(*iter1 != *iter2)
            return *iter2;
    }
    return *(participant.end() - 1);
}
