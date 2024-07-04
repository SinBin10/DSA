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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* head2 = NULL;
        ListNode* temp2 = NULL;
        int sum = 0;
        bool check = true;
        while(temp != NULL){
            sum+=temp->val;
            if(temp->val == 0){
                ListNode* node = new ListNode(sum);
                if(check){
                    head2 = node;
                    temp2 = node;
                    check = false;
                }
                else{
                    temp2->next = node;
                    temp2 = temp2->next;
                }
                sum = 0;
            }
            temp = temp->next;
        }
        return head2;
    }
};