// https://www.acmicpc.net/problem/1546
// BOJ 1546번 - 평균

#include <iostream>
#include <algorithm>

using namespace std;

int scores[1001];
int N;
int max_score = 1;

double avg_score = 0.0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> scores[i];
        max_score = max(max_score, scores[i]);
        avg_score += scores[i];
    }

    avg_score /= N;
    avg_score = (avg_score / max_score) * 100;

    cout << avg_score << '\n';

    return 0;
}