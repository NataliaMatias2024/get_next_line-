/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:47 by namatias          #+#    #+#             */
/*   Updated: 2025/08/27 18:26:03 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *text;
	ssize_t 	read_bytes;
	char		*text_remainder;
	char		*line;

//text_reminder vai ser responsavel por guardar todo o "resto" do texto após
//retornar 1 linha. Iniciamos ela com NULL, assim se nao receber nada retorna NULL 
	text_remainder = NULL;
	
//Em casos de erro o fd retorna negativo, por isso devemos validar
	if (fd < 0)
		return (NULL);

//BUFFER_SIZE é uma variável estatica definida no nosso header
//O malloc só deve ser feito quando o text ainda estiver vazio, ou seja, apenas na primeira chamada
	if (!text)
		text = malloc (sizeof(char) * BUFFER_SIZE);
	if (!text)
		return (NULL);

//Read retorna o numero de bytes lidos com sucesso.
//SE = -1, ocorreu algum erro. SE = 0 chegou ao fim do arquivo.
	read_bytes = read(fd, text, BUFFER_SIZE);
	//printf("Read_bytes antes do if = %zd\n", read_bytes);
	if (read_bytes > 0)
	{
		read_bytes = 0;
		line = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		while (text[read_bytes] != '\n' && text[read_bytes] != '\0')
		{
			line[read_bytes] = text[read_bytes];
			read_bytes++;
		}
		line[read_bytes] = '\n';
		line[read_bytes + 1] = '\0';


		text_remainder = ft_substr(text, (read_bytes + 1), (ft_strlen(text) - (read_bytes + 1)));
		text = text_remainder;
		return (line);
	}
	return (text_remainder);
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
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);
	retorno = get_next_line(fd);
	printf("%s", retorno);

//daqui pra frente tem que devolver NULL
	retorno = get_next_line(fd);
	printf("%s", retorno);

	close(fd);
}