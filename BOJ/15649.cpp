// https://www.acmicpc.net/problem/15649
// BOJ 15649번 - N과 M (1)

#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool flag[12];
vector<int> result;

void printResult()
{
    for (int num : result)
    {
        cout << num << ' ';
    }
    cout << '\n';
}

void backtracking(int N, int M)
{
    if (M == 0)
    {
        printResult();
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (flag[i] == true)
            continue;
        flag[i] = true;
        result.push_back(i);
        backtracking(N, M - 1);
        result.pop_back();
        flag[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    backtracking(N, M);

    return 0;
}