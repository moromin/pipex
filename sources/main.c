#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	size_t	i;

	(void)argc;
	(void)argv;
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			printf("%s\n", ft_strchr(envp[i], '/'));
		i++;
	}
	return (0);
}
