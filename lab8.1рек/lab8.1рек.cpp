#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

bool containsWhile(const char* str, size_t index) {
    if (index + 4 > strlen(str)) {
        return false;  // ��������� ������ "while", ���� ���������� ����� 4 �������
    }

    return (str[index] == 'w' && str[index + 1] == 'h' && str[index + 2] == 'i' && str[index + 3] == 'l' && str[index + 4] == 'e') ||
        containsWhile(str, index + 1);
}

void replaceWhile(char* str, size_t index) {
    if (index + 4 > strlen(str)) {
        return;  // ��������� ������ "while", ���� ���������� ����� 4 �������
    }

    if (str[index] == 'w' && str[index + 1] == 'h' && str[index + 2] == 'i' && str[index + 3] == 'l' && str[index + 4] == 'e') {
        str[index] = '*';
        str[index + 1] = '*';
        str[index + 2] = '\0';
        strcat_s(str, 101, str + index + 5); // ���������� �� "e" � ���� "while"
        replaceWhile(str, index);  // ��������� ������� ����� ��� ��������� ����� ����� ��������
    }
    else {
        replaceWhile(str, index + 1);
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "������ �����:" << endl;
    char str[101];
    cin.getline(str, 100);

    size_t index = 0;
    bool containsAllWhile = containsWhile(str, index);

    cout << "����� ������ �� ����� � ���� 'while': " << (containsAllWhile ? "true" : "false") << endl;

    replaceWhile(str, index);

    cout << "������������� �����: " << str << endl;

    return 0;
}

