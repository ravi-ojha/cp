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

node * add_lists(node * first, node * second)
{
	int carry = 0, data;
	node * head = NULL;
	while(first != NULL && second != NULL)
	{
		data = first->data + second->data + carry;
		carry = data/10;
		data = data%10;
		head = insert(head, data);
		first = first->next;
		second = second->next;
	}
	while(first != NULL)
	{
		data = first->data + carry;
		carry = data/10;
		data = data%10;
		head = insert(head, data);
		first = first->next;
	}
	while(second != NULL)
	{
		data = second->data + carry;
		carry = data/10;
		data = data%10;
		head = insert(head, data);
		second = second->next;
	}
	if(carry == 1)
	{
		head = insert(head, carry);
	}
	return head;
}

node * reverse(node * head)
{
	node * prev = NULL;
	node * curr = head;
	node * next;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

node * add_lists_2(node * first, node * second)
{
	node * first1 = reverse(first);
	node * second1 = reverse(second);
	node * added = add_lists(first1,second1);
	added = reverse(added);
	return added;
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
	
	node * head_2 = NULL;
	head_2 = insert(head_2,8);
	head_2 = insert(head_2,2);
	head_2 = insert(head_2,1);
	head_2 = insert(head_2,7);
	head_2 = insert(head_2,9);
	print_list(head);
	print_list(head_2);
	
	node * added = add_lists(head, head_2);
	node * added_2 = add_lists_2(head, head_2);
	print_list(added);
	print_list(added_2);
	return 0;
}
