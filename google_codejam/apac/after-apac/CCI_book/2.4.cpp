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

node * separate_by_x(node * head, int x)
{
	node * first = NULL;
	node * curr = head;
	while(curr != NULL)
	{
		if(curr->data < x)
		{
			first = insert(first, curr->data);
		}
		curr = curr->next;
	}
	first = insert(first,x);
	curr = head;
	while(curr != NULL)
	{
		if(curr->data > x)
		{
			first = insert(first, curr->data);
		}
		curr = curr->next;
	}
	//print_list(first);
	return first;
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
	head = separate_by_x(head,7);
	print_list(head);
	return 0;
}
