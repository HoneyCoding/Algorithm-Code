// https://www.acmicpc.net/problem/7569
// BOJ 7569번 - 토마토

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int M, N, H;
int map[103][103][103]; // map[y][x][z]
int day[103][103][103];

int result = 0;

queue<tuple<int, int, int>> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                cin >> map[y][x][z];
                if (map[y][x][z] == 1)
                {
                    q.push({y, x, z});
                }
            }
        }
    }

    while (!q.empty())
    {
        tuple<int, int, int> cpos = q.front();
        int cy = get<0>(cpos);
        int cx = get<1>(cpos);
        int cz = get<2>(cpos);
        int nday = day[cy][cx][cz] + 1;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nz = cz + dz[i];

            if (ny < 0 || nx < 0 || nz < 0 || ny >= N || nx >= M || nz >= H)
                continue;
            if (map[ny][nx][nz] != 0)
                continue;
            map[ny][nx][nz] = 1;
            q.push({ny, nx, nz});
            day[ny][nx][nz] = nday;
            result = max(day[ny][nx][nz], result);
        }
    }

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (map[y][x][z] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << result << '\n';

    return 0;
}