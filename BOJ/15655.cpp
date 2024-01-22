// https://www.acmicpc.net/problem/15655
// BOJ 15655번 - N과 M (6)

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int numbers[10];
int sequenceIndex[10];
bool isSelected[10];

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
        if (isSelected[i])
            continue;
        isSelected[i] = true;
        if ((k > 0 && sequenceIndex[k - 1] < i) || k == 0)
        {
            sequenceIndex[k] = i;
            backtracking(k + 1);
        }
        isSelected[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + N);

    backtracking(0);

    return 0;
}