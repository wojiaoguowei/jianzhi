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
    //设置两个队列，一个存放父节点；一个存放子节点;打印完父节点后，再把子队列的值存放到父队列中
    vector<vector<int> > Print(TreeNode* pRoot) {
        queue<TreeNode*> faQue;
        queue<TreeNode*> chQue;
        vector<vector<int>> vec;
        vector<int> line;
        if (pRoot == NULL) return{};
        faQue.push(pRoot);
        /*line.push_back(pRoot->val);
        vec.push_back(line);*/

        while (!faQue.empty ()/*||!chQue.empty ()*/)
        {
            if (faQue.front()->left != NULL) chQue.push(faQue.front()->left); //左右节点放到孩子节点的位置
            if (faQue.front()->right != NULL) chQue.push(faQue.front()->right);
            line.push_back(faQue.front()->val);
            faQue.pop();
            if (faQue.empty())//当节点打印完成后，将所有父节点的值传递过去；要清空line；把孩子的节点给父节点；子队列清空；进行下次循环；
            {
                vec.push_back(line);
                line.clear();
                while (!chQue.empty ())
                {
                    faQue.push(chQue.front());
                    chQue.pop();
                }
            }
        }
        return vec;

    }


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



    cout << "T1的前序遍历:" << endl;
    so.preOrder(T1);
    cout << endl;

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
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
			if(!pRoot)
			{
				return vector<vector<int> >();
			}
			
			queue<TreeNode *> pQue;
			queue<TreeNode *> cQue;
			vector<vector<int> > res;
			vector<int> tmpVec;
			pQue.push(pRoot);
			
			while(!pQue.empty())
			{
				if(pQue.front()->left)
				{
					cQue.push(pQue.front()->left);
				}
				
				if(pQue.front()->right)
				{
					cQue.push(pQue.front()->right);
				}
				
				
				int nValue = pQue.front()->val;
				tmpVec.push_back(nValue);
				
				pQue.pop();
				//pQue父队列为空，把孩子队列的值放到父队列里
				if(pQue.empty())
				{
					res.push_back(tmpVec);
					tmpVec.clear();
					
					while(!cQue.empty())
					{
						TreeNode *pTmp = cQue.front();
						pQue.push(pTmp);
						
						cQue.pop();
					}
				}
			}
			
			return res;
        }
    
};

















