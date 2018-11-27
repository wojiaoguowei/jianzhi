/*题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size = str.size();
		if(n >= size || size == 0 || n <= 0)
		{
			return str;
		}
		
		string s;
		s.clear();
		
		s = str.substr(0, n);
		str.erase(0, n);
		
		str += s;
		
		return str;
    }
};
/*
二、解题思路
经典的三次翻转：
1.先翻转字符串前n个字符；
2.再翻转后面的字符；
3.翻转整个字符串；
*/
比如：输入字符串s="12345abc"，n=5;首先翻转前5个字符变成54321abc，然后翻转后面的字符变成54321cba，最后翻转整个字符串变成abc12345

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size = str.size();
		if(n >= size || size == 0 || n <= 0)
		{
			return str;
		}
		
		reverse(str, 0, n - 1);
		reverse(str, n, size - 1);
		reverse(str, 0, size - 1);
		
		return str;
    }
	
	void reverse(string &str, int begin, int end)
	{
		while(begin < end)
		{
			char temp;
			temp = str[begin];
			str[begin] = str[end];
			str[end] = temp;
			
			begin++;
			end--;
		}
	}
};
