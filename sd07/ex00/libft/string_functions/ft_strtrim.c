/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:15 by lemarino          #+#    #+#             */
/*   Updated: 2025/06/23 19:25:53 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	unsigned int	i;
	unsigned int	len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	if (i >= len)
		return ((char *)ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[len]))
		len--;
	len = len - i + 1;
	return (ft_substr(s1, i, len));
}
