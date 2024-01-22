// https://www.acmicpc.net/problem/15652
// BOJ 15652번 - N과 M (4)

#include <iostream>

using namespace std;

int N, M;
int sequence[10];

void backtracking(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << sequence[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (k == 0 || (k > 0 && sequence[k - 1] <= i))
        {
            sequence[k] = i;
            backtracking(k + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    backtracking(0);

    return 0;
}