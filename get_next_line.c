/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:47 by namatias          #+#    #+#             */
/*   Updated: 2025/08/26 20:07:52 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *read_text;
	ssize_t read_bytes;

//Só retorna fd negativo em casos de erros
	if (fd < 0)
		return (NULL);
//BUFFER_SIZE é uma variável estatica definida no nosso header
	read_text = malloc (sizeof(char) * BUFFER_SIZE);
	if (!read_text)
		return (NULL);
//Read retorna o numero de bytes lidos com sucesso.
//SE = -1, ocorreu algum erro. SE = 0 chegou ao fim do arquivo.
	read_bytes = read(fd, read_text, BUFFER_SIZE);



	printf("%s\n", read_text);
	printf("%d\n", fd);
	printf("%zd\n", read_bytes);
	return (read_text);
}

int main()
{
	int		fd;
	char	*retorno;

	fd = open("teste1.txt", O_RDONLY);
	retorno = get_next_line(fd);
	//printf("%s", retorno);
	// get_next_line(fd);
	// printf("%s", retorno);

	close(fd);
}