/*
https://www.acmicpc.net/problem/1181
*/

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

void input_words(vector<pair<string, int>> &words, int n);
bool compare(const pair<string, int> &v1, const pair<string, int> &v2);

int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> words(n);
    input_words(words, n);

    sort(words.begin(), words.end(), compare);

    map<string, int> myWords;
    for(auto iter = words.begin(); iter != words.end(); ++iter) {
        if(myWords.find(iter->first) == myWords.end()) {
            myWords[iter->first] = iter->second;
            cout << iter->first << endl;
        }
    }

    return 0;
}

void input_words(vector<pair<string, int>> &words, int n) {

    string word;
    for(int i = 0; i < n; ++i) {
        cin >> word;
        words.emplace_back(make_pair(word, word.length()));
    }
}

bool compare(const pair<string, int> &v1, const pair<string, int> &v2) {
    if(v1.second == v2.second) return v1.first < v2.first;

    return v1.second < v2.second;
}
