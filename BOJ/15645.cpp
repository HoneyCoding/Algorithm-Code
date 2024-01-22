// https://www.acmicpc.net/problem/15654
// BOJ 15654번 - N과 M (5)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int sequenceIndex[10];
bool isSelected[10];
int numbers[10];

void backtracking(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << numbers[sequenceIndex[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSelected[i])
            continue;
        isSelected[i] = true;
        sequenceIndex[k] = i;
        backtracking(k + 1);
        isSelected[i] = false;
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