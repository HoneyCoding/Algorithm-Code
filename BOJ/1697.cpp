// https://www.acmicpc.net/problem/1697
// BOJ 1697번 - 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> q;
int quickTime[100003];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i <= 100000; i++)
        quickTime[i] = -1;

    q.push(N);
    quickTime[N] = 0;

    bool resultFlag = false;

    while (!q.empty())
    {
        int cpos = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int npos = cpos;
            if (i == 0)
            {
                npos -= 1;
            }
            else if (i == 1)
            {
                npos += 1;
            }
            else
            {
                npos *= 2;
            }
            if (npos < 0 || npos > 100000)
                continue;
            if (quickTime[npos] != -1)
                continue;
            q.push(npos);
            quickTime[npos] = quickTime[cpos] + 1;
            if (npos == K)
            {
                resultFlag = true;
                break;
            }
        }

        if (resultFlag)
            break;
    }

    cout << quickTime[K] << '\n';

    return 0;
}