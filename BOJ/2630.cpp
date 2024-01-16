// https://www.acmicpc.net/problem/2630
// BOJ 2630번 - 색종이 만들기

#include <iostream>

using namespace std;

int paper[150][150];
int N;
int whiteCount;
int blueCount;

void increaseCount(int value)
{
    if (value == 0)
        whiteCount++;
    else
        blueCount++;
}

bool checkSame(int startY, int startX, int N)
{
    int value = paper[startY][startX];

    for (int i = startY; i < startY + N; i++)
        for (int j = startX; j < startX + N; j++)
            if (value != paper[i][j])
                return false;

    return true;
}

void calculateResult(int startY, int startX, int N)
{
    int value = paper[startY][startX];
    if (N == 1)
    {
        increaseCount(value);
        return;
    }

    if (checkSame(startY, startX, N))
    {
        increaseCount(value);
        return;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            calculateResult(startY + (N / 2) * i, startX + (N / 2) * j, N / 2);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    calculateResult(0, 0, N);

    cout << whiteCount << '\n'
         << blueCount << '\n';

    return 0;
}