#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <vector>
#include <stack>

//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

/*class Solution
{
public:
    int cou = 0;
    void push(int node) {
        stack1.push_back(node);
        stack2.push_back(cou++);
    }
 
    int pop() {
        int i = 0;
        while(stack2[i] == -1)
            {
            i++;
        }
        stack2[i] = -1;
        return stack1[i];
    }
 
private:
    std::vector<int> stack1;//存数
    std::vector<int> stack2;//地址
};*/

class Solution
{
public:
    void push(int node)
    {
       stack1.push(node);    
    }

    int pop() 
    {
        if(stack2.empty())
	{
	   int nCount = stack1.size();
           for(int i = 0; i < nCount; i++)
           {
               stack2.push(stack1.top());
               stack1.pop();
	   }
	}

	
       int nTmp = stack2.top();
       stack2.pop();
       return nTmp;    
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};




int main()
{
    Solution sol;

    sol.push(2);
    sol.push(5);
    sol.push(8);

    int nTmp = sol.pop();

    sol.push(9);
    return true;

}
