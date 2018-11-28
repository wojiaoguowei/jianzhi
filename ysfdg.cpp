class Solution {
public:
	/*
	 n 总人数
	 m 报数最大值
	*/
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m <= 0)
		{
			return -1;
		}
		
		return ysfdg(n, m, n) + 1;
    }
	
	/*
		count 第几次出环
	*/
	int ysfdg(int n, int m, int count)
	{
		if(count == 1)
		{
			return (n + m - 1) % n;
		}
		else
		{
			/*
				n人环 m次出环
				n-1人环 m-1此出环        n人环m次出环下标 = (n-1人环m-1次出环下标 + m) % n
			*/
			return (ysfdg(n - 1, m, count - 1) + m) % n;
		}
	}
};

int main()
{
	Solution sol;
	sol.LastRemaining_Solution(5, 3);
	
	return 1;
}
