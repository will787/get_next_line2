#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

void free_list(t_list *list)
{
    while (list)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }
}















































// char	*ft_strrchr(const char *s, int c)
// {
// 	const char *last;

// 	last = NULL;
// 	while (*s)
// 	{
// 		if (*s == c)
// 			last = s;
// 		s++;
// 	}

// 	if (c == '\0')
// 		return ((char *)s);

// 	return ((char *)last);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*pt;
// 	int	lenght;
//     int     i;
//     int     j;

// 	lenght = ft_strlen(s1) + ft_strlen(s2);
// 	pt = malloc(sizeof(char) * (lenght + 1));
// 	if (!pt)
// 		return (NULL);
//     i = 0;
//     while (s1[i] != '\0')
//     {
//         pt[i] = s1[i];
//         i++;
//     }
//     j = 0;
//     while (s2[j] != '\0')
//     {
//         pt[i + j] = s2[j];
//         j++;
//     }
//     pt[i + j] = '\0';
// 	return (pt);
// }

// int	ft_strlen(const char *s)
// {	
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }