/*题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。*/
//引用马客（Mark）的解题思路，马客没加注释，我用自己的理解加下注释，希望对你们有用，
//如有错误，见谅，我会及时修改。
//deque s中存储的是num的下标
#include<iostream>
#include<vector>
#include<iostream>
#include<stdio.h>
#include <queue>

using namespace std;

/*class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> s;
        for(unsigned int i=0;i<num.size();++i)
		{
            while(s.size() && num[s.back()]<=num[i])//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
			{
				s.pop_back();
			}    
				
            while(s.size() && i-s.front()+1>size)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
			{
				s.pop_front();
			}
				
            s.push_back(i);//把每次滑动的num下标加入队列
            if(size&&i+1>=size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
			{
				res.push_back(num[s.front()]);
			}
				
        }
        return res;
    }
};*/






class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
		if(size == 0)
		{
			return vector<int>();
		}
		
		vector<int> res;
		deque<int> que;	//保存数组下标
		
		int len = num.size();
		for(int i = 0; i < len; i++)
		{
			//比队列最后一个元素大，弹出最后一个元素，当前元素加入到堆列
			while(que.size() && num[que.back()] < num[i])
			{
				que.pop_back();
			}
			
			while(que.size() && i - que.front() + 1 > size)
			{
				que.pop_front();
			}
			
			que.push_back(i);
			if(i + 1 >= size)
			{
				res.push_back(num[que.front()]);
			}	
		}
		
		return res;
    }
};

int main()
{
	vector<int> num = {2,3,4,2,6,2,5,1};
	
	Solution sol;
	sol.maxInWindows(num, 3);
	
	return 1;
}