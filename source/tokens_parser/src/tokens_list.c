/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hastid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 01:20:36 by hastid            #+#    #+#             */
/*   Updated: 2020/02/11 20:56:47 by hastid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens_parser.h"

static t_tok	*init_token(char *tmp, int id)
{
	t_tok	*token;

	if (!(token = (t_tok *)malloc(sizeof(t_tok))))
		return (0);
	token->id = id;
	if (!(token->token = ft_strdup(tmp)))
		return (0);
	token->next = 0;
	return (token);
}

int				save_tokens(t_tok **tok, char *token, int id)
{
	t_tok	*tmp;

	if (!token)
		return (0);
	if (*tok)
	{
		tmp = *tok;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = init_token(token, id)))
			return (1);
	}
	else if (!((*tok) = init_token(token, id)))
		return (1);
	return (0);
}

void			free_toks(t_tok *lst)
{
	t_tok	*tmp;

	while (lst)
	{
		tmp = lst->next;
		if (lst->token)
			ft_memdel((void **)&(lst->token));
		ft_memdel((void **)&lst);
		lst = tmp;
	}
}
