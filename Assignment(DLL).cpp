#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode
{
	int data;
	struct ListNode* nxt;
	struct ListNode* prev;

}ListNode;

ListNode* new_dll(int n)
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}
	ListNode* new_node = head;

	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			printf("Enter the data of the %dth node : \n", i + 1);
			scanf("%d", &new_node->data);
			
			new_node->nxt = head;
			head->prev = new_node;
			return head;
		}
		
		printf("Enter the data of the %dth node : \n", i+1);
		scanf("%d", &new_node->data);
		new_node->nxt = (ListNode*)malloc(sizeof(ListNode));
		new_node->nxt->prev = new_node;
		new_node = new_node->nxt;

	}

	return head;	
}
void printL(ListNode* Head)
{
	ListNode* ptr = Head;

	while (1)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->nxt;

		if (ptr == Head) return;
	}
}

int Len(ListNode* Head)
{
	if (Head == NULL) return 0;
	ListNode* ptr = Head;
	int count = 0;

	while (1)
	{
		count++;
		ptr = ptr->nxt;
		if (ptr == Head) return count;
	}

	return count;
}

void Insert(ListNode* head,ListNode* tail, int pos, int val)
{
	if (pos == 1)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->data = val;
		temp->nxt = head;
		temp->prev = tail;
		head->prev = temp;
		tail->nxt = temp;

		head = temp;
		return;
	}

	else if (pos >= Len(head) + 1)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		temp->data = val;
		temp->nxt = head;
		temp->prev = tail;
		tail->nxt = temp;
		head->prev = temp;

		tail = temp;
		return;
	}

	ListNode* ptr = head;

	for (int i = 0; i < pos-2; i++)
	{
		ptr = ptr->nxt;
	}

	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = val;
	temp->nxt = ptr->nxt;
	temp->prev = ptr;
	ptr->nxt->prev = temp;
	ptr->nxt = temp;

	return;
}

int main()
{
	int len = 0;

	printf("Enter the length of the Linked List you want to create : \n");
	scanf("%d", &len);

	ListNode* pt = new_dll(len);

	printL(pt);

	return 0;
}