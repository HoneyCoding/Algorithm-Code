// https://www.acmicpc.net/problem/10828
// BOJ 10828번 - 스택

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string input;
    int X;

    cin >> N;
    while (N--)
    {
        cin >> input;
        if (input == "push")
        {
            cin >> X;
            s.push(X);
        }
        else if (input == "pop")
        {
            if (s.empty())
                cout << -1 << '\n';
            else
            {
                cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (input == "size")
        {
            cout << s.size() << '\n';
        }
        else if (input == "empty")
        {
            cout << (s.empty() ? 1 : 0) << '\n';
        }
        else if (input == "top")
        {
            if (s.empty())
                cout << -1 << '\n';
            else
                cout << s.top() << '\n';
        }
    }

    return 0;
}