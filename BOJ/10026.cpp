// https://www.acmicpc.net/problem/10026
// BOJ 10026번 - 적록색약

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> rgbQueue;
queue<pair<int, int>> rbQueue;

char rgbMap[102][102];
char rbMap[102][102];
bool rgbVisited[102][102];
bool rbVisited[102][102];
int N;
string input;

int rgbResult;
int rbResult;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < N; j++)
        {
            rgbMap[j][i] = input[j];
            rbMap[j][i] = (input[j] == 'G') ? 'R' : input[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!rgbVisited[j][i])
            {
                rgbQueue.push({j, i});
                rgbResult++;
            }
            if (!rbVisited[j][i])
            {
                rbQueue.push({j, i});
                rbResult++;
            }
            while (!rgbQueue.empty())
            {
                pair<int, int> cpos = rgbQueue.front();
                rgbQueue.pop();
                int cy = cpos.first;
                int cx = cpos.second;

                for (int i = 0; i < 4; i++)
                {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (rgbMap[cy][cx] != rgbMap[ny][nx] || rgbVisited[ny][nx])
                        continue;
                    rgbQueue.push({ny, nx});
                    rgbVisited[ny][nx] = true;
                }
            }

            while (!rbQueue.empty())
            {
                pair<int, int> cpos = rbQueue.front();
                rbQueue.pop();
                int cy = cpos.first;
                int cx = cpos.second;

                for (int i = 0; i < 4; i++)
                {
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (rbMap[cy][cx] != rbMap[ny][nx] || rbVisited[ny][nx])
                        continue;
                    rbQueue.push({ny, nx});
                    rbVisited[ny][nx] = true;
                }
            }
        }
    }

    cout << rgbResult << " " << rbResult << "\n";

    return 0;
}