#include <iostream>
#include <fstream> // ��� ������ � �������
#include <string>

using namespace std;

struct Student {
    string name;
    int course;
    string group;
    int grades[4]; // ����� ��� ��������� 4-� ������
};

int main() {
    int n; // ʳ������ ��������
    cout << "Enter number of students: ";
    cin >> n;

    Student students[5]; // ����� ��������

    int lowGradeCount = 0; // ˳������� �������� � �������� < 50

    // ³�������� ���� ��� ������ ����������
    ofstream outFile("results.txt");

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1; // ���� �� ������� ������� ����
    }

    // �������� ��������� � ����
    outFile << "Student Name, Course, Group, Low Grade Count\n";

    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter course: ";
        cin >> students[i].course;
        cout << "Enter group: ";
        cin >> students[i].group;

        bool hasLowGrade = false; // �������� ��� �������� � ������� < 50

        cout << "Enter 4 ratings: ";
        for (int j = 0; j < 4; j++) {
            cin >> students[i].grades[j];
            if (students[i].grades[j] < 50) {
                hasLowGrade = true; // ³������, ���� �������� ������ < 50
            }
        }

        if (hasLowGrade) {
            lowGradeCount++; // �������� ��������, ���� ������� �� ������ < 50
        }

        // �������� ��� �������� � ����
        outFile << students[i].name << ", " << students[i].course << ", " << students[i].group << ", " << (hasLowGrade ? "Yes" : "No") << endl;
    }

    // ��������� ����������
    cout << "\nThe number of students with a score of less than 50 in at least one subject: " << lowGradeCount << endl;

    // �������� ��������� � ����
    outFile << "\nTotal students with a low grade: " << lowGradeCount << endl;

    // ��������� ����
    outFile.close();

    return 0;
}
