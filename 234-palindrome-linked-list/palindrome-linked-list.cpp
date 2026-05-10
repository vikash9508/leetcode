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
    bool isPalindrome(ListNode* head) {
    
       ListNode *temp=head;
       if(head->next==NULL)
       return 1;
       vector<int>nums;
       while(temp){
        nums.push_back(temp->val);
        temp=temp->next;
       };
       int n=nums.size();
       int i=0,j=n-1;
       while(i<j){
        if(nums[i]!=nums[j])
        return 0;
        i++;
        j--;
       }
        return 1;
      

    }
};