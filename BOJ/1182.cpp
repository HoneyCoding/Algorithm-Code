// https://www.acmicpc.net/problem/1182
// BOJ 1182번 - 부분수열의 합

#include <iostream>

using namespace std;

int N, S;
int result;

int sequence[23];
bool checked[23];
int sum;

void backtracking(int k, int sum)
{
    if (k == N)
    {
        if (sum == S)
            result++;
        return;
    }

    backtracking(k + 1, sum);
    backtracking(k + 1, sum + sequence[k]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    backtracking(0, 0);
    if (S == 0)
        result--;
    cout << result << '\n';

    return 0;
}