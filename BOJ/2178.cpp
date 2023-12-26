// https://www.acmicpc.net/problem/2178
// BOJ 2178번 - 미로 탐색

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int arr[102][102];
int min_count[102][102];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string input;
queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = input[j] - '0';
            min_count[i][j] = -1;
        }
    }

    q.push({0, 0});
    min_count[0][0] = 1;

    while (!q.empty())
    {
        pair<int, int> cpos = q.front();
        q.pop();
        int cy = cpos.first;
        int cx = cpos.second;

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (arr[ny][nx] == 0 || min_count[ny][nx] != -1)
                continue;
            min_count[ny][nx] = min_count[cy][cx] + 1;
            q.push({ny, nx});
        }
    }

    cout << min_count[N - 1][M - 1] << '\n';

    return 0;
}