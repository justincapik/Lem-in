/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klebon <klebon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:52:47 by klebon            #+#    #+#             */
/*   Updated: 2019/03/06 15:34:50 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 100

typedef struct	s_buffer
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	struct s_buffer	*next;
}				t_buffer;

int				get_next_line(const int fd, char **line);

#endif
