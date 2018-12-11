#include<iostream>
#include<vector>
#include<iostream>
#include<stdio.h>

using namespace std;

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
    Heap(T* arr, const T size){
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

    void Push(const T& data){
        _v.push_back(data);
        _AdjustUp(_v.size() - 1);
    }

    void Pop(){
        //交换堆顶元素与堆底元素
        size_t size = _v.size();
        swap(_v[0], _v[size - 1]);
        //删除堆底元素
        _v.pop_back();
        //向下调整
        _AdjustDown(0);
    }

    size_t Size(){
        return _v.size();
    }

    bool Empty(){
        return _v.empty();
    }

    //打印堆
    void Print(){
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
    ~Heap(){
        _v.~vector();
    }

protected:
    //向下调整
    void _AdjustDown(size_t root){
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
            /*if (Compare()(_v[parent],_v[child])){
                break;
            }
            else{
                swap(_v[parent], _v[child]);
                child = parent;
                parent = (child - 1) >> 1;
            }*/
			
			if (Compare()(_v[parent],_v[child]))
			{
				swap(_v[parent], _v[child]);
                child = parent;
                parent = (child - 1) >> 1;
            }
            else
			{
                break;
            }
        }
    }

private:
    vector<T> _v;
};

 
//test.cpp




class Solution {
//priority_queue<int, vector<int>, less<int> > p;	//大根堆
//priority_queue<int, vector<int>, greater<int> > q;	//小根堆

public:

	
	void Insert(int num)
	{
		if(count % 2 == 0)
		{
			//偶数个元素时，加入到小根堆，但要经过大根堆排序，大根堆堆顶弹出给小根堆
			PushMaxHeapElem(num);
			int v = MaxHeapFront();
			PopMaxHeapElem();
			
			PushMinHeapElem(v);
		}
		else
		{
			//奇数个元素时，加入到大根堆，但要经过小根堆排序，小根堆堆顶弹出给大根堆
			PushMinHeapElem(num);
			int v = MinHeapFront();
			PopMinHeapElem();
			
			PushMaxHeapElem(v);
		}
		
		count++;
	}
	
	double GetMedian()
	{ 
		if(count % 2 == 0)
		{
			
			double s = MinHeapFront() + MaxHeapFront();
			return (double)((s) / 2);
		}
		else
		{
			return (double)MinHeapFront();
		}
	}
	
	
	int MinHeapFront()
	{
		return vecMin.front();
	}
	//最小堆元素下沉
	void MinHeapElemDown(vector<int> &vec, int len, int index)
	{
		if(index < 0 || index >= len)
		{
			return;
		}
		
		int parent = index;
		int child = 2 * parent + 1;
		
		while(child < len)
		{
			//右子节点
			if(child + 1 < len && vecMin[child] > vecMin[child + 1])
			{
				child++;
			}
			
			if(vecMin[parent] > vecMin[child])
			{
				Swap(&vecMin[parent], &vecMin[child]);
			}
			
			parent = child;
			child = 2 * parent + 1;
		}
	}
	
	void BuildMinHeap()
	{
		int len = vecMin.size();
		
		for(int i = len / 2 - 1; i >= 0; i++)
		{
			MinHeapElemDown(vecMin, len, i);
		}
	}
	
	void PushMinHeapElem(int data)
	{
		vecMin.push_back(data);
		//添加元素后元素上升
		MinHeapElemUp(vecMin, vecMin.size(), vecMin.size() - 1);
	}
	
	void PopMinHeapElem()
	{
		//首位元素交换
		Swap(&vecMin[0], &vecMin[vecMin.size() - 1]);
		
		//堆底元素弹出
		vecMin.pop_back();
		
		//元素下沉
		MinHeapElemDown(vecMin, vecMin.size(), 0);
	}
	
	//在后边添加元素，从最后开始元素上升
	void MinHeapElemUp(vector<int> &vec, int len, int index)
	{
		int child = index;
		int parent = (child - 1) >> 1;
		while(child)
		{
			if(vecMin[child] < vecMin[parent])
			{
				Swap(&vecMin[child], &vecMin[parent]);
				
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
	
	
	
	
	
	
	
	
	int MaxHeapFront()
	{
		return vecMax.front();
	}
	
	
	void MaxHeapElemDown(vector<int> &vec, int len, int index)
	{
		if(index < 0 || index >= len)
		{
			return;
		}
		
		int parent = index;
		int child = 2 * parent + 1;
		while(child < len - 1)
		{
			//左右子节点里大的
			if(child + 1 < len && vecMax[child] < vecMax[child + 1])
			{
				child++;
			}
			
			if(vecMax[parent] < vecMax[child])
			{
				Swap(&vec[parent], &vec[child]);
			}
			
			parent = child;
			child = 2 * parent + 1;
		}
	}
	
	//建最大堆
	void BuildMaxHeap()
	{
		int len = vecMax.size();
		
		for(int i = len / 2 - 1; i >= 0; i++)
		{
			MaxHeapElemDown(vecMax, len, i);
		}
	}
	
	void PushMaxHeapElem(int data)
	{
		vecMax.push_back(data);
		//添加元素后元素上升
		MaxHeapElemUp(vecMax, vecMax.size(), vecMax.size() - 1);
	}
	
	void PopMaxHeapElem()
	{
		//首位元素交换
		Swap(&vecMax[0], &vecMax[vecMax.size() - 1]);
		
		//堆底元素弹出
		vecMax.pop_back();
		
		//元素下沉
		MaxHeapElemDown(vecMax, vecMax.size(), 0);
	}
	
	//在后边添加元素，从最后开始元素上升
	void MaxHeapElemUp(vector<int> &vec, int len, int index)
	{
		int child = index;
		int parent = (child - 1) >> 1;
		while(child)
		{
			if(vecMax[child] > vecMax[parent])
			{
				Swap(&vecMax[child], &vecMax[parent]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
	
	void Swap(int *v1, int *v2)
	{
		int temp = *v1;
		*v1 = *v2;
		*v2 = temp;
	}
	
	vector<int> vecMax;
	vector<int> vecMin;
	
	int count = 0;
};

void test(){
    int arr[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
	//5,2,3,4,1,6,7,0,8
	
	
    Heap<int,Less<int> > hp;
    //此处传的是小堆Less<int>,若要大堆可传Greater<int>
    hp.Push(53);
	hp.Push(17);
	hp.Push(78);
	hp.Push(9);
	hp.Push(45);
	hp.Push(65);
	hp.Push(87);
	hp.Push(23);
    hp.Pop();
    cout << hp.Size() << endl;
    //cout << hp.Front() << endl;
    //cout << hp.Back() << endl;
	
	Solution sol;
	sol.Insert(5);
	sol.Insert(2);
	sol.Insert(3);
	sol.Insert(4);
	double mid = sol.GetMedian();
}

int main(){
    test();
    system("pause");
    return 0;
}

