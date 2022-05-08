// https://www.acmicpc.net/problem/3273
// BOJ 3273번 - 두 수의 합

#include <iostream>

using namespace std;

int n;
int list[100006] = {0};
int chk[2000006] = {0};
int x;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> list[i];
        chk[list[i]] = 1;
    }
    cin >> x;

    int cnt = 0;

    for(int i=0; i<n; i++) {
        if(x-list[i] >= 0 && chk[x-list[i]] == 1) cnt++;
    }

    cnt /= 2;

    cout << cnt << '\n';

    return 0;
}