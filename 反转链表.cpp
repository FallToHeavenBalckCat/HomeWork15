/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
       //迭代写法,维护一个前驱结点，将后续结点指向前驱结点即
       ListNode prev=null;
       ListNode cnt=head;
       while(cnt!=null){
           ListNode next=cnt.next;
           cnt.next=prev;
           prev=cnt;
           cnt=next;
       }
       return prev;
    }
}