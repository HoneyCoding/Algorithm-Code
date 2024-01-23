// https://www.acmicpc.net/problem/15657
// BOJ 15657번 - N과 M (8)

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int sequenceIndex[10];
int numbers[10];

void backtracking(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
            cout << numbers[sequenceIndex[i]] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if ((k > 0 && sequenceIndex[k - 1] <= i) || k == 0)
        {
            sequenceIndex[k] = i;
            backtracking(k + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers + N);
    backtracking(0);

    return 0;
}