#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
	stack<int> in_stack, out_stack;
	
	void in2out() {
		while(!in_stack.empty()) {
			out_stack.push(in_stack.top());
			in_stack.pop();
		}
	}
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		in_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	int x;
		if(out_stack.empty())
			in2out();
			
		x = out_stack.top();
		out_stack.pop();
		return x;	
    }
    
    /** Get the front element. */
    int peek() {
		if(out_stack.empty())
			in2out();

		return out_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return in_stack.empty() && out_stack.empty();
    }
};


int main()
{
	MyQueue* obj = new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	cout << obj->pop() << endl;
	return 0;
}
