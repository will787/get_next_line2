#include "get_next_line.h"


char *ft_newline(t_list buffer, int fd)
{
    int char_read;
    char *cutline;
    char *linefull;

    char_read = 0;
    linefull = NULL;
    while (!ft_strrchr(cutline, '\n'))
    {
        cutline = malloc(BUFFER_SIZE + 1);
        if(!cutline)
            return NULL;
        
        char_read = read(fd, cutline, BUFFER_SIZE);
        if(char_read <= 0)
            free(cutline);
            return NULL;
        cutline[char_read] = '\0';
        linefull = ft_strjoin(linefull, cutline);
    }
    return(linefull);
}


char *get_next_line(int fd)
{   
    static s_list buffer;
    char *line;
    line = NULL;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
        return (NULL);
    line = ft_newline(buffer, fd); 
    return (line);
}

// int main(void)
// {
//     char *line;
//     int fd;

//     fd = open("arquivo.txt", O_RDONLY);
//     line = get_next_line(fd);
//     free(line);
//     printf("%s\n", line);
// }