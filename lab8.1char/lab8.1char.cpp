#include <iostream>
#include <cstring>
#include<Windows.h>
using namespace std;

// ������� ��� �������� �������� "while" � �����
bool findWhile(const char* str, size_t index) {
    const char* whileStr = "while";
    size_t whileLen = strlen(whileStr);

    while (index + whileLen <= strlen(str)) {
        if (strncmp(str + index, whileStr, whileLen) == 0) {
            return true;
        }
        ++index;
    }

    return false;
}

// ������� ��� ����� ����� ����� "while" �� "**"
void replaceWhile(char* str, size_t index) {
    const char* whileStr = "while";
    size_t whileLen = strlen(whileStr);

    while (index + whileLen <= strlen(str)) {
        if (strncmp(str + index, whileStr, whileLen) == 0) {
            str[index] = '*';
            str[index + 1] = '*';
            // ����� ����� ����� "while" �� "**"
            memmove(str + index + 2, str + index + whileLen, strlen(str + index + whileLen) + 1);
            // ���������� �� "**"
            index += 2;
        }
        else {
            ++index;
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char str[101];
    cout << "������ �����:" << endl;
    cin.getline(str, 100);

    size_t index = 0;
    bool containsAllWhile = findWhile(str, index);

    cout << "����� ������ �� ����� � ���� 'while': " << (containsAllWhile ? "true" : "false") << endl;

    replaceWhile(str, index);

    cout << "������������� �����: " << str << endl;

    return 0;
}
