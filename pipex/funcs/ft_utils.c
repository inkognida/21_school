/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:33:00 by hardella          #+#    #+#             */
/*   Updated: 2021/12/08 13:11:04 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	ft_bonus_helper(int fd2, char **argv, int argc, char **envp)
{
	pid_t	waitall;

	dup2(fd2, 1);
	waitall = fork();
	if (!waitall)
		ft_execute(argv[argc - 2], envp);
	else
		while (argc-- - 4)
			waitpid(waitall, NULL, 0);
}

void	ft_mainelse(int *fd1, int *fd2, char **argv, int argc)
{
	*fd1 = ft_open(argv[1], 0);
	*fd2 = ft_open(argv[argc - 1], 1);
	if (*fd1 < 0 || *fd2 < 0)
		ft_puterror();
	dup2(*fd1, 0);
}

void	heredoc_helper(int *files)
{
	close(files[1]);
	dup2(files[0], 0);
	wait(NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_findpath(char *cmd, char **envp)
{
	char	**paths;
	char	*single_path;
	char	*used_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0 && envp[i])
		i++;
	if (envp[i] == '\0')
		ft_puterror();
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		used_path = ft_strjoin(paths[i++], "/");
		if (used_path == NULL)
			ft_puterror();
		single_path = ft_strjoin(used_path, cmd);
		if (single_path == NULL)
			ft_putmallocerror(used_path);
		free(used_path);
		if (access(single_path, F_OK) == 0)
			return (single_path);
	}
	return (NULL);
}
