/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/





#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>

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
    vector<vector<int> > Print(TreeNode* pRoot) {
		/*vector<vector<int> > res;

		stack<TreeNode *> stk1;			//从左到右
		stack<TreeNode *> stk2;			//从右到左
		
		TreeNode *node = NULL;
		
		if(!pRoot)
		stk1.push(pRoot);*/
		
		vector<vector<int> > res;
		vector<int> tmpVec;
		stack<TreeNode *> stk1;           //从左到右
		stack<TreeNode *> stk2;           //从右到左
	
		TreeNode *node = NULL;
		if(pRoot != NULL)
			stk1.push(pRoot);
		
		
		while(!stk1.empty() || !stk2.empty())
		{	
			vector<int> tmpVec;
			
			if(!stk1.empty())
			{	
				/*while(!stk1.empty())
				{
					node = stk1.top();
					stk1.pop();
					tmpVec.push_back(node->val);
					if(node->left)
					{
						stk2.push(node->left);
					}
					
					if(node->right)
					{
						stk2.push(node->right);
					}
				}
				
				res.push_back(tmpVec);*/
				
				while(!stk1.empty())
                {
                    node = stk1.top();
                    stk1.pop();
                    tmpVec.push_back(node->val);
                    if(node->left)
                    {
                        stk2.push(node->left);
                    }
					
                    if(node->right)
                    {
                        stk2.push(node->right);
                    }
                }
				
                res.push_back(tmpVec);
			}
			else if(!stk2.empty())
			{
				/*while(!stk2.empty())
				{
					node = stk2.top();
					stk2.pop();
					tmpVec.push_back(node->val);
					if(node->right)
					{
						stk1.push(node->right);
						
					}
					
					if(node->left)
					{
						stk1.push(node->left);
					}
				}
				
                res.push_back(tmpVec);*/
				
				
				while(!stk2.empty())
                {
                    node = stk2.top();
                    stk2.pop();
                    tmpVec.push_back(node->val);
                    if(node->right)
                    {
                        stk1.push(node->right);
						
                    }
					
                    if(node->left)
                    {
                        stk1.push(node->left);
                    }
					
                }
				
                res.push_back(tmpVec);
			}
		}
		
		return res;
    }
	
};


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {      
        vector<vector<int> > res;
        vector<int> tmpVec;
        stack<TreeNode *> stk1;           //从左到右
        stack<TreeNode *> stk2;           //从右到左
		
        TreeNode *node = NULL;
        if(pRoot != NULL)
			stk1.push(pRoot);
		
        while(!stk1.empty() || !stk2.empty())
        {  
            vector<int> tmpVec;
            if(!stk1.empty())
            {  
                while(!stk1.empty())
                {
                    node = stk1.top();
                    stk1.pop();
                    tmpVec.push_back(node->val);
                    if(node->left)
                    {
                        stk2.push(node->left);
                    }
					
                    if(node->right)
                    {
                        stk2.push(node->right);
                    }
                }
				
                res.push_back(tmpVec);
            }
            else if(!stk2.empty())
            {
                while(!stk2.empty())
                {
                    node = stk2.top();
                    stk2.pop();
                    tmpVec.push_back(node->val);
                    if(node->right)
                    {
                        stk1.push(node->right);
						
                    }
					
                    if(node->left)
                    {
                        stk1.push(node->left);
                    }
					
                }
				
                res.push_back(tmpVec);
            }
        }
		
        return res;
    }
	
};

int main()
{
    
    Solution so;
    TreeNode *T1;
    TreeNode *T2;
    vector<vector<int>> vec;


    cout << "创建T1:" << endl;
    so.preCreate(T1);
    cout << "创建T1成功！" << endl;

    //so.CreateImageTree(T1,T2);
    //cout << "T2的前序遍历是（T2是T1的镜像）："<<endl;
    //so.preOrder(T2);
    //cout << endl;

    cout << "T1的层次关系是："<<endl ;
    vec = so.Print(T1);
    for (auto it = vec.begin();it != vec.end();++it)
    {
        for (auto p = it->begin();p != it->end();++p)
        {
            cout << *p << "  ";
        }
        cout << endl;
    }




    
    
    cout << endl;
    return 0;
}
