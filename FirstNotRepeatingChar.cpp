/*在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.*/
#include <string>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int size = str.size();
	
		if(size == 0)
		{
			return -1;
		}
		
		int *hashTable = new int[256];
		int res = -1;
		for(int i = 0; i < size; i++)
		{
			hashTable[i] = 0;
		}
		
		for(int i = 0; i < size; i++)
		{
			hashTable[str[i]] += 1;
		}
		
		for(int i = 0; i < size; i++)
		{
			if(hashTable[str[i]] == 1)
			{
				res = i;
				return res;
			}
		}
		
		return res;
    }
};

int main()
{
	string str = "google";
	Solution sol;
	sol.FirstNotRepeatingChar(str);
	
	return 1;
}
