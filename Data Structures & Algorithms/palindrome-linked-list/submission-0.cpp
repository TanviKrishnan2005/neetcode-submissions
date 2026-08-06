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
        ListNode* fast = head;
        ListNode* slow = head;
// find middle(slow)
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
// reverse second half
        ListNode *prev = NULL;
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev= slow;
            slow=next; 
        }
// check palindrome
        ListNode* left = head;
        ListNode* right = prev;
        while(right){
            if(left->val != right->val){
                return false;
            }
            left= left->next;
            right = right->next;
        }
        return true;
    }
};