#include "ft_printf.h"

void		ft_data_init(t_struct *data)
{
	data->ash = 0;
	data->moins = 0;
	data->plus = 0;
	data->j = 0;
	data->z = 0;
	data->acc = -1;
	data->zero = ' ';
	data->size = 0;
	data->nblen = 0;
	data->wid = 0;
}
/*
**	affichage
*/

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static void		ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');

}
MaM`
static int		ft_putstr(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

/*
**	quelle conversion ?
*/

/*
**	conversions
*/
int		ft_parse_flags1(t_struct *data, int i)
{
	if (data->fmtcpy[i] == '#' )
		data->ash = 1;
	if ( data->fmtcpy[i] == '0')
		data->zero = '0';
	if  (data->fmtcpy[i] == '-')
		data->moins = 1;
	if (data->fmtcpy[i] == '+') 
		data->plus = '+';
	if (data->fmtcpy[i] == ' ' && data->plus == 0)
		data->plus = 32;
	else if (data->fmtcpy[i] == 'h' || data->fmtcpy[i] == 'l' || data->fmtcpy[i] == 'j' || data->fmtcpy[i] == 'z')
	{
		if (data->len[0] == 0)
			data->len[0] = data->fmtcpy[i];
		else if (data->len[0] == data->fmtcpy[i] && data->len[1] == 0)
			data->len[1] = data->len[0];
		else if (data->len[0] == data->fmtcpy[i] && data->len[1] == data->fmtcpy[i])
			data->len[1] = 0;
		
	}
	else if (data->fmtcpy[i] == '.')
	{
		data->i = i + 1;
		data->acc = atoi(data->fmtcpy + data->i);
		while(data->fmtcpy[data->i] <= '9' && data->fmtcpy[data->i] >= '0')
			data->i++;
		data->i--;
	}
	else if (data->fmtcpy[i] <= '9' && data->fmtcpy[i] >= '1')
	{
		data->wid = atoi(fmtcpy + i);
		while (data->fmtcpy[i] <= '9' && data->fmtcpy[i] >= '0')
		{
			if (data->fmtcpy[i] == 0)
				return (1);
			i++;
		}
		data->i = i - 1;
	}
	else
	{
		data->nb_char++;
		write(1, &data->fmtcpy[i], 1);
		data->i = i;
		return (1);
	}
	return (0);
}

size_t		ft_put_mult(char c, size_t n)
{
	size_t	i;
	char    str[n];

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	write(1, str, i);
	return (i);
}

void	ft_wich_conversion(t_struct *data, int j)
{

}

void	ft_parse_conversion(t_struct *data, int i)
{
	int		j;
	char	*mask;

	while (data->fmtcpy[i])
	{
		j = 0
		data->i = i;
		mask = "sScCpdDioOuUxX";
		while(mask[j])
		{
			if (data->fmtcpy[i] == mask[j])
			{
				ft_wich_conversion(data, j)
				return;
			}
			j++;
		}
		if (ft_parse_flags1(data, i) == 1)
			return;
		i = data->i + 1;
	}
}

/*
**	parsing
*/

int			ft_parse_format(t_struct *data)
{
	int		i;

	i = 0;
	while (data->fmtcpy[i])
	{
		if (data->fmtcpy[i] != '%')
		{
			ft_putchar(data->fmtcpy[i]);
			i++;
			data->nb_char++;
		}
		 else
		{
			ft_data_init(data);
			data->posi = i;
			ft_parse_conversion(data, i + 1)
			i = data->i + 1;
		}	
	}
	free(data->fmtcpy);
	return (0);
}

/*
**	fonction source
*/

int				ft_printf(const char *format, ...)
{
	t_struct	data;

	data.fmtcpy = format;
	va_start(data.ap, format);
	data.nb_char = 0;
	if (format == NULL)
		data.nb_char = ft_putstr(va_arg(data.ap, char *));
	else
		ft_parse_format(&format, &data);
	va_end(data.ap);
	return (data.nb_char);
}

int		main()
{
	int i;

	ft_printf("%ld\n", i);
	printf("%d\n", i);
	return (0);
}
