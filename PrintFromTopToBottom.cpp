题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		if(root == NULL)
		{
			return vector<int>();
		}
		
		vector<int> res;
		
		queue<TreeNode *> que;
		que.push(root);
		
		while(!que.empty())
		{
			TreeNode *pTmp = que.front();
		
			if(pTmp->left != NULL)
			{
				que.push(pTmp->left);
			}
			
			if(pTmp->right != NULL)
			{
				que.push(pTmp->right);
			}
			
			res.push_back(pTmp->val);
			
			que.pop();
		}
		
		return res;
    }
};
