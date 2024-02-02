/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:49:03 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/03 01:00:38 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_chr2d(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**dstr_realloc2d(char **ptr, size_t nmemb)
{
	char	**self;
	size_t	i;

	i = 0;
	self = ft_calloc(nmemb, sizeof(*self));
	if (!self)
	{
		free_chr2d(ptr);
		wexit(ERR"Couldn't load map...", EXIT_FAILURE);
		return (NULL);
	}
	while (ptr[i++])
		self[i - 1] = ptr[i - 1];
	free_chr2d(ptr);
	return (self);
}
