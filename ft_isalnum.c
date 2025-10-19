#include "libft.h"

// Check if character is alphanumeric
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
