
#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j;
	int flags[255] = {0};

	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[2][j] != '\0')
			{
				if (argv[1][i] == argv[2][j]) 
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