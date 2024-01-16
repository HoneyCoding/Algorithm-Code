// https://www.acmicpc.net/problem/1780
// BOJ 1780번 - 종이의 개수

#include <iostream>

using namespace std;

int N;
int papers[2188][2188];

int zeroCount;
int minusOneCount;
int oneCount;

bool checkSame(int startY, int startX, int N)
{
    int value = papers[startY][startX];
    int endY = startY + N;
    int endX = startX + N;

    for (int i = startY; i < endY; i++)
        for (int j = startX; j < endX; j++)
            if (value != papers[i][j])
                return false;

    return true;
}

void increaseCount(int value)
{
    if (value == 1)
        oneCount++;
    else if (value == 0)
        zeroCount++;
    else if (value == -1)
        minusOneCount++;
}

void calculateResult(int startY, int startX, int N)
{
    int value = papers[startY][startX];
    bool flag = false;

    if (N == 1)
    {
        increaseCount(value);
        return;
    }

    int endY = startY + N;
    int endX = startX + N;

    if (checkSame(startY, startX, N))
    {
        increaseCount(value);
        return;
    }

    for (int p = 0; p < 3; p++)
        for (int q = 0; q < 3; q++)
            calculateResult((startY) + (N / 3) * p, (startX) + (N / 3) * q, N / 3);
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
            cin >> papers[i][j];
        }
    }

    calculateResult(0, 0, N);

    cout << minusOneCount << '\n'
         << zeroCount << '\n'
         << oneCount << '\n';

    return 0;
}