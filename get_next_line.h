#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif


typedef struct s_list{
    char c;
    struct s_list next;
} t_list;


#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char    *get_next_line(int fd);
char	*ft_strrchr(const char *s, int c); // função que irá achar o '\n' QUEBRA DE LINHA SEARCHING
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *s);
char *ft_newline(t_list buffer, int fd);
#endif
