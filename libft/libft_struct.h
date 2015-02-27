/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/03 15:21:40 by cmehay            #+#    #+#             */
/*   Updated: 2014/05/03 15:23:27 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCT_H
# define LIBFT_STRUCT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_strlen
{
	size_t	s1;
	size_t	s2;
}				t_strlen;

typedef struct	s_alloc_lst
{
	ssize_t				ptr;
	struct s_alloc_lst	*next;
}				t_alloc_lst;

#endif
