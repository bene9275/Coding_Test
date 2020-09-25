/*
https://www.acmicpc.net/problem/14655
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    int x;
    cin >> n;

    vector<int> round1(n), round2(n);
    for(int i = 0; i < n; ++i) {
        cin >> x;
        round1.emplace_back(x);
    }

    for(int i = 0; i < n; ++i) {
        cin >> x;
        round2.emplace_back(x);
    }

    transform(round1.begin(), round1.end(), round1.begin(), ::abs);
    transform(round2.begin(), round2.end(), round2.begin(), ::abs);

    int sum1, sum2;
    sum1 = accumulate(round1.begin(), round1.end(), 0);
    sum2 = accumulate(round2.begin(), round2.end(), 0);
    cout << sum1 + sum2 << endl;

    return 0;
}
