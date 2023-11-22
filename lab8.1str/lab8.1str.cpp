#include <iostream>
#include <string>

using namespace std;

// �������, ��� ��������, �� ������ ����� �� ����� ����� "while"
bool containsWhile(const string& str) {
    size_t found = str.find("while");
    return found != string::npos;
}

// �������, ��� ������ ����� ����� ���� "while" �� "**" � �������� �����
void replaceWhile(string& str) {
    size_t pos = 0;
    while ((pos = str.find("while", pos)) != string::npos) {
        str.replace(pos, 5, "**");
        pos += 2; // ���������� �������� pos ���� �����
    }
}

int main() {
    // ������� �����
    string inputString;
    cout << "������ �����: ";
    getline(cin, inputString);

    // �������� 1: ��������, �� ������ ����� �� ����� ����� "while"
    if (containsWhile(inputString)) {
        cout << "����� ������ �� ����� ����� 'while'" << endl;
    }
    else {
        cout << "����� �� ������ �� ����� ����� 'while'" << endl;
    }

    // �������� 2: ����� ����� ����� ���� "while" �� "**"
    replaceWhile(inputString);
    cout << "��������� ���� �����: " << inputString << endl;

    return 0;
}

