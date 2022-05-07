// https://www.acmicpc.net/problem/10871
// BOJ 10871번 - X보다 작은 수

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;

    cin >> N >> X;

    int num;

    for(int i=0; i<N; i++) {
        cin >> num;
        if (num < X) cout << num << ' ';
    }

    return 0;
}