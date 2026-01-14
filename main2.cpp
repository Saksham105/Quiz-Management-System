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
    cout << "\n\t------------- Quiz Menu -------------\n";
    cout << "\t1. Add questions toQuiz\n";
    cout << "\t2. Start Quiz\n";
    cout << "\t3. Erase Quiz questions\n";
    cout << "\t0. Exit\n";
}

int main() {
    // File names for quizzes
    const char* cQuizFile = "C_Quiz.txt";
    const char* cppQuizFile = "Cpp_Quiz.txt";
    const char* dsaQuizFile = "DSA_Quiz.txt";

    // Create Quiz objects using smart pointers
    // follows principle of RAII (resource aquisition is initialization)
    // automatically deallocates dynamically allocated memory as soon as the object goes out of scope.
    unique_ptr<C_Quiz> cQuiz = make_unique<C_Quiz>(cQuizFile);
    unique_ptr<Cpp_Quiz> cppQuiz = make_unique<Cpp_Quiz>(cppQuizFile);
    unique_ptr<DSA_Quiz> dsaQuiz = make_unique<DSA_Quiz>(dsaQuizFile);

    int choice;
    int in_choice;

    do {
        showMenu();
        cout << "\tEnter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {
            case 1:
                cout << "\t\t1. C Quiz\n";
                cout << "\t\t2. C++ Quiz\n";
                cout << "\t\t3. DSA Quiz\n";
                cout << "\tEnter your choice: ";
                cin >> in_choice;

                switch(in_choice) {
                    case 1:
                        cout << "\n\tAdding questions for C Quiz\n";
                        cQuiz->setQuiz();
                        break;
                    case 2:
                        cout << "\n\tAdding questions for C++ Quiz\n";
                        cppQuiz->setQuiz();
                        break;
                    case 3:
                        cout << "\n\tAdding questions for DSA Quiz\n";
                        dsaQuiz->setQuiz();
                        break;
                    default:
                        cout << "\n\tInvalid choice.!\n";
                        break;
                }
                break;
            case 2:
                cout << "\t\t1. C Quiz\n";
                cout << "\t\t2. C++ Quiz\n";
                cout << "\t\t3. DSA Quiz\n";
                cout << "\tEnter your choice: ";
                cin >> in_choice;

                switch(in_choice) {
                    case 1:
                        cout << "\n\tStarting C Quiz\n";
                        cQuiz->startQuiz();
                        cQuiz->displayScore();
                        break;
                    case 2:
                        cout << "\n\tStarting C++ Quiz\n";
                        cppQuiz->startQuiz();
                        cppQuiz->displayScore();
                        break;
                    case 3:
                        cout << "\n\tStarting DSA Quiz\n";
                        dsaQuiz->startQuiz();
                        dsaQuiz->displayScore();
                        break;
                    default:
                        cout << "\n\tInvalid choice.!\n";
                        break;
                }
                break;
            case 3:
                cout << "\t\t1. C Quiz\n";
                cout << "\t\t2. C++ Quiz\n";
                cout << "\t\t3. DSA Quiz\n";
                cout << "\tEnter your choice: ";
                cin >> in_choice;

                switch(in_choice) {
                    case 1:
                        cout << "\n\tErazing questions for C Quiz\n";
                        cQuiz->eraseQuizQuestions();
                        break;
                    case 2:
                        cout << "\n\tErazing questions for C++ Quiz\n";
                        cppQuiz->eraseQuizQuestions();
                        break;
                    case 3:
                        cout << "\n\tErazing questions for DSA Quiz\n";
                        dsaQuiz->eraseQuizQuestions();
                        break;
                    default:
                        cout << "\n\tInvalid choice.!\n";
                        break;
                }
                break;
            default:
                cout << "\tInvalid choice! Please select a valid option from the menu.\n";
                break;
        }
    }while(choice != 0);

    return 0;
}