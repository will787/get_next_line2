#include "get_next_line.h"

char *ft_dropline(t_list **buffer)
{
    int len;
    int i;
    char *formline;
    t_list *temp;
    
    len = 0;
    temp = (*buffer);
    while (temp)
    {
        len++;
        temp = temp -> next;
    }
    formline = malloc(len + 1);
    if(!formline)
        return (NULL);
    i = 0;
    while (*buffer)
    {
        //printf("%c\n", (*buffer)->c);
        formline[i] = (*buffer)->c;
        i++;
        temp = *buffer;
        *buffer = (*buffer)->next;
        free(temp);
    }
    formline[i] = '\0';
    return(formline);
}



void ft_joinlists(t_list **list, char new_char)
{
    t_list *new_node;
    t_list *last_node;

    last_node = ft_lstlast(*list);
    new_node = malloc(sizeof(t_list));
    if(!new_node)
        return ;
    if(!last_node)
        *list = new_node;
    else
    {
        last_node->next = new_node;
    }
    new_node->c = new_char;
    new_node->next = NULL;
}

void ft_readandropping(t_list **list, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    int i;

    bytes_read = 1;
    while (bytes_read > 0)
    {   
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read < 0)
        {
            return ;
        }
        i = 1;
        while (buffer[i] && i <= BUFFER_SIZE)
        {
            ft_joinlists(list, buffer[i]);
            if(buffer[i] == '\n')
            {
                printf("Ele encontrou o barra aqui: %i\n", i);
                return ;
            }
            printf("%i\n", i);
            i++;
        }
    }
}

char *get_next_line(int fd)
{   
    static t_list *buffer;
    char *line;
    line = NULL;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
        return (NULL);
    ft_readandropping(&buffer, fd);
    line = ft_dropline(&buffer);
    return (line);
}

int main(void)
{
    char *line;
    int fd;

    fd = open("arquivo.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
}
