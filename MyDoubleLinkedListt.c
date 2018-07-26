#include	<stdio.h>
#include	<stdlib.h>

typedef	struct node	{
	int	val;
	struct node*	next;
	struct node*	prev;
}Node;

typedef	struct List	{
	Node*	head;
}LinkedList;

Node*	createNode(int	value);
LinkedList*	emptyList();
void	insertFront(int value,	LinkedList*	list);
void	insertBack(int value,	LinkedList*	list);
void	display(LinkedList*	list);
void	deleteFront(LinkedList*	list);
void	deleteBack(LinkedList*	list);
int 	countElem(LinkedList*	list);

int	main()	{
	printf("Double LinkedList\n");
	LinkedList*	D_LinkedList	=	emptyList();
	int count =	countElem(D_LinkedList);
	printf("COUNT:%d\n",	count);
	insertFront(5,	D_LinkedList);
	insertFront(6,	D_LinkedList);
	insertFront(7,	D_LinkedList);
	count =	countElem(D_LinkedList);
	printf("COUNT:%d\n",	count);
	display(D_LinkedList);
	insertBack(8,	D_LinkedList);
	insertBack(9,	D_LinkedList);
	insertBack(10,	D_LinkedList);
	count =	countElem(D_LinkedList);
	printf("COUNT:%d\n",	count);
	display(D_LinkedList);
	deleteFront(D_LinkedList);
	deleteFront(D_LinkedList);
	deleteFront(D_LinkedList);
	count =	countElem(D_LinkedList);
	printf("COUNT:%d\n",	count);
	display(D_LinkedList);
	deleteBack(D_LinkedList);
	deleteBack(D_LinkedList);
	deleteFront(D_LinkedList);
	count =	countElem(D_LinkedList);
	printf("COUNT:%d\n",	count);
	display(D_LinkedList);
	return	0;
}

Node*	createNode(int	value)	{
	Node*	newNode	=	malloc(sizeof(Node));
	if (newNode	==	NULL)	printf("Failed	to	allocate	memory\n");
	newNode->val =	value;
	newNode->prev	=	newNode->next	=	NULL;
}

LinkedList*	emptyList()	{
	LinkedList*	list =	malloc(sizeof(LinkedList));
	list->head	=	NULL;
	return	list;
}

void	insertFront(int value,	LinkedList*	list)	{
	Node*	newNode	=	createNode(value);
	if (list->head	==	NULL)	
		list->head	=	newNode;
	else	{
		newNode->next	=	list->head;
		list->head->prev	=	newNode;
		list->head	=	newNode;
	}
	printf("Insertion	succesed!!!!!\n");
}

void	insertBack(int value,	LinkedList*	list)	{
	Node*	newNode	=	createNode(value);
	Node*	temp	=	NULL;
	if (list->head	==	NULL)	
		list->head	=	newNode;
	else	{
		temp	=	list->head;
		while	(temp->next	!=	NULL)	{	temp	=	temp->next;	}
		temp->next	=	newNode;
		newNode->prev	=	temp;
	}
	printf("Insertion	succesed!!!!!\n");
}

void	display(LinkedList*	list)	{
	Node*	temp	=	list->head;
	if (list->head	==	NULL)	printf("LinkedList	is empty\n");
	while	(temp->next	!=	NULL)	{
		printf("<----%d----> ",	temp->val);
		temp	=	temp->next;
	}
	printf("<----%d----> ",	temp->val);
	printf("\n");
}

void	deleteFront(LinkedList*	list)	{
	Node*	temp	=	list->head;
	if (list->head	==	NULL)	
		printf("List is empty");
	else	{
		if (temp->next	==	temp->prev)	{
			list->head	=	NULL;
			free(temp);
		}	else	{
			list->head	=	temp->next;
			temp->next	=	NULL;
			list->head->prev	=	NULL;
			free(temp);
		}
	}
	printf("Deletion	succesed!!!!!\n");
}

void	deleteBack(LinkedList*	list)	{
	Node*	temp	=	list->head;
	Node*	back =	NULL;
	if (list->head	==	NULL)	
		printf("List is empty\n");
	else {
		if (temp->next	==	temp->prev)	{
			list->head	=	NULL;
			free(temp);
		}	else	{
			while	(temp->next	!=	NULL)	{
				back 	=	temp;	
				temp	=	temp->next;	
			}
			if (back !=	NULL)	{
				temp->prev	=	NULL;
				back->next	=	NULL;
				free(temp);
			}
		}
	}
	printf("Deletion	succesed!!!!!\n");
}

int 	countElem(LinkedList*	list)	{
	int count =	0;
	Node*	temp	=	list->head;
	if (list->head	==	NULL)	
		return	count;
	else	{
		while	(temp->next	!=	NULL)	{
			++count;
			temp	=	temp->next;
		}
	}
	++count;
	return	count;
}
