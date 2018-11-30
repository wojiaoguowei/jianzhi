/*在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。*/
#include <cstring>
#include <iostream>

/*
不需要额外的数组或者hash table来保存，题目里写了数组里数字的范围保证在0 ~ n-1 之间，所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，之后再遇到相同的数时，
会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。

代码是C：

int find_dup( int numbers[], int length) {

    for ( int i= 0 ; i<length; i++) {

        int index = numbers[i];

        if (index >= length) {

            index -= length;

        }   

        if (numbers[index] >= length) {

            return index;

        }   

        numbers[index] = numbers[index] + length;

    }   

    return - 1 ; 

}
*/

using namespace std; 
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length == 0 || numbers == NULL)
		{
			return false;
		}
		
		int hashtable[length];
		memset(hashtable, 0, length);
		
		bool flag = false;
		for(int i = 0; i < length; i++)
		{
			int t = numbers[i];
			
			hashtable[t] = hashtable[t] + 1;
			if(hashtable[t] == 2)
			{
				flag = true; 
				*duplication = numbers[i];
				
				break;
			}
		}
		
		return flag;
    }
};

int main()
{
	int nums[] = {2,4,3,1,4};
	Solution sol;
	int tmp;
	bool b = sol.duplicate(nums, 5, &tmp);
	cout << b << tmp << endl;
	
	return 1;
}
