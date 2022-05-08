// https://www.acmicpc.net/problem/1475
// BOJ 1475번 - 방 번호

#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int list[30] = {0};

    int num;

    cin >> num;

    do {
        if (num % 10 == 9)
            list[6]++;
        else
            list[num % 10]++;
    } while(num /= 10);

    list[6] = (list[6] / 2) + (list[6] % 2);

    int result = 0;

    for(int i = 0; i < 9; i++) {
        if(result < list[i]) {
            result = list[i];
        }
    }

    cout << result << '\n';

    return 0;
}