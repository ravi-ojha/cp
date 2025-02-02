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

/*node * reverse(node * head)
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
}*/

bool is_palin(node * head)
{
	int len = 0;
	node * curr = head;
	while(curr != NULL)
	{
		curr = curr->next;
		len++;
	}
	stack <int> my_stack;
	curr = head;
	for(int i=0;i<len/2;i++)
	{
		my_stack.push(curr->data);
		curr = curr->next;
	}
	if(len%2 == 1)
	{
		curr = curr->next;
	}
	while(curr != NULL)
	{
		if(my_stack.top() != curr->data)
		{
			return false;
		}
		my_stack.pop();
		curr = curr->next;
	}
	return true;
}

int main()
{
	node * head = NULL;
	head = insert(head,1);
	head = insert(head,2);
	head = insert(head,5);
	head = insert(head,8);
	//head = insert(head,8);
	head = insert(head,5);
	//head = insert(head,2);
	head = insert(head,1);
	print_list(head);
	cout << is_palin(head) << endl;
	return 0;
}
