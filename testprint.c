#include "includes/filler.h"

int	main()
{
sleep(5);
char *s;

s = ft_strdup("ABC");


ft_printf("TEST PRINTF [%d %d %d] \n [%s %s %s] \n [%u %u %u]", -1111, -2222, -3333, s, "def", "ghi", 1111, 2222, 3333);
sleep(5);
}	
