/*
https://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input_array(vector<int> &v, int n);
void decrypt(vector<int> &arr1, vector<int> &arr2, int n);
void print_vector(vector<char> &v);

int main()
{
    int n;
    cin >> n;

    vector<int> arr1, arr2;
    input_array(arr1, n);
    input_array(arr2, n);

    decrypt(arr1, arr2, n);

    return 0;
}

void print_vector(vector<char> &v) {

    for(int i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
}

void decrypt(vector<int> &arr1, vector<int> &arr2, int n) {

    vector<char> result(n);
    int x;

    for(int i = 0; i < n; ++i) {
        x = arr1[i] | arr2[i];
        for(int j = 0; j < n; ++j) {
            if((x >> j) % 2 == 0)
                result.emplace_back(' ');
            else
                result.emplace_back('#');
        }
        reverse(result.begin(), result.end());
        print_vector(result);
        cout << endl;
        result.clear();
    }
}

void input_array(vector<int> &v, int n) {

    int x;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        v.emplace_back(x);
    }
}
