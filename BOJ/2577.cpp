// https://www.acmicpc.net/problem/2577
// BOJ 2577번 - 숫자의 개수

#include <iostream>
#include <vector>

using namespace std;

int A, B, C;
int result;

int counts[10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> C;

    result = A * B * C;

    while (result != 0)
    {
        counts[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << counts[i] << '\n';
    }

    return 0;
}