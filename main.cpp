#include <iostream>
#include <iomanip> // For formatting
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    int marks[5];
    int total;
    float percentage;
    char grade;

public:
    // Function to input student details
    void inputDetails() {
        cout << "Enter student name: ";
        cin.ignore(); // To avoid getline skipping input
        getline(cin, name);

        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter marks for 5 subjects: ";
        for(int i = 0; i < 5; i++) {
            cin >> marks[i];
        }
    }

    // Function to calculate total, percentage, and grade
    void calculate() {
        total = 0;
        for(int i = 0; i < 5; i++) {
            total += marks[i];
        }

        percentage = (total / 500.0) * 100; // assuming each subject out of 100

        if(percentage >= 90)
            grade = 'A';
        else if(percentage >= 75)
            grade = 'B';
        else if(percentage >= 50)
            grade = 'C';
        else
            grade = 'F';
    }

    // Function to display the report card
    void displayReport() {
        cout << "\n-------------------------------\n";
        cout << "          REPORT CARD          \n";
        cout << "-------------------------------\n";
        cout << "Name      : " << name << endl;
        cout << "Roll No   : " << rollNo << endl;
        cout << "Marks     : ";
        for(int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nTotal     : " << total;
        cout << "\nPercentage: " << fixed << setprecision(2) << percentage << "%";
        cout << "\nGrade     : " << grade << endl;
        cout << "-------------------------------\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];

    for(int i = 0; i < n; i++) {
        cout << "\n--- Enter details for student " << i + 1 << " ---\n";
        students[i].inputDetails();
        students[i].calculate();
        students[i].displayReport();
    }

    cout << "\nAll reports generated successfully!\n";
    return 0;
}
