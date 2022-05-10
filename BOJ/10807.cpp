// https://www.acmicpc.net/problem/10807
// BOJ 10807번 - 개수 세기

#include <iostream>

using namespace std;

int n, v;
int num[123];
int cnt = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> num[i];
    }

    cin >> v;

    for(int i=0; i<n; i++) {
        if(v == num[i]) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}