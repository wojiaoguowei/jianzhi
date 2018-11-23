题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(!pRoot)
		{
			return true;
		}
		
		int left = GetTreeDepth(pRoot->left);
		int right = GetTreeDepth(pRoot->right);
		
		if(left - right < -1 || left - right > 1)
		{
			return false;
		}
		
		if(IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right))
		{
			return true;
		}
		
		return false;
    }
	
private:
	int GetTreeDepth(TreeNode* pRoot)
	{
		if(pRoot == NULL)
		{
			return 0;
		}
		
		int left = GetTreeDepth(pRoot->left);
		int right = GetTreeDepth(pRoot->right);
		
		return 1 + (left > right ? left :right);
	}
	
};
