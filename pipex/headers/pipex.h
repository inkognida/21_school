/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hardella <hardella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:04:44 by hardella          #+#    #+#             */
/*   Updated: 2021/12/08 13:16:15 by hardella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

void		*ft_memcpy(void *dst, void *src, int n);
int			ft_strlcpy(char *dst, char *src, int dstsize);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);

char		*get_next_line(int fd);

char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strnstr(char *haystack, char *needle, int len);
int			ft_strncmp(char *s1, char *s2, int n);

char		*ft_findpath(char *cmd, char **envp);
void		heredoc_helper(int *files);
void		ft_bonus_helper(int fd2, char **argv, int argc, char **envp);
void		ft_mainelse(int *fd1, int *fd2, char **argv, int argc);

void		ft_bonuserror(void);
void		ft_putmallocerror(char *str);
void		ft_puterror(void);

int			ft_strlen(const char *s);
void		ft_execute(char *cmd1, char **envp);

int			ft_open(char *filename, int flag);

void		ft_heredoc(char *limiter);
void		ft_chpar(char *cmd, char **envp);

#endif