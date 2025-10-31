#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <limits> // for std::numeric_limits

using namespace std;

struct Question {
    string question;      // question text
    string a, b, c, d;    // four options
    char option;          // correct option (a-d)
};

class Quiz {
protected:
    list<Question> quiz;  // list of all questions
    int score;            // score of the quiz
public:
    virtual void setQuiz() = 0;
    void saveToFile(const char *);
    virtual void startQuiz() = 0;
    void calculateScore(const Question&, const char&);
    void displayScore();
    virtual void eraseQuizQuestions() = 0;
    virtual ~Quiz();
};

// Quiz for C Language
class C_Quiz : public Quiz {
    char fileName[50];
public:
    explicit C_Quiz(const char *);
    void setQuiz() override;
    void startQuiz() override;
    void eraseQuizQuestions() override;
};

// Quiz for C++ Language
class Cpp_Quiz : public Quiz {
    char fileName[50];
public:
    explicit Cpp_Quiz(const char *);
    void setQuiz() override;
    void startQuiz() override;
    void eraseQuizQuestions() override;
};

// Quiz for DSA
class DSA_Quiz : public Quiz {
    char fileName[50];
public:
    explicit DSA_Quiz(const char *);
    void setQuiz() override;
    void startQuiz() override;
    void eraseQuizQuestions() override;
};