#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

// Linked list struct thing...
typedef struct node
{
	int val;
	struct node *next;
} node_t;

// definitions
void printList(node_t * head);
void pushLast(node_t *head, int val);
void pushFirst(node_t **head, int val);
int popFirst(node_t **head);
int popLast(node_t *head);
int popByIndex(node_t **head, int index);
int popByValue(node_t **head, int val);
void pushByIndex(node_t **head, int index, int val);
void pushBByValue(node_t **head, int sVal, int iVal);
void reverse(node_t **head);

// main function
int main()
{
	node_t *head = NULL;
	head = malloc(sizeof(node_t));

	if (head == NULL)
	{
		return 1;
	}

	head->val = 7;
	head->next = malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = malloc(sizeof(node_t));
	head->next->next->val = 6;
	head->next->next->next = NULL;

	//pushBByValue(&head, 7, 1);
	//pushByIndex(&head, 1, 5);
	//pushLast(head, 9);
	//pushFirst(&head, 1);
	//popFirst(&head);
	//popLast(head);
	//popByIndex(&head, 3);
	//popByValue(&head, 9);
	//printList(head);
	//reverse(&head);
	printList(head);

	free(head);

	return 0;
}

// Printing out the list
void printList(node_t *head)
{
	node_t *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}

	return;
}

// Pushing the item to the end of the list
void pushLast(node_t *head, int val)
{
	node_t *current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;

	return;
}

// Pushing the item to the beginning of the list
void pushFirst(node_t **head, int val)
{
	node_t *new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;

	return;
}

// Pushing value by index number
void pushByIndex(node_t **head, int index, int val)
{
	node_t *current = *head;
	node_t *temp_node = NULL;
	node_t *new_node = malloc(sizeof(node_t));

	if (index == 0)
	{
		pushFirst(head, val);
	}

	for (int i = 0; i < index - 1; i++)
	{
		if (current->next == NULL)
		{
			return;
		}
		current = current->next;
	}

	new_node->val = val;
	temp_node = current->next;
	current->next = new_node;
	new_node->next = temp_node;

	return;
}

// Pushing a value before a certain value. sVal = search value   iVal = inserted value
void pushBByValue(node_t **head, int sVal, int iVal)
{
	node_t *current = *head;
	node_t *temp_node = NULL;
	node_t *new_node = malloc(sizeof(node_t));

	if (sVal == NULL || iVal == NULL)
	{
		return;
	}

	if ((*head)->val == sVal)
	{
		return pushFirst(head, iVal);
	}

	while (current->next->val != sVal)
	{
		if (current->next == NULL)
		{
			return;
		}

		current = current->next;
	}

	new_node->val = iVal;
	temp_node = current->next;
	current->next = new_node;
	new_node->next = temp_node;

	return;
}
// Popping the first item of the list
int popFirst(node_t **head)
{
	int retval = -1;
	node_t *next_node = NULL;

	if (*head == NULL)
	{
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

// Popping the last item from the list
int popLast(node_t *head)
{
	int retval = 0;

	if (head->next == NULL)
	{
		retval = head->val;
		free(head);
		return retval;
	}

	node_t *current = head;
	while (current->next->next != NULL)
	{
		current = current->next;
	}

	retval = current->next->val;
	free(current->next);
	current->next = NULL;

	return retval;
}

// Popping the item by selected index
int popByIndex(node_t **head, int index)
{
	int retval = -1;
	node_t *current = *head;
	node_t *temp_node = NULL;

	if (index == 0)
	{
		return popFirst(head);
	}

	for (int i = 0; i < index - 1; i++)
	{
		if (current->next == NULL)
		{
			return -1;
		}
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}

// Popping the item by selected value
int popByValue(node_t **head, int val)
{

	int retval = -1;
	node_t *current = *head;
	node_t *temp_node = NULL;

	if (current == NULL)
	{
		return -1;
	}

	if ((*head)->val == val)
	{
		return popFirst(head);
	}

	temp_node = current = (*head)->next;
	while (current) {
		if (current->val == val)
		{
			temp_node->next = current->next;
			free(current);
			return val;
		}

		temp_node = current;
		current = current->next;
	}
	return -1;
}

// Reversing the linked lists
void reverse(node_t **head)
{
	node_t *current, *prev, *next;
	current = *head;
	prev = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;

	return;
}
