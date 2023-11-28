#include "get_next_line.h"

char *ft_dropline(t_list **buffer, int totalchars)
{
    int len;
    int i;
    char *formline;
    t_list *temp;
    
    formline = malloc(totalchars + 1);
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



int ft_joinlists(t_list **list, char new_char)
{
    t_list *new_node;
    t_list *last_node;

    last_node = ft_lstlast(*list);
    new_node = malloc(sizeof(t_list));
    if(!new_node)
        return 0;
    if(!last_node)
        *list = new_node;
    else
    {
        last_node->next = new_node;
    }
    new_node->c = new_char;
    new_node->next = NULL;
    return(1);
}

int ft_readandropping(t_list **list, int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    int total_characters = 0;  // Adicione esta variável

    bytes_read = 1;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE) > 0))
    {
        int i = 0;
        while (buffer[i] && i < BUFFER_SIZE)
        {
            total_characters += ft_joinlists(list, buffer[i]);
            if(total_characters == 0)
            {
                return 0;
            }
            if (buffer[i] == '\n')
            {   
                return 1;
            }
            printf("%i\n", total_characters);
            i++;
        }
        
    }
    if (bytes_read < 0)
    {
        return 0;
    }
    return(total_characters);
}


char *get_next_line(int fd)
{
    static t_list *buffer;
    char *line;
    int totalchars;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
        return NULL;

    totalchars = ft_readandropping(&buffer, fd);
    if (totalchars > 0)
    {
        line = ft_dropline(&buffer, totalchars);
        free_list(buffer);
    }
    return line;
}

int main(void)
{
    char *line;
    int fd;

    fd = open("arquivo.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
}