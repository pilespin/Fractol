/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:56:39 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/13 23:03:49 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (len <= 0 || (s == NULL) || start > ft_strlen(s))
		return (ft_strdup(""));
	res = malloc((sizeof(char *)) * (len + 1));
	if (res == NULL)
		return (0);
	i = 0;
	while ((size_t)i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
