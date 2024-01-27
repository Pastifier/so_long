/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:26:09 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/26 23:26:09 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

int main(void)
{
    void *mlx_ptr = mlx_init();
    void *mlx_win = mlx_new_window(mlx_ptr, 600, 600, "Hello, world!");
    mlx_loop(mlx_ptr);
    (void)mlx_win;
    return (0);
}