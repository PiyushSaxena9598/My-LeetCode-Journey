/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> v;
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> v2;
        for(int i=0;i<v.size();i++)
        {
            bool flag=true;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i]==v[j])
                {
                    flag=false;
                    i++;
                }
                
            }
            if(flag)
            v2.push_back(v[i]);
        }
        ListNode* newHead=NULL;
        for(int i=0;i<v2.size();i++)
        {
            if(newHead==NULL)
            {
                newHead=new ListNode(v2[i]);
                temp=newHead;
            }
            else
            {
                ListNode* newNode=new ListNode(v2[i]);
                temp->next=newNode;
                temp=temp->next;
            }
        }
        return newHead;
    }
};