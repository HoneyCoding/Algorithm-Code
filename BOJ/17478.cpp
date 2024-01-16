// https://www.acmicpc.net/problem/17478
// BOJ 17478번 - 재귀함수가 뭔가요?

#include <iostream>

using namespace std;

int N;

void printTabs(int N)
{
    for (int i = 0; i < N; i++)
        cout << "____";
}

void print(int depth)
{
    printTabs(depth);
    cout << "\"재귀함수가 뭔가요?\"\n";
    if (depth >= N)
    {
        printTabs(depth);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';
        printTabs(depth);
        cout << "라고 답변하였지." << '\n';
        return;
    }

    printTabs(depth);
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';
    printTabs(depth);
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';
    printTabs(depth);
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';
    print(depth + 1);
    printTabs(depth);
    cout << "라고 답변하였지." << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    print(0);

    return 0;
}