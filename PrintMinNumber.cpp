#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int size = numbers.size();
		string res;
		if(size == 0)
		{
			return res;
		}
		
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size - i - 1; j++)
			{
				compare(numbers[j], numbers[j + 1]);
			}
		}
		
		for(int i = 0; i < size; i++)
		{
			res += to_string(numbers[i]);
		}
		
		return res;
    }
	
private:
	void compare(int &a, int &b)
	{
		string strFirst = to_string(a) + to_string(b);
		string strSecond = to_string(b) + to_string(a);
		
		if(strFirst > strSecond)
		{
			swap(a, b);
		}
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(32);
		vec.push_back(321);

		
		
	
	Solution sol;
	sol.PrintMinNumber(vec);
	
}
