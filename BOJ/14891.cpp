// https://www.acmicpc.net/problem/14891
// BOJ 14891번 - 톱니바퀴

#include <iostream>

using namespace std;

int gears[8][8]; // gears[톱니바퀴 위치][톱니바퀴 번호]
int K;
int current_top_indexes[8];
int next_top_indexes[8];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < 8; j++)
        {
            gears[j][i] = input[j] - '0';
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int gear_num, spin_direction;
        cin >> gear_num >> spin_direction;
        gear_num -= 1;

        for (int j = 0; j < 4; j++)
            current_top_indexes[j] = next_top_indexes[j];

        if (spin_direction == 1) // 시계 방향 회전
        {
            next_top_indexes[gear_num] = (current_top_indexes[gear_num] + 7) % 8;
            if (
                gear_num + 1 < 4 &&
                next_top_indexes[gear_num] != current_top_indexes[gear_num] &&
                gears[(current_top_indexes[gear_num] + 2) % 8][gear_num] != gears[(current_top_indexes[gear_num + 1] + 6) % 8][gear_num + 1])
                next_top_indexes[gear_num + 1] = (current_top_indexes[gear_num + 1] + 1) % 8;
            if (
                gear_num + 2 < 4 &&
                next_top_indexes[gear_num + 1] != current_top_indexes[gear_num + 1] &&
                gears[(current_top_indexes[gear_num + 1] + 2) % 8][gear_num + 1] != gears[(current_top_indexes[gear_num + 2] + 6) % 8][gear_num + 2])
                next_top_indexes[gear_num + 2] = (current_top_indexes[gear_num + 2] + 7) % 8;
            if (
                gear_num + 3 < 4 &&
                next_top_indexes[gear_num + 2] != current_top_indexes[gear_num + 2] &&
                gears[(current_top_indexes[gear_num + 2] + 2) % 8][gear_num + 2] != gears[(current_top_indexes[gear_num + 3] + 6) % 8][gear_num + 3])
                next_top_indexes[gear_num + 3] = (current_top_indexes[gear_num + 3] + 1) % 8;
            if (
                gear_num - 1 >= 0 &&
                next_top_indexes[gear_num] != current_top_indexes[gear_num] &&
                gears[(current_top_indexes[gear_num] + 6) % 8][gear_num] != gears[(current_top_indexes[gear_num - 1] + 2) % 8][gear_num - 1])
                next_top_indexes[gear_num - 1] = (current_top_indexes[gear_num - 1] + 1) % 8;
            if (
                gear_num - 2 >= 0 &&
                next_top_indexes[gear_num - 1] != current_top_indexes[gear_num - 1] &&
                gears[(current_top_indexes[gear_num - 1] + 6) % 8][gear_num - 1] != gears[(current_top_indexes[gear_num - 2] + 2) % 8][gear_num - 2])
                next_top_indexes[gear_num - 2] = (current_top_indexes[gear_num - 2] + 7) % 8;
            if (
                gear_num - 3 >= 0 &&
                next_top_indexes[gear_num - 2] != current_top_indexes[gear_num - 2] &&
                gears[(current_top_indexes[gear_num - 2] + 6) % 8][gear_num - 2] != gears[(current_top_indexes[gear_num - 3] + 2) % 8][gear_num - 3])
                next_top_indexes[gear_num - 3] = (current_top_indexes[gear_num - 3] + 1) % 8;
        }
        else if (spin_direction == -1) // 반시계 방향 회전
        {
            next_top_indexes[gear_num] = (current_top_indexes[gear_num] + 1) % 8;
            if (
                gear_num + 1 < 4 &&
                next_top_indexes[gear_num] != current_top_indexes[gear_num] &&
                gears[(current_top_indexes[gear_num] + 2) % 8][gear_num] != gears[(current_top_indexes[gear_num + 1] + 6) % 8][gear_num + 1])
                next_top_indexes[gear_num + 1] = (current_top_indexes[gear_num + 1] + 7) % 8;
            if (
                gear_num + 2 < 4 &&
                next_top_indexes[gear_num + 1] != current_top_indexes[gear_num + 1] &&
                gears[(current_top_indexes[gear_num + 1] + 2) % 8][gear_num + 1] != gears[(current_top_indexes[gear_num + 2] + 6) % 8][gear_num + 2])
                next_top_indexes[gear_num + 2] = (current_top_indexes[gear_num + 2] + 1) % 8;
            if (
                gear_num + 3 < 4 &&
                next_top_indexes[gear_num + 2] != current_top_indexes[gear_num + 2] &&
                gears[(current_top_indexes[gear_num + 2] + 2) % 8][gear_num + 2] != gears[(current_top_indexes[gear_num + 3] + 6) % 8][gear_num + 3])
                next_top_indexes[gear_num + 3] = (current_top_indexes[gear_num + 3] + 7) % 8;
            if (
                gear_num - 1 >= 0 &&
                next_top_indexes[gear_num] != current_top_indexes[gear_num] &&
                gears[(current_top_indexes[gear_num] + 6) % 8][gear_num] != gears[(current_top_indexes[gear_num - 1] + 2) % 8][gear_num - 1])
                next_top_indexes[gear_num - 1] = (current_top_indexes[gear_num - 1] + 7) % 8;
            if (
                gear_num - 2 >= 0 &&
                next_top_indexes[gear_num - 1] != current_top_indexes[gear_num - 1] &&
                gears[(current_top_indexes[gear_num - 1] + 6) % 8][gear_num - 1] != gears[(current_top_indexes[gear_num - 2] + 2) % 8][gear_num - 2])
                next_top_indexes[gear_num - 2] = (current_top_indexes[gear_num - 2] + 1) % 8;
            if (
                gear_num - 3 >= 0 &&
                next_top_indexes[gear_num - 2] != current_top_indexes[gear_num - 2] &&
                gears[(current_top_indexes[gear_num - 2] + 6) % 8][gear_num - 2] != gears[(current_top_indexes[gear_num - 3] + 2) % 8][gear_num - 3])
                next_top_indexes[gear_num - 3] = (current_top_indexes[gear_num - 3] + 7) % 8;
        }
    }

    int answer = 0;

    for (int i = 0; i < 4; i++)
    {
        if (gears[next_top_indexes[i]][i] != 1)
            continue;
        int add_value = 1;
        for (int j = 0; j < i; j++)
            add_value *= 2;
        answer += add_value;
    }

    std::cout << answer << '\n';

    return 0;
}