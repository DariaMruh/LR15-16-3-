#include <iostream>
#include <fstream> // Для роботи з файлами
#include <string>

using namespace std;

struct Student {
    string name;
    int course;
    string group;
    int grades[4]; // Масив для зберігання 4-х оцінок
};

int main() {
    int n; // Кількість студентів
    cout << "Enter number of students: ";
    cin >> n;

    Student students[5]; // Масив студентів

    int lowGradeCount = 0; // Лічильник студентів з оцінками < 50

    // Відкриваємо файл для запису результатів
    ofstream outFile("results.txt");

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1; // Якщо не вдалося відкрити файл
    }

    // Записуємо заголовок у файл
    outFile << "Student Name, Course, Group, Low Grade Count\n";

    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter course: ";
        cin >> students[i].course;
        cout << "Enter group: ";
        cin >> students[i].group;

        bool hasLowGrade = false; // Позначка для студента з оцінкою < 50

        cout << "Enter 4 ratings: ";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].grades[j];
            if (students[i].grades[j] < 50) {
                hasLowGrade = true; // Відмічаємо, якщо знайдена оцінка < 50
            }
        }

        if (hasLowGrade) {
            lowGradeCount++; // Збільшуємо лічильник, якщо студент має оцінку < 50
        }

        // Записуємо дані студента в файл
        outFile << students[i].name << ", " << students[i].course << ", " << students[i].group << ", " << (hasLowGrade ? "Yes" : "No") << endl;
    }

    // Виведення результату
    cout << "\nThe number of students with a score of less than 50 in at least one subject: " << lowGradeCount << endl;

    // Записуємо результат у файл
    outFile << "\nTotal students with a low grade: " << lowGradeCount << endl;

    // Закриваємо файл
    outFile.close();

    return 0;
}
