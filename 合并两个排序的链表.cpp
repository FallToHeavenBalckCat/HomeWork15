/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*归并排序的思想，选择小的，一个先选完之后把另一个直接放进去*/
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        else if(l2==nullptr) return l1;
        else if(l1==nullptr&&l2==nullptr) return nullptr;
        
        ListNode* l=new ListNode(0);//l指针是处理链表的，还需要一个指针保存头结点
        ListNode* head=l;
        ListNode* i=l1;
        ListNode* j=l2;
        while(i!=nullptr&&j!=nullptr){
            ListNode* ne=new ListNode(0);
            if(i->val<j->val) 
            {
                ne->val=i->val;
                i=i->next;
            }
            else 
            {
                ne->val=j->val;
                j=j->next;
            }
            l->next=ne;
            l=ne;
        }
        while(i!=nullptr) {
            ListNode* ne=new ListNode(0);
            ne->val=i->val;
            i=i->next;
            l->next=ne;
            l=ne;
        }
        while(j!=nullptr){
            ListNode* ne=new ListNode(0);
            ne->val=j->val;
            j=j->next;
            l->next=ne;
            l=ne;
        }
        head=head->next;
        return head;
    }
};