/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:04:56 by hardella          #+#    #+#             */
/*   Updated: 2021/12/08 13:58:03 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	ft_open(char *filename, int flag)
{
	if (flag == 0)
	{
		if (access(filename, F_OK))
			ft_puterror();
		return (open(filename, O_RDONLY, 0777));
	}
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, 0777));
}

void	ft_execute(char *cmd1, char **envp)
{
	char	**cmds;

	cmds = ft_split(cmd1, ' ');
	if (!(envp))
		ft_puterror();
	if (execve(ft_findpath(cmds[0], envp), cmds, envp) == -1)
		ft_puterror();
}

static void	ft_child(char **argv, char **envp, int *files)
{
	int		fd1;

	fd1 = ft_open(argv[1], 0);
	if (fd1 < 0)
		ft_puterror();
	dup2(files[1], 1);
	dup2(fd1, 0);
	close(files[0]);
	ft_execute(argv[2], envp);
}

static void	ft_parent(char **argv, char **envp, int *files)
{
	int		fd2;

	fd2 = ft_open(argv[4], 1);
	if (fd2 < 0)
		ft_puterror();
	dup2(files[0], 0);
	dup2(fd2, 1);
	close(files[1]);
	ft_execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		files[2];
	pid_t	parent;

	if (argc != 5)
		return (write(2, "Wrong args\n", ft_strlen("Wrong args\n")));
	else
	{
		if (pipe(files) == -1)
			ft_puterror();
		parent = fork();
		if (parent == -1)
			ft_puterror();
		if (parent == 0)
			ft_child(argv, envp, files);
		else
		{
			ft_parent(argv, envp, files);
			waitpid(parent, NULL, 0);
			close(files[0]);
			close(files[1]);
		}
	}
	return (0);
}
