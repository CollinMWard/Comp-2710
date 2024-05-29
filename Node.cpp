#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
public:
    Node(string question, string answer, int pointValue)
        : question(question), answer(answer), pointValue(pointValue), next(nullptr) {
    }

    // Getter methods
    string getQuestion()  {
        return question;
    }

   string getAnswer() {
        return answer;
    }

    int getPointValue() {
        return pointValue;
    }

    Node* getNext() {
        return next;
    }
    // Setter methods
    void setQuestion(string newQuestion) {
        question = newQuestion;
    }

    void setAnswer(string newAnswer) {
        answer = newAnswer;
    }

    void setPointValue(int newPointValue) {
        pointValue = newPointValue;
    }

    void setNext(Node* newNode) {
        next = newNode;
    }

private:
    string question;
    string answer;
    int pointValue;
    Node* next;
};
