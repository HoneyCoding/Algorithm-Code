// https://www.acmicpc.net/problem/1629
// BOJ 1629번 - 곱셈

#include <iostream>

using namespace std;

long long func(int A, int B, int C)
{
    if (B == 0)
        return 1;
    long long result = func(A, B / 2, C);
    result = (result * result) % C;
    if (B % 2 == 1)
        result = (result * A) % C;
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;

    cin >> A >> B >> C;

    cout << func(A, B, C) << '\n';

    return 0;
}