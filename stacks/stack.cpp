#include <iostream>
using namespace std;

#define SIZE 10

class Stack {

    // properties
    int *arr;
    int top;
    int capacity;

    // methods declaration
    public:
        Stack(int size = SIZE);
        void push(int);
        int pop();
        int peek();
        int size();

        bool isEmpty();
        bool isFull();
};


int main(){

    Stack stack();

    stack.push(1);
    stack.push(10);
    stack.push(4);

    stack.size();
    stack.peek();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();


}