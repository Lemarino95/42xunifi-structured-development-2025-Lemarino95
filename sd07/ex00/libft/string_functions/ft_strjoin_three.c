/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:08:32 by lemarino          #+#    #+#             */
/*   Updated: 2025/06/23 19:25:53 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

/**
 * @brief Concatenates three strings into a newly allocated string.
 *
 * Joins the strings 's1', 's2', and 's3' in sequence,
 * allocating memory for the combined result.
 * The intermediate allocation is freed before returning.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param s3 The third string.
 * @return char* Pointer to the newly allocated concatenated string,
 *               or NULL if memory allocation fails.
 */
char	*ft_strjoin_three(const char *s1, const char *s2, const char *s3)
{
	char	*joined;
	char	*rejoined;

	joined = ft_strjoin(s1, s2);
	rejoined = ft_strjoin(joined, s3);
	free(joined);
	return (rejoined);
}
