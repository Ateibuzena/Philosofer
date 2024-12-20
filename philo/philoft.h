/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azubieta <azubieta@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:10:55 by azubieta          #+#    #+#             */
/*   Updated: 2024/12/20 23:22:59 by azubieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOFT_H
# define PHILOFT_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_PHILOS 200

typedef struct s_philo
{
	long int		id;
	pthread_t		thread;
	long int		left_fork;
	long int		right_fork;
	long int		last_meal_time;
	long int		meals_eaten;
	pthread_mutex_t	mutex_philo;
	struct s_env	*env;
}	t_philo;

typedef struct s_env
{
	long int		num_philos;
	pthread_t		thread;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		meals_required;
	long int		start_time;
	long int		simulation_running;
	pthread_mutex_t	simulation_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_env;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

/*philo_init.c*/
int			ft_init_environment(t_env *env, int argc, char **argv);

/*philo_clean.c*/
void		ft_clean_up(t_env *env, int len);

/*philo_threads.c*/
int			ft_create_threads(t_env *env);
int			ft_join_threads(t_env *env);

/*philo_lifestyle.c*/
void		*ft_lifecycle(void *arg);

/*philo_utils.c*/
void		ft_print(char *str, t_env *env, int i);
long int	ft_get_time(void);
void		*ft_monitoring(void *arg);
void		ft_print_philosophers(t_env *env);
void		ft_print_environment(t_env *env);
t_color		ft_generate_color(int i);

/*ft_strtol.c*/
long int	ft_strtol(const char *str, char **endptr, int base);

/*ft_atoi.c*/
int			ft_atoi(const char *str);

int	ft_simulation_lock(t_env *env, int change);

#endif