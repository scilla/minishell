#include <stdio.h>
#include "../includes/minishell.h"

void	watermark(void)
{
	printf("\n" CC_BHYEL
		   "██████╗ ███████╗██████╗ ██████╗ ███████╗██████╗ ███████╗"
		"          _.---._		\n"
		   "██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝"
		"      .\'\"\".\'/|\\`.\"\"\'.\n"
		   "██████╔╝█████╗  ██████╔╝██████╔╝█████╗  ██████╔╝█████╗  "
		"     :  .' / | \\ `.  :	\n"
		   "██╔═══╝ ██╔══╝  ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝  "
		"     '.'  /  |  \\  `.'	\n"
		   "██║     ███████╗██║     ██║     ███████╗██║  ██║███████╗"
		"      `. /   |   \\ .'	\n"
		   "╚═╝     ╚══════╝╚═╝     ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝"
		"        `-.__|__.-'		\n"
		   CC_WHT "\t\t\t\t\t   Fatto da " CC_CYN "tutti"\
CC_WHT " & " CC_CYN "nessuno" CC_RESET "\n");
}