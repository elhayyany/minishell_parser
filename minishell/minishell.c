/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hayy <ael-hayy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:50:09 by ael-hayy          #+#    #+#             */
/*   Updated: 2022/06/11 19:39:44 by ael-hayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "executor/minishell.h"

// void	po(t_prior *script)
// {
// 	//int	i = script->numofchilds;
// }

int main(int ac, char **av, char **env)
{
	char     *line;
	t_prior  *script;

	line = 0;
	(void)ac;
	(void)av;
	while (1)
	{
		line = readline("monosholo-1.0$ ");
		if (!line  || line[0] == '\0')
		{
			if (line && line[0] == '\0')
			{
				free(line);
				continue ;
			}
			write(1, "\n", 1);
			continue ;
		}
		if (!all_space(line))
		{
			free(line);
			continue ;
		}
		if (pre_check_line(line))
		{
		   free(line);
		   continue ;
		}
		script = m_shell_parser(line);
		tree_parser(script, env);
		//po(script);
		//free_tree(script);
		free(script);
		free (line);
   }
}