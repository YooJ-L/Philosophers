#include <stdio.h>
#include <stdbool.h>

bool ft_isdigit(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		if ('0' > s[i] || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int main(void)
{
	char *s;
	s = "a12345";

	printf("%d\n", ft_isdigit(s + 2));
	return (0);
}
