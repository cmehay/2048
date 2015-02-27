/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:49:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/05/03 15:16:53 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1_cp;
	const char	*s2_cp;
	size_t		i;

	s1_cp = (char*)s1;
	s2_cp = (char*)s2;
	i = 0;
	while (i < n)
	{
		s1_cp[i] = s2_cp[i];
		i++;
	}
	return (s1);
}
