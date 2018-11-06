#include <stddef.h>
#include <stdbool.h>

using namespace std;

/*struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
}; 

class Solution {
public:
  bool HasSubtree(TreeNode *root1, TreeNode *root2) {
        bool result = false;
        //当Tree1和Trmee2都不为零的时候，才进行比较。否则直接返回false
        if (root2 != NULL && root1 != NULL) {
            //如果找到了对应Tree2的根节点的点
            if(root1->val == root2->val){
                //以这个根节点为为起点判断是否包含Tree2
                result = doesTree1HaveTree2(root1,root2);
            }
            //如果找不到，那么就再去root的左儿子当作起点，去判断时候包含Tree2
            if (!result) {
                result = HasSubtree(root1->left,root2);
            }
             
            //如果还找不到，那么就再去root的右儿子当作起点，去判断时候包含Tree2
            if (!result) {
                result = HasSubtree(root1->right,root2);
               }
            }
          //返回结果
        return result;
    }
 
     bool doesTree1HaveTree2(TreeNode *node1, TreeNode *node2) {

        //如果Tree2已经遍历完了都能对应的上，返回true
        if (node2 == NULL) {
            return true;
        }
        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if (node1 == NULL) {
            return false;
        }
        //如果其中有一个点没有对应上，返回false
        if (node1->val != node2->val) {  
                return false;
        }
         
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return doesTree1HaveTree2(node1->left,node2->left) && doesTree1HaveTree2(node1->right,node2->right);
    }
};*/




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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if(pRoot1 == NULL || pRoot2 == NULL)
		{
			return false;
		}
		
		bool result = false;
		
		if(pRoot1->val == pRoot2->val)
		{
			result = TreeHasTree2(pRoot1, pRoot2);
		}
		
		if(result == false)
		{
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		
		if(result == false)
		{
			result = HasSubtree(pRoot1->right, pRoot2);				
		}
		
		return result;
    }
private:
	bool TreeHasTree2(TreeNode* pNode1, TreeNode* pNode2)
	{
		if(pNode2 == NULL)
		{
			return true;
		}
		
		if(pNode1 == NULL)
		{
			return false;
		}
		
		if(pNode1->val != pNode2->val)
		{
			return false;
		}
		
		return TreeHasTree2(pNode1->left, pNode2->left) && TreeHasTree2(pNode1->right, pNode2->right);
	}
};

int main()
{
	return 1;
}
    
