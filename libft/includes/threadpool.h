/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:26:14 by pholster       #+#    #+#                */
/*   Updated: 2019/05/02 12:27:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADPOOL_H
# define FT_THREADPOOL_H
# include "libft.h"
# include <pthread.h>
# include <stdatomic.h>

# define STATE_IDLE		0
# define STATE_ACTIVE	1
# define STATE_LOCKED	2

typedef struct	s_task
{
	void			(*fnc)();
	char			param_count;
	void			*params[5];
	struct s_task	*next;
}				t_task;

typedef struct	s_thread
{
	pthread_t		thread;
	struct s_pool	*pool;
	char			state;
}				t_thread;

typedef struct	s_pool
{
	t_thread		**threads;
	t_task			*que;
	t_task			*last;
	atomic_char		state;
	char			terminating;
	char			suspended;
	char			size;
}				t_pool;

int				ft_pooldone(t_pool *pool);
int				ft_poolque(t_pool *pool, void (*f)(), int count, ...);
int				ft_taskrunfnc(t_task *task);
int				ft_threadcreate(pthread_t *thread, void (*f)(), int count, ...);
t_pool			*ft_poolcreate(int size);
void			*ft_threadmanager(void *param);
void			ft_pooldelete(t_pool **pool);
void			ft_pooljoin(t_pool *pool);
t_task			*ft_tasksetinfo(t_task *task, void (*f)(), int count,
					va_list params);

#endif
