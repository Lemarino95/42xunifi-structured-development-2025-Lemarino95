/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:44:33 by lemarino          #+#    #+#             */
/*   Updated: 2025/06/23 19:25:53 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Sets the first 'n' bytes of the memory area pointed to by
 * 's' to zero.
 *
 * This function writes zero bytes to the memory area to clear it.
 *
 * @param s Pointer to the memory area to be zeroed.
 * @param n Number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*int main()
{
	char	buffer[10];
	int	i = 0;
	ft_bzero(buffer, 6);
	while(i < 6)
	{
		printf("%d", buffer[i]);
		i++;
	}
}*/
