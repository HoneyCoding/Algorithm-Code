// https://www.acmicpc.net/problem/10808
// BOJ 10808번 - 알파벳 개수

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count[60] = {0};

    int last_idx = 'z' - 'a';
    string S;

    cin >> S;

    for (char c: S) {
        count[c-'a'] += 1;
    }

    for(int i=0; i<=last_idx; i++) {
        cout << count[i] << ' ';
    }

    return 0;
}