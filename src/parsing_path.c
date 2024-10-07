/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:31:38 by ctechy            #+#    #+#             */
/*   Updated: 2022/10/11 15:31:40 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

char	**env_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		error_msg("malloc failed path");
	return (paths);
}

char	*look_for_path(char **envp, char *cmd_shell)
{
	char	**paths;
	char	*tmp;
	char	*final_path;
	int		i;

	paths = env_path(envp);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		final_path = ft_strjoin(tmp, cmd_shell);
		free(tmp);
		if (access(final_path, F_OK) == 0)
		{
			free_tab(paths);
			return (final_path);
		}
		free(final_path);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

void	make_exec(char *argv, char **envp)
{
	char	**cmd_tab;
	char	*final_path;

	cmd_tab = ft_split(argv, ' ');
	if (!cmd_tab)
		error_msg("Malloc failed cmd");
	final_path = look_for_path(envp, cmd_tab[0]);
	if (!final_path)
	{
		free_tab(cmd_tab);
		error_msg("Command not found");
	}
	if (execve(final_path, cmd_tab, envp) == -1)
		error_msg("Error");
}
