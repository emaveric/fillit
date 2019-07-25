//
// Created by Erik Maverick on 2019-07-25.
//

#include "fillit.h"

int 	**n_arr()
{
	int i;
	int **arr;

	i = 0;
	arr = (int**)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		arr[i] = (int *) malloc(sizeof(int) * 2);
		i++;
	}
	return (arr);
}

tet_list int	*ls_new()
{
	tet_list *new;


	new = (tet_list*)malloc(sizeof(tet_list));
	new->coord = n_arr();
	new->frog = 0;
	new->jaba = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int 	main()
{
	/*int 	i;
	tet_list *first, *last;

	i = 0;
	first = ls_new();
	last = ls_new();
	first->next = last;
	last->prev = first;
	*/
	int		i;
	tet_list *temp;
	tet_list *head;
	tet_list *div;

	i = 0;
	temp = ls_new();
	head = temp;
	while (i < 3)
	{
		div = temp;
		temp->next = ls_new();
		temp = temp->next;
		temp->prev = div;
		i++;
	}
}