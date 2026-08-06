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
        ListNode* slow = head;
        ListNode* fast = head;
        //find middle slow is where middle is
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse second half (curr = slow)
        ListNode* prev = NULL;
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;// prev is at last
            prev = slow;
            slow = next;
        }
        //check for palindrom
        ListNode* left = head;
        ListNode* right = prev;
        while(right){
            if(left->val != right->val){
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};