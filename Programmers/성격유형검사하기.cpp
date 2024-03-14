#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";

    map<string, int> m;

    m.insert({"R", 0});
    m.insert({"T", 0});
    m.insert({"C", 0});
    m.insert({"F", 0});
    m.insert({"J", 0});
    m.insert({"M", 0});
    m.insert({"A", 0});
    m.insert({"N", 0});

    int size = survey.size();

    for (int i = 0; i < size; i++)
    {
        int score = 0;
        string target = "";
        switch (choices[i])
        {
        case 1:
        case 2:
        case 3:
            score = 4 - choices[i];
            target = survey[i][0];
            break;
        case 5:
        case 6:
        case 7:
            score = choices[i] - 4;
            target = survey[i][1];
            break;
        }
        auto map_it = m.find(target);
        m[target] = score + (map_it->second);
    }

    if (m.find("R")->second >= m.find("T")->second)
        answer += "R";
    else
        answer += "T";

    if (m.find("C")->second >= m.find("F")->second)
        answer += "C";
    else
        answer += "F";

    if (m.find("J")->second >= m.find("M")->second)
        answer += "J";
    else
        answer += "M";

    if (m.find("A")->second >= m.find("N")->second)
        answer += "A";
    else
        answer += "N";

    return answer;
}

int main()
{
    cout << solution({"AN", "CF", "MJ", "RT", "NA"}, {5, 3, 2, 7, 5}) << '\n';
    cout << solution({"TR", "RT", "TR"}, {7, 1, 3}) << '\n';
}