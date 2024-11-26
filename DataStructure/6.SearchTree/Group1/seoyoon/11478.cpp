#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> substrings; // �ߺ� ���Ÿ� ���� Ž�� Ʈ��

    // ��� �κ� ���ڿ� ����
    for (size_t start = 0; start < s.size(); ++start) {
        string substring = ""; // �κ� ���ڿ� �ʱ�ȭ
        for (size_t end = start; end < s.size(); ++end) {
            substring += s[end]; // �κ� ���ڿ� Ȯ��
            substrings.insert(substring); // Ž�� Ʈ���� �߰�
        }
    }

    // ���� �ٸ� �κ� ���ڿ��� ���� ���
    cout << substrings.size() << endl;

    return 0;
}
