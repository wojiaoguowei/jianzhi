/*题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。*/

#include <stddef.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <cstdio>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*class Solution {
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
	
	void preOrder(TreeNode* T)
    {
        if (T == NULL) return; 
        else
        {
            cout << T->val << "  ";
            preOrder(T->left);
            preOrder(T->right);
        }
		
		cout << endl;
    }
	
	TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k < 0)
		{
			return NULL;
		}
		
		int len = 0;
		pre(pRoot, len);
		
		preOrder(pRoot);
		
		for(int i = len / 2 - 1; i >= 0; --i)
		{
			//建堆
			ElementDown(pRoot, len, i);
		}
		
		preOrder(pRoot);
		
		TreeNode* pK = NULL;
		//调整小根堆
		for(int i = 0; i < k; i++)
		{
			swap(&pRoot[0].val, &pRoot[len - 1].val);
			pK = pRoot + len - 1;
			ElementDown(pRoot, len--, i);
		}
		
		return pK;
    }

    void ElementDown(TreeNode* pRoot, int len, int index)
	{
		if(pRoot == NULL || index >= len)
		{
			return;
		}
		
		for(int i = index; i < len;)
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			
			//左右子节点都有
			if(left <= len - 1)
			{
				//因为是搜索二叉树，所以左子节点一定小于根，右子节点大于根
				swap(&pRoot[i].val, &pRoot[left].val);
				i = left;
			}
			//else if(left == len - 1)	//只有左子节点
			//{
			//	i = left;
			//}
			else	//叶子节点
			{
				return;
			}
		}
		
		return;
	}
	
	void swap(int *v1, int *v2)
	{
		int tmp = *v1;
		*v1 = *v2;
		*v2 = tmp;
	}
	
	void pre(TreeNode* pRoot, int &len)
	{
		if(pRoot == NULL)
		{
			return;
		}
		
		//根
		len++;
		pre(pRoot->left, len);
		pre(pRoot->right, len);
	}
};*/


//
//{8,6,10,5,7,9,11},1

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
	
	void midOrder(TreeNode* T, int &k, TreeNode* &pK)
	{
		if (T == NULL)
		{
			return;
		}
		else
        {
            midOrder(T->left, k, pK);
			
			if(--k == 0)
			{
				pK = T;
			}
			cout << T->val << "  ";
			
			midOrder(T->right, k, pK);
        }
			
	}
	
	void preOrder(TreeNode* T)
    {
        if (T == NULL) return; 
        else
        {
            cout << T->val << "  ";
            preOrder(T->left);
            preOrder(T->right);
        }

    }
	
	TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k < 0)
		{
			return NULL;
		}
		
		
		TreeNode* p = NULL;
		midOrder(pRoot, k, p);
		
		return p;
    }
};



int main()
{

	Solution so;
    TreeNode *T1;
    TreeNode *T2;
    vector<vector<int> > vec;
	
	//{8,6,10,5,7,9,11},1
    cout << "创建T1:" << endl;
    so.preCreate(T1);
    cout << "创建T1成功！" << endl;
	
	T2 = so.KthNode(T1, 1);
	
	//char *str = so.Serialize(T1) /*"1,2,4,#,#,5,#,#,3,6,#,#,7,#,#"*/;
	
	return 1;
}
