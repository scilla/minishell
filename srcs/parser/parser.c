#include "../../includes/minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**append_to_arr(const char *str, int *len, char **arr)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (*len + 1));
	i = 0;
	while (i < *len)
	{
		tmp[i] = arr[i];
		i++;
	}
	// remove system strdup
	tmp[i] = ft_strdup(str);
	free(arr);
	(*len)++;
	return (tmp);
}

char	*app_char(const char *cmd, int *i, char *buff)
{
	char	*cc;
	char	*tmp;

	cc = malloc(sizeof(char) * 2);
	cc[0] = *(cmd + *i);
	cc[1] = 0;
	tmp = ft_strjoin(buff, cc);
	free(cc);
	free(buff);
	(*i)++;
	return (tmp);
}

char	*escape_slash(const char *src, int *i, char *dst)
{
	char	c;
	int		k;

	k = 0;
	c = *(src + *i + 1);
	if (c == '\\' || c == '"' || c == '\'' || c == '?')
	{
		dst = app_char(&c, &k, dst);
		(*i)++;
		(*i)++;
	}
	else
	{
		dst = app_char(src, i, dst);
	}
	return (dst);
}

char	*elab_dollar(const char *src, int *i, char *dst)
{
	char	c;
	char	*var_name;
	char	*var_value;
	char	*tmp;

	var_name = malloc(sizeof(char));
	var_name[0] = 0;
	c = *(src + *i + 1);
	if (c == '?')
	{
		(*i)++;
		var_value = ft_itoa(errno);
		if (var_value)
		{
			tmp = ft_strjoin(dst, var_value);
			free(dst);
			dst = tmp;
		}
		free(var_name);
		(*i)++;
		return (dst);
	}
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'))
	{
		dst = app_char(src, i, dst);
	}
	else
	{
		(*i)++;
		c = *(src + *i);
		while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9') || c == '_')
		{
			var_name = app_char(src, i, var_name);
			c = *(src + *i);
		}
		var_value = getenv(var_name);
		if (var_value)
		{
			tmp = ft_strjoin(dst, var_value);
			free(dst);
			dst = tmp;
		}
	}
	free(var_name);
	return (dst);
}

char	*elab_quote(const char *src, int *i, char *dst)
{
	(*i)++;
	while (*(src + *i))
	{
		if (*(src + *i) == '\'')
		{
			(*i)++;
			break ;
		}
		dst = app_char(src, i, dst);
	}
	return (dst);
}

char	*elab_dquote(const char *src, int *i, char *dst)
{
	(*i)++;
	while (*(src + *i))
	{
		if (*(src + *i) == '"')
		{
			(*i)++;
			break ;
		}
		else if (*(src + *i) == '$')
			dst = elab_dollar(src, i, dst);
		else
			dst = app_char(src, i, dst);
	}
	return (dst);
}

int		next_char(char *str, char c, int start)
{
	while (*(str + start))
	{
		if (*(str + start) == c)
			return (start);
		start++;
	}
	return (-1);
}

int		is_break(const char *cmd, int i)
{
	char	c;

	c = *(cmd + i);
	if (c == ' ' || c == 0)
		return (1);
	if (c == '>' && *(cmd + i + 1) == '>')
		return (4);
	if (c == '>')
		return (3);
	if (c == '<')
		return (5);
	if (c == '|')
		return (2);
	if (c == ';')
		return (6);
	return (0);
}

char	*next_token(const char *cmd, int *i, int *isb)
{
	char	*buff;

	buff = malloc(sizeof(char));
	buff[0] = 0;
	while (1)
	{
		*isb = is_break(cmd, *i);
		if (*isb)
			break ;
		if (*(cmd + *i) == '\'')
			buff = elab_quote(cmd, i, buff);
		else if (*(cmd + *i) == '"')
			buff = elab_dquote(cmd, i, buff);
		else if (*(cmd + *i) == '$')
			buff = elab_dollar(cmd, i, buff);
		else if (*(cmd + *i) == '\\' && *i < (int)ft_strlen(cmd) - 1)
			buff = escape_slash(cmd, i, buff);
		else
			buff = app_char(cmd, i, buff);
	}
	return (buff);
}

void	init_cmd(t_cmd *comm)
{
	comm->file_in = 0;
	comm->file_out = 1;
	comm->err_out = 2;
	comm->is_append = 0;
	comm->len = 0;
	comm->next = NULL;
}

t_cmd	**start_parsing(const char *cmd)
{
	t_cmd	**cmd_arr;
	t_cmd	**tmp_cmd_arr;
	t_cmd	*comm;
	t_cmd	*tmp_comm;
	char	**arr;
	int		i;
	int		n;
	char	*buff;
	int		stage;
	int		isb;
	int		arr_len;

	cmd_arr = malloc(sizeof(t_cmd*));
	cmd_arr[0] = NULL;
	i = 0;
	arr_len = 0;
	while (1)
	{
		arr_len++;
		tmp_cmd_arr = malloc(sizeof(t_cmd*) * (arr_len + 1));
		tmp_cmd_arr[arr_len] = NULL;
		n = 0;
		while (n < arr_len - 1)
		{
			tmp_cmd_arr[n] = cmd_arr[n];
			n++;
		}
		free(cmd_arr);
		cmd_arr = tmp_cmd_arr;
		comm = malloc(sizeof(t_cmd));
		cmd_arr[arr_len - 1] = comm;
		init_cmd(comm);
		arr = malloc(0);
		stage = 0;
		isb = 0;
		while (*(cmd + i))
		{
			buff = next_token(cmd, &i, &isb);
			if (!stage && ft_strlen(buff))
				arr = append_to_arr(buff, &comm->len, arr);
			if (!stage && isb == 2)
			{
				tmp_comm = malloc(sizeof(t_cmd));
				comm->next = tmp_comm;
				comm->arr = arr;
				tmp_comm->next = 0;
				comm = comm->next;
				init_cmd(comm);
				i++;
				arr = malloc(0);
				stage = 0;
				continue ;
			}
			if (stage == 3 && ft_strlen(buff))
			{
				if (comm->file_out != 1)
					close(comm->file_out);
				comm->file_out = open(buff, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
				stage = 0;
			}
			if (stage == 4 && ft_strlen(buff))
			{
				if (comm->file_out != 1)
					close(comm->file_out);
				comm->file_out = open(buff, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
				comm->is_append = 1;
				stage = 0;
			}
			if (stage == 5 && ft_strlen(buff))
			{
				if (comm->file_in != 0)
					close(comm->file_in);
				comm->file_in = open(buff, O_RDONLY);
				stage = 0;
			}
			if (isb > 2)
				stage = isb;
			if (isb == 4)
				i++;
			if (*(cmd + i) != 0)
				i++;
			if (isb == 6)
			{
				// se cmd vuoto > ERRORE
				stage = 0;
				break ;
			}
		}
		comm->arr = arr;
		if (!*(cmd + i))
			break ;
	}
	return (cmd_arr);
}
/*
int	main(int argv, char **argc)
{
	t_cmd	**comm_arr;
	t_cmd	*comm_list;
	char	*str = "ciao | pwd > wooo < fregnaaa | wc >> appp";
	printf("input: %s\n", str);
	comm_arr = start_parsing(str);
	comm_list = comm_arr[0];
	while (comm_list)
	{
		printf("%s\n", comm_list->arr[0]);
		printf("file in: %d file out: %d is app: %d\n", comm_list->file_in, comm_list->file_out, comm_list->is_append);
		comm_list = comm_list->next;
	}
	return (0);
}
*/

/*

cmd > file1 > file2 > file3
cmd1 | cmd2 < file_in
cmd > file_out
cmd >> file_app
cmd < file_in
cmd1 ; cmd2

bash-3.2$ echo "$TERM"
xterm-256color

bash-3.2$ echo '$TERM'
$TERM

bash-3.2$ echo "\'"
\'

bash-3.2$ echo '\"'
\"

bash-3.2$ echo "ciao   test"
ciao   test

bash-3.2$ echo ciao   test
ciao test

bash-3.2$ echo 'ciao   test'
ciao   test

bash-3.2$ ARG="ciao   test"
bash-3.2$ echo $ARG
ciao test

*/