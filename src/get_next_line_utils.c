/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:24:15 by hganet            #+#    #+#             */
/*   Updated: 2025/01/07 15:33:42 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

int	print_line(char *line)
{
	if (!line)
		return (0);
	return (printf("%s", line));
}