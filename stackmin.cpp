#include <stack>

using namespace std;

class Solution {
public:
    void push(int value) {
        stackmy.push(value);
		
		if(stackmin.empty())
		{
			stackmin.push(value);
		}
		else if(value <= stackmin.top())
		{
			stackmin.push(value);
		}
    }
    void pop() {
        if(stackmy.top() == stackmin.top())
		{
			stackmin.pop();
		}
		
		stackmy.pop();
    }
    int top() {
        return stackmy.top();
    }
    int min() {
        return stackmin.top();
    }
	
private:
	stack<int> stackmy;
	stack<int> stackmin;
};


class Solution {
public:
	
    stack<int> stack1,stack2;
	
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(value<=stack2.top())
        {
            stack2.push(value);
        }
    }
	
    void pop() {
        if(stack1.top()==stack2.top())
            stack2.pop();
        stack1.pop();
		
    }
	
    int top() {
        return stack1.top();       
    }
	
    int min() {
        return stack2.top();
    }
	
};

int main()
{
	Solution so;
    so.push(5);
	so.push(3);
	so.push(4);
	int b = so.min();
	so.pop();
	
	int bb = so.min();

	
	return 1;
}
