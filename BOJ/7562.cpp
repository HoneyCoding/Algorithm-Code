// https://www.acmicpc.net/problem/7562
// BOJ 7562번 - 나이트의 이동

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int T;
int I;
int knightX, knightY;
int destX, destY;

int map[303][303];
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int dx[8] = {2, 1, -2, -1, -2, -1, 2, 1};

int result;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--)
    {
        queue<pair<int, int>> q;
        cin >> I;
        cin >> knightX >> knightY;
        q.push({knightY, knightX});
        cin >> destX >> destY;

        for (int i = 0; i < I; i++)
            for (int j = 0; j < I; j++)
                map[i][j] = -1;
        map[knightY][knightX] = 0;

        while (!q.empty())
        {
            pair<int, int> cpos = q.front();
            q.pop();
            int cy = cpos.first;
            int cx = cpos.second;

            if (cy == destY && cx == destX)
            {
                result = map[cy][cx];
                break;
            }

            for (int i = 0; i < 8; i++)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (ny < 0 || nx < 0 || ny >= I || nx >= I)
                    continue;
                if (map[ny][nx] != -1)
                    continue;
                map[ny][nx] = map[cy][cx] + 1;
                q.push({ny, nx});
            }
        }

        cout << result << '\n';
    }

    return 0;
}