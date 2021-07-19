/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------
en
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.
----------------------------------------------------------------------------------

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$

*/
#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int flags[128] = {0};
	
	i = 0;
	if (argc == 3) //это условие необходимо для того, чтобы обрабатывать только случаи с двумя аргументами. Первый аргумент - это название функции, поэтому проверяем, что аргументов 3
	{
		while (argv[1][i] != '\0')
		{
			j = 0;
			if (argv[1][i] == argv[1][i + j])
			{
				flags[argv[1][i]] = 1;
				j++;
			}
		i++;
		}
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (flags[argv[1][i]] == 1)
			{
				write(1, &argv[1][i], 1);
				flags[argv[1][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}