#include "Quiz.hpp"
#include <cstring>

// Destructor
Quiz::~Quiz() {
    // virtual destructor
}

//=================== Constructors =====================

C_Quiz::C_Quiz(const char* filePath) {
    strncpy(fileName, filePath, sizeof(fileName) - 1);
    fileName[sizeof(fileName)-1] = '\0';
}

Cpp_Quiz::Cpp_Quiz(const char* filePath) {
    strncpy(fileName, filePath, sizeof(fileName) - 1);
    fileName[sizeof(fileName)-1] = '\0';
}

DSA_Quiz::DSA_Quiz(const char* filePath) {
    strncpy(fileName, filePath, sizeof(fileName) - 1);
    fileName[sizeof(fileName)-1] = '\0';
}

//=================== Common Helper Functions ==============

// Saves questions in overwrite mode (to avoid duplication)
void Quiz::saveToFile(const char *fileName) {
    ofstream file(fileName, ios::out); // overwrite mode

    if (!file.is_open()) {
        cerr << "Error opening file to write: " << fileName << endl;
        return;
    }

    int count = 1;
    for (const auto &q : quiz) {
        file << q.question << "\n";
        file << q.a << "\n";
        file << q.b << "\n";
        file << q.c << "\n";
        file << q.d << "\n";
        file << q.option << "\n";
        count++;
    }
    file.close();
    cout << "Questions saved successfully to " << fileName << "\n";
}

// Clear all questions from file (erase file)
void C_Quiz::eraseQuizQuestions() {
    ofstream file(fileName, ios::trunc);
    if (file.is_open()) {
        cout << "File: " << fileName << " erased successfully!" << endl;
    } else {
        cerr << "Error opening file to erase: " << fileName << endl;
    }
}

void Cpp_Quiz::eraseQuizQuestions() {
    ofstream file(fileName, ios::trunc);
    if (file.is_open()) {
        cout << "File: " << fileName << " erased successfully!" << endl;
    } else {
        cerr << "Error opening file to erase: " << fileName << endl;
    }
}

void DSA_Quiz::eraseQuizQuestions() {
    ofstream file(fileName, ios::trunc);
    if (file.is_open()) {
        cout << "File: " << fileName << " erased successfully!" << endl;
    } else {
        cerr << "Error opening file to erase: " << fileName << endl;
    }
}

//=================== Set Quiz Functions ===================

void C_Quiz::setQuiz() {
    Question q;
    int ch = 1;
    cout << "\nEnter to continue..";
    cin.ignore(); // clear input buffer before getline
    while (ch == 1) {
        cout << "\nEnter one question and its four options:\n";

        cout << "Question: ";
        getline(cin, q.question);
        cout << "Option a: ";
        getline(cin, q.a);
        cout << "Option b: ";
        getline(cin, q.b);
        cout << "Option c: ";
        getline(cin, q.c);
        cout << "Option d: ";
        getline(cin, q.d);

        while (true) {
            cout << "Set the correct option (a-d): ";
            cin >> q.option;
            q.option = tolower(q.option);
            cin.ignore();
            if (q.option < 'a' || q.option > 'd') {
                cout << "Invalid option. Please enter a letter between 'a' and 'd'.\n";
            } else {
                break;
            }
        }

        quiz.push_back(q);

        cout << "Do you want to add another question? (1:Yes / 0:No) ";
        cin >> ch;
        cin.ignore();
    }
    score = 0;

    // Save questions to file (overwrite)
    saveToFile(fileName);
}

void Cpp_Quiz::setQuiz() {
    Question q;
    int ch = 1;
    cout << "\nEnter to continue..";
    cin.ignore(); // clear buffer
    while (ch == 1) {
        cout << "\nEnter one question and its four options:\n";

        cout << "Question: ";
        getline(cin, q.question);
        cout << "Option a: ";
        getline(cin, q.a);
        cout << "Option b: ";
        getline(cin, q.b);
        cout << "Option c: ";
        getline(cin, q.c);
        cout << "Option d: ";
        getline(cin, q.d);

        while (true) {
            cout << "Set the correct option (a-d): ";
            cin >> q.option;
            q.option = tolower(q.option);
            cin.ignore();
            if (q.option < 'a' || q.option > 'd') {
                cout << "Invalid option. Please enter a letter between 'a' and 'd'.\n";
            } else {
                break;
            }
        }

        quiz.push_back(q);

        cout << "Do you want to add another question? (1:Yes / 0:No) ";
        cin >> ch;
        cin.ignore();
    }
    score = 0;

    saveToFile(fileName);
}

void DSA_Quiz::setQuiz() {
    Question q;
    int ch = 1;
    cout << "\nEnter to continue..";    
    cin.ignore(); // clear buffer
    while (ch == 1) {
        cout << "\nEnter one question and its four options:\n";

        cout << "Question: ";
        getline(cin, q.question);
        cout << "Option a: ";
        getline(cin, q.a);
        cout << "Option b: ";
        getline(cin, q.b);
        cout << "Option c: ";
        getline(cin, q.c);
        cout << "Option d: ";
        getline(cin, q.d);

        while (true) {
            cout << "Set the correct option (a-d): ";
            cin >> q.option;
            q.option = tolower(q.option);
            cin.ignore();
            if (q.option < 'a' || q.option > 'd') {
                cout << "Invalid option. Please enter a letter between 'a' and 'd'.\n";
            } else {
                break;
            }
        }

        quiz.push_back(q);

        cout << "Do you want to add another question? (1:Yes / 0:No) ";
        cin >> ch;
        cin.ignore();
    }
    score = 0;

    saveToFile(fileName);
}

//=================== Start Quiz Functions ===================

// Helper function to read questions from file and run quiz
void runQuizFromFile(const char* fileName, int &score) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "File not found: " << fileName << endl;
        return;
    }

    score = 0;
    Question q;
    char op;
    string line;
    int questionCount = 0;

    cout << "\nStarting quiz...\n";

    while (getline(file, q.question)) {
        // Read next 4 lines for a,b,c,d options
        if (!getline(file, q.a)) break;
        if (!getline(file, q.b)) break;
        if (!getline(file, q.c)) break;
        if (!getline(file, q.d)) break;

        // Read correct option line (single char)
        if (!(file >> q.option)) break;
        // After reading q.option, consume leftover newline
        file.ignore();

        questionCount++;

        cout << "\nQ" << questionCount << ": " << q.question << endl;
        cout << "a) " << q.a << endl;
        cout << "b) " << q.b << endl;
        cout << "c) " << q.c << endl;
        cout << "d) " << q.d << endl;

        while (true) {
            cout << "Choose your option (a-d), or 'q' to quit: ";
            cin >> op;
            op = tolower(op); // converts the input in lowercase.
            cin.ignore();
            if (op == 'q') {
                cout << "Exiting quiz early.\n";
                file.close();
                cout << "\nYou scored " << score << " out of " << questionCount-1 << ".\n";
                return;
            }
            if (op < 'a' || op > 'd') {
                cout << "Invalid option. Please enter a letter between 'a' and 'd', or 'q' to quit.\n";
            } else {
                break;
            }
        }

        if (op == q.option) {
            score++;
        }
    }

    file.close();
    cout << "\nQuiz completed.\n";
    cout << "Your score: " << score << " out of " << questionCount << "\n";
}

void C_Quiz::startQuiz() {
    runQuizFromFile(fileName, score);
}

void Cpp_Quiz::startQuiz() {
    runQuizFromFile(fileName, score);
}

void DSA_Quiz::startQuiz() {
    runQuizFromFile(fileName, score);
}

//=================== Calculate Score ===================

void Quiz::calculateScore(const Question& q, const char& op) {
    if (q.option == op) {
        score++;
    }
}

//=================== Display Score ===================

void Quiz::displayScore() {
    cout << "\nYour total score: " << score << endl;
}