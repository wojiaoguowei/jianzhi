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
    void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL)
		{
			return;
		}	
		
		if(pRoot->left == NULL && pRoot->right == NULL)
		{
			return;
		}
		
		TreeNode *pTmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTmp;
		
		Mirror(pRoot->left);
		Mirror(pRoot->right);
    }
};
