/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:22:29 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/03 02:47:43 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wexit(const char *msg, int exit_code)
{
	int	fd;

	fd = STDOUT_FILENO;
	if (exit_code != 0)
	{
		fd = STDERR_FILENO;
		ft_putstr_fd(RED, fd);
	}
	else
		ft_putstr_fd(GREEN, fd);
	ft_putstr_fd((char *)msg, fd);
	ft_putendl_fd(DFLT, fd);
	exit(exit_code);
}
