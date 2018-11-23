
不通过
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例
case通过率为57.14%

	测试用例:
{1,2,3,4,5},{},{}

对应输出应该为:

{}

你的输出为:

{5}

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
		{
			return 0;
		}
		
		int len1 = GetListLength(pHead1);
		int len2 = GetListLength(pHead2);
		
		int diff = 0;
		if(len1 > len2)
		{
			diff = len1 - len2;
			
			for(int i = 0; i < diff; i++)
			{
				pHead1 = pHead1->next;
			}
			
			while(pHead1 != NULL && pHead2 != NULL && pHead1 != pHead2)
			{
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
			
			if(!pHead1)
			{
			
			return NULL;
			}
			else
			{
				return pHead1;
			}
		}
		else
		{
			diff = len2 - len1;
			
			for(int i = 0; i < diff; i++)
			{
				pHead2 = pHead2->next;
			}
			
			while(pHead1 != NULL && pHead2 != NULL && pHead1 != pHead2)
			{
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
			
			if(!pHead1)
			{
				
				return NULL;
			}
			else
			{
				return pHead1;
			}
		}
		
    }
	
	int GetListLength(ListNode* pHead1)
	{
		if(!pHead1)
		{
			return 0;
		}
		
		int i = 0;
		while(pHead1)
		{
			if(pHead1->next)
			{
				i++;
			}
			
			pHead1 = pHead1->next;
		}
		
		return i;
	}
};
