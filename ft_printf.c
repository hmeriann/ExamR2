#include <stdio.h> // delete before push
#include <stdlib.h> //malloc
#include <stdarg.h> //arguments
#include <unistd.h>

int g_result;
int g_wid;
int g_pre;

static void ft_putchar(char c)
{
	write(1, &c, 1);
	g_result++;
}

static int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i] != 0)
		i++;
	return (i);
}

static void ft_putstr(char *str, int len)
{
	while (*str !='\0' && len > 0)
	{
		ft_putchar(*str);
		str++;
		len--;
	}
}

static void ft_printstr(char *str)
{
	int len = ft_strlen(str);

	if (g_pre != -1 && g_pre < len)
		len = g_pre;
	while (g_wid > len)
	{
		ft_putchar(' ');
		g_wid--;
	}
	ft_putstr(str, len);
}

static char *ft_itoa(unsigned long number, int base)
{
	int len = 0;
	unsigned long tmp_num = number;
	char *str = NULL;

	if (tmp_num == 0)
		len += 1;
	while (tmp_num > 0)
	{
		tmp_num = tmp_num / base;
		len++;
	}
	if (!(str = malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = "0123456789abcdef"[number % base];
		number = number / base;
		len--;
	}
	return(str);
}

static void ft_printint(int number)
{
	int tmp_num = number;
	char *str = ft_itoa(tmp_num, 10);
	int len = ft_strlen(str);

	while (g_wid > g_pre && g_wid > len)
	{
		ft_putchar(' ');
		g_wid--;
	}
	while (g_pre > len)
	{
		ft_putchar('0');
		g_pre--;
	}
	ft_putstr(str, len);
}

static void ft_printhex(unsigned int number)
{
	int tmp_num = number;
	char *str = ft_itoa(tmp_num, 16);
	int len = ft_strlen(str);

	while (g_wid > g_pre && g_wid > len)
	{
		ft_putchar(' ');
		g_wid--;
	}
	while (g_pre > len)
	{
		ft_putchar('0');
		g_pre--;
	}
	ft_putstr(str, len);	
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int i = 0;
	g_result = 0;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			g_pre = -1;
			g_wid = 0;
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_wid = g_wid * 10 + (str[i] - '0');
				i++;
			}
			if (str[i] == '.')
			{
				g_pre = 0;
				i++;
				while (str[i] >= '0' && str[i] <= '9')
				{
					g_pre = g_pre * 10 + (str[i] - '0');
					i++;
				}
			}
			if (str[i] == 's')
				ft_printstr(va_arg(ap, char *));
			else if (str[i] == 'd')
				ft_printint(va_arg(ap, int));
			else if (str[i] == 'x')
				ft_printhex(va_arg(ap, unsigned int));
			else
				ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (g_result);
}

int main()
{
	printf("%10.2s\n", "toto");
	ft_printf("%10.2s\n", "toto");
	printf("Magic %s is %5d\n", "number", 42);
	ft_printf("Magic %s is %5d\n", "number", 42);
	printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}