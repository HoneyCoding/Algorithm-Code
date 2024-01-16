// https://www.acmicpc.net/problem/1074
// BOJ 1074번 - Z

#include <iostream>

using namespace std;

int N, r, c;

int square[20];

int calculateSquare(int N)
{
    if (N == 0)
        return 1;
    if (square[N] != 0)
        return square[N];
    int result = calculateSquare(N / 2);
    result *= result;
    if (N % 2 == 1)
        result *= 2;
    square[N] = result;
    return result;
}

int solution(int N, int r, int c)
{
    if (N == 1)
    {
        return (2 * r + c);
    }

    if (r < calculateSquare(N - 1) && c < calculateSquare(N - 1))
    {
        return solution(N - 1, r, c);
    }
    else if (r < calculateSquare(N - 1) && c >= calculateSquare(N - 1))
    {
        return (solution(N - 1, r, c - calculateSquare(N - 1)) + (calculateSquare(N - 1) * calculateSquare(N - 1)));
    }
    else if (r >= calculateSquare(N - 1) && c < calculateSquare(N - 1))
    {
        return (solution(N - 1, r - calculateSquare(N - 1), c) + (calculateSquare(N - 1) * calculateSquare(N - 1)) * 2);
    }
    else
    {
        return (solution(N - 1, r - calculateSquare(N - 1), c - calculateSquare(N - 1)) + (calculateSquare(N - 1) * calculateSquare(N - 1)) * 3);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> r >> c;

    cout << solution(N, r, c) << '\n';

    return 0;
}