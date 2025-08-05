#include "push_swap.h"
#include <limits.h>

static int max_digits(t_node *head)
{
    int max_val = head->val;
    for (t_node *cur = head; cur; cur = cur->next)
        if (cur->val > max_val)
            max_val = cur->val;

    int digits = 0;
    do {
        max_val /= 10;
        digits++;
    } while (max_val);
    return digits;
}

static void return_a(t_node **a, t_node **b)
{
    while (*b)
    {
        pa(a, b);
    }
    return ;
}

void	radix_sort(t_node **stac_a, t_node **stac_b, int list_size)
{
    int dig;
    int digs;
    int count;

    dig = 1;
    digs = max_digits(*stac_a);
    count = 0;
	if (!(*stac_a && (*stac_a)->next))
		return ;
	while (dig <= digs)
	{
        if (count % 2 == 0)
            a_to_b(stac_a, stac_b, dig, list_size);
        else
            b_to_a(stac_a, stac_b, dig, list_size);
        dig++;
        count++;
	}
    if (stac_b)
        return_a(stac_a, stac_b);
}


// void	put_node(t_node *head)
// {
// 	while (head)
// 	{
// 		printf("val: %d index: %d\n", head->val, head->index);
// 		head = head->next;
// 	}
// 	printf("\n");
// 	return ;
// }

// /******************************************************* */

// int	main(int argc, char **argv)
// {
// 	t_node	*stac_a;
// 	t_node	*stac_b;
//     t_node  *head;
//     int size;

// 	stac_a = NULL;
// 	if (argc > 2)
// 	{
// 		stac_a = make_list(argc - 1, argv);
// 		stac_b = NULL;
//         head = stac_a;
//         size = index_list(&stac_a);
// 		printf("index_test:\n");
// 		put_node(head);
//         if (size <= 1)
//             return (0);
//         printf("chack: %d\n", a_to_b(&stac_a, &stac_b, 1));
//         printf("%d\n", b_to_a(&stac_a, &stac_b, 1));

//         // radix_sort(&stac_a, &stac_b);
// 		put_node(stac_a);
// 	}

// 	return (0);
// }


// ccw index_list.c make_list.c my_atoi.c ope_push.c ope_rev.c ope_rotate.c ope_swap.c radix_sort.c

