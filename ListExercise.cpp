
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

/*
删除有序列表重复元素
*/
ListNode *DeleteDuplicates(ListNode *heard)
{
    if (heard == nullptr || heard->next == nullptr)
    {
        return heard;
    }

    ListNode *pNode = heard;
    ListNode *pDelete = heard;
    while (pNode != nullptr && pNode->next != nullptr)
    {
        if (pNode->val == pNode->next->val)
        {
            // 删除重复
            int temp = pNode->val;
            bool isHeard = pNode == heard;
            while (pNode && pNode->val == temp)
            {
                pDelete = pNode;
                pNode = pNode->next;
                delete pDelete;
            }
            // 头节点更新
            if (isHeard)
            {
                heard = pNode;
            }
        }
        else if(pNode != nullptr)
        {
            pNode = pNode->next;
        }
    }

    return heard;
}

int main()
{

    cout << "main enter" << endl;
    while(true);
    return 0;
}















