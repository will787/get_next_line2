#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif


typedef struct s_list{
    char c;
    struct s_list *next;
} t_list;


#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char    *get_next_line(int fd);
char *ft_dropline(t_list **buffer);
t_list	*ft_lstlast(t_list *lst);
void ft_readandropping(t_list **buffer, int fd);
void ft_joinlists(t_list **list, char new_char);
void free_list(t_list *list);
#endif
