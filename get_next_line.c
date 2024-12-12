/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadhira <anadhira@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:00:57 by anadhira          #+#    #+#             */
/*   Updated: 2024/12/05 20:17:27 by anadhira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_convert(t_list *head)
{
	t_list	*temp;
	char	*string;
	int		length;
	int		i;
	int		j;

	temp = head;
	length = ft_lstsize(head);
	if (length <= 0)
		return (ft_lstreset(temp));
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (ft_lstreset(temp));
	head = temp;
	i = 0;
	while (head && i < length)
	{
		j = 0;
		while ((head->buffer)[j])
			string[i++] = (head->buffer)[j++];
		head = head->next;
	}
	string[length] = '\0';
	ft_lstreset(temp);
	return (string);
}

static t_list	*ft_splitnode(t_list *lst, char *line)
{
	t_list	*new_node;
	int		i;

	if (lst == NULL || line == NULL)
		return (NULL);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	i = 0;
	line++;
	while (line[i])
	{
		(new_node->buffer)[i] = line[i];
		if (i == 0)
			line[i] = '\0';
		i++;
	}
	(new_node->buffer)[i] = '\0';
	new_node->next = NULL;
	return (new_node);
}

static int	ft_extend_lst(t_list **lst, t_list **head)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		ft_lstreset(*head);
		return (0);
	}
	new_node->next = NULL;
	if (*lst == NULL)
		*head = new_node;
	else
		(*lst)->next = new_node;
	*lst = new_node;
	return (1);
}

static void	ft_initialize(t_list *lst, t_list **head, char **line, int *bytes)
{
	*head = NULL;
	*line = NULL;
	*bytes = 1;
	if (lst != NULL)
	{
		*head = lst;
		*line = ft_strchr(lst->buffer, '\n');
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*head;
	char			*line;
	int				bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	ft_initialize(lst, &head, &line, &bytes);
	while (line == NULL && bytes > 0)
	{
		if (ft_extend_lst(&lst, &head) == 0)
			return (NULL);
		bytes = read(fd, lst->buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			lst = NULL;
			return (ft_lstreset(head));
		}
		(lst->buffer)[bytes] = '\0';
		line = ft_strchr(lst->buffer, '\n');
	}
	lst = ft_splitnode(lst, line);
	return (ft_convert(head));
}
