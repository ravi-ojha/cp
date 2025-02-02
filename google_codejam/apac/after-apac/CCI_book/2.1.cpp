#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};

/*
node * new_node(int d)
{
	node * mynode = new node;
	node->data = d;
	node->next = NULL;
	return mynode;
}
*/
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

node * remove_duplicates_using_hash(node * head)
{
	set <int> hash;
	node * curr = head;
	node * prev = NULL;
	while(curr != NULL)
	{
		if(hash.find(curr->data) == hash.end()) //lookup in the set is done in O(log n)
		{
			hash.insert(curr->data);
			prev = curr;
			curr = curr->next;
		}
		else
		{
			prev->next = curr->next;
			curr = curr->next;
		}
	}
	return head;
}

bool exists(node * head, node * curr) //checks if the data in curr has ever came before curr node
{
	node * curr2 = head;
	while(curr2 != curr)
	{
		if(curr2->data == curr->data)
		{
			return true;
		}
		curr2 = curr2->next;
	}
	return false;
}

node * remove_duplicates_bf(node * head)
{
	node * curr = head;
	node * prev = NULL;
	while(curr != NULL)
	{
		if(!exists(head, curr)) //check is done in O(n)
		{
			prev = curr;
			curr = curr->next;
		}
		else
		{
			prev->next = curr->next;
			curr = curr->next;
		}
	}
	return head;
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
	print_list(head);
	head = remove_duplicates_using_hash(head);
	print_list(head);
	
	head = insert(head,2);
	head = insert(head,1);
	head = insert(head,7);
	head = insert(head,9);
	print_list(head);
	head = remove_duplicates_bf(head);
	print_list(head);
	return 0;
}
