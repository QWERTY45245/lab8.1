#include <iostream>
#include <cstring>
#include<Windows.h>
using namespace std;

// Функція для перевірки наявності "while" у рядку
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

// Функція для заміни кожної групи "while" на "**"
void replaceWhile(char* str, size_t index) {
    const char* whileStr = "while";
    size_t whileLen = strlen(whileStr);

    while (index + whileLen <= strlen(str)) {
        if (strncmp(str + index, whileStr, whileLen) == 0) {
            str[index] = '*';
            str[index + 1] = '*';
            // Заміна кожної групи "while" на "**"
            memmove(str + index + 2, str + index + whileLen, strlen(str + index + whileLen) + 1);
            // Переходимо за "**"
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
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 100);

    size_t index = 0;
    bool containsAllWhile = findWhile(str, index);

    cout << "Рядок містить всі літери в слові 'while': " << (containsAllWhile ? "true" : "false") << endl;

    replaceWhile(str, index);

    cout << "Модифікований рядок: " << str << endl;

    return 0;
}
