/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:04:17 by cmehay            #+#    #+#             */
/*   Updated: 2015/02/28 19:30:45 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <fcntl.h>


int output(void)
{
	static int fd = -1;

	if (fd > 0)
		return fd;
	fd = open("debug.txt", O_RDWR|O_CREAT, 0666);
	return fd;
}
