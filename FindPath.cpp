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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
			if(root == NULL)
			{
				return res;
			}
			
			tmp.push_back(root->val);
			
			//叶子节点
			if(root->left == NULL && root->right == NULL)
			{
				if(expectNumber - root->val == 0)
				{
					res.push_back(tmp);
					
					//弹出当前叶子节点,回到上一级路径
					tmp.pop_back();
					
					return res;
				}
			}
			
			FindPath(root->left, expectNumber - root->val);
			FindPath(root->right, expectNumber - root->val);
			
			//弹出当前叶子节点,回到上一级路径
			tmp.pop_back();
			
			return res;
    }
	
private:
    vector<vector<int> > res;
	vector<int> tmp;
};
