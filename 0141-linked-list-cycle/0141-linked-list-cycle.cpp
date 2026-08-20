/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // int pos;
        // cin >> pos;
        ListNode* curr = head;
        unordered_set<ListNode*> set;
        if(head == NULL){
            return false;
        }
        // if(pos == -1){
        //     return false;
        // }
        while(curr->next != NULL){
            if(!set.contains(curr))
            // if(set.find(curr -> val) == set.end())
                set.insert(curr);
            else
                return true;
            curr = curr -> next;
        }
        return false;
    }
};