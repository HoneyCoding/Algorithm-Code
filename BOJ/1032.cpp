// https://www.acmicpc.net/problem/1032
// BOJ 1032번 - 명령 프롬프트

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> v;
    int N;
    string input;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    string answer = input;
    int answer_size = answer.size();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < answer_size; j++)
        {
            if (answer[j] != v[i][j])
                answer[j] = '?';
        }
    }

    cout << answer << '\n';

    return 0;
}