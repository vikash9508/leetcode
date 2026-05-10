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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL || head->next==NULL){
        return head;
      }
      vector<int>nums;
      ListNode* temp=head;
      while(temp){
        nums.push_back(temp->val);
        temp=temp->next;
      }
      int n=nums.size();
      k=k%n;
      vector<int>rotate;
      for(int i=n-k;i<n;i++){
        rotate.push_back(nums[i]);
        
      }
      for(int i=0;i<n-k;i++){
        rotate.push_back(nums[i]);
      }
      temp=head;
      int i=0;
      while(temp){
        temp->val=rotate[i];
        i++;
        temp=temp->next;
      }
      return head;
    }
};       
