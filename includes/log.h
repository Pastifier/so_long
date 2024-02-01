/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:58:45 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/01 04:27:41 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <unistd.h>
# include <string.h>

# ifndef RED
#  define RED "\x1b[31m"
# endif // !RED

# ifndef GREEN
#  define GREEN "\x1b[32m"
# endif // !GREEN

# ifndef DFLT
#  define DFLT "\x1b[0m"
# endif // !DFLT

# ifndef INVALID_EXTENSION
#  define INVALID_EXTENSION "Only accepting:\n[*.ber]"
# endif // !INVALID_EXTENSION

# define ERR "Error!\n"

#endif // !LOG_H