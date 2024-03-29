/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:45:41 by echrysta          #+#    #+#             */
/*   Updated: 2022/04/21 14:45:44 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_ph
{
	int					nbr_id;
	int					count_eat;
	long				last_time_eat;
	pthread_mutex_t		*left_fork_m;
	pthread_mutex_t		*right_fork_m;
	pthread_t			philo_id_pth;
	struct s_data_ph	*data;
}	t_ph;

typedef struct s_data_ph
{
	int						ph_nbr;
	unsigned long long		time_to_die;
	unsigned long long		time_to_eat;
	unsigned long long		time_to_sleep;
	int						eat_count_p;
	int						dead_or_nbr;
	unsigned long long		start_prog;
	t_ph					*all_ph;
	pthread_mutex_t			*all_forks_m;
	pthread_mutex_t			print;
	pthread_mutex_t			food_record;
	pthread_mutex_t			dead_or_nbr_m;
	pthread_mutex_t			count_eat_m;
}	t_data_ph;

int					check_input(char **argv);
int					init_data(t_data_ph *data, int argc, char **argv);
int					ft_atoi(const char *str);
unsigned long long	get_time(void);
int					init_mutex(t_data_ph *data);
void				ph_init(t_data_ph *data);
void				print_ph(t_data_ph *data, int nbr, char *str);
void				check(t_data_ph *data);
int					start_prog(t_data_ph *data);
void				my_usleep(unsigned long long time_now);
void				m_destr_ph(t_data_ph *data);

#endif
