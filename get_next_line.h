/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namatias <namatias@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:05:07 by namatias          #+#    #+#             */
/*   Updated: 2025/08/27 16:51:25 by namatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
 
//Para usar o write
# include <unistd.h>
//Para usar funções com alocação de memoria como Malloc, Calloc e Free
# include <stdlib.h>
//Para definir constantes e declarar operações com File Descriptor como Open
# include <fcntl.h>
//Para funções de entrada e saida padrão. Como printf e scanf
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif