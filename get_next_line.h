/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:52:01 by dgurova           #+#    #+#             */
/*   Updated: 2017/10/26 13:50:30 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define FD_MAX 8192

# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

int	get_next_line(int fd, char **line);

#endif
