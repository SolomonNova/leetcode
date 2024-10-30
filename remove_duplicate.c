/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    
    struct ListNode* ptr1=head;
    struct ListNode* ptr2=head;
    
    while(ptr1!=NULL&&ptr1->next!=NULL)
    {
        if(ptr1->next==NULL)
        {
            head->next=NULL;

            return head;
        }

        if(ptr1->val!=(ptr1->next)->val)
        {
            if(ptr2->next!=NULL)
            {
                ptr2->next=ptr1->next;
                ptr2=ptr1->next;
            }
        }
        ptr1=ptr1->next;
    }

    ptr2->next=NULL;

    return head;
}
    
