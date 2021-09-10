#include "../includes/pipex.h"

static void	child(char **cmd)
{
	printf("Child pid: %d.\n", getpid());
	execve("/bin/echo", cmd, NULL);
}

static void	parent(pid_t pid_child)
{
	pid_t	result;
	int		status;

	result = wait(&status);
	printf("Parent. parent's pid: %d. child's pid: %d\n", getpid(), pid_child);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd;
	pid_t	pid;

	(void)argc;
	(void)argv;
	(void)envp;
	pid = fork();
	if (pid == -1)
		perror("fork()");
	if (pid == 0)
	{
		cmd = ft_split(argv[1], ' ');
		child(cmd);
		free_split(cmd);
	}
	else
		parent(pid);
	return (0);
}
