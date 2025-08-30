/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:47 by namatias          #+#    #+#             */
/*   Updated: 2025/08/30 13:28:16 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	
}

int main()
{
	int		fd;
	char	*retorno;

	fd = open("teste1.txt", O_RDONLY);

	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);
// //daqui pra frente tem que devolver NULL
// 	retorno = get_next_line(fd);
// 	printf("%s", retorno);

	close(fd);
}