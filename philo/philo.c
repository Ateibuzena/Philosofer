/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:02:55 by azubieta          #+#    #+#             */
/*   Updated: 2024/12/20 22:15:16 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philoft.h"

static int	ft_check_args(int argc, char **argv)
{
	int			i;
	long int	arg;
	char		*endptr;

	if (argc < 5 || argc > 6)
		return (printf("Error: Incorrect number of arguments.\n"));
	i = 0;
	while (++i < argc)
	{
		arg = ft_strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || arg <= 0 || arg > INT_MAX)
			return (printf("Error: %s is not a valid argument.\n", argv[i]));
		if (i == 1)
			if (arg > MAX_PHILOS)
				return (printf("Error: Cant create more than 200 threads\n"));
		if ((i != 1) && (i != argc - 1))
			if (arg < 60)
					return (printf("Error: Time must be more than 60 ms\n"));
	}
	if (argc == 6)
	{
		arg = ft_strtol(argv[5], &endptr, 10);
		if (*endptr != '\0' || arg <= 0 || arg > INT_MAX)
			return (printf("Error: %s is not a valid argument.\n", argv[5]));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	int		len;

	env = malloc(sizeof(t_env));
	if (!env)
		return (printf("Error: Creating environment\n"), 1);
	if (ft_check_args(argc, argv))
		return (free(env), 1);
	if (ft_init_environment(env, argc, argv))
		return (ft_clean_up(env, env->num_philos), 1);
	len = ft_create_threads(env);
	if (len)
		return (ft_clean_up(env, len), 1);
	ft_clean_up(env, env->num_philos);
	return (0);
}
