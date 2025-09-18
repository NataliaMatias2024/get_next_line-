/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:35:47 by namatias          #+#    #+#             */
/*   Updated: 2025/09/07 14:19:39 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_text(int fd, char *text, char **saving)
{
	char		*helper;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		//caso 1: Erro ao ler arquivo, returna NULL
		if (bytes_read < 0)
			return (NULL);
		//caso 2: Chegamos ao final do arquivo, n há nada novo a ser copiado.
		//retornamos oq temos salvo ate agora. 
		if (bytes_read == 0)
			return (*saving);
		//caso 3: td ok e parte do texto foi copiada para o ponteiro text
		//colocamos um terminador NULL na ultima posição copiada, 
		//Assim ela é interpretada como sendo uma string
		text[bytes_read] = '\0';
		//Salvamos oq ja esta contindo na nossa variavel estatica em uma 
		//variavel ajudante (raciocinio do swap da piscina)
		helper = *saving;
		//Agora nossa variável estatica irá assumir o valor da junção 
		//Oq foi lido agora e salvo em text + oq ja estava salvo (helper)
		*saving = ft_strjoin(helper, text);
		//Após a junção precisamos liberar helper para a proxima leitura
		free(helper);
		//As leituras devem continuar até encontrarmos uma quebra de linha, 
		//ao encontrar \n o new_line dessa chamada se encerra
		//retorna TUDO que foi copiado, incluindo os bytes após o \n
		if (ft_strchr(*saving, '\n'))
			return (*saving);
	}
	return (*saving);
}

char	*extract_line(char *new_line)
{
	int		i;
	char	*helper;

	if (!new_line)
		return (NULL);
	i = 0;
// Conta quantos caracteres até o \n ou ate o \0
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
// inclui o \n na linha
	if (new_line[i] == '\n')
		i++;
	if (new_line[i] == '\0')
		helper = ft_strdup(new_line);
	else
//faz uma cópia até o \n inclusive (caso ele exista) e NAO seja ultima linha
		helper = ft_substr(new_line, 0, i);
	return (helper);
}

char	*extract_rest(char *new_line)
{
	int		i;
	int		j;
	char	*helper;

	i = 0;
	helper = NULL;
	// Conta quantos caracteres até o \n ou ate o \0
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	// Verifica se o ultimo caracter foi o \n
	//SE existir formará uma substring ate seu aparecimento
	if (new_line[i] == '\n' && new_line[i + 1] != '\0')
	{
		j = ft_strlen(new_line);
		helper = ft_substr(new_line, i + 1, j - (i+1));
	}
	return (helper);
}

char	*get_next_line(int fd)
{
	char		*text;
	char		*new_line;
	char		*line;
	static char	*saving;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(saving);
    	saving = NULL;
		return (NULL);
	}
	text = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!text)
		return (NULL);
	new_line = read_text(fd, text, &saving);
	free (text);
	if (!new_line)
	{
		free(saving);
    	saving = NULL;
		return (NULL);
	}
		
	line = extract_line(new_line);
	saving = extract_rest(new_line);
	
	if (new_line != NULL && new_line != saving)
    	free(new_line);

	return (line);
}

//#include <fcntl.h>
//#include <stdio.h>
//int	main()
//{
//	int	fd;
//	char *retorno;
//	fd = open("teste2.txt", O_RDONLY);
//	while ((retorno = get_next_line(fd)))
//	{
//		printf("%s", retorno);
//		free (retorno);
//	}
//	retorno = get_next_line(fd);
//	printf("%s", retorno);
//	free (retorno);
//	close (fd);
//}
