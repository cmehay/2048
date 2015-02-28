/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:04:17 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 14:10:48 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <fcntl.h>


int output(void)
{
	static int fd = -1;

	if (fd > 0)
		return fd;
	fd = open("debug", O_CREAT | O_RDWR);
	return fd;
}
