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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       ListNode* prev=head;
       ListNode* curr=head->next;
       int currpos=1;
       int prevcriticalpos=0;
       int firstcriticalpos=0;
       int mindist=INT_MAX;
       while(curr->next!=NULL)
       {
        if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val))
        {
            if(prevcriticalpos==0)
            {
                prevcriticalpos=currpos;
                firstcriticalpos=currpos;
            }
            else
            {
                mindist=min(mindist,currpos-prevcriticalpos);
                prevcriticalpos=currpos;
            }
        }
        currpos++;
        prev=curr;
        curr=curr->next;
       }
       if(mindist==INT_MAX)
       return {-1,-1};

    return {mindist,prevcriticalpos-firstcriticalpos};

    }
};