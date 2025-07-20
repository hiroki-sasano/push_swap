#include "push_swap.h"
#include <unistd.h>

static void push_swap(t_node **stac_a, t_node **stac_b, int list_size)
{
    if (list_size <= 10)
        small_sort(stac_a, stac_b, list_size);
    // else if (list_size <= 500)
    //     bucket_sort(&stac_a, &stac_b);
    // else if (list_size > 500)
    //     heap_sort(&stac_a, &stac_b);

    return ;
}

int	main(int argc, char **argv)
{
	t_node	*stac_a;
	t_node	*stac_b;
    int size;

	if (!(argc < 3))
	{
		stac_a = make_list(argc - 1, argv);
		stac_b = NULL;
        size = index_list(&stac_a);
        if (size <= 1)
            return (0);
        push_swap(&stac_a, &stac_b, size);
        // printf("before a:\n");
		// put_node(stac_a);
		// printf("before b:\n");
		// put_node(stac_b);

		// printf("after a:\n");
		// put_node(stac_a);
		// printf("after b:\n");
		// put_node(stac_b);
	}
	return (0);
}

// ccw main.c small_sort.c index_list.c make_list.c my_atoi.c ope_push.c ope_rev.c ope_rotate.c ope_swap.c

