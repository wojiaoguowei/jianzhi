/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。*/
private int count = 0;
private PriorityQueue<Integer> minHeap = new PriorityQueue<>();
private PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(15, new Comparator<Integer>() {
    @Override
    public int compare(Integer o1, Integer o2) {
        return o2 - o1;
    }
});

public void Insert(Integer num) {
    if (count %2 == 0) {//当数据总数为偶数时，新加入的元素，应当进入小根堆
        //（注意不是直接进入小根堆，而是经大根堆筛选后取大根堆中最大元素进入小根堆）
        //1.新加入的元素先入到大根堆，由大根堆筛选出堆中最大的元素
        maxHeap.offer(num);
        int filteredMaxNum = maxHeap.poll();
        //2.筛选后的【大根堆中的最大元素】进入小根堆
        minHeap.offer(filteredMaxNum);
    } else {//当数据总数为奇数时，新加入的元素，应当进入大根堆
        //（注意不是直接进入大根堆，而是经小根堆筛选后取小根堆中最大元素进入大根堆）
        //1.新加入的元素先入到小根堆，由小根堆筛选出堆中最小的元素
        minHeap.offer(num);
        int filteredMinNum = minHeap.poll();
        //2.筛选后的【小根堆中的最小元素】进入大根堆
        maxHeap.offer(filteredMinNum);
    }
    count++;
}

public Double GetMedian() {
    if (count %2 == 0) {
        return new Double((minHeap.peek() + maxHeap.peek())) / 2;
    } else {
        return new Double(minHeap.peek());
    }
}

#include <vector>
class Solution {
public:
    Solution()
	:count(0)
	{
		
	}
	
	void Insert(int num)
    {	
		if(count % 2 == 0)
		{
			//当数据总数为偶数时，加入小堆，但要先加入大堆排序，堆顶再加入到小堆
			max.push(num);
			min.push(max.top());
			max.pop();
		}
		else
		{
			min.push(num);
			max.push(min.top());
			min.pop();
		}
		
		count++;
    }

    double GetMedian()
    { 
		if(count % 2 == 0)
		{
			return (double)(max.top() + min.top()) / 2;
		}
		else
		{
			return (double)min.top();
		}
    }

	priority_queue<int, vector<int>, less<int> > max;	//大根堆
    priority_queue<int, vector<int>, greater<int> > min;	//小根堆
	
	int count;
};

class Solution {
    priority_queue<int, vector<int>, less<int> > p;	//大根堆
    priority_queue<int, vector<int>, greater<int> > q;	//小根堆
	
public:
    void Insert(int num){
        if(p.empty() || num <= p.top()) 
		{
			p.push(num);
		}	
        else 
		{
			q.push(num);
		}
		
        if(p.size() == q.size() + 2)
		{
			q.push(p.top()), p.pop();
		}
		
        if(p.size() + 1 == q.size())
		{
			p.push(q.top()), q.pop();
		}
    }
    double GetMedian(){ 
		return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

//升序队列
//priority_queue <int,vector<int>,greater<int> > q;
//降序队列
//priority_queue <int,vector<int>,less<int> >q;

#include <iostream>
#include <queue>
using namespace std;

#ifndef __HEAP_H__
#define __HEAP_H__
#include<iostream>
#include<vector>
		
		
using namespace std;
		
template<class T>
class Less
{
public:
    bool operator()(T& left, T& right){
        return left < right;
    }
};
		
template<class T>
class Greater
{
public:
    bool operator()(T& left, T& right){
        return left>right;
    }
};
		
template<class T,class Compare = Greater<T>>
class Heap
{
	public:
	//无参构造
	Heap()
	{}
	
	//带参构造
	Heap(T* arr, const T size)
	{
		_v.reserve(size);
		for (int i = 0; i < size; ++i){
			_v.push_back(arr[i]);
		}
		//建堆
		for (int j = (_v.size() - 2) >> 1; j >= 0; --j){
			//向下调整
			_AdjustDown(j);
		}
	}
		
	void Push(const T& data)
	{
		_v.push_back(data);
		_AdjustUp(_v.size() - 1);
	}
		
	void Pop()
	{
		//交换堆顶元素与堆底元素
		size_t size = _v.size();
		swap(_v[0], _v[size - 1]);
		//删除堆底元素
		_v.pop_back();
		//向下调整
		_AdjustDown(0);
	}
		
	size_t Size()
	{
		return _v.size();
	}
		
	bool Empty()
	{
		return _v.empty();
	}
		
	//打印堆
	void Print()
	{
		for (size_t i = 0; i < _v.size(); ++i){
			cout << _v[i] << "  ";
		}
		cout << endl;
}
		
	T Top()const
	{
		return _v.front();
	}
		
	T Back()const
	{
		return _v.back();
	}
		
	//析构
	~Heap()
	{
		_v.~vector();
	}
		
protected:
	//向下调整
	void _AdjustDown(size_t root)
	{
		size_t parent = root;
		size_t min_child = parent * 2 + 1;
		while (min_child < _v.size()){
			if ((min_child + 1 < _v.size()) && (Compare()(_v[min_child + 1],_v[min_child])))
				min_child += 1;
			if (Compare()(_v[min_child],_v[parent])){
				swap(_v[parent], _v[min_child]);
				parent = min_child;
				min_child = parent * 2 + 1;
			}
			else{
				break;
			}
		}
	}
		
	//向上调整
	void _AdjustUp(size_t index){
		size_t child = index;
		size_t parent = (child - 1) >> 1;
		while (child){
			if (Compare()(_v[parent],_v[child])){
				break;
			}
			else{
				swap(_v[parent], _v[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
		}
	}						
		
private:
	vector<T> _v;
};
#endif //__HEAP_H__


int main() 
{
    //对于基础类型 默认是大顶堆
    priority_queue<int> a; 
    //等同于 priority_queue<int, vector<int>, less<int> > a;

    //             这里一定要有空格，不然成了右移运算符↓
    priority_queue<int, vector<int>, greater<int> > c;  //这样就是小顶堆
    priority_queue<string> b;

    for (int i = 0; i < 5; i++) 
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty()) 
    {
        cout << a.top() << ' ';
        a.pop();
    } 
    cout << endl;

    while (!c.empty()) 
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty()) 
    {
        cout << b.top() << ' ';
        b.pop();
    } 
    cout << endl;
    return 0;
}
