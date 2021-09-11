#include "../includes/pipex.h"

static void	child(char **cmd, int *pipefd)
{
	char	*line;
	int		fd;

	fd = open("outfile", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(pipefd[1]);
	while (1)
	{
		line = get_next_line(pipefd[0]);
		if (line == NULL)
			break ;
		printf("%s", line);
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	close(pipefd[0]);
	printf("Child pid: %d.\n", getpid());
	execve("/bin/echo", cmd, NULL);
}

static void	parent(pid_t pid_child, int *pipefd)
{
	pid_t	result;
	int		status;
	char	*line;
	int		fd;

	close(pipefd[0]);
	fd = open("infile", O_RDONLY);
	if (fd < 0)
		perror("open()");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd);
	close(pipefd[1]);
	result = wait(&status);
	if (result < 0)
	{
		perror("wait()");
		exit(EXIT_FAILURE);
	}
	printf("Parent. parent's pid: %d. child's pid: %d\n", getpid(), pid_child);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd;
	pid_t	pid;
	int		pipefd[2];

	(void)argc;
	(void)envp;
	if (pipe(pipefd) == -1)
		perror("pipe()");
	pid = fork();
	if (pid == -1)
		perror("fork()");
	if (pid == 0)
	{
		cmd = ft_split(argv[1], ' ');
		child(cmd, pipefd);
		free_split(cmd);
	}
	else
		parent(pid, pipefd);
	return (0);
}
