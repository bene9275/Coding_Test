/*
https://www.acmicpc.net/problem/13414
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using  namespace std;
vector<pair<string, int>> enroll(map<string, int> &m, int K, int L);
void print_vector(vector<pair<string, int>> &v);
bool compare(const pair<string, int> &v1, const pair<string, int> &v2);

int main()
{
    int K, L;
    vector<pair<string, int>> result;
    map<string, int> m;

    cin >> K >> L;

    result = enroll(m, K, L);
    print_vector(result);

    return 0;
}

void print_vector(vector<pair<string, int>> &v) {
    for(auto iter = v.begin(); iter != v.end(); ++iter)
        cout << iter->first << endl;
}

vector<pair<string, int>> enroll(map<string, int> &m, int K, int L) {

    vector<pair<string, int>> v;
    string id;

    for(int i = 0; i < L; ++i) {
        cin >> id;
        m[id] = i;
    }

    for(auto iter = m.begin(); iter != m.end(); ++iter) {
        v.emplace_back(make_pair(iter->first, iter->second));
    }

    sort(v.begin(), v.end(), compare);

    return vector<pair<string, int>> (v.begin(), v.begin() + min(K, L));
}

bool compare(const pair<string, int> &v1, const pair<string, int> &v2) {
    return v1.second < v2.second;
}
