/*
https://programmers.co.kr/learn/courses/30/lessons/68644
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for(auto iter1 = numbers.begin(); iter1 != numbers.end() - 1; ++iter1) {
        for(auto iter2 = iter1 + 1; iter2 != numbers.end(); ++iter2) {
            static int sum;
            sum = *iter1 + *iter2;

            if(find(answer.begin(), answer.end(), sum) == answer.end())
                answer.emplace_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
