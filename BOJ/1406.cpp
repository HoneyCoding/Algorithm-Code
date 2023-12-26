// https://www.acmicpc.net/problem/1406
// BOJ 1406번 - 에디터

#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    string command;
    int N;

    cin >> input;
    cin >> N;

    list<char> editor;

    for (char ch : input)
    {
        editor.push_back(ch);
    }

    list<char>::iterator cursor = editor.end();

    while (N--)
    {
        cin >> command;
        if ("L" == command && cursor != editor.begin())
        {
            cursor--;
        }
        else if ("D" == command && cursor != editor.end())
        {
            cursor++;
        }
        else if ("B" == command && cursor != editor.begin())
        {
            cursor = editor.erase(--cursor);
        }
        else if ("P" == command)
        {
            char ch;
            cin >> ch;
            editor.insert(cursor, ch);
        }
    }

    for (char ch : editor)
    {
        cout << ch;
    }

    cout << '\n';

    return 0;
}