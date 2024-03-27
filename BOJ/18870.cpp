// https://www.acmicpc.net/problem/18870
// BOJ 18870번 - 좌표 압축

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
int x[1000002];
int sorted_x[1000002];

map<int, int> m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        sorted_x[i] = x[i];
        m[sorted_x[i]] = 0;
    }

    sort(sorted_x, sorted_x + N);

    for (int i = 1; i < N; i++)
    {
        if (sorted_x[i - 1] < sorted_x[i])
            m[sorted_x[i]] = m[sorted_x[i - 1]] + 1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << m[x[i]] << ' ';
    }
    cout << '\n';

    return 0;
}