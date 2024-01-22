// https://www.acmicpc.net/problem/15650
// BOJ 15650번 - N과 M (2)

#include <iostream>

using namespace std;

int N, M;

bool isSelected[10];
int sequence[10];

void backtracking(int k, int argI)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << sequence[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = argI; i <= N; i++)
    {
        if (isSelected[i])
            continue;
        isSelected[i] = true;
        sequence[k] = i;
        backtracking(k + 1, i + 1);
        isSelected[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    backtracking(0, 1);

    return 0;
}