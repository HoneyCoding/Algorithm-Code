// https://www.acmicpc.net/problem/1919
// BOJ 1919번 - 애너그램 만들기

#include <iostream>
#include <cstdlib>

using namespace std;

int string_cnt1[100];
int string_cnt2[100];

string s1;
string s2;

int result = 0;

int main(void) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> s1 >> s2;

    for(char c1: s1) {
        string_cnt1[c1-'a']++;
    }

    for(char c2: s2) {
        string_cnt2[c2-'a']++;
    }

    for(int i='a'-'a'; i<='z'-'a'; i++)
        result += abs(string_cnt1[i] - string_cnt2[i]);

    cout << result << '\n';

    return 0;
}