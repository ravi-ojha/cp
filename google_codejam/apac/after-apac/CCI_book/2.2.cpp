#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};
node * insert(node * head, int d)
{
	node * my_node = new node;
	my_node->data = d;
	my_node->next = NULL;
	if(head == NULL)
	{
		return my_node;
	}
	else
	{
		node * curr = head;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = my_node;
		return head;
	}
}
void print_list(node * head)
{
	if(head == NULL)
	{
		return;
	}
	node * curr = head;
	while(curr != NULL)
	{
		cout << curr->data << " -> ";
		curr = curr->next;
	}
	cout << "NULL" << endl;
}

//We first find the length of the list
//Then subtract k from length and store in target
// target is the position from the beginning of the list
int kth_element_from_end(node * head, int k)
{
	node * curr = head;
	int len = 0;
	while(curr != NULL)
	{
		len++;
		curr = curr->next;
	}
	int target = len - k;
	int i = 0;
	curr = head;
	while(i != target)
	{
		curr = curr->next;
		i++;
	}
	cout << curr->data << endl;
}

int kth_element_from_end_2(node * head, int k)
{
	node * curr1 = head;
	node * curr2 = head;
	int i = 0;
	while(i != k)
	{
		curr1 = curr1->next;
		i++;
	}
	while(curr1 != NULL)
	{
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	cout << curr2->data << endl;
}

int main()
{
	node * head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,5);
	head = insert(head,8);
	head = insert(head,2);
	head = insert(head,1);
	head = insert(head,7);
	head = insert(head,9);
	print_list(head);
	kth_element_from_end(head,2);
	kth_element_from_end_2(head,2);
	print_list(head);
	return 0;
}
