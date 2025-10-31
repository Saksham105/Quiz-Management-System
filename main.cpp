/*
    Project: Quiz Competition

    Features:
    1. Allows user to add questions to the quiz.
    2. Start the quiz and answer questions.
    3. View scores after finishing.
    4. Improvements: file handling, input validation, memory management.
*/

#include "Quiz.hpp"
#include <cstring>
#include <memory>

void showMenu() {
    cout << "\n------------- Quiz Menu -------------\n";
    cout << "1. Add questions to C Quiz\n";
    cout << "2. Add questions to C++ Quiz\n";
    cout << "3. Add questions to DSA Quiz\n";
    cout << "4. Start C Quiz\n";
    cout << "5. Start C++ Quiz\n";
    cout << "6. Start DSA Quiz\n";
    cout << "7. Erase C Quiz questions\n";
    cout << "8. Erase C++ Quiz questions\n";
    cout << "9. Erase DSA Quiz questions\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    // File names for quizzes
    const char* cQuizFile = "C_Quiz.txt";
    const char* cppQuizFile = "Cpp_Quiz.txt";
    const char* dsaQuizFile = "DSA_Quiz.txt";

    // Create Quiz objects using smart pointers
    unique_ptr<C_Quiz> cQuiz = make_unique<C_Quiz>(cQuizFile);
    unique_ptr<Cpp_Quiz> cppQuiz = make_unique<Cpp_Quiz>(cppQuizFile);
    unique_ptr<DSA_Quiz> dsaQuiz = make_unique<DSA_Quiz>(dsaQuizFile);

    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1:
                cout << "\nAdding questions for C Quiz\n";
                cQuiz->setQuiz();
                break;
            case 2:
                cout << "\nAdding questions for C++ Quiz\n";
                cppQuiz->setQuiz();
                break;
            case 3:
                cout << "\nAdding questions for DSA Quiz\n";
                dsaQuiz->setQuiz();
                break;
            case 4:
                cout << "\nStarting C Quiz\n";
                cQuiz->startQuiz();
                cQuiz->displayScore();
                break;
            case 5:
                cout << "\nStarting C++ Quiz\n";
                cppQuiz->startQuiz();
                cppQuiz->displayScore();
                break;
            case 6:
                cout << "\nStarting DSA Quiz\n";
                dsaQuiz->startQuiz();
                dsaQuiz->displayScore();
                break;
            case 7:
                cout << "\nErasing C Quiz questions\n";
                cQuiz->eraseQuizQuestions();
                break;
            case 8:
                cout << "\nErasing C++ Quiz questions\n";
                cppQuiz->eraseQuizQuestions();
                break;
            case 9:
                cout << "\nErasing DSA Quiz questions\n";
                dsaQuiz->eraseQuizQuestions();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select a valid option from the menu.\n";
                break;
        }
    }while(choice != 0);

    return 0;
}