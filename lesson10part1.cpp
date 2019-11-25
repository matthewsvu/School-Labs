/*
Program will use two parallel arrays and read in student answers and correct answer into
both respectively. After checking they are valid, the display function will output if there are any
incorrect answers and see if the student passed or failed.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;
// reads in array and file name
int readAnswers(char read[], string fileName)
{
    ifstream finput;
    int totalFile = 0; // number of answers within a file
    char answer;
    finput.open(fileName.c_str());
    if(!finput) // if file is not opened.
    {
        return -1;
    }
    while(finput >> answer) // checks to see when file is done being read in and loops accordingly.
    {
        totalFile++;
        if(totalFile > 30) // if num answer is more than 30 set it to 30
            totalFile = 30;
    }
    finput.close(); // closes the file
    finput.open(fileName.c_str()); // open the file again and does how many number of answers are within the file
    for(int i = 0; i < totalFile; i++)
    {
        finput >> read[i]; // reads input file contents into the given array
    }
    finput.close(); // closes
    return totalFile;
}
// display function is given the student answers and correct answer also, the number of answers within both files
void displayResults(char student[], char answers[], int numAnswer)
{
    double missed = 0, total = 0;
    for(int i = 0; i < numAnswer ; i++)
    {
        if(student[i] != answers[i]) // if the one part of the array doesn't match the other array, output that it's a wrong answer
        {
            cout << "Question " << i+1 << " has incorrect answer '" << student[i] << "', the correct answer is '" << answers[i] << "'\n";
            missed++;
        }
        total++;
    }
    cout << missed << " questions were missed out of " << total << endl; // shows questions missed out of total
    double grade = ((total - missed) / total) * 100; // calc and output student grade
    cout << fixed << setprecision(1) << "The student grade is " << grade << "%" << endl;
    if(grade >= 70) // student passes or fails
    {
        cout << "The student passed" << endl;
    }
    else
    {
        cout << "The student failed" << endl;
    }
}
// main function
int main()
{
    char student[30], answers[30]; // two parallel arrays
    int correctAnswerTotal, studentAnswerTotal; // vars that count the num answer in each file

    string inputFileName;

    cout << "Enter student answers file name\n"; // reads file name from user
    cin >> inputFileName;
    studentAnswerTotal = readAnswers(student, inputFileName); // calls read function to get num answer from file
    if(studentAnswerTotal == -1) // checks to see if file opens
    {
        cout << "File \"" << inputFileName << "\" could not be opened\n";
        exit(1);
    }
    else
    {
        cout << "Enter correct answer file name\n"; // // calls read function to get num answer from file
        cin >> inputFileName;
        correctAnswerTotal = readAnswers(answers, inputFileName);
        if(correctAnswerTotal == -1) // validation check for the file not opening
        {
            cout << "File \"" << inputFileName << "\" could not be opened\n";
            exit(1); // exits program
        }
        if(correctAnswerTotal != studentAnswerTotal) // checks to see if num answers in both files matches
        {
            cout << "The student answers file has " << studentAnswerTotal << " entries and the correct answers file has " << correctAnswerTotal << " entries\n";
            cout << "Grading cannot be done if they are not the same\n";
            exit(1);
        }
        if(correctAnswerTotal == 0 && studentAnswerTotal == 0) // makes sure if both files are not empty
        {
            cout << "The number of student answers and correct answers are both 0\n";
            cout << "No grade can be calculated\n";
            exit(1);
        }
        displayResults(student, answers, studentAnswerTotal); // calls the display function
    }
}
