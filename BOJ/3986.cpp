// https://www.acmicpc.net/problem/3986
// BOJ 3986번 - 좋은 단어

#include <iostream>
#include <stack>

using namespace std;

int N;
string input;
int result;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    while (N--)
    {
        cin >> input;
        stack<char> s;
        for (char c : input)
        {
            if (!s.empty() && s.top() == c)
                s.pop();
            else
                s.push(c);
        }
        if (s.empty())
            result++;
    }

    cout << result << '\n';

    return 0;
}