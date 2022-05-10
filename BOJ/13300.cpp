// https://www.acmicpc.net/problem/13300
// BOJ 13300번 - 방 배정

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int s, y;

int people[4][10]; // people[성별][학년]

const int WOMAN = 0;
const int MAN = 1;

int room_cnt = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        cin >> s >> y;
        people[s][y] += 1;
    }

    for(int i=0; i<=1; i++) {
        for(int j=1; j<=6; j++) {
            room_cnt += (people[i][j] / k + (people[i][j] % k != 0 ? 1 : 0));
        }
    }

    cout << room_cnt << '\n';

    return 0;
}