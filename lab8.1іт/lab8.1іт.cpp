#include<Windows.h>
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

// Функція для визначення, чи є серед символів всі букви слова "while"
bool containsWhile(const char* str) {
    for (const char* ptr = str; *ptr != '\0'; ++ptr) {
        if (*ptr == 'w' || *ptr == 'h' || *ptr == 'i' || *ptr == 'l' || *ptr == 'e') {
            continue;
        }
        return false;
    }
    return true;
}

// Функція для заміни кожної групи "while" на "**"
void replaceWhile(char* str) {
    size_t len = strlen(str);
    if (len < 5) {
        return;  // Рядок не може містити "while"
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
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 100);

    // Завдання 1: Визначення, чи є всі букви слова "while" у рядку
    cout << "Рядок містить всі літери в слові 'while': " << (containsWhile ? "true" : "false") << endl;
    
    // Завдання 2: Заміна кожної групи "while" на "**"
    replaceWhile(str);
    cout << "Модифікований рядок: " << str << endl;

    return 0;
}

    

  