// https://www.acmicpc.net/problem/9506
// BOJ 9506번 - 약수들의 합

#include <iostream>
#include <vector>

using namespace std;

void solution(int n)
{
    int sum = 0;
    int factors[100000] = {
        0,
    };
    int factor_size = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            factors[factor_size++] = i;
        }
    }

    if (sum == n)
    {
        cout << n << " = ";
        for (int i = 0; i < factor_size; i++)
        {
            cout << factors[i];
            if (i != factor_size - 1)
                cout << " + ";
        }
        cout << '\n';
    }
    else
    {
        cout << n << " is NOT perfect." << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        solution(n);
    }

    return 0;
}