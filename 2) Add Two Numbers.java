public class ListNode
{
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution
{
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        int carry = 0;
        ListNode result = new ListNode();
        ListNode p = result;
        ListNode p1 = l1;
        ListNode p2 = l2;

        while (p1 != null || p2 != null)
        {
            if (p1 != null && p2 != null)
            {
                p.val = (p1.val + p2.val + carry) % 10;
                carry = (p1.val + p2.val + carry) / 10;
                p1 = p1.next;
                p2 = p2.next;
            }

            else if (p1 == null && p2 != null)
            {
                p.val = (p2.val + carry) % 10;
                carry = (p2.val + carry) / 10;
                p2 = p2.next;
            }

            else if (p2 == null && p1 != null)
            {
                p.val = (p1.val + carry) % 10;/**/
                carry = (p1.val + carry) / 10;
                p1 = p1.next;
            }

            if (p1 != null || p2 != null)
            {
                p.next = new ListNode();
                p = p.next;
            }
        }

        if (carry > 0)
        {
            p.next = new ListNode(carry);
        }

        return result;
    }
}

class Main
{
    public static void main(String[] args)
    {
        ListNode l1 = new ListNode(5);
        l1.next = new ListNode(6);
        l1.next.next = new ListNode(7);

        ListNode l2 = new ListNode(5);
        l2.next = new ListNode(4);
        l2.next.next = new ListNode(9);
        l2.next.next.next = new ListNode(3);
        l2.next.next.next.next = new ListNode(1);

        ListNode res = Solution.addTwoNumbers(l1, l2);

        while (res != null)
        {
            System.out.println(" " + res.val);
            res = res.next;
        }
    }
}