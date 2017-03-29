#include "Includes/filler.h"

int	main()
{
	ft_printf("[Test 1: %s, Test 2: %c]\n[Test 3: %u, Test 4: %d[ABC]", "abc", 'c', 12, -1);
	ft_dprintf(2, "abc", "abc", 'c', 12, -1);
	ft_printf("");
	ft_printf("%s", 0);
	ft_printf("%d", 0 );
	return(0);
}
