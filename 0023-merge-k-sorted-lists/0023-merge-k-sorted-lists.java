import java.util.*;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer> values = new ArrayList<>();

        for (ListNode head : lists) {
            while (head != null) {
                values.add(head.val);
                head = head.next;
            }
        }

        Collections.sort(values);

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        for (int val : values) {
            curr.next = new ListNode(val);
            curr = curr.next;
        }

        return dummy.next;
    }
}