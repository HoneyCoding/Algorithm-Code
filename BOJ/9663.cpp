// https://www.acmicpc.net/problem/9663
// BOJ 9663번 - N-Queen

#include <iostream>

using namespace std;

bool horizontalChecked[20];
bool crossUpChecked[20];
bool crossDownChecked[20];

int N;
int result;

void backtracking(int y)
{
    if (y == N)
    {
        result++;
        return;
    }

    for (int x = 0; x < N; x++)
    {
        if (horizontalChecked[x] || crossUpChecked[y + x] || crossDownChecked[N - y + x - 1])
            continue;
        horizontalChecked[x] = crossUpChecked[y + x] = crossDownChecked[N - y + x - 1] = true;
        backtracking(y + 1);
        horizontalChecked[x] = crossUpChecked[y + x] = crossDownChecked[N - y + x - 1] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    backtracking(0);

    cout << result << '\n';

    return 0;
}