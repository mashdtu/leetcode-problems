public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int modsum, sum, carry = 0;
        ListNode o = new ListNode();

        while (l1 != null || l2 != null) {
            int val1 = (l1 != null) ? l1.val : 0;
            int val2 = (l2 != null) ? l2.val : 0;

            ListNode t = new ListNode();

            sum = val1 + val2 + carry;
            System.out.println("sum: " + sum);
            modsum = (sum > 9) ? sum % 10 : sum;

            o.val = modsum;
            carry = (sum > 9) ? 1 : 0;

            System.out.println("val: " + o.val);
            System.out.println("carry: " + carry);

            l1 = (l1 != null) ? l1.next : null;
            l2 = (l2 != null) ? l2.next : null;

            if (l1 != null || l2 != null || carry != 0) {
                o = new ListNode(o.val, o);
            }
            o.val = (carry != 0) ? carry : o.val;
        }

        return reverseList(o);
    }
}