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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //dummy node
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        //carry initialization
        int carry =0;

        //loop conditon also avoids carry
        while(l1 != nullptr || l2!=nullptr || carry !=0){
        //getting values
        int v1 = (l1!= nullptr) ? l1->val:0;
        int v2 = (l2!= nullptr) ? l2->val:0;

        //add digits + carry

        int val = v1+v2+carry;
        carry = val/10;//carry to next step
        val = val % 10;//digits to store

        //create new node
        cur->next = new ListNode(val);
        cur = cur->next;

        //move input lists

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
