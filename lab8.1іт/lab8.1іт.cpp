#include<Windows.h>
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

// ������� ��� ����������, �� � ����� ������� �� ����� ����� "while"
bool containsWhile(const char* str) {
    for (const char* ptr = str; *ptr != '\0'; ++ptr) {
        if (*ptr == 'w' || *ptr == 'h' || *ptr == 'i' || *ptr == 'l' || *ptr == 'e') {
            continue;
        }
        return false;
    }
    return true;
}

// ������� ��� ����� ����� ����� "while" �� "**"
void replaceWhile(char* str) {
    size_t len = strlen(str);
    if (len < 5) {
        return;  // ����� �� ���� ������ "while"
    }

    for (size_t i = 0; i < len - 4; ++i) {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e') {
            str[i] = '*';
            str[i + 1] = '*';
            str[i + 2] = '\0';
            strcat_s(str, 101, str + i + 5);
            len = strlen(str);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char str[101];
    cout << "������ �����:" << endl;
    cin.getline(str, 100);

    // �������� 1: ����������, �� � �� ����� ����� "while" � �����
    cout << "����� ������ �� ����� � ���� 'while': " << (containsWhile ? "true" : "false") << endl;
    
    // �������� 2: ����� ����� ����� "while" �� "**"
    replaceWhile(str);
    cout << "������������� �����: " << str << endl;

    return 0;
}

    

  