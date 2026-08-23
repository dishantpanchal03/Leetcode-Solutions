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
        
        // ListNode* curr = head;
        // vector<int> v1;
        // vector<int> v2;
        // while(curr->next != NULL){
        //     v1.push_back(curr->val);
        //     v2.insert(v2.begin(), curr->val);
        //     curr = curr->next;
        // }
        // if(curr->next == NULL){
        //     v1.push_back(curr->val);
        //     v2.insert(v2.begin(), curr->val);
        // }
        // if(v1 == v2)
        //     return true;
        // return false;

        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast)
            slow = slow->next;

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            if (left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};