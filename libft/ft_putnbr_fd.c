/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sum <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:14:17 by sum               #+#    #+#             */
/*   Updated: 2022/10/06 19:14:53 by sum              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nb;

	nb = ft_itoa(n);
	ft_putstr_fd(nb, fd);
}

/*int main ()
{
	int a = -2147483648;
	ft_putnbr_fd(a, 1);
}*/
