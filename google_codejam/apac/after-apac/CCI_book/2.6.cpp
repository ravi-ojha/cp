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

node * detect_loop(node * head)
{
	set <node *> hash;
	node * curr = head;
	while(hash.find(curr) != hash.end())
	{
		curr = curr->next;
	}
	return curr;
}

int main()
{
	node * head = NULL;
	return 0;
}
