#include <stdio.h>
#include <stdlib.h>

void insert(int in);

struct node
{
	int data;
	struct node* next;
	struct node* skip5;
};
struct node* head;
int size=0;	

int main()
{
	head = (struct node*)malloc(sizeof(struct node));
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	struct node* cur = head;
	while(cur!=NULL)
	{
		printf("%d",cur->data);
		cur = cur->next;
	}
	printf("\n\n\n");
	struct node* pre = head;
	while(pre!=NULL)
	{
		printf("%d",pre->data);
		pre=pre->skip5;
	}
	return 0;
}

void insert(int in)
{
	if(size == 0)
	{
		head->data = in;
		size++;
	}
	else
	{
		struct node* cur = head;
		struct node* pre = head;
		int preCount = 0;
		while(cur->next!=NULL)
		{
			if(preCount>=5)
				pre = pre->next;
			cur=cur->next;
			preCount++;
		}
		cur->next = (struct node*)malloc(sizeof(struct node));
		pre->skip5 = cur->next;
		cur->next->data = in;
		size++;
	}
}
/*


		struct node* pre5 = NULL;
		int preCount =0;
		while(cur->next!=NULL)
		{
			if(preCount==5)
				pre5 = head;
			if(preCount>=5)
				pre5 = pre5->next;
			preCount++;
			cur = cur->next;
		}
*/
