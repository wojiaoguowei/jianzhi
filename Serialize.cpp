/*题目描述
请实现两个函数，分别用来序列化和反序列化二叉树*/



#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <cstdio>

#ifndef _DEBUG
#define _SECURE_SCL 0
#endif

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
	void preCreate(TreeNode* &T)
    {
        int num;
        cin >> num;
        if (num == 0) T = NULL;
        else
        {
            T = new TreeNode(num);
            preCreate(T->left);
            preCreate(T->right);
        }
    }
	
    char* Serialize(TreeNode *root) 
	{    
        if(root == NULL)
		{
			return NULL;
		}
		
		string str = "";
		str = SerializeCore(root);
		
		int len = str.size();
		char *res = new char[len + 1];
		
		for(int i = 0; i < len; i++)
		{
			res[i] = str[i];
		}
		
		res[len] = '\0';
		
		return res;
    }
	
    TreeNode* Deserialize(char *str) {
		if(str == NULL)
		{
			return NULL;
		}
		
		
		
		
		
		
		vector<TreeNode *> nodesVec;
		const char *delm = ",";
		vector<string> strVec = split(str, delm);
		int size = strVec.size();
		for(int i = 0; i < size; ++i)
		{
			if(strVec[i] == "#")
			{
				nodesVec.push_back(NULL);
			}
			else
			{
				int val = atoi(strVec[i].c_str());
				TreeNode *n = new TreeNode(val);
				nodesVec.push_back(n);	
			}
		}
		
		int index = 0;
		TreeNode *root = DeserializeCore(nodesVec, size, index);
		return root;
    }
	
	string SerializeCore(TreeNode *root)
	{
		if(root == NULL)
		{
			return string("#,");
		}
		
		char str[10];
		sprintf(str, "%d,", root->val);
		string rs = str;
		
		rs += SerializeCore(root->left);
		rs += SerializeCore(root->right);
		
		return rs;
	}
	
	
	
	//len元素个数 index数组索引
	TreeNode *DeserializeCore(vector<TreeNode *> &num, int len, int &index)
	{
		if(index >= len)
		{
			return NULL;
		}
		
		TreeNode *node = NULL;
		if(index < len)
		{
			node = num[index];
			if(node == NULL)
			{
				return NULL;
			}
			
			node->left = DeserializeCore(num, len, ++index);
			node->right = DeserializeCore(num, len, ++index);
		}
		
		return node;
	}
	
private:
	vector<string> split(char *str, const char *delim)
	{
		vector<string> res;
		res.clear();
		
		if(str == NULL || delim == NULL)
		{
			return res;
		}
	
		char *p;
		p = strtok(str, delim);
		string s;
		while(p) 
		{
			stringstream ss(p);
			
			ss >> s;
			res.push_back(s);
			
			p = strtok(NULL, delim);
			
			s.clear();
		}
		
		return res;
	}
	
public:
	void preOrderTraver(TreeNode *T)
    {
        if (T == NULL) return;
        else
        {
            cout << T->val << "  ";
            preOrderTraver(T->left);
            preOrderTraver(T->right);
        }
    }
	
};

int main()
{
	Solution so;
    TreeNode *T1;
    TreeNode *T2;
    vector<vector<int> > vec;
	
	
    cout << "创建T1:" << endl;
    so.preCreate(T1);
    cout << "创建T1成功！" << endl;
	
	char *str = so.Serialize(T1) /*"1,2,4,#,#,5,#,#,3,6,#,#,7,#,#"*/;
	
	TreeNode *T3 = so.Deserialize(str);
	so.preOrderTraver(T3);
	cout << endl;
    //cout << "T1的前序遍历:" << endl;
    //so.preOrder(T1);
    //cout << endl;
	
	
	return 0;
}
