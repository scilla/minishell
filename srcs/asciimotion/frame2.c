/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*   By: vbuonvin <vbuonvin@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:59:13 by scilla            #+#    #+#             */
/*   Updated: 2021/07/09 15:59:14 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	frame4(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "███████╗██████╗ ███████╗       _.---._        █████"
		   "█╗ ███████╗██████╗ ██████╗ \n"
		   "██╔════╝██╔══██╗██╔════╝   .\'\"\".\'/|\\`.\"\"\'. "
		   "   ██╔══██╗██╔════╝██╔══██╗██╔══██╗\n"
		   "█████╗  ██████╔╝█████╗    :  .' / | \\ `.  :   ████"
		   "██╔╝█████╗  ██████╔╝██████╔╝\n"
		   "██╔══╝  ██╔══██╗██╔══╝    '.'  /  |  \\  `.'   ██╔═"
		   "══╝ ██╔══╝  ██╔═══╝ ██╔═══╝ \n"
		   "███████╗██║  ██║███████╗   `. /   |   \\ .'    ██║ "
		   "    ███████╗██║     ██║     \n"
		   "╚══════╝╚═╝  ╚═╝╚══════╝     `-.__|__.-'      ╚═╝  "
		   "   ╚══════╝╚═╝     ╚═╝     \n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame5(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "██████╗ ███████╗       _.---._        ██████"
		   "╗ ███████╗██████╗ ██████╗ ███████╗\n"
		   "██╔══██╗██╔════╝   .\'\"\".\'/|\\`.\"\"\'.  "
		   "  ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝\n"
		   "██████╔╝█████╗    :  .' / | \\ `.  :   █████"
		   "█╔╝█████╗  ██████╔╝██████╔╝█████╗  \n"
		   "██╔══██╗██╔══╝    '.'  /  |  \\  `.'   ██╔══"
		   "═╝ ██╔══╝  ██╔═══╝ ██╔═══╝ ██╔══╝  \n"
		   "██║  ██║███████╗   `. /   |   \\ .'    ██║  "
		   "   ███████╗██║     ██║     ███████╗\n"
		   "╚═╝  ╚═╝╚══════╝     `-.__|__.-'      ╚═╝   "
		   "  ╚══════╝╚═╝     ╚═╝     ╚══════╝\n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame6(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "███████╗       _.---._        ██████╗ ███"
		   "████╗██████╗ ██████╗ ███████╗██████╗ \n"
		   "██╔════╝   .\'\"\".\'/|\\`.\"\"\'.    ██╔"
		   "══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗\n"
		   "█████╗    :  .' / | \\ `.  :   ██████╔╝██"
		   "███╗  ██████╔╝██████╔╝█████╗  ██████╔╝\n"
		   "██╔══╝    '.'  /  |  \\  `.'   ██╔═══╝ ██"
		   "╔══╝  ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══██╗\n"
		   "███████╗   `. /   |   \\ .'    ██║     ██"
		   "█████╗██║     ██║     ███████╗██║  ██║\n"
		   "╚══════╝     `-.__|__.-'      ╚═╝     ╚══"
		   "════╝╚═╝     ╚═╝     ╚══════╝╚═╝  ╚═╝\n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame7(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "        _.---._        ██████╗ ███████╗████"
		   "██╗ ██████╗ ███████╗██████╗ ███████╗\n"
		   "    .\'\"\".\'/|\\`.\"\"\'.    ██╔══██╗██╔═"
		   "═══╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝\n"
		   "   :  .' / | \\ `.  :   ██████╔╝█████╗  ███"
		   "███╔╝██████╔╝█████╗  ██████╔╝█████╗  \n"
		   "   '.'  /  |  \\  `.'   ██╔═══╝ ██╔══╝  ██╔"
		   "═══╝ ██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝  \n"
		   "    `. /   |   \\ .'    ██║     ███████╗██║"
		   "     ██║     ███████╗██║  ██║███████╗\n"
		   "      `-.__|__.-'      ╚═╝     ╚══════╝╚═╝ "
		   "    ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝\n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame8(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "     _.---._         ██████╗ ███████╗██"
		   "████╗ ██████╗ ███████╗██████╗ ███████╗  \n"
		   " .\'\"\".\'/|\\`.\"\"\'.     ██╔══██╗██"
		   "╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝  \n"
		   ":  .' / | \\ `.  :    ██████╔╝█████╗  █"
		   "█████╔╝██████╔╝█████╗  ██████╔╝█████╗    \n"
		   "'.'  /  |  \\  `.'    ██╔═══╝ ██╔══╝  █"
		   "█╔═══╝ ██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝    \n"
		   " `. /   |   \\ .'     ██║     ███████╗█"
		   "█║     ██║     ███████╗██║  ██║███████╗  \n"
		   "   `-.__|__.-'       ╚═╝     ╚══════╝╚═"
		   "╝     ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝  \n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}
