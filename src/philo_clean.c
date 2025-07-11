/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:02:32 by azubieta          #+#    #+#             */
/*   Updated: 2025/07/06 11:44:54 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philoft.h"

void	ft_clean_up(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->num_philos)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&env->simulation_lock);
	if (env->forks)
		free(env->forks);
	if (env->philos)
		free(env->philos);
	if (env)
		free(env);
}
