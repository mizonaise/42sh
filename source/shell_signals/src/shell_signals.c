/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 05:32:23 by hastid            #+#    #+#             */
/*   Updated: 2020/02/07 05:43:17 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_signals.h"

/*static void child_seg(int seg)
{
	(void)seg;
	update_status();
}*/

static void	kill_seg(int seg)
{
	t_cmd	*l;
	char	buf[1];

	(void)seg;
	l = NULL;
	l = keep_l(l, 1);
	if (l != NULL)
	{
		l->res = 0;
		l->ctl_c = 1;
		buf[0] = 0;
		ioctl(0, TIOCSTI, buf);
	}
	else
		ft_putchar('\n');
}

void    signals(int c)
{   
    if (c)
    {
		//signal (SIGCHLD, child_seg);
        signal(SIGINT, kill_seg);
        signal (SIGQUIT, SIG_IGN);
        signal (SIGTSTP, SIG_IGN);
        signal (SIGTTIN, SIG_IGN);
        signal (SIGTTOU, SIG_IGN);
        return ;
    }
    signal (SIGINT, SIG_DFL);
    signal (SIGQUIT, SIG_DFL);
    signal (SIGTSTP, SIG_DFL);
    signal (SIGTTIN, SIG_DFL);
    signal (SIGTTOU, SIG_DFL);
	 //signal (SIGCHLD, SIG_DFL);//
}
