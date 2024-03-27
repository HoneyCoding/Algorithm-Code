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

        int spin_value = spin_direction == 1 ? 7 : 1;
        next_top_indexes[gear_num] = (current_top_indexes[gear_num] + spin_value) % 8;
        for (int j = 1; j < 4; j++)
        {
            // 우측 톱니바퀴
            if (
                gear_num + j < 4 &&
                next_top_indexes[gear_num + (j - 1)] != current_top_indexes[gear_num + (j - 1)] &&
                gears[(current_top_indexes[gear_num + (j - 1)] + 2) % 8][gear_num + (j - 1)] != gears[(current_top_indexes[gear_num + j] + 6) % 8][gear_num + j])
                next_top_indexes[gear_num + j] = (current_top_indexes[gear_num + j] + (j % 2 == 0 ? spin_value : (8 - spin_value))) % 8;
            // 좌측 톱니바퀴
            if (
                gear_num - j >= 0 &&
                next_top_indexes[gear_num + (-j + 1)] != current_top_indexes[gear_num + (-j + 1)] &&
                gears[(current_top_indexes[gear_num + (-j + 1)] + 6) % 8][gear_num + (-j + 1)] != gears[(current_top_indexes[gear_num - j] + 2) % 8][gear_num - j])
                next_top_indexes[gear_num - j] = (current_top_indexes[gear_num - j] + (j % 2 == 0 ? spin_value : (8 - spin_value))) % 8;
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