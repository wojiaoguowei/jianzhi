/*题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

/*class Solution {
public:
    string ReverseSentence(string str) {
        string strT;
		if(str.size() == 0 )
		{
			return strT;
		}
		else if(split(str).empty())
		{
			return str;
		}
		
		vector<string> vec = split(str);
		reverse(vec, 0, vec.size() - 1);
		
		for(int i = 0; i < vec.size(); i++)
		{
			strT += vec[i] + string(" ");
		}
		
		strT = strT.substr(0, strT.size() - 1);
		
		return strT;
    }
	
	vector<string> split(string str)
	{
		vector<string> vec;
		char *s = (char *)str.c_str();
		char *p;
		const char *delim = " ";
		p = strtok(s, delim);
		while(p)
		{
			vec.push_back(p);
			p = strtok(NULL, delim);
		}
		
		return vec;
	}
	
	void reverse(vector<string> &vec, int begin, int end)
	{
		while(begin < end)
		{
			string temp;
			temp = vec[begin];
			vec[begin] = vec[end];
			vec[end] = temp;
			
			begin++;
			end--;
		}
	}
};*/

class Solution {
public:
    string ReverseSentence(string str) {
        string strT;
		if(str.size() == 0 )
		{
			return strT;
		}
		
		reverse(str, 0, str.size() - 1);
		int s = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == ' ')
			{
				reverse(str, s, i - 1);
				s = i + 1;
			}
		}
		
		if(s < str.size())
		{
			reverse(str, s, str.size() - 1);
		}
		
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

/*class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.length();
        string &temp = str;
        reserve(temp,0,len-1);
        int s = -1;
        for(int i=0;i<len;i++){
            if(str[i] == ' '){
                reserve(temp,s+1,i-1);
                s = i;
            }
        }
        reserve(temp,s+1,len-1);
        return str;
    }
    void reserve(string &s,int start,int end){
        char temp;
        while(start < end){
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};*/

 
int main() {
	char s[] = "I am a student.";
	/*char *p;
	const char *delim = " ";
	p = strtok(s, delim);
	while(p) {
		cout << p << endl;
		p = strtok(NULL, delim);
	}*/
	
	Solution sol;
	string ss = sol.ReverseSentence(s);
 
	return 0;
}
