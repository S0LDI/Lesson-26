#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Функція для порівняння відповіді користувача з правильною відповіддю
bool checkAnswer(const string& userAnswer, const string& correctAnswer, int points) {
    return userAnswer == correctAnswer;
}

int main() {
    setlocale(LC_ALL, "ukr");
    // Питання та правильні відповіді
    map<string, pair<string, int>> questions = {
        {"Питання 1", {"Відповідь 1", 5}},
        {"Питання 2", {"Відповідь 2", 4}},
        {"Питання 3", {"Відповідь 3", 3}},
        {"Питання 4", {"Відповідь 4", 2}},
        {"Питання 5", {"Відповідь 5", 1}}
    };

    int totalPoints = 0;  // Загальна кількість балів

    // Перебираємо питання
    for (const auto& pair : questions) {
        cout << pair.first << ": " << pair.second.first << endl;

        string userAnswer;
        cout << "Ваша відповідь: ";
        getline(cin, userAnswer);

        // Перевірка відповіді користувача
        if (checkAnswer(userAnswer, pair.second.first, pair.second.second)) {
            totalPoints += pair.second.second;  // Зарахувати бали за правильну відповідь
            cout << "Правильно! За це питання ви отримали " << pair.second.second << " балів." << endl;
        }
        else {
            cout << "Неправильно! Вірна відповідь: " << pair.second.first << endl;
        }

        // Почекайте 60 секунд перед наступним питанням
        cout << "Наступне питання через 60 секунд..." << endl;
        this_thread::sleep_for(chrono::seconds(60));
    }

    // Виведення результатів
    cout << "Гра завершена. Ваша загальна кількість балів: " << totalPoints << endl;

    return 0;
}
