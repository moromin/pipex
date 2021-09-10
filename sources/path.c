#include "../includes/pipex.h"

char	**split_envp(char **envp)
{
	size_t	i;
	size_t	j;
	char	**path;

	i = 0;
	while (envp[i])
	{
		j = 0;
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path = ft_split(ft_strchr(envp[i], '/'), ':');
			while (path[j])
			{
				printf("%s\n", path[j]);
				j++;
			}
			free_split(path);
		}
		i++;
	}
	return (path);
}
