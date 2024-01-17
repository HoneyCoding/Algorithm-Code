// https://www.acmicpc.net/problem/11729
// BOJ 11729번 - 하노이 탑 이동 순서

#include <iostream>

using namespace std;

int N;

int calculateResult(int N, int from, int to)
{
    if (N == 0)
        return 0;
    int result = calculateResult(N - 1, from, 6 - from - to);
    result++;
    result += calculateResult(N - 1, 6 - from - to, to);
    return result;
}

void printMove(int N, int from, int to)
{
    if (N == 0)
        return;
    printMove(N - 1, from, 6 - from - to);
    cout << from << ' ' << to << '\n';
    printMove(N - 1, 6 - from - to, to);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    cout << calculateResult(N, 1, 3) << '\n';
    printMove(N, 1, 3);

    return 0;
}