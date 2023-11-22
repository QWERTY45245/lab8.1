#include <iostream>
#include <string>

using namespace std;

// Функція, яка перевіряє, чи містить рядок всі букви слова "while"
bool containsWhile(const string& str) {
    size_t found = str.find("while");
    return found != string::npos;
}

// Функція, яка замінює кожну групу букв "while" на "**" у заданому рядку
void replaceWhile(string& str) {
    size_t pos = 0;
    while ((pos = str.find("while", pos)) != string::npos) {
        str.replace(pos, 5, "**");
        pos += 2; // Переміщення позначки pos після заміни
    }
}

int main() {
    // Вхідний рядок
    string inputString;
    cout << "Введіть рядок: ";
    getline(cin, inputString);

    // Завдання 1: Перевірка, чи містить рядок всі букви слова "while"
    if (containsWhile(inputString)) {
        cout << "Рядок містить всі букви слова 'while'" << endl;
    }
    else {
        cout << "Рядок не містить всі букви слова 'while'" << endl;
    }

    // Завдання 2: Заміна кожної групи букв "while" на "**"
    replaceWhile(inputString);
    cout << "Результат після заміни: " << inputString << endl;

    return 0;
}

