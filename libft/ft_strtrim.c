/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:14:59 by pilespin          #+#    #+#             */
/*   Updated: 2015/09/13 23:03:32 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	char	*new2;
	int		i;

	if (s == NULL)
		return (NULL);
	new = ft_strdup(s);
	i = 0;
	while (((new[i] == 9) || (new[i] == 10) || (new[i] == 32)))
		new++;
	i = ft_strlen(new) - 1;
	while (((new[i] == 9) || (new[i] == 10) || (new[i] == 32)))
		i--;
	i++;
	new[i] = '\0';
	new2 = ft_strdup(new);
	return (new2);
}
