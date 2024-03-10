// https://www.acmicpc.net/problem/9012
// BOJ 9012번 - 괄호

#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;

    cin >> N;

    while (N--)
    {
        stack<char> s;
        string input;
        cin >> input;

        for (char ch : input)
        {
            if (ch == '(')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                    s.push(ch);
            }
        }

        if (s.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}