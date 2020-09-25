/*
https://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    int all = 0, dup = 0;
    int ans = 65536;
    int len1 = str1.length(), len2 = str2.length();

    map<string, int> m;
    for(int i = 0; i < len1 - 1; ++i) {

        if(!('a' <= str1[i] && str1[i] <= 'z')) continue;
        if(!('a' <= str1[i + 1] && str1[i + 1] <= 'z')) continue;

        string s;
        s = str1[i];
        s += str1[i + 1];

        if(m.find(s) != m.end())
            ++m[s];
        else
            m[s] = 1;

        ++all;
    }

    for(int i = 0; i < len2 - 1; ++i) {

        if(!('a' <= str2[i] && str2[i] <= 'z')) continue;
        if(!('a' <= str2[i + 1] && str2[i + 1] <= 'z')) continue;

        string s;
        s = str2[i];
        s += str2[i + 1];

        if(m.find(s) != m.end()) {
            if(m[s] > 0) {
                --m[s];
                ++dup;
            }
            else
                ++all;
        }
        else
            ++all;
    }

    if (all != 0)
        ans = (int)(ans * ((double)dup / all));
    cout << ans;

    return 0;
}
