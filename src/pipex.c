/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:32:37 by ctechy            #+#    #+#             */
/*   Updated: 2022/10/11 15:32:39 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	*error_msg(char *errormsg)
{
	perror(errormsg);
	exit(EXIT_FAILURE);
}

void	parent_process(char **argv, char **envp, int *end, int outfile)
{
	if (dup2(end[0], STDIN_FILENO) == -1)
		error_msg("Error : dup2 failed parent.\n");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		error_msg("Error : dup2 failed parent.\n");
	close(end[1]);
	make_exec(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *end, int infile)
{
	if (dup2(end[1], STDOUT_FILENO) == -1)
		error_msg("Error : dup2 failed parent.\n");
	if (dup2(infile, STDIN_FILENO) == -1)
		error_msg("Error : dup2 failed parent.\n");
	close(end[0]);
	make_exec(argv[2], envp);
}

void	pipex(int infile, int outfile, char **argv, char **envp)
{
	int		end[2];
	pid_t	pid;

	if (pipe(end) == -1)
		error_msg("Error : pipe failed.\n");
	pid = fork();
	if (pid == -1)
		error_msg("Error : forks failed.\n");
	if (pid == 0)
		child_process(argv, envp, end, infile);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, end, outfile);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc != 5)
		error_msg("Error : Invalid number of arguments. must be 5.\n");
	infile = open(argv[1], O_RDONLY, 0777);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (infile == -1 || outfile == -1)
		error_msg("file failed.\n");
	if (argc == 5)
		pipex(infile, outfile, argv, envp);
	return (0);
}
