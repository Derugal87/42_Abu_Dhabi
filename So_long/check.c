/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 01:25:09 by aderugo           #+#    #+#             */
/*   Updated: 2022/07/17 23:35:26 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	temp_check_1(char *temp, int fd, t_game *game)
{
	if (!temp || temp[0] != '1')
	{
		free(game);
		close(fd);
		perror("First_element_should_be_WALL or Map_is_not_valid\n");
		exit (1);
	}
}

void	temp_check_2(char *temp, int fd, char *str, t_game *game)
{
	if (temp != NULL && temp[0] != '1')
	{
		free_1(game, str, temp);
		close(fd);
		perror("First_element_should_be_WALL or Map_is_not_valid\n");
		exit (1);
	}
}

void	check_map(t_game *game)
{
	check_map_structure(game);
	check_borders(game);
	check_components(game);
	count_components(game);
}

void	check_file(char *file, t_game *game)
{
	int i;

	i = ft_strlen(file) - 4;
	if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r')
	{
		if (parsing(file, game) == -1)
			parsing_error(game);
		check_map(game);
	}
	else
		file_error(game);	
}