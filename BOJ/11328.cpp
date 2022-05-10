// https://www.acmicpc.net/problem/11328
// BOJ 11328번 - Strfry

#include <iostream>

using namespace std;

int N;
string input1;
string input2;

bool check_possible(string s1, string s2) {
    int arr1[100];
    int arr2[100];

    for(int i='a'-'a'; i<='z'-'a'; i++) {
        arr2[i] = arr1[i] = 0;
    }

    for(char c: s1) {
        arr1[c-'a']++;
    }
    for(char c: s2) {
        arr2[c-'a']++;
    }

    for(int i='a'-'a'; i<='z'-'a'; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> input1 >> input2;
        if(check_possible(input1, input2)) {
            cout << "Possible" << '\n';
        } else {
            cout << "Impossible" << '\n';
        }
    }

    return 0;
}