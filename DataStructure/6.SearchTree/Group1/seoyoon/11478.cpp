#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> substrings; // 중복 제거를 위한 탐색 트리

    // 모든 부분 문자열 생성
    for (size_t start = 0; start < s.size(); ++start) {
        string substring = ""; // 부분 문자열 초기화
        for (size_t end = start; end < s.size(); ++end) {
            substring += s[end]; // 부분 문자열 확장
            substrings.insert(substring); // 탐색 트리에 추가
        }
    }

    // 서로 다른 부분 문자열의 개수 출력
    cout << substrings.size() << endl;

    return 0;
}
