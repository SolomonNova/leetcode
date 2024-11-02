/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* ptr1=l1;
    struct ListNode* ptr2=l2;

    long long unsigned num1=0;
    long long unsigned num2=0;

    while(ptr1!=NULL)
    {
        num1=num1*10+ptr1->val;
        ptr1=ptr1->next;

        if(ptr1==NULL)
        {
            break;
        }
    }

    while(ptr2!=NULL)
    {
        num2=num2*10+ptr2->val;
        ptr2=ptr2->next;

        if(ptr2==NULL)
        {
            break;
        }
    }

    long long unsigned sum=num1+num2;
    int count=0;

    if (sum == 0)
        {
            struct ListNode* zeroNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            zeroNode->val = 0;
            zeroNode->next = NULL;
            return zeroNode;
        }

    struct ListNode* tail=NULL;
    struct ListNode* head=NULL;

    while(sum!=0)
    {
        int last_digit=sum%10;

        struct ListNode* nextNode=(struct ListNode*)malloc(sizeof(struct ListNode));

        nextNode->val=last_digit;
        nextNode->next=NULL;

        if(count==0)
        {
            head=nextNode;
            tail=nextNode;
        }

        else
        {
            tail->next=nextNode;
            tail=nextNode;
        }

        count++;

        sum/=10;
    }

    return head;
}
    
