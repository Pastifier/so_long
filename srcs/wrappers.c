/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:22:29 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/28 22:42:32 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include "libft.h"

void	wexit(const char *errmsg, int exit_code)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd((char *)errmsg, STDERR_FILENO);
	ft_putendl_fd(DFLT, STDERR_FILENO);
	exit(exit_code);
}