#include <list>
#include <iostream>

using namespace std;

class Stack
{
    int limit;
    list<int> stack_array;
    public:
        Stack(int limit_arg);
        void push(int val);
        void pop();
        void peek();
};

Stack::Stack(int limit_arg=10){
    limit = limit_arg;
}

void Stack::push(int val)
{
    if(stack_array.size() < limit)
    {
        stack_array.push_back(val);
    }else{
        cout << "stack is full" << endl;
    }
    
}

void Stack::pop()
{
    if(stack_array.size() != 0){
        int poped = stack_array.front();
        stack_array.pop_front();
        cout << to_string(poped) + " is poped"<<endl;
    }else{
        cout << "there is no element inside the stack"<<endl;
    }
}

void Stack::peek(){
    if(stack_array.size() != 0){
        int peeked = stack_array.front();
        cout << to_string(peeked) + " is peeked"<<endl;
    }else{
        cout << "there is no element inside the stack"<<endl;
    }

}

int main(){
    Stack stack(3);
    stack.push(3);
    stack.push(4);
    stack.push(2);
    stack.push(1);
    stack.pop();
    stack.peek();
}
