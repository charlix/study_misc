
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int val;
	struct node *next;
} node_t;

typedef  node_t  list_t;

typedef  int (*func_t)(int);

list_t *sort_by_userfunc(node_t *list, func_t user_func)
{
	node_t *odd_list=NULL;
	node_t *even_list=NULL;
	node_t *odd_first=NULL;
	node_t *even_first=NULL;
	node_t *cur=list;

	while(cur != NULL) {
		if (user_func(cur->val)) {
			if (!odd_list) {
				odd_list = cur;
				odd_first = cur;
			} else {
				odd_list->next = cur;
				odd_list = odd_list->next;
			}	
			cur = cur->next;
			odd_list->next = NULL;
		}else {
			if(!even_list) {
				even_list = cur;
				even_first = cur;
			} else {
				even_list->next = cur;
				even_list = even_list->next;
			}
			cur = cur->next;
			even_list->next = NULL;
		}
	}

	//foreach_list(even_first);
	//foreach_list(odd_first);
	even_list->next = odd_first;
	//foreach_list(even_first);
	return even_first;
	

	odd_list->next = even_first;
	return odd_first;
}


list_t *group_even_odd(node_t *list, func_t user_func)
{
	node_t *odd_list=NULL;
	node_t *even_list=NULL;
	node_t *odd_first=NULL;
	node_t *even_first=NULL;
	node_t *cur=list;
	int step = 0;
	
	while(cur != NULL) {
		if (step%2) {
			if (!odd_list) {
				odd_list = cur;
				odd_first = cur;
			} else {
				odd_list->next = cur;
				odd_list = odd_list->next;
			}	
			cur = cur->next;
			odd_list->next = NULL;
		}else {
			if(!even_list) {
				even_list = cur;
				even_first = cur;
			} else {
				even_list->next = cur;
				even_list = even_list->next;
			}
			cur = cur->next;
			even_list->next = NULL;
		}
		step++;
	}
	even_list->next = odd_first;
	return even_first;
}



#ifdef TEST
node_t *create_node(val)
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	memset((void *)node, 0, sizeof(node_t));
	node->val = val; 
	return node;
}


void free_list(list_t *list)
{
	list_t *head = list;
	list_t *list_node = NULL;
	while (head) {
		list_node = head->next;
		free(head);
		head = list_node;
	}
}



list_t *create_list(int num)
{
	list_t *list_node = NULL;
	list_t *head = NULL;
	while (num--) {
		if (!head) {
			list_node = create_node(num);
			head = list_node;
		} else {
			list_node->next = create_node(num);
			if (!list_node->next) goto failed;
			list_node = list_node->next;
		}
	}	

	return head;

failed:
	free_list(head);
	return NULL;
}


void foreach_list(list_t *head)
{
	while (head) {
		printf("%d\t", head->val);
		head = head->next;
	}

	printf("\n");
}


int is_even(int val)
{
	return val%2;
}


int main(int argc, char *argv[])
{	
	list_t *list = create_list(10);
	if (list) {
		foreach_list(list);

	//	group_even_odd(list);
		list = sort_by_userfunc(list, is_even);


		foreach_list(list);

		free_list(list);
	}

	return 0;
}
#else

int main(int argc, char *argv[])
{
	return 0;
}


#endif
