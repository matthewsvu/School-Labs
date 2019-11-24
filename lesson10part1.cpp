#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;
// reads in array and file name
int readAnswers(char read[], string fileName)  {
     ifstream finput;
     int totalFile = 0;
     char answer;
     finput.open(fileName.c_str());
     if(!finput) {
        return -1;
     }
     while(finput >> answer) {
        totalFile++;
        if(totalFile > 30)
            totalFile = 30;
     }
     finput.close();
     finput.open(fileName.c_str());
     for(int i = 0; i < totalFile; i++) {
        finput >> read[i];
     }
     finput.close();
    return totalFile;
}

void displayResults(char student[], char answers[], int studentAnswer) {
    double missed = 0, total = 0;
    for(int i = 0; i < studentAnswer ; i++) {
        if(student[i] != answers[i]) {
            cout << "Question " << i+1 << " has incorrect answer '" << student[i] << "', the correct answer is '" << answers[i] << "'\n";
            missed++;
        }
        total++;
    }
    cout << missed << " questions were missed out of " << total << endl;
    double grade = ((total - missed) / total) * 100;
    cout << fixed << setprecision(1) << "The student grade is " << grade << "%" << endl;
    if(grade >= 70) {
        cout << "The student passed" << endl;
    }
    else {
        cout << "The student failed" << endl;
    }
}

int main()
{
    char student[30], answers[30];
    int correctAnswer, studentAnswer;

    string inputFileName;

    cout << "Enter student answers file name\n";
    cin >> inputFileName;
    studentAnswer = readAnswers(student, inputFileName);
    if(studentAnswer == -1) {
         cout << "File \"" << inputFileName << "\" could not be opened\n";
         exit(1);
    }
    else {
        cout << "Enter correct answer file name\n";
        cin >> inputFileName;
        correctAnswer = readAnswers(answers, inputFileName);
        if(correctAnswer == -1) {
            cout << "File \"" << inputFileName << "\" could not be opened\n";
            exit(1);
        }
        if(correctAnswer != studentAnswer) {
            cout << "The student answers file has " << studentAnswer << " entries and the correct answers file has " << correctAnswer << " entries\n";
            cout << "Grading cannot be done if they are not the same\n";
            exit(1);
        }
        if(correctAnswer == 0 && studentAnswer == 0) {
            cout << "The number of student answers and correct answers are both 0\n";
            cout << "No grade can be calculated\n";
            exit(1);
        }
        displayResults(student, answers, studentAnswer);

    }



}
