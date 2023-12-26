// https://www.acmicpc.net/problem/7576
// BOJ 7576번 - 토마토

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int box[1002][1002];
int days[1002][1002];
queue<pair<int, int>> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

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
            if (box[ny][nx] != 0)
                continue;
            days[ny][nx] = days[cy][cx] + 1;
            box[ny][nx] = 1;
            q.push({ny, nx});
        }
    }

    int result = 0;
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            result = max(result, days[i][j]);
            if (box[i][j] == 0)
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << result << '\n';

    return 0;
}