// https://www.acmicpc.net/problem/1748
// BOJ 1748번 - 수 이어 쓰기 1

#include <iostream>

using namespace std;

int N;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int current_count = 1;
    int current_max = 10;
    int result = 0;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        if (i >= current_max)
        {
            current_count++;
            current_max *= 10;
        }
        result += current_count;
    }

    cout << result << '\n';

    return 0;
}