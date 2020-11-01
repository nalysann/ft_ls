/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_folder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgilwood <bgilwood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:19:57 by bgilwood          #+#    #+#             */
/*   Updated: 2020/10/13 22:27:11 by bgilwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <string.h>

DIR		*open_folder(char *name)
{
	DIR	*dir_stream;

	dir_stream = opendir(name);
	if (dir_stream == NULL)
		; // error
	return dir_stream;
}