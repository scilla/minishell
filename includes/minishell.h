#ifndef MINISHELL_MINISHELL_H
#define MINISHELL_MINISHELL_H

/*
 *	; should separate commands like bash
 *	< infile
 *	> outfile
 *	| redirect output
 *
 */

#include <stdlib.h>
#include "../libft/libft.h"
#include "color.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

typedef struct	s_cmd
{
	char		**cmd_table;
}				t_cmd;


#define ECHO "echo"
#define CD "cd"
#define PWD "pwd"
#define EXPORT "export"
#define UNSET "unset"
#define ENV "env"
#define EXIT "exit"

enum e_token
{
	CHAR_GENERAL=	-1,
	CMD			=	0,
	INFILE		=	'<',
	OUTFILE		=	'>',
	PIPE		=	'|',

};

typedef struct	s_scmd
{

}				t_scmd;

typedef struct	s_shell
{
	char *prompt;
	char *line;
	char **splitted;
}				t_shell;

/*
 *
 */

/*
** LEXAR
*/

char *lexar(t_shell *minishell);

/*
** PROMPT
*/

void set_prompt(t_shell *minishell, char *str);
char* getprompt(t_shell *minishell);

/*
** CMD
*/

void	command_handle(char *command, t_shell *minishell);
void	ft_echo(t_shell *minishell);
void	ft_pwd(t_shell *minishell);
void	ft_cd(t_shell *minishell);

#endif //MINISHELL_MINISHELL_H