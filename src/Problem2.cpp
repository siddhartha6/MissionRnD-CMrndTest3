/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};

int dll_length(struct node_dll *head)
{
	struct node_dll *temp = head;
	int len = 0;
	while(temp!=NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

void inorder_traversal(struct node *root, int *arr, int *index){
	if (root != NULL)
	{
		inorder_traversal(root->left, arr, index);
		*index = *index + 1;
		arr[*index] = root->data;
		inorder_traversal(root->right, arr, index);
	}
}


int is_identical(struct node_dll *head, struct node *root){
	if (head==NULL || root==NULL)
	       return -1;

	int *arr = (int *)malloc(20*sizeof(int));
	int index = -1;
	inorder_traversal(root, arr, &index);
	int res = 0, index1 = 0;
	while (head)
	{
		if ((head->data) == arr[index1])
			res = 1;
		else
			res = 0;
		head = head->next;
		index1++;
	}
	return res;
}