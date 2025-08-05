#include "push_swap.h"

static int fount_position(t_node *stac, int max)
{
    int pos;

    pos = 0;
    while (stac)
    {
        if (stac->index == max)
            break;
        stac = stac->next;
        pos++;
    }
    return (pos);
}

static int	found_max(t_node *b)
{
	int	max;
	int	num;

	max = 0;
	while (b)
	{
		num = b->index;
		if (max < num)
			max = num;
		b = b->next;
	}
	return (max);
}

void b_to_a(t_node **stac_a, t_node **stac_b)
{
    int max;
    int size;
    int max_posi;

    while (*stac_b)
    {
        size = list_count(*stac_b);
        max = found_max(*stac_b);
        max_posi = fount_position(*stac_b, max);
        if (max_posi <= size / 2)
            while ((*stac_b)->index != max)
                rb(stac_b);
        else
            while((*stac_b)->index != max)
                rrb(stac_b);
        pa(stac_a, stac_b);
    }
}