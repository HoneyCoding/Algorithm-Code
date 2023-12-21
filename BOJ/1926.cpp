// https://www.acmicpc.net/problem/1926
// BOJ 1926번 - 그림

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;

int n, m;
int picture_count;
int picture_area;
int max_picture_area;
int arr[502][502]; // [세로][가로]
int visited[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == 0)
            {
                q.push({i, j});
                visited[i][j] = 1;
                picture_area = 1;
                picture_count++;

                while (!q.empty())
                {
                    pair<int, int> item = q.front();
                    q.pop();
                    int cy = item.first;
                    int cx = item.second;
                    for (int d = 0; d < 4; d++)
                    {
                        int ny = cy + dy[d];
                        int nx = cx + dx[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                            continue;
                        if (visited[ny][nx] == 1 || arr[ny][nx] == 0)
                            continue;
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                        picture_area++;
                    }
                }

                max_picture_area = max(max_picture_area, picture_area);
            }
        }
    }

    cout << picture_count << '\n'
         << max_picture_area << '\n';

    return 0;
}